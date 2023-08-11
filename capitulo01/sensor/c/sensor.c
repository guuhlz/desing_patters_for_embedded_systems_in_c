#include "Sensor.h"
#include <stdlib.h>


void sensor_init(Sensor* const me){

}

void sensor_cleanup(Sensor* const me){

}

int sensor_get_filter_frequency (const Sensor* const me){
  return me->filter_frequency;
      
}

void sensor_set_filter_frequency(Sensor* const me, int p_filter_frequency){
  me->filter_frequency = p_filter_frequency;
}

void sensor_set_update_frequency(Sensor* const me, int p_update_frequency){
  me->filter_frequency = p_update_frequency;
}

int sensor_get_update_frequency(Sensor* const me){
  return me->update_frequency;
}

int sensor_get_value(const Sensor* const me){
  return me->value;
}

Sensor* sensor_create(void){
  Sensor* me = (Sensor*)malloc(sizeof(Sensor));
  if(me!=NULL){
    sensor_init(me);
  }
  return me;
}

void sensor_destroy(Sensor * const me){
  if(me!=NULL){
    sensor_cleanup(me);
  }
  free(me);
}






