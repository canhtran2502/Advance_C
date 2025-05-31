#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include "sensor.h"

typedef enum {
    TEMPERATURE_SENSOR,
    HUMIDITY_SENSOR,
    PRESSURE_SENSOR,
    LIGHT_SENSOR
} e_sensor_type_t;

s_sensor_t* create_sensor(e_sensor_type_t sensor_type);

#endif