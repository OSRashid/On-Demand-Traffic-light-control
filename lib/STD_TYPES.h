/*****************************************/
/* Date 10/8/2022           */
/* File Name: Bit math operation file */
/* Author : Omar Salah  */


/* header guard */

#ifndef STD_TYPES_h
#define STD_TYPES_h

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef unsigned long long int u64;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;

#define NULL    ((void*)0)


typedef enum {
	Success,
	Error,
	NULLPointer,
	Not_Found,
	EmptyLinkedList,
}Status_Type;


#endif
