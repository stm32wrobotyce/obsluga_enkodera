/*
 * encoder.c
 *
 *  Created on: Jan 28, 2021
 *      Author: piotr
 */

#include "main.h"

#define ENCODER_RESOLUTION			3
#define TIMER_CONF_BOTH_EDGE_T1T2	4
#define MOTOR_GEAR					150

#define	TIMER_FREQENCY				10
#define	SECOND_IN_MINUTE			60

void motor_str_init(motor_str *m, TIM_HandleTypeDef *tim)
{
	m->timer = tim;
	m->resolution = ENCODER_RESOLUTION * TIMER_CONF_BOTH_EDGE_T1T2 * MOTOR_GEAR;

	m->pulse_count = 0;
	m->speed = 0;
}

void motor_calculate_speed(motor_str *m)
{
	motor_update_count(m);

	m->speed = (m->pulse_count * TIMER_FREQENCY * SECOND_IN_MINUTE) / m->resolution;
}

void motor_update_count(motor_str *m)
{
	m->pulse_count = (int16_t)__HAL_TIM_GET_COUNTER(m->timer);
	__HAL_TIM_SET_COUNTER(m->timer, 0);
}
