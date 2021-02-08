/*
 * encoder.h
 *
 *  Created on: Jan 28, 2021
 *      Author: piotr
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

typedef struct
{
	TIM_HandleTypeDef *timer;	//timer obsługujący enkoder silnika

	uint16_t resolution;		//rozdzielczość silnika

	int32_t pulse_count;		//zliczone impulsy
	int32_t speed;				//obliczona prędkość silnika
}motor_str;

void motor_str_init(motor_str *, TIM_HandleTypeDef *);
void motor_update_count(motor_str *);
void motor_calculate_speed(motor_str *);

#endif /* INC_MOTOR_H_ */
