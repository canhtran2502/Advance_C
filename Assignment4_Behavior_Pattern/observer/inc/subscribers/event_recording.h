#ifndef EVENT_RECORDING_H
#define EVENT_RECORDING_H

#include "../subscriber_publisher.h"

typedef struct {
    s_subscriber_t base;
} s_event_recording_t;

void event_recording_init(s_event_recording_t* notifier);

#endif // EVENT_RECORDING_H
