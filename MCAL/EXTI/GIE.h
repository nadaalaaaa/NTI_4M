/*
 * GIE.h
 *
 * Created: 25/02/2023 15:34:58
 *  Author: dell
 */ 


#ifndef GIE_H_
#define GIE_H_

#define SREG		*((volatile u8 * ) (0X5F))

void GIE_disable(void);
void GIE_enable(void);



#endif /* GIE_H_ */