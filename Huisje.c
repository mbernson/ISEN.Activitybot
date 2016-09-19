/*
  Huisje tekenen
*/
#include "simpletools.h"
#include "abdrive.h"

const float wheel_base = 105.8;
const float pi = 3.1415;
const float millimeters_per_tick = 3.25;
const float distance = 20;

typedef enum { CLOCKWISE, COUNTERCLOCKWISE } rotation;

void spin(float multiplier, rotation direction) {
  float full_rotation = (wheel_base * pi) / millimeters_per_tick;
  if(direction == CLOCKWISE) {
    drive_goto(full_rotation*multiplier, -full_rotation*multiplier);
  } else if(direction == COUNTERCLOCKWISE) {
    drive_goto(-full_rotation*multiplier, full_rotation*multiplier);
  }    
  pause(200);
}  

void forward(float distance) {
  drive_goto(distance, distance);
  pause(200);
}  

int main()
{
  float line_distance = 5 * 100 / millimeters_per_tick; // 5 cm
  
  forward(distance);
  spin(0.375, COUNTERCLOCKWISE);
  forward(28.28);
  spin(0.375, CLOCKWISE);
  forward(distance);
  spin(0.375, COUNTERCLOCKWISE);
  forward(14.14);
  spin(0.25, COUNTERCLOCKWISE);
  forward(14.14);
  spin(0.125, COUNTERCLOCKWISE);
  forward(distance);
  spin(0.375, COUNTERCLOCKWISE);
  forward(28.28);
  spin(0.375, CLOCKWISE);
  forward(distance);
}
