/*
 * LED_Control.h
 *
 *  Created on: Jul 12, 2022
 *      Author: gopala4
 */

#ifndef LED_CONTROL_H_
#define LED_CONTROL_H_

void LED_Init(char color);
void breathe_LED_up(char color, int breath_duration_ms, int num_repeats);
void breathe_LED_down(char color, int duration_ms, int num_repeats);
void breathe_LED_up_and_down(char color, int breath_duration_ms, int num_repeats);
void blink_LED(char color, int flash_duration, int num_blinks);
void solid_LED(char color, int duration);
void off_LED(char color);
void on_LED(char color);



#endif /* LED_CONTROL_H_ */