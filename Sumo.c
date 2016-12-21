#include "simpletools.h"
#include "abdrive.h"
#include "ping.h"

int speedLeft, speedRight;
int speedForward = 64;

int lightLeft, lightRight;

int distancePing;
int distanceAttack = 30;

void findTarget();

int *cogTarget;

typedef enum { NORMAL, ATTACKING } state;

int main()                    
{
  stay();
  cogTarget = cog_run(findTarget, 512);
}

void stay() {
  while(1) {
    high(9);
    pause(1);
    lightLeft = rc_time(9, 1);
    
    high(5);
    pause(1);
    lightRight = rc_time(5, 1);
    
    if(lightLeft > 5000 && distancePing < 30) {
      cog_end(cogTarget);
      drive_speed(-56, 57);
      pause(1000);
      cogTarget = cog_run(findTarget, 512);
    } else if(lightRight > 5000 && distancePing < 30) {
      cog_end(cogTarget);
      drive_speed(56, -57);
      pause(1000);
      cogTarget = cog_run(findTarget, 512);
    }           
    
    drive_speed(speedForward, speedForward);
  }  
}

void findTarget() {
  while(1) {
    distancePing = ping_cm(7);
    
    if(distancePing < distanceAttack) {
      drive_speed(128, 128);
      high(3);
    } else { 
      drive_speed(speedForward, speedForward);
    }          
  }  
}  