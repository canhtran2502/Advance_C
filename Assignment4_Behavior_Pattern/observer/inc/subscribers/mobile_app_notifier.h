#ifndef MOBILE_APP_NOTIFIER_H
#define MOBILE_APP_NOTIFIER_H

#include "../subscriber_publisher.h"

typedef struct {
    s_subscriber_t base;
} s_mobile_app_notifier_t;

void mobile_app_notifier_init(s_mobile_app_notifier_t* notifier);

// Update method for MobileAppNotifier
void mobile_app_update(s_subscriber_t* self, s_publisher_t* context, const char* event_info);

#endif // MOBILE_APP_NOTIFIER_H
