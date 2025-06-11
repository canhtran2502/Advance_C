#ifndef HVAC_SYSTEM_H
#define HVAC_SYSTEM_H

#include "../subscriber_publisher.h"

typedef struct {
    s_subscriber_t base;
} s_hvac_system_t;

void hvac_system_init(s_hvac_system_t* notifier);

#endif // HVAC_SYSTEM_H
