#include "subscribers/event_recording.h"
#include <stdio.h>

// Update method for AlarmSystemController
void event_recording_update(s_subscriber_t* self, s_publisher_t* context, const char* event_info) {
    (void)self; (void)context;
    printf("[EventRecording] Event: %s\n", event_info);
}

// Initialize AlarmSystemController
void event_recording_init(s_event_recording_t* controller) {
    controller->base.update = event_recording_update;
    controller->base.data = NULL;
}
