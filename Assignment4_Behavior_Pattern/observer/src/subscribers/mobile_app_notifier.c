#include "subscribers/mobile_app_notifier.h"
#include <stdio.h>

// Update method for MobileAppNotifier
void mobile_app_update(s_subscriber_t* self, s_publisher_t* context, const char* event_info){
    (void)self; (void)context;
    printf("[MobileApp] Alert: %s\n", event_info);
}

// Initialize MobileAppNotifier
void mobile_app_notifier_init(s_mobile_app_notifier_t* notifier) {
    notifier->base.update = mobile_app_update;
    notifier->base.data = NULL;
}
