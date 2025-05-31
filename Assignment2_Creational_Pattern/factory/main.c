#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sensor_factory/sensor_factory.h"

int main() {

    srand(time(NULL)); //Call for simulating the sensor data.

    /* Create a temperature sensor */
    s_sensor_t* temperature_sensor = create_sensor(TEMPERATURE_SENSOR);
    if (temperature_sensor != NULL) {
        temperature_sensor->init();
        printf("Temperature: %.2f°C\n", temperature_sensor->read());
        free(temperature_sensor);
    }
    else 
    {
        printf("Create temperature sensor failed\n");
        return 1;
    }

    /* Create a humidity sensor */
    s_sensor_t* humidity_sensor = create_sensor(HUMIDITY_SENSOR);
    if (humidity_sensor != NULL) {
        humidity_sensor->init();
        printf("Humidity: %.2f \n", humidity_sensor->read());
        free(humidity_sensor);
    }
    else
    {
        printf("Create humidity sensor failed\n");
        return 1;
    }

    /* Create a light sensor */
    s_sensor_t* light_sensor = create_sensor(LIGHT_SENSOR);
    if (light_sensor != NULL) {
        light_sensor->init();
        printf("Light: %.2f\n", light_sensor->read());
        free(light_sensor);
    }
    else
    {
        printf("Create light sensor failed\n");
        return 1;
    }

    /* Create a pressure sensor */
    s_sensor_t* pressure_sensor = create_sensor(PRESSURE_SENSOR);
    if (pressure_sensor != NULL) {
        pressure_sensor->init();
        printf("Pressure: %.2f PA\n", pressure_sensor->read());
        free(pressure_sensor);
    }
    else
    {
        printf("Create pressure sensor failed\n");
        return 1;
    }

    return 0;
}
