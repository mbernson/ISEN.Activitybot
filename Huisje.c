/*
  Huisje tekenen 
*/
#include "simpletools.h"
#include "abdrive.h"

const float wheel_base = 105.8;
const float pi = 3.1415;
const float millimeters_per_tick = 3.25;

const float house_size = 30;

typedef enum { CLOCKWISE, COUNTERCLOCKWISE } rotation;

int main()
{ 
  better_house();
}

void spin(float multiplier, rotation direction) {
  float turn_distance = ((wheel_base * pi) / millimeters_per_tick) * multiplier;
  
  if(direction == CLOCKWISE)
  {
    print("\nTurning %f degrees to the right(%s)!", multiplier, direction);
    drive_goto(turn_distance, -turn_distance);
  } 
  else if(direction == COUNTERCLOCKWISE)
  {
    print("\nTurning %f degrees to the left(%s)!", multiplier, direction);
    drive_goto(-turn_distance, turn_distance);
  }      
  
  pause(200);
}  

void forward(float distance) 
{
  print("\nDriving distance %d!", distance);
  drive_goto(distance, distance);
  pause(200);
}  

float calculateAngle(float x, float y) 
{
  return (sqrt(((x*x)+(y*y))));
}

void better_house()
{
  float angle_size = calculateAngle(house_size, house_size);
  float roof_size = angle_size / 2;
  
  print("\nThe house size is %f", house_size);
  print("\nThe angle size is %f", angle_size);
  print("\nThe roof size is %f", roof_size);
  
  //1. Go forward
  forward(house_size);
  
  //2. Turn 45 degrees
  spin(0.375, COUNTERCLOCKWISE);
  
  //3. Make first file for cross
  forward(angle_size);
  
  //4. Turn 45 degrees
  spin(0.375,CLOCKWISE);  
  
  //5. Go forward
  forward(house_size);
  
  //6. Turn 45 degrees
  spin(0.375, COUNTERCLOCKWISE);  
  
  //7. Make roof part 1
  forward(roof_size);
  
  //8. Turn 90 degrees
  spin(0.25, COUNTERCLOCKWISE);  
  
  //9. Make roof part 2
  forward(roof_size);
  
  //10. Turn 135 degrees
  spin(0.125, COUNTERCLOCKWISE);  
  
  //11. Go forward
  forward(house_size);

  //12. Turn 45 degrees
  spin(0.375, COUNTERCLOCKWISE);
  
  //13. Make cross part 2
  forward(angle_size);
  
  //14. Turn 45 degrees
  spin(0.375, CLOCKWISE);
  
  //15. Go forward
  forward(house_size);
}   