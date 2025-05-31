#include <stdio.h>
#include <stdlib.h>
#include "pressure.h"

s_sensor_t create_pressure_sensor(void)
{
    s_sensor_t pressure_sensor;
    pressure_sensor.init = init_pressure_sensor;
    pressure_sensor.read = read_pressure_sensor;
    return pressure_sensor;
}
void init_pressure_sensor(void)
{
    printf("\nInitialize pressure sensor\n");
}
float read_pressure_sensor(void)
{
    printf("Read pressure sensor\n");
    float data = 10000 + (rand() % 100) / 10.0;
    return data;
}