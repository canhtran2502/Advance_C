#ifndef ALARM_SYSTEM_CONTROLLER_H
#define ALARM_SYSTEM_CONTROLLER_H

#include "../subscriber_publisher.h"

typedef struct {
    s_subscriber_t base;
} s_alarm_system_controller_t;

void alarm_system_controller_init(s_alarm_system_controller_t* controller);

#endif // ALARM_SYSTEM_CONTROLLER_H
