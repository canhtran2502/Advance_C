#include <stdio.h>
#include <stdlib.h>
#include "sensor_factory.h"
#include "../temperature/temperature.h"
#include "../humidity/humidity.h"
#include "../light/light.h"
#include "../pressure/pressure.h"


s_sensor_t* create_sensor(e_sensor_type_t sensor_type)
{
    s_sensor_t* sensor = (s_sensor_t*)malloc(sizeof(s_sensor_t));
    if (NULL == sensor)
    {
        printf("Allocate memory failed for sensor creation\n");
        return NULL;
    }

    switch(sensor_type)
    {
        case TEMPERATURE_SENSOR:
            *sensor = create_temperature_sensor();
            break;
        case HUMIDITY_SENSOR:
            *sensor = create_humidity_sensor();
            break;
        case PRESSURE_SENSOR:
            *sensor = create_pressure_sensor();
            break;
        case LIGHT_SENSOR:
            *sensor = create_light_sensor();
            break;
        default:
            break;
    }

    return sensor;
}