#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "connectivity.h"

uint8_t simulation_buffer[100];
size_t  simulation_length;

static int send(void* channelInstance, const uint8_t* data, size_t length)
{
    if (channelInstance == NULL)
    {
        printf("Error with channel instance\n");
        return INVALID_CHANNEL;
    }

    if (data == NULL)
    {
        printf("Error with send buffer data\n");
        return INVALID_SEND_BUFFER;
    }

    printf("Send %zu bytes data\n", length);

    //Prepare for simulating receive API
    memcpy(simulation_buffer, data, length);
    simulation_length = length;

    return (int)length;
}
static int receive(void* channelInstance, uint8_t* buffer, size_t bufferLength, size_t* receivedLength)
{
    if (channelInstance == NULL)
    {
        printf("Error with channel instance\n");
        return INVALID_CHANNEL;
    }

    if (buffer == NULL)
    {
        printf("Error with receive buffer data\n");
        return INVALID_RECEIVE_BUFFER;
    }

    memcpy(buffer, simulation_buffer, simulation_length);
    
    *receivedLength = simulation_length;

    printf("Received %zu bytes data\n", *receivedLength);

    return (int)*receivedLength;
}

s_connectivity_t* create_connect_interface(void)
{
    s_connectivity_t* connect_interface = (s_connectivity_t*)malloc(sizeof(s_connectivity_t));
    if (connect_interface != NULL)
    {
        connect_interface->send = send;
        connect_interface->receive = receive;
    }
    else
    {
        printf("Error when creating connect interface\n");
    }

    return connect_interface;
}

void free_connect_interface(s_connectivity_t* connect_interface)
{
    free(connect_interface);
}