 /******************************************************************************
 *
 * Module: Dc motor
 *
 * File Name: dc_motor.h
 *
 * Description: header file for the dc_motor driver
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"
/*******************************************************************************
 *                                Define new data type                                  *
 *******************************************************************************/
typedef enum{
	CW, A_CW,STOP
}DcMotor_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT_ID PORTB_ID
#define MOTOR_PIN_1_ID PIN0_ID
#define MOTOR_PIN_2_ID PIN1_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * description
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 *  Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);
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
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif
