/*
 * On_Demand_Lights.h
 *
 * Created: 10/19/2023 2:47:59 PM
 *  Author: Omar
 */ 


#ifndef ON_DEMAND_LIGHTS_H_
#define ON_DEMAND_LIGHTS_H_


// Enum for states definitions
typedef enum {
	R,
	Y,
	G,
	Y_2,
	Y_GY,
	R_G,
	Y_RY
} State;


// Enum for event triggers definitions
typedef enum {
	Button,
	TimeOut
} Event;


// event handler helper function
State Event_Handler(State CurrentState , Event Trigger);

// App initiation function
void App_Init();

// App run function
void App_Run();




#endif /* ON_DEMAND_LIGHTS_H_ */