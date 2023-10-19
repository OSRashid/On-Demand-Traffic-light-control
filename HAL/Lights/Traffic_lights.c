/*
 * Traffic_lights.c
 *
 * Created: 10/19/2023 2:03:03 PM
 *  Author: Omar
 */ 

#include "HAL/Lights/Traffic_lights.h"
#include "MCAL/DIO/DIO_Interface.h"


void Lights_vidInit()
{
	DIO_vidSetPinDir(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);DIO_vidSetPinDir(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);DIO_vidSetPinDir(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);DIO_vidSetPinDir(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);DIO_vidSetPinDir(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
}


void Lights_vidSET_Light (u8 light)
{
	switch (light)
	{
	case Traffic_Red:
		DIO_vidSetPinVal(PORTA,DIO_PIN2,DIO_HIGH);	
		break;
	case Traffic_Yellow:
		DIO_vidSetPinVal(PORTA,DIO_PIN1,DIO_HIGH);
		break;
	case Traffic_Green:
		DIO_vidSetPinVal(PORTA,DIO_PIN0,DIO_HIGH);
		break;
	case Pedestrian_Red:
		DIO_vidSetPinVal(PORTB,DIO_PIN2,DIO_HIGH);
		break;
	case Pedestrian_Yellow:
		DIO_vidSetPinVal(PORTB,DIO_PIN1,DIO_HIGH);
		break;
	case Pedestrian_Green:
		DIO_vidSetPinVal(PORTB,DIO_PIN0,DIO_HIGH);
		break;	
	}
}

void Lights_vidAllOff()
{
	DIO_vidSetPinVal(PORTA,DIO_PIN2,DIO_LOW);DIO_vidSetPinVal(PORTA,DIO_PIN1,DIO_LOW);DIO_vidSetPinVal(PORTA,DIO_PIN0,DIO_LOW);
	DIO_vidSetPinVal(PORTB,DIO_PIN2,DIO_LOW);DIO_vidSetPinVal(PORTB,DIO_PIN1,DIO_LOW);DIO_vidSetPinVal(PORTB,DIO_PIN0,DIO_LOW);
}

void Lights_vidTogYellow(u8 light)
{
	switch(light)
	{
		case Traffic_Yellow:
			DIO_vidTogglePinVal(DIO_PORTA,DIO_PIN1);
			break;
		case Pedestrian_Yellow:
			DIO_vidTogglePinVal(DIO_PORTB,DIO_PIN1);
			break;
	}
	
}