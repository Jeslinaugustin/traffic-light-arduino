# traffic-light-arduino
Traffic light system using arduino

This simple project imitates the working of a traffic signal system. The purpose of this project is to demonstare how different components can be integrated to arduino board, how to syncronize the data fetching and other operations, how to handle multiple external interrupts effectively and finally how to write neat code using functions.

Assumptions:
The junction has only two signal point (labelled as 1 and 2)

The working scenario:
The system operates in two different modes.
	1. Regular mode
		Activated during day time(switching is based on the output of LDR), and the lights at the signal points are operated in the following patterns.
			i. Red1, Green2
			ii. yellow1, yellow2
			iii. Red2, Green1
			iv. yellow1, yellow2
		and the pattern repeates if there is no pedestrian interrupts.
  		If a pedestrian presses, the butten at any time, the interrupt handling function sets a flag. The fag is checked during the red signal at each poin and a buzzer beeps to indicate the pedestrian to 		croos.
	2. Night mode
		Activated in night time. The yello signal repeatedly turn on ond off. 

Components used:
	1)Arduino mega
	2)buzzers
	3)LDR
	4)button switches
	5)LEDs
