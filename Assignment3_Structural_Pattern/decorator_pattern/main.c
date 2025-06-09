#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "connectivity/connectivity.h"
#include "decorator/decorators.h"


int main()
{
    s_connectivity_t* raw_uart_channel = create_connect_interface(); //create raw uart channel

    s_logging_t* logging_decorator = create_logging_decorator(raw_uart_channel);
    s_crc_checksum_t* crc_checksum_decorator = create_crc_checksum_decorator(raw_uart_channel);
    s_enc_dec_t* enc_dec_decorator = create_enc_dec_decorator(raw_uart_channel);
    s_compress_descompress_t* compress_descompress_decorator = create_compress_descompress_decorator(raw_uart_channel);
    
    //Simulation send and receive data
    uint8_t data[] = "Hello";
    int status;
    status = compress_descompress_decorator->connectivity->send(enc_dec_decorator,data, strlen((const char*)data));
    if (status == ERROR)
    {
        printf("Send failed\n");
    }
    
    uint8_t receiveBuffer[256];
    size_t receivedLength;
    status = compress_descompress_decorator->connectivity->receive(enc_dec_decorator, receiveBuffer, sizeof(receiveBuffer),&receivedLength);
    if (status == ERROR)
    {
        printf("Send failed\n");
    }
    else 
    {
        printf("Received buffer: %s\n", receiveBuffer);
    }

    free_connect_interface(raw_uart_channel);
    
    free_crc_checksum_decorator(crc_checksum_decorator);
    free_enc_dec_decorator(enc_dec_decorator);
    free_compress_descompress_decorator(compress_descompress_decorator);
    free_logging_decorator(logging_decorator);

    return 0;
}