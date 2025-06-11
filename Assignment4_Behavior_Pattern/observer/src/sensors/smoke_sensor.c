#include "../../inc/sensors/smoke_sensor.h"
#include <stdio.h>

// Initialize the s_smoke_sensor_t struct
void smoke_sensor_init(s_smoke_sensor_t* sensor) {
    publisher_init(&sensor->base);
    sensor->smoke_detected = RESET_VALUE;
}

// Simulate a smoke event and notify subscribers
void smoke_sensor_trigger(s_smoke_sensor_t* sensor, int detected) {
    sensor->smoke_detected = detected;
    if (detected) {
        sensor->base.notify_subscribers(&sensor->base, "Smoke Detected");
    } else {
        sensor->base.notify_subscribers(&sensor->base, "No Smoke");
    }
}
