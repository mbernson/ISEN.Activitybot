/* 
  Test for Trim.c

  Test and adjust trim for servos and encoders

  http://learn.parallax.com/activitybot/test-and-tune-your-activitybot
*/

#include "simpletools.h"
#include "abdrive.h"
#include <math.h>

int main()                   
{
  int max_speed = 128;
  
  drive_trimSet(0, 0, 0);
  int t = 290;
  while(1) {
//    t = t + 1;
    int speed = sin(t/40) * max_speed;
    drive_speed(speed, speed);    
    pause(10);
  }    

}


