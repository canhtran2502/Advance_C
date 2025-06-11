#ifndef SMOKE_SENSOR_H
#define SMOKE_SENSOR_H

#include "../subscriber_publisher.h"

#define DETECTED_SMOKE  (1)

// Smoke sensor struct
typedef struct {
    s_publisher_t base;
    int smoke_detected;
} s_smoke_sensor_t;

void smoke_sensor_init(s_smoke_sensor_t* sensor);
void smoke_sensor_trigger(s_smoke_sensor_t* sensor, int detected);

#endif // SMOKE_SENSOR_H
