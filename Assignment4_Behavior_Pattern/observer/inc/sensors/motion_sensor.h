#ifndef MOTION_SENSOR_H
#define MOTION_SENSOR_H

#include "../subscriber_publisher.h"

#define DETECTED_MOTION  (1)

// Motion sensor struct
typedef struct {
    s_publisher_t base;
    int detect_motion;
} s_motion_sensor_t;

void motion_sensor_init(s_motion_sensor_t* sensor);
void motion_sensor_trigger(s_motion_sensor_t* sensor, int detect_motion);

#endif // MOTION_SENSOR_H
