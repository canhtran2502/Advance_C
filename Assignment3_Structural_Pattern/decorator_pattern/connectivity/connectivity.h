#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#include <stdint.h>

typedef struct {
    int (*send)(void* channelInstance, const uint8_t* data, size_t length);
    int (*receive)(void* channelInstance, uint8_t* buffer, size_t bufferLength, size_t* receivedLength);
} s_connectivity_t;

enum e_error {
    ERROR               = -1,
    INVALID_CHANNEL     = -2,
    INVALID_SEND_BUFFER = -3,
    INVALID_RECEIVE_BUFFER = -4,
};

s_connectivity_t* create_connect_interface(void);
void free_connect_interface(s_connectivity_t* connect_interface);

#endif
