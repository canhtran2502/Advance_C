#include <stdio.h>
#include <stdlib.h>
#include "light.h"

s_sensor_t create_light_sensor(void)
{
    s_sensor_t light_sensor;
    light_sensor.init = init_light_sensor;
    light_sensor.read = read_light_sensor;
    return light_sensor;
}
void init_light_sensor(void)
{
    printf("\nInitialize light sensor\n");
}
float read_light_sensor(void)
{
    printf("Read light sensor\n");
    float data = 60 + (rand() % 100) / 10.0;
    return data;
}