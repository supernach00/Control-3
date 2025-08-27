#ifndef UART_H_
#define UART_H_

#include <avr/io.h>

#define F_CPU        16000000UL
#define BAUDRATE     9600
#define BAUD_PRESCALLER ((F_CPU / (16UL * BAUDRATE)) - 1)

// Declaración de funciones
void USART_init(void);
unsigned char USART_receive(void);
void USART_send(unsigned char data);
void USART_putstring(char *StringPtr);

#endif /* UART_H_ */
