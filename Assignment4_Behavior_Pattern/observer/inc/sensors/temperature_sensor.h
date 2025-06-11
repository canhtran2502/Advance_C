#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "../subscriber_publisher.h"

#define MAX_CHARACTER (100)

// Temperature sensor struct
typedef struct {
    s_publisher_t base;
    int temperature;
} s_temperature_sensor_t;

void temperature_sensor_init(s_temperature_sensor_t* sensor);
void temperature_sensor_trigger(s_temperature_sensor_t* sensor, int temperature);

#endif // SMOKE_SENSOR_H
