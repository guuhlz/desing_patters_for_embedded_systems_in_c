#include <stdlib.h>
#include <stdio.h>

#include "Sensor.h"


int main (int argc, char *argv[])
{
  Sensor *p_sensor0, *p_sensor1;

  p_sensor0 = sensor_create();
  p_sensor1 = sensor_create();

  p_sensor0->value = 99;
  p_sensor1->value = -1;

  printf("The current value from Sensor 0 is %d\n",
  sensor_get_value(p_sensor0));
  printf("The current value from Sensor 1 is %d\n",
  sensor_get_value(p_sensor1));
  /* done with sensors */
  sensor_destroy(p_sensor0);
  sensor_destroy(p_sensor1); 
  return 0;
}
