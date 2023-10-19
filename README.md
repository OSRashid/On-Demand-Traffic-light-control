# On-Demand-Traffic-light-control
This is a capstone project for Udacity's embedded systems professional course.
the followig is the project's description, requirements and success criteria, state machine for my code will attached in the end.
 
Project description:
There are two types of lights on the street, traffic lights and pedestrian lights, when the pedestrian want to pass te street they should press a button on the light pole so that trafic and pedestrian light change accordingly to make the cars stop and pedestrian pass safely, in the software requirements the exact way of operation will be explained.
 
Hardware requirements:
1. ATmega32 microcontroller
2. One push button connected to INT0 pin for pedestrian
3. Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
4. Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
 
Software requirements: 
In normal mode:
1. Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
2. The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
 
In pedestrian mode:
1. Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2. If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3. If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4. At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5. After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6. Traffic lights signals are going to the normal mode again.
 
Success criteria:
User story 1: As a pedestrian when I will make a short press on the crosswalk button while the cars green light is on and pedestrian red light is off, I will wait for the yellow lights to blink for five seconds then the cars red light is on and pededstrian green light is on for five seconds, so that I can cross the street
User story 2: As a pedestrian when I will make a short press on the crosswalk button while the cars yellow light is blinking and pedestrian red light is on, I will wait for all yellow lights to blink for five seconds then the cars red light is on and pededstrian green light is on for five seconds, so that I can cross the street
User story 3: As a pedestrian when I will make a short press on the crosswalk button while the cars red light is on and pedestrian green light is on, I expect nothing to be done
User story 4: As a pedestrian when I made a long press on the crosswalk button, I expect nothing to be done.
User story 5: As a pedestrian when I made a double press on the crosswalk button, I expect that the first press will do the action and nothing to be done after the second press.

 ![Untitled Workspace](https://github.com/OSRashid/On-Demand-Traffic-light-control/assets/30478113/3ee02749-5dd6-4465-8031-39fa7869c8e1)
