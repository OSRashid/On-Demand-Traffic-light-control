/*
 * On_Demand_Lights.c
 *
 * Created: 10/19/2023 2:48:11 PM
 *  Author: Omar
 */ 

#include "HAL/Lights/Traffic_lights.h"
#include "MCAL/INTRPT/Intrpt_Interface.h"
#include "MCAL/Timer0/Timer0_Interface.h"


// A volatile global variable to hold the current state
// it will be changed by interrupts
State CurrentState = R;

// Function to handle state transition based on the current state and the trigger event
State Event_Handler(State CurrentState , Event Trigger)
{
	switch (CurrentState)
	{
		case R:
		if (Trigger == Button)
		return R_G;
		else if (Trigger == TimeOut)
		return Y;
		break;
		case Y:
		if (Trigger == Button)
		return Y_RY;
		else if (Trigger == TimeOut)
		return G;
		break;
		case G:
		if (Trigger == Button)
		return Y_RY;
		else if (Trigger == TimeOut)
		return Y_2;
		break;
		case Y_2:
		if (Trigger == Button)
		return Y_RY;
		else if (Trigger == TimeOut)
		return R;
		break;
		case Y_GY:
		if (Trigger == TimeOut)
		return G;
		break;
		case R_G:
		if (Trigger == TimeOut)
		return Y_GY;
		break;
		case Y_RY:
		if (Trigger == TimeOut)
		return R_G;
		break;
	}
}

// Button ISR
ISR(INTRPT0)
{
	CurrentState = Event_Handler(CurrentState , Button);
}

void App_Init()
{
	// lights driver initiation
	Lights_vidInit();
	// Timer0 driver initiation
	Tim0_vidInit(Tim0_Normal_Mode);
	// External interrupt timer initiation
	Intrpt_vidIntrptInit(Intrpt_INT0,Intrpt_FalEdg);
}

void App_Run()
{
	int DelayCounter;
	while (1)
	{
		switch (CurrentState)
		{
			case R:
			// Off all traffic lights
			Lights_vidAllOff();
			// light red traffic light
			Lights_vidSET_Light(Traffic_Red);
			int DelayCounter = 0;
			while (CurrentState == R && DelayCounter < 5000)
			{
				// delay for 1 millisecond
				Tim0_vidDelay_MS(1, Tim0_PS_1);
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case Y:
			// Off all traffic lights
			Lights_vidAllOff();
			// light yellow traffic light
			Lights_vidSET_Light(Traffic_Yellow);
			int DelayCounter = 0;
			while (CurrentState == Y && DelayCounter < 5000)
			{
				// Toggle yellow light every 1 second
				if ((DelayCounter % 1000) == 0)
					Lights_vidTogYellow(Traffic_Yellow);
				// delay for 1 millisecond
				Tim0_vidDelay_MS(1, Tim0_PS_1);
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case G:
			// Off all traffic lights
			Lights_vidAllOff();
			// light green traffic light
			Lights_vidSET_Light(Traffic_Green);
			int DelayCounter = 0;
			while (CurrentState == G && DelayCounter < 5000)
			{
				// delay for 1 millisecond
				Tim0_vidDelay_MS(1, Tim0_PS_1);
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case Y_2:
			// Off all traffic lights
			Lights_vidAllOff();
			// light Yellow traffic light
			Lights_vidSET_Light(Traffic_Yellow);
			int DelayCounter = 0;
			while (CurrentState == Y_2 && DelayCounter < 5000)
			{
				// Toggle yellow light every 1 second
				if ((DelayCounter % 1000) == 0)
					Lights_vidTogYellow(Traffic_Yellow);
				// delay for 1 millisecond
				Tim0_vidDelay_MS(1, Tim0_PS_1);
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case Y_GY:
			// Off all traffic lights
			Lights_vidAllOff();
			// light Yellow traffic light, yellow pedestrian lights and green pedestrian lights
			Lights_vidSET_Light(Pedestrian_Green);Lights_vidSET_Light(Pedestrian_Yellow);Lights_vidSET_Light(Traffic_Yellow);
			
			int DelayCounter = 0;
			while (DelayCounter < 5)
			{
				// Toggle yellow lights
				Lights_vidTogYellow(Pedestrian_Yellow);
				Lights_vidTogYellow(Traffic_Yellow); 
				
				// delay for 1second
				Tim0_vidDelay_MS(1000, Tim0_PS_1);
				
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case R_G:
			// Off all traffic lights
			Lights_vidAllOff();
			
			// light red traffic light and green pedestrian lights
			Lights_vidSET_Light(Traffic_Red);
			Lights_vidSET_Light(Pedestrian_Green);
			
			// Delay for 5 seconds
			Tim0_vidDelay_MS(5000, Tim0_PS_1);
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
			
			case Y_RY:
			// Off all traffic lights
			Lights_vidAllOff();
			// light Yellow traffic light, yellow pedestrian lights and red pedestrian lights
			Lights_vidSET_Light(Pedestrian_Red);Lights_vidSET_Light(Pedestrian_Yellow);Lights_vidSET_Light(Traffic_Yellow);

			int DelayCounter = 0;
			while (DelayCounter < 5)
			{
				// Toggle yellow lights every 1 second
				Lights_vidTogYellow(Pedestrian_Yellow);
				Lights_vidTogYellow(Traffic_Yellow);
				
				// delay for 1 second
				Tim0_vidDelay_MS(1000, Tim0_PS_1);
				
				// increment the delay counter
				DelayCounter++;
			}
			// Go to next state due to the end of this state by time out
			CurrentState = Event_Handler(CurrentState , TimeOut);
			break;
		}
	}
}


