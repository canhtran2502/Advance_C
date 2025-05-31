#ifndef UART_BUILDER_H
#define UART_BUILDER_H
#include <stdint.h>

typedef enum e_baudrate_value
{
    BAUDRATE_9600 = 9600, //Default value
    BAUDRATE_19200 = 19200,
    BAUDRATE_38400 = 38400,
    BAUDRATE_57600 = 57600,
    BAUDRATE_115200 = 115200,
    BAUDRATE_230400 = 230400
} e_baudrate_value_t;

typedef enum e_parity_value
{
    NONE = 0, //Default value
    ODD_PARITY,
    EVEN_PARITY
} e_parity_value_t;

typedef enum e_stop_bits_value
{
    ONE_STOP_BIT = 1, //Default value
    TWO_STOP_BIT = 2
} e_stop_bits_value_t;

typedef enum e_data_bits_value
{
    DATA_8_BIT = 8, //Default value
    DATA_9_BIT = 9
} e_data_bits_value_t;

// UART Configuration Structure
typedef struct {
    uint32_t baud_rate;  // Baud rate (e.g., 9600, 115200)
    uint8_t parity;     // 0: None, 1: Odd, 2: Even
    uint8_t stop_bits;   // 1: 1 Stop Bit, 2: 2 Stop Bits
    uint8_t data_bits;   // 8: 8 Data Bits, 9: 9 Data Bits
} s_uart_config_t;

// UART Builder Structure
typedef struct s_uart_builder_t{
    s_uart_config_t config;
    struct s_uart_builder_t* (*set_baud_rate)(struct s_uart_builder_t*, e_baudrate_value_t);
    struct s_uart_builder_t* (*set_parity)(struct s_uart_builder_t*, e_parity_value_t);
    struct s_uart_builder_t* (*set_stop_bits)(struct s_uart_builder_t*, e_stop_bits_value_t);
    struct s_uart_builder_t* (*set_data_bits)(struct s_uart_builder_t*, e_data_bits_value_t);
    s_uart_config_t (*build)(struct s_uart_builder_t*);
} s_uart_builder_t;

// Function to initialize the Builder
s_uart_builder_t uart_builder_init(void);

#endif
