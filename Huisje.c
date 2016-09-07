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
    printf("drive_goto(%f, %f)\n", full_rotation*multiplier, -full_rotation*multiplier);
    drive_goto(full_rotation*multiplier, -full_rotation*multiplier);
  } else if(direction == COUNTERCLOCKWISE) {
    printf("drive_goto(%f, %f)\n", -full_rotation*multiplier, full_rotation*multiplier);
    drive_goto(-full_rotation*multiplier, full_rotation*multiplier);
  }    
  pause(200);
}  

void forward(float distance) {
  printf("drive_goto(%f, %f)\n", distance, distance);
  drive_goto(distance, distance);
  pause(200);
}  

int main()
{
  float line_distance = 5 * 100 / millimeters_per_tick; // 5 cm
  
  printf("Starting\n");
  printf("Moving forward 1 step\n");
  drive_goto(distance, distance);
  printf("Turning %i degrees ccw\n", 180 - 45);
  spin(0.375, COUNTERCLOCKWISE);
  printf("Moving forward 1 step\n");
  drive_goto(28.28, 28.28);
  printf("Turning %i degrees cw\n", 180 - 45);
  spin(0.375, CLOCKWISE);
  printf("Moving forward 1 step\n");
  drive_goto(distance, distance);
  spin(0.375, COUNTERCLOCKWISE);
  drive_goto(14.14, 14.14);
  spin(0.25, COUNTERCLOCKWISE);
  drive_goto(14.14, 14.14);
  spin(0.125, COUNTERCLOCKWISE);
  drive_goto(distance, distance);
  spin(0.375, COUNTERCLOCKWISE);
  drive_goto(28.28, 28.28);
  spin(0.375, CLOCKWISE);
  drive_goto(distance, distance);
}
