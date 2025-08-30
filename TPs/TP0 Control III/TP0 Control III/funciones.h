/*
 * funciones.h
 *
 * Created: 24/8/2025 14:56:21
 *  Author: nacho
 */ 


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

// Includes
#include <stdint.h>

// Constantes

#define referencia 3000 // (En milivoltios)
#define T 1.0
#define tau 10.0
#define alfa  tau / (T + tau)
#define beta  T / (T + tau)
#define A 16000.0 / (5.0*1024.0)sd
#define C  5;
#define A 16000 / (5*1024)

// Funciones de configuraci�n

void setup_ADC(void);
void setup_PWM(void);

// Funciones generales

uint16_t leer_ADC(void);
uint16_t filtro_RC(uint16_t tension_entrada);
uint16_t tension_a_WC(uint16_t tension);

#endif /* FUNCIONES_H_ */