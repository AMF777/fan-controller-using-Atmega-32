 /******************************************************************************
 *
 * Module: Main file
 *
 * File Name: Main.c
 *
 * Description: source file for the project
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/

#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"
#include "adc.h"



int main(void){
	/* to get the temperature*/
	uint8 temp=0;
	DcMotor_State fanMotion=CW;

	 /* we will use the internal voltage reference = 2.56 and pre-scalar = 8*/
	ADC_ConfigType adc_config = {Internal,F_CPU_8};

//intializing drivers
	ADC_init(&adc_config);
	LCD_init();
	DcMotor_Init();


	LCD_moveCursor(0,3);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");

	while(1){
		/* to get the temperature*/
		temp = LM35_getTemperature();

		if(temp < 30){
			/*if temperature less then 30 the motor will stop rotating*/
			DcMotor_Rotate(STOP,0);
		}
		else if(temp >= 30 && temp < 60){
			/*if temperature less then 60 the motor will run on speed = 25 */
			DcMotor_Rotate(fanMotion,25);
		}
		else if(temp >= 60  && temp < 90){
			/*if temperature less then 90 the motor will run on speed = 50 */
			DcMotor_Rotate(fanMotion,50);
		}
		else if(temp >= 90  && temp < 120 ){
			/*if temperature less then 120 the motor will run on speed = 75 */
			DcMotor_Rotate(fanMotion,75);
		}
		else if(temp >= 120 ){
			/*if temperature greater then 120 the motor will run on speed = 100 */
			DcMotor_Rotate(fanMotion,100);
		}

		if(temp < 30 ){
			/*if temperature less then 30 the FAN will be on OFF mode */
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
		}
		else{
			/*if temperature greater then 30 the FAN will be on ON mode */
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
		}

		LCD_moveCursor(1,10);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}
