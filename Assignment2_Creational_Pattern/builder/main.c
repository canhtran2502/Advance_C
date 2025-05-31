#include <stdio.h>
#include "UART/uart_builder.h"

int main() {
    // Initialize the Builder
    s_uart_builder_t builder = uart_builder_init();

    // Configure UART using the Builder
    s_uart_config_t uartConfig = builder
    .set_baud_rate(&builder, BAUDRATE_115200)
    ->set_parity(&builder, EVEN_PARITY)
    ->set_stop_bits (&builder, TWO_STOP_BIT)
    ->set_data_bits (&builder, DATA_9_BIT)
    ->build(&builder);

    // Print the configured UART parameters
    printf("UART Configuration:\n");
    printf("Baud Rate: %d\n", uartConfig.baud_rate);
    printf("Parity: %d\n", uartConfig.parity);
    printf("Stop Bits: %d\n", uartConfig.stop_bits);
    printf("Data Bits: %d\n", uartConfig.data_bits);

    return 0;
}