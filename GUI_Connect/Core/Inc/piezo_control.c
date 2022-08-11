/*
 * Piezo_Control.c
 *
 *  Created on: Jul 12, 2022
 *      Author: gopala4
 */

//include
#include "piezo_control.h"
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//defines
#define CLOCKFREQ 1000000
#define NUM_NOTES 12
#define DUTYCYCLE 50
#define PIEZO_CHANNEL TIM_CHANNEL_1


TIM_HandleTypeDef htim16;

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 160-1;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 1000;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim16, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim16, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */
  HAL_TIM_MspPostInit(&htim16);

}

int frequency_to_arr(int frequency) {
	return CLOCKFREQ/frequency;
}

void piezo_init(void) {
	MX_TIM16_Init();
	HAL_TIM_Base_Start(&htim16);
	HAL_TIM_PWM_Start(&htim16, PIEZO_CHANNEL);
}

void piezo_off(void) {
	__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, 0);
}

void pause_piezo(int duration_in_ms) {
	__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, 0);
	HAL_Delay(duration_in_ms);
}

void play_siren(int num_repeats) {
	int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
		for (int k = 0; k < 5; k++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
			HAL_Delay(200);
			__HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
			HAL_Delay(200);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void play_alarm1(int num_repeats) {
	int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	//pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
			HAL_Delay(250);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			HAL_Delay(250);
			pause_piezo(1000);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void play_alarm2(int num_repeats) {
	int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
		HAL_Delay(250);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		HAL_Delay(250);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		HAL_Delay(250);
		pause_piezo(750);
	}
	piezo_off();
}

void play_ascending(int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
		int arr = frequency_to_arr(freq);
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(200);
			freq = freq + 100;
			arr = frequency_to_arr(freq);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void play_descending(int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 2000;
		int arr = frequency_to_arr(freq);
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(200);
			freq = freq - 100;
			arr = frequency_to_arr(freq);
		}
		pause_piezo(750);
	}
	piezo_off();
}
void chime_neutral(int num_repeats) {
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		HAL_Delay(1000);
		pause_piezo(750);
	}
	piezo_off();
}

void chime_negative(int num_repeats) {
	int freq = 500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 2; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(500);
			pause_piezo(100);
		}
		pause_piezo(750);
	}
}
void chime_positive(int num_repeats) {
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(330);
			pause_piezo(100);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void chime_notify(int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	pause_piezo(100);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 4; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(100);
			pause_piezo(10);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void battery_chime(int num_repeats) {
	pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
	    int arr = frequency_to_arr(freq);
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr/2);
			HAL_Delay(200);
			freq = freq + 250;
			arr = frequency_to_arr(freq);
		}
		pause_piezo(750);
	}
	piezo_off();
}

//for music playing purposes
float get_freq_from_note(char note[]) {
	char NOTES[12][2] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
	int octave;
	char curr_note[2];
	int note_len = strlen(note);
	//extracting the octave number from the char that was passed in
	if (note_len == 3) {
		octave = (int) (note[2] - '0');
		strncpy(curr_note, note, 2);
	} else if (note_len == 2) {
		octave = (int) (note[1] - '0');
		strncpy(curr_note, note, 1);
	} else {
		return 0;
	}
	//extracting the index (as per the NOTES array above) of the note passed in
	int keyIndex = 0;
	for (int i = 0; i < NUM_NOTES; i++) {
		if (strncmp(curr_note, NOTES[i], 2) == 0) {
			keyIndex = i;
			break;
		}
	}
	//@source: https://gist.github.com/stuartmemo/3766449#file-note-to-frequency
	//math to calculate the frequency from the note index
	if (keyIndex < 3) {
		keyIndex = keyIndex + 12 + ((octave - 1) * 12) + 1;
	} else {
		keyIndex = keyIndex + ((octave - 1) * 12) + 1;
	}
	// Return frequency of note
	return 440 * pow(2, ((float) (keyIndex - 49)) / 12);
}

void play_frequency(int duration_ms, float frequency) {
	if (frequency == 0) {
		pause_piezo(duration_ms);
	} else {
		int arr_val = (int)(CLOCKFREQ/frequency);
		//changing PWM frequency
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_val);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_val / 2);
		//delaying so the note holds
		HAL_Delay(duration_ms);
	}
}

void play_frequency_array(float beats[], float frequencies[], float tempo, int song_len) {
	float beats_per_sec = tempo/60;
	pause_piezo(100);
	for (int i = 0; i < song_len; i++) {
		int duration_ms = (int)((beats[i]/beats_per_sec)*1000);
		play_frequency(duration_ms, frequencies[i]);
		pause_piezo((int)(50/(beats_per_sec)));
	}
}

void play_tune(float beats[], char *song_notes, float tempo) {
	int note_num = 0;
	float freq_arr[250];
	char *context = NULL;
	char *space_split = strtok_r(song_notes, " ", &context);
	while (space_split != NULL) {
		freq_arr[note_num] = get_freq_from_note(space_split);
		note_num += 1;
		space_split = strtok_r(NULL, " ", &context);
	}
	play_frequency_array(beats, freq_arr, tempo, note_num);
}
