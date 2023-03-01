/*
 * sevensegment_config.h
 *
 * Created: 22/02/2023 14:55:40
 *  Author: dell
 */ 


#ifndef SEVENSEGMENT_CONFIG_H_
#define SEVENSEGMENT_CONFIG_H_
#include "dio.h"
#include "dio_types.h"
#include "dio_reg.h"
#include "sevensegment.h"

#define sevenseg_port1 DIO_PORTB
#define sevenseg_port2 DIO_PORTB
#define sevenseg_port3 DIO_PORTB
#define sevenseg_port4 DIO_PORTB
#define sevenseg_port5 DIO_PORTB
#define sevenseg_port6 DIO_PORTB
#define sevenseg_port7 DIO_PORTA
#define sevenseg_port8 DIO_PORTA


#define PB0 DIO_PIN0
#define PB1 DIO_PIN1	
#define PB2 DIO_PIN2
#define PB4 DIO_PIN4
#define PB5 DIO_PIN5
#define PB6 DIO_PIN6
#define PA2 DIO_PIN2
#define PA3 DIO_PIN3

#endif /* SEVENSEGMENT_CONFIG_H_ */