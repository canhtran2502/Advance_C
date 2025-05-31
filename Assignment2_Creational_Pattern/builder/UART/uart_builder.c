#include <stdio.h>
#include "uart_builder.h"

static s_uart_builder_t* set_baud_rate(s_uart_builder_t* builder, e_baudrate_value_t baud_rate);
static s_uart_builder_t* set_parity(s_uart_builder_t* builder, e_parity_value_t parity);
static s_uart_builder_t* set_stop_bits(s_uart_builder_t* builder, e_stop_bits_value_t stop_bits);
static s_uart_builder_t* set_data_bits(s_uart_builder_t* builder, e_data_bits_value_t data_bits);
static s_uart_config_t build(s_uart_builder_t* builder);


static s_uart_builder_t* set_baud_rate(s_uart_builder_t* builder, e_baudrate_value_t baud_rate)
{   
    switch (baud_rate)
    {
        case BAUDRATE_9600:
        case BAUDRATE_19200:
        case BAUDRATE_38400:
        case BAUDRATE_57600:
        case BAUDRATE_115200:
        case BAUDRATE_230400:
            builder->config.baud_rate = baud_rate;
            break;
        default:
            printf("Error: Invalid baud rate value.\n");
            break;
    }
    
    return builder;
}

static s_uart_builder_t* set_parity(s_uart_builder_t* builder, e_parity_value_t parity)
{
    switch (parity)
    {
        case NONE:
        case ODD_PARITY:
        case EVEN_PARITY:
            builder->config.parity = parity;
            break;
        default:
            printf("Error: Invalid parity value.\n");
            break;
    }
    
    return builder;
}

static s_uart_builder_t* set_stop_bits(s_uart_builder_t* builder, e_stop_bits_value_t stop_bits)
{
    switch (stop_bits)
    {
        case ONE_STOP_BIT:
        case TWO_STOP_BIT:
            builder->config.stop_bits = stop_bits;
            break;
        default:
            printf("Error: Invalid stop bits value.\n");
            break;
    }

    return builder;
}

static s_uart_builder_t* set_data_bits(s_uart_builder_t* builder, e_data_bits_value_t data_bits)
{
    switch (data_bits)
    {    
        case DATA_8_BIT:
        case DATA_9_BIT:
            builder->config.data_bits = data_bits;
            break;
        default:
            printf("Error: Invalid data bits value.\n");
            break;
    }

    return builder;
}

static s_uart_config_t build(s_uart_builder_t* builder)
{
    return builder->config;
}

s_uart_builder_t uart_builder_init(void)
{
    s_uart_builder_t    uart_builder;
    uart_builder.config.baud_rate = BAUDRATE_9600; //Default baud rate
    uart_builder.config.parity = NONE; //Default parity: None
    uart_builder.config.stop_bits = ONE_STOP_BIT; //Default stop bits: 1
    uart_builder.config.data_bits = DATA_8_BIT; //Default data bits: 8
    uart_builder.set_baud_rate = set_baud_rate;
    uart_builder.set_parity = set_parity;
    uart_builder.set_stop_bits = set_stop_bits;
    uart_builder.set_data_bits = set_data_bits;
    uart_builder.build = build;

    return uart_builder;
}