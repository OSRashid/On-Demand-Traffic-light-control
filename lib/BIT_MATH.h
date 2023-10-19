/*****************************************/
/* Date 10/8/2022           */
/* File Name: Bit math operation file */
/* Author : Omar Salah  */


/* header guard */

#ifndef BIT_MATH_h
#define BIT_MATH_h

#define SHL_BIT(VAR)	(VAR<<1)
#define SHR_BIT(VAR)	(VAR>>1)
#define SET_BIT(VAR,BIT_NO) (VAR |= (1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO) (VAR &= ~(1<<BIT_NO))
#define TOG_BIT(VAR,BIT_NO) (VAR ^= (1<<BIT_NO))
#define READ_BIT(VAR,BIT_NO)    ((VAR>>BIT_NO) & 1)
#define ASSIGN_BIT(VAR,BIT_NO,VALUE)  VAR |= (1<<BIT_NO) & (VALUE << BIT_NO)

#endif
