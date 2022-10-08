 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver(More configurable version of old one)
 *
 * Author: Ahmed Magdy
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56 //update value to the internal vref=2.56v
/*******************************************************************************
 *                                Define new data types                        *
 *******************************************************************************/
//define a new data type of all possible values of vref of ADC
typedef enum{
	AREF,AVCC,RESERVED,Internal
}ADC_ReferenceVolatge;
//define a new data type of all possible values of ADC prescaler(8 values are available after checking data sheet)
typedef enum{
	F_CPU_,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;
//DEFINE a new struct that we will contain the two configurable parameters that we will use in the init function
typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 * take one parameter of type ADC_ConfigType * to set vref and prescaler of ADC
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
