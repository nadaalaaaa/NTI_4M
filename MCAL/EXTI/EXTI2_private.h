/*
 * EXTI2_private.h
 *
 * Created: 25/02/2023 18:49:56
 *  Author: dell
 */ 


#ifndef EXTI2_PRIVATE_H_
#define EXTI2_PRIVATE_H_


#define MCUCR		*((volatile u8 * ) (0X55))
#define SREG		*((volatile u8 * ) (0X5F))
/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of MCUCSR   	*/
/**			   Register	is  0X54.								*/
/****************************************************************/
/**			   MCUCSR : MCU Control and Status Register			*/
/****************************************************************/

#define MCUCSR      *((volatile u8 * ) (0X54))

/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of GICR     	*/
/**			   Register	is  0X5B.								*/
/****************************************************************/
/**			   GICR : General Interrupt Control Register		*/
/****************************************************************/

#define GICR        *((volatile u8 * ) (0X5B))


/****************************************************************/
/** !comment : From Data Sheet :  Memory mapped of GIFR     	*/
/**			   Register	is  0X5A.						    	*/
/****************************************************************/
/**			   GIFR : General Interrupt Flag Register			*/
/****************************************************************/

#define GIFR        *((volatile u8 * ) (0X5A))

/** Linker Problem solved */
void __vector_3(void) __attribute__(( signal , used ));




#endif /* EXTI2_PRIVATE_H_ */