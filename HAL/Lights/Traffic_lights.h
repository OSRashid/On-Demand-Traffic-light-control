/*
 * Traffic_lights.h
 *
 * Created: 10/19/2023 2:02:31 PM
 *  Author: Omar
 */ 


#ifndef TRAFFIC_LIGHTS_H_
#define TRAFFIC_LIGHTS_H_

// Traffic and pedestrian lights definitions
#define Traffic_Red			0
#define Traffic_Yellow		1
#define Traffic_Green		2
#define Pedestrian_Red		3	
#define Pedestrian_Yellow	4
#define Pedestrian_Green	5


// light On/Off defintions
#define Light_OFF	0
#define Light_ON	1


// Traffic lights initiation function
void Lights_vidInit();
// Set light function by color and type
void Lights_vidSET_Light (u8 light);
// All lights off
void Lights_vidAllOff();
// Toggle yellow light function whether traffic or pedestrian
void Lights_vidTogYellow(u8 type);


#endif /* TRAFFIC_LIGHTS_H_ */
