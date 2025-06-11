#include "subscribers/hvac_system.h"
#include <stdio.h>

// Update method for AlarmSystemController
void hvac_system_update(s_subscriber_t* self, s_publisher_t* context, const char* event_info) {
    (void)self; (void)context;
    printf("[HVACSystem] Message: %s\n", event_info);
}

// Initialize AlarmSystemController
void hvac_system_init(s_hvac_system_t* controller) {
    controller->base.update = hvac_system_update;
    controller->base.data = NULL;
}
