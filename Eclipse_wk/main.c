/*
 * main.c
 *
 *  Created on: 11 Oct 2022
 *      Author: Omar Elsherif
 *     
 */

#include"lcd.h"
#include"ultrasonic_sensor.h"
#include<avr/io.h>


int main(void)
{

	uint16 distance;

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize LCD driver */
	LCD_init();

	/* Initialize Ultrasonic sensor */
	Ultrasonic_init();


	LCD_displayString("Distance=    cm");


	while(1)
	{
		/*	Read distance from ultrasonic sensor*/
		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);

		/*	Display Distance on LCD*/
		if(distance>=100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		}

	}



	return 0;
}

