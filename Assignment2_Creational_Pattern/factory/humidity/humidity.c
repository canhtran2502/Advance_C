#include <stdio.h>
#include <stdlib.h>
#include "humidity.h"

s_sensor_t create_humidity_sensor(void)
{
    s_sensor_t humidity_sensor;
    humidity_sensor.init = init_humidity_sensor;
    humidity_sensor.read = read_humidity_sensor;
    return humidity_sensor;
}
void init_humidity_sensor(void)
{
    printf("\nInitialize humidity sensor\n");
}
float read_humidity_sensor(void)
{
    printf("Read humidity sensor\n");
    float data = 60 + (rand() % 100) / 10.0;
    return data;
}