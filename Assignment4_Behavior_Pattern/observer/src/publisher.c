#include "../inc/subscriber_publisher.h"
#include <string.h>

// Subscribe a subscriber to the publisher
void publisher_subscribe(s_publisher_t* self, s_subscriber_t* s) {
    if (self->subscriber_count < MAX_SUBSCRIBERS) {
        self->subscribers[self->subscriber_count++] = s;
    }
}

// Unsubscribe a subscriber from the publisher
void publisher_unsubscribe(s_publisher_t* self, s_subscriber_t* s) {
    for (int i = 0; i < self->subscriber_count; ++i) {
        if (self->subscribers[i] == s) {
            for (int j = i; j < self->subscriber_count - 1; ++j) { 
                self->subscribers[j] = self->subscribers[j + 1]; // Re-arrange subscriber list.
            }
            self->subscriber_count--;
            break;
        }
    }
}

// Notify all subscribers about an event
void publishernotify_subscribers(s_publisher_t* self, const char* event_info) {
    for (int i = 0; i < self->subscriber_count; ++i) {
        if (self->subscribers[i] && self->subscribers[i]->update) {
            self->subscribers[i]->update(self->subscribers[i], self, event_info);
        }
    }
}

// Initialize the publisher struct
void publisher_init(s_publisher_t* pub) {
    memset(pub, RESET_VALUE, sizeof(s_publisher_t));
    pub->subscribe = publisher_subscribe;
    pub->unsubscribe = publisher_unsubscribe;
    pub->notify_subscribers = publishernotify_subscribers;
}