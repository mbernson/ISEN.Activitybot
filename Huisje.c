/*
  Huisje tekenen
*/
#include "simpletools.h"
#include "abdrive.h"

const float wheel_base = 105.8;
const float pi = 3.1415;
const float millimeters_per_tick = 3.25;

typedef enum { CLOCKWISE, COUNTERCLOCKWISE } rotation;

void spin(float multiplier, rotation direction) {
  float full_rotation = (wheel_base * pi) / millimeters_per_tick;
  if(direction == CLOCKWISE)
    drive_goto(full_rotation*multiplier, -full_rotation*multiplier);
  else if(direction == COUNTERCLOCKWISE)
    drive_goto(-full_rotation*multiplier, full_rotation*multiplier);
}  

void forward(float distance) {
  drive_goto(distance, distance);
}  

int main()
{
  float line_distance = 5 * 100 / millimeters_per_tick; // 5 cm
  
  printf("Starting\n");
  printf("Moving forward 1 step\n");
  forward(line_distance);
  printf("Turning %i degrees ccw\n", 180 - 45);
  spin((180 - 45) / 360, COUNTERCLOCKWISE);
  printf("Moving forward 1 step\n");
  forward(line_distance);
}
