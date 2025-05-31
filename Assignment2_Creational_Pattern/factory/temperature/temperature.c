#include <stdio.h>
#include <stdlib.h>
#include "temperature.h"

s_sensor_t create_temperature_sensor(void)
{
    s_sensor_t temperature_sensor;
    temperature_sensor.init = init_temperature_sensor;
    temperature_sensor.read = read_temperature_sensor;
    return temperature_sensor;
}
void init_temperature_sensor(void)
{
    printf("\nInitialize temperature sensor\n");
}
float read_temperature_sensor(void)
{
    printf("Read temperature sensor\n");
    float data = 25.0 + (rand() % 100) / 10.0;
    return data;
}