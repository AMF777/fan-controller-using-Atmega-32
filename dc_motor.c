 /******************************************************************************
 *
 * Module: Dc motor
 *
 * File Name: dc_motor.c
 *
 * Description: source file for the dc_motor driver
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/
#include "gpio.h"
#include "PWM.h"
#include "dc_motor.h"
#include "common_macros.h"
/*******************************************************************************
 *                      Functions implementation                                   *
 *******************************************************************************/
/*
 * description
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *  Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void){
	//set up direction of motor pins
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN_1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN_2_ID, PIN_OUTPUT);
	//make intial state of motor as stop by writing 0 pn both pins
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_2_ID, LOGIC_LOW);
}
/*
 * description
 * The function responsible for rotate the DC Motor CW/ or A_CW or stop the motor based
 * on the state input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 * inputs:
 * state: The required DC Motor state, it should be CW or A-CW or stop.
 * DcMotor_State data type should be declared as enum or uint8.
 * speed: decimal value for the required motor speed, it should be from
 * 0 to 100. For example, if the input is 50, The motor should rotate with
 *  50% of its maximum speed
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	if (state == CW){
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_2_ID, LOGIC_HIGH);
	}
	else if (state==A_CW) {
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_1_ID, LOGIC_HIGH);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_2_ID, LOGIC_LOW);
	}
	else if(state==STOP){
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_2_ID, LOGIC_LOW);
	}
	else{
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_1_ID, LOGIC_LOW);
		GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN_2_ID, LOGIC_LOW);
	}
	/*
	 * he said speed range is 0 to 100 but duty  cycle range 0 to 256
	 * therefore we get the equation duty cycle=(speed * 256)/100
	 */
	uint8 duty_cycle= (uint8) ((speed/100.0f)*255 ) ;
	PWM_Timer0_Start(duty_cycle);
}
