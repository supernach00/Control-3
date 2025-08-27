#include "funciones.h"
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint16_t tension_entrada;
extern volatile uint16_t tension_salida_actual;

void setup_ADC(void){
	
	/*
	PRESCALER = 128 (f_adc = 125Khz)
	ADC = ENABLE
	ADC INTERRUPT = ENABLE
	PIN DE ENTRADA = ADC0
	REFERENCIA = 5V
	*/
	
	ADMUX = (1 << REFS0) | (1 << MUX0);
	ADCSRA = (1 << ADEN) | (0 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); 	
	
	}
	
void setup_PWM(void){
	
	/*
	TIMER = 1
	MODO = FAST PWM
	PRESCALER = 1 (f = 16MHz)
	COMPARADOR PERIODO = ICR1 = 16000 (1ms)
	COMPARADOR DC = OCR1A
	PIN DE  SALIDA = PB1
	DC INICIAL = 50%
	*/
	
	DDRB |= (1 << PB1); // OC1A = PB1 en Arduino Uno

	TCCR1A = (1 << WGM11) | (1 << COM1A1);
	TCCR1B = (1 << WGM12) | (1 << WGM13) | (1 << CS10); // 
	TIMSK1 |= (1 << TOIE1);
	
	ICR1 = 15999;
	OCR1A = 8000;  // Valor inicial de ciclo de trabajo.
	
	}
	
uint16_t leer_ADC(){
	
	ADCSRA |= (1 << ADSC);
	
	while ( !(ADCSRA & (1 << ADIF)) ); // Se espera hasta que termine la conversion.

	ADCSRA |= (1 << ADIF);

	return ADC*C; // Devuelve el valor en milivoltios. C = 5.
	
	}
		
uint16_t filtro_RC(uint16_t tension_entrada){
	
	// Filtrado
	
	uint16_t tension_salida_anterior = tension_salida_actual;
	tension_salida_actual = (uint16_t)(alfa * tension_salida_anterior + beta * tension_entrada);
	
	// Conversion a ciclo de trabajo:
	
	return tension_salida_actual;
	
}

uint16_t tension_a_WC(uint16_t tension){
	
	// Convierte un valor de tensión en milivoltios a un entero entre 0 y 15999, que se utiliza
	// como valor de comparacion del timer1.
	// Esto define el ciclo de trabajo (WC) de la PWM de salida.
	
	return tension *  A - 1; //  A = 16000 / (5*1024)
	
}
