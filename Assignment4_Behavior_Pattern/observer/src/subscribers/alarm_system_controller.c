#include "subscribers/alarm_system_controller.h"
#include <stdio.h>

// Update method for AlarmSystemController
void alarm_system_update(s_subscriber_t* self, s_publisher_t* context, const char* event_info) {
    (void)self; (void)context;
    printf("[AlarmSystem] Alarm: %s\n", event_info);
}

// Initialize AlarmSystemController
void alarm_system_controller_init(s_alarm_system_controller_t* controller) {
    controller->base.update = alarm_system_update;
    controller->base.data = NULL;
}
