/*
 * TP0 Control III.c
 *
 * Created: 24/8/2025 14:55:34
 * Author : nacho
 */ 

#include "funciones.h"
#include "UART.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

volatile uint16_t tension_entrada;
uint8_t flag_lectura_ADC = 0;
uint16_t tension_filtrada = 0;

#define referencia 3000 // (En milivoltios)
#define T 1
#define tau 500
#define alfa  tau / (T + tau)
#define beta  T / (T + tau)

ISR(TIMER1_OVF_vect) {
	
	flag_lectura_ADC = 1;
	
	};

int main(void)
{
    setup_ADC();
	setup_PWM();
	USART_init();
	sei();

    while (1) {
		 
		if (flag_lectura_ADC) {
			flag_lectura_ADC = 0;
			
			tension_entrada = leer_ADC();
			tension_filtrada = filtro_RC(referencia - tension_entrada);
			OCR1A = tension_a_WC(tension_filtrada);
			
		} 
    }
    return 0;
}

