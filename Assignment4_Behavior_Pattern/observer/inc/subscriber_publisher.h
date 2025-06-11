#ifndef SUBSCRIBER_PUBLISHER_H
#define SUBSCRIBER_PUBLISHER_H

#define MAX_SUBSCRIBERS     (10)
#define RESET_VALUE         (0x00)

typedef struct s_publisher s_publisher_t;

// Subscriber interface
typedef struct s_subscriber {
    void (*update)(struct s_subscriber* self, s_publisher_t* context, const char* event_info);
    void* data;
} s_subscriber_t;

struct s_publisher {
    s_subscriber_t* subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;

    void (*subscribe)(struct s_publisher* self, s_subscriber_t* s);
    void (*unsubscribe)(struct s_publisher* self, s_subscriber_t* s);
    void (*notify_subscribers)(struct s_publisher* self, const char* event_info);
};

void publisher_init(s_publisher_t* pub);

#endif // SUBSCRIBER_PUBLISHER_H