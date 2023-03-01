/*
 * sevensegment.h
 *
 * Created: 22/02/2023 14:55:16
 *  Author: dell
 */ 


#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "dio.h"
#include "dio_types.h"
#include "dio_reg.h"
#include "sevensegment_config.h"

void SSD_vidInit(void);
void SSD_DisplayNum(u16 num);


#endif /* SEVENSEGMENT_H_ */