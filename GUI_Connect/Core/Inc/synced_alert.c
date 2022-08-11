#include "led_control.c"
#include "piezo_control.c"
#include "synced_alert.h"

void siren_up(char color, int num_repeats) {
    int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0, 0.04);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up(color, 200, 0.04, 0.08);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0.08, 0.12);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up(color, 200, 0.12, 0.16);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0.16, 0.2);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up(color, 200, 0.2, 0.24);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0.24, 0.28);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up_off(color, 200, 0.28, 0.32);
		pause_piezo(750);
	}
	piezo_off();
}

void siren_down(char color, int num_repeats) {
    int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.3, 0.26);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down(color, 200, 0.26, 0.22);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.22, 0.18);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down(color, 200, 0.18, 0.14);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.14, 0.10);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down(color, 200, 0.1, 0.06);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.06, 0.02);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down_off(color, 200, 0.02, 0);
		pause_piezo(750);
	}
	piezo_off();
}

void siren_breathe(char color, int num_repeats){
    int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0, 0.02);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up(color, 200, 0.02, 0.06);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_up(color, 200, 0.06, 0.1);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_up(color, 200, 0.1, 0.14);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.14, 0.1);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down(color, 200, 0.1, 0.06);
        __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
        synced_breathe_down(color, 200, 0.06, 0.02);
        __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
        __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
        synced_breathe_down_off(color, 200, 0.02, 0);
        pause_piezo(750);
    }
    piezo_off();
}

void siren_flash(char color, int num_repeats){
    int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
        for (int i = 0; i < 4; i++){
            __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
            __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
            solid_LED(color, 200);
            __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
            __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
            HAL_Delay(200);
        }
        pause_piezo(750);
    }
    piezo_off();
}

void siren_solid(char color, int num_repeats){
    int high_arr = frequency_to_arr(2500);
	int low_arr = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++) {
        on_LED(color);
        for (int i = 0; i < 4; i++){
            __HAL_TIM_SET_AUTORELOAD(&htim16, high_arr);
            __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, high_arr/2);
            HAL_Delay(200);
            __HAL_TIM_SET_AUTORELOAD(&htim16, low_arr);
            __HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, low_arr/2);
            HAL_Delay(200);
        }
        off_LED(color);
        pause_piezo(750);
    }
    piezo_off();
}

void alarm1_up(char color, int num_repeats) {
    int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	//pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
			synced_breathe_up(color, 250, 0, 0.05);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			synced_breathe_up_off(color, 250, 0.05, 0.1);
			pause_piezo(750);
		}
		pause_piezo(750);
	}
	piezo_off();
}
void alarm1_down(char color, int num_repeats) {
    int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	//pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
			synced_breathe_down(color, 250, 0.1, 0.05);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			synced_breathe_down_off(color, 250, 0.05, 0);
			pause_piezo(750);
		}
		pause_piezo(750);
	}
	piezo_off();
}
void alarm1_breathe(char color, int num_repeats){
    int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	//pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
			synced_breathe_up(color, 250, 0, 0.05);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			synced_breathe_down_off(color, 250, 0.05, 0);
			pause_piezo(750);
		}
		pause_piezo(750);
	}
	piezo_off();
}
void alarm1_flash(char color, int num_repeats) {
    int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	//pause_piezo(100);
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
            solid_LED(color, 250);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			pause_LED(color, 250);
			pause_piezo(750);
		}
		pause_piezo(750);
	}
	piezo_off();
}
void alarm1_solid(char color, int num_repeats) {
    int freq_2000 = frequency_to_arr(1750);
	int freq_1500 = frequency_to_arr(1500);
	for (int j = 0; j < num_repeats; j++){
        on_LED(color);
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_2000);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_2000/2);
            HAL_Delay(250);
			__HAL_TIM_SET_AUTORELOAD(&htim16, freq_1500);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, freq_1500/2);
			HAL_Delay(250);
			pause_piezo(750);
		}
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void alarm2_up(char color, int num_repeats) {
    int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
		synced_breathe_up(color, 300, 0, 0.03);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_up(color, 300, 0.03, 0.06);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_up_off(color, 300, 0.06, 0.09);
		pause_piezo(750);
	}
	piezo_off();
}

void alarm2_down(char color, int num_repeats) {
    int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
		synced_breathe_down(color, 300, 0.09, 0.06);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_down(color, 300, 0.06, 0.03);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_down_off(color, 300, 0.03, 0);
		pause_piezo(750);
	}
	piezo_off();
}
void alarm2_breathe(char color, int num_repeats) {
    int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
		synced_breathe_up(color, 300, 0, 0.03);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_up(color, 300, 0.03, 0.06);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		synced_breathe_down_off(color, 300, 0.06, 0);
		pause_piezo(750);
	}
	piezo_off();
}

void alarm2_flash(char color, int num_repeats) {
    int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
		solid_LED(color, 300);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		pause_LED(color, 300);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
		solid_LED(color, 300);
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void alarm2_solid(char color, int num_repeats) {
    int arr_1750 = frequency_to_arr(1750);
	int arr_2250 = frequency_to_arr(2250);
	for (int j = 0; j < num_repeats; j++){
        on_LED(color);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1750/2);
        HAL_Delay(300);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2250);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
        HAL_Delay(300);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_2250/2);
        HAL_Delay(300);
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void ascending_up(char color, int num_repeats) {
    for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
		int arr = frequency_to_arr(freq);
        float start_pulse = 0;
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 200, start_pulse, start_pulse + 0.02);
            start_pulse += 0.02;
			freq = freq + 100;
			arr = frequency_to_arr(freq);
		}
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void ascending_down(char color, int num_repeats){
    for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
		int arr = frequency_to_arr(freq);
        float start_pulse = 0.1;
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 200, start_pulse, start_pulse - 0.02);
            start_pulse -= 0.02;
			freq = freq + 100;
			arr = frequency_to_arr(freq);
		}
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void ascending_breathe(char color, int num_repeats) {
    for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
		int arr = frequency_to_arr(freq);
        float start_pulse = 0;
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 200, start_pulse, start_pulse + 0.02);
            start_pulse += 0.02;
			freq = freq + 100;
			arr = frequency_to_arr(freq);
		}
        start_pulse = 0.04;
        for (int k = 0; k < 2; k++){
            __HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 200, start_pulse, start_pulse - 0.02);
            start_pulse -= 0.02;
			freq = freq + 100;
			arr = frequency_to_arr(freq);
        }
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void ascending_flash(char color, int num_repeats) {
	int arr_1900 = frequency_to_arr(1900);
	int arr_1800 = frequency_to_arr(1800);
	int arr_1700 = frequency_to_arr(1700);
	int arr_1600 = frequency_to_arr(1600);
	int arr_1500 = frequency_to_arr(1500);
    for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1500);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1500/2);
		solid_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1600);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1600/2);
		pause_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1700);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1700/2);
		solid_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1800);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1800/2);
		pause_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1900);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1700/2);
		solid_LED(color, 200);
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void ascending_solid(char color, int num_repeats) {
    for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
		int arr = frequency_to_arr(freq);
        on_LED(color);
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			freq = freq + 100;
			arr = frequency_to_arr(freq);
		}
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void descending_up(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1900;
		int arr = frequency_to_arr(freq);
		float start_pulse = 0;
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 200, start_pulse, start_pulse + 0.02);
            start_pulse += 0.02;
			freq = freq - 100;
			arr = frequency_to_arr(freq);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void descending_down(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1900;
		int arr = frequency_to_arr(freq);
		float start_pulse = 0.1;
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 200, start_pulse, start_pulse - 0.02);
            start_pulse -= 0.02;
			freq = freq - 100;
			arr = frequency_to_arr(freq);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void descending_breathe(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1900;
		int arr = frequency_to_arr(freq);
        float start_pulse = 0;
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 200, start_pulse, start_pulse + 0.02);
            start_pulse += 0.02;
			freq = freq - 100;
			arr = frequency_to_arr(freq);
		}
        start_pulse = 0.04;
        for (int k = 0; k < 2; k++){
            __HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 200, start_pulse, start_pulse - 0.02);
            start_pulse -= 0.02;
			freq = freq - 100;
			arr = frequency_to_arr(freq);
        }
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void descending_flash(char color, int num_repeats) {
	int arr_1900 = frequency_to_arr(1900);
	int arr_1800 = frequency_to_arr(1800);
	int arr_1700 = frequency_to_arr(1700);
	int arr_1600 = frequency_to_arr(1600);
	int arr_1500 = frequency_to_arr(1500);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1900);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1900/2);
		solid_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1800);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1800/2);
		pause_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1700);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1700/2);
		solid_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1600);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1600/2);
		pause_LED(color, 200);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1500);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr_1500/2);
		solid_LED(color, 200);
        off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void descending_solid(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1900;
		int arr = frequency_to_arr(freq);
		for (int i = 0; i < 5; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			freq = freq - 100;
			arr = frequency_to_arr(freq);
		}
		pause_piezo(750);
	}
	piezo_off();
}

void chimenotify_up(char color, int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		float start_pulse = 0;
		for (int i = 0; i < 4; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 100, start_pulse, start_pulse+0.02);
			start_pulse += 0.02;
			pause_piezo(10);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimenotify_down(char color, int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		float start_pulse = 0.08;
		for (int i = 0; i < 4; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 100, start_pulse, start_pulse - 0.02);
			start_pulse -= 0.02;
			pause_piezo(10);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimenotify_breathe(char color, int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 100, 0, 0.02);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 100, 0.02, 0.04);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down(color, 100, 0.04, 0.02);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down(color, 100, 0.02, 0);
		pause_piezo(10);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimenotify_flash(char color, int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		solid_LED(color, 100);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		pause_LED(color, 100);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		solid_LED(color, 100);
		pause_piezo(10);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		pause_LED(color, 100);
		pause_piezo(10);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimenotify_solid(char color, int num_repeats) {
	int freq = 2500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		on_LED(color);
		for (int i = 0; i < 4; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(100);
			pause_piezo(10);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void batterychime_up(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
	    int arr = frequency_to_arr(freq);
		float start_pulse = 0;
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr/2);
			synced_breathe_up(color, 200, start_pulse, start_pulse + 0.02);
			start_pulse += 0.02;
			freq = freq + 250;
			arr = frequency_to_arr(freq);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void batterychime_down(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int freq = 1500;
	    int arr = frequency_to_arr(freq);
		float start_pulse = 0.06;
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr/2);
			synced_breathe_down(color, 200, start_pulse, start_pulse - 0.02);
			start_pulse -= 0.02;
			freq = freq + 250;
			arr = frequency_to_arr(freq);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void batterychime_breathe(char color, int num_repeats) {
	for (int j = 0; j < num_repeats; j++){
        int arr_1500 = frequency_to_arr(1500);
		int arr_1750 = frequency_to_arr(1750);
		int arr_2000 = frequency_to_arr(2000);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1500);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_1500/2);
		synced_breathe_up(color, 200, 0, 0.02);
		pause_piezo(10);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_1750/2);
		synced_breathe_up(color, 200, 0.02, 0.04);
		pause_piezo(10);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2000);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_2000/2);
		synced_breathe_down(color, 200, 0.04, 0);
		pause_piezo(10);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void batterychime_flash(char color, int num_repeats) {
	int arr_1500 = frequency_to_arr(1500);
	int arr_1750 = frequency_to_arr(1750);
	int arr_2000 = frequency_to_arr(2000);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1500);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_1500/2);
		solid_LED(color, 200);
		pause_piezo(10);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_1750);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_1750/2);
		pause_LED(color, 200);
		pause_piezo(10);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr_2000);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr_2000/2);
		solid_LED(color, 200);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void batterychime_solid(char color, int num_repeats){
	for (int j = 0; j < num_repeats; j++){
		on_LED(color);
        int freq = 1500;
	    int arr = frequency_to_arr(freq);
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, (int) arr/2);
			HAL_Delay(200);
			freq = freq + 250;
			arr = frequency_to_arr(freq);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimeneutral_up(char color, int num_repeats) {
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 1000, 0, 0.1);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void chimeneutral_down(char color, int num_repeats) {
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down(color, 1000, 0.1, 0);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void chimeneutral_breathe(char color, int num_repeats) {
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 500, 0, 0.05);
		synced_breathe_down(color, 500, 0.05, 0);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimeneutral_flash(char color, int num_repeats){
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		for (int i = 0; i<5; i++){
			solid_LED(color, 100);
			pause_LED(color, 100);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}
void chimeneutral_solid(char color, int num_repeats) {
	int freq = 1000;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		on_LED(color);
		__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimepos_up(char color, int num_repeats) {
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	float start_pulse = 0;
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_up(color, 330, start_pulse, start_pulse + 0.02);
			pause_piezo(100);
			start_pulse += 0.02;
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimepos_down(char color, int num_repeats) {
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	float start_pulse = 0.06;
	for (int j = 0; j < num_repeats; j++){
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			synced_breathe_down(color, 330, start_pulse, start_pulse - 0.02);
			pause_piezo(100);
			start_pulse -= 0.02;
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimepos_breathe(char color, int num_repeats) {
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 330, 0, 0.033);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 330, 0.033, 0.066);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down_off(color, 330, 0.066, 0);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimepos_flash(char color, int num_repeats) {
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		solid_LED(color, 330);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		pause_LED(color, 330);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		solid_LED(color, 330);
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimepos_solid(char color, int num_repeats){
	int freq = 2000;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		on_LED(color);
		for (int i = 0; i < 3; i++) {
			__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
			HAL_Delay(330);
			pause_piezo(100);
		}
		off_LED(color);
		pause_piezo(750);
	}
	piezo_off();
}

void chimeneg_up(char color, int num_repeats) {
	int freq = 500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 500, 0, 0.05);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up_off(color, 500, 0.05, 0.1);
		pause_piezo(750);
	}
}

void chimeneg_down(char color, int num_repeats){
	int freq = 500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down(color, 500, 0.1, 0.05);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down_off(color, 500, 0.05, 0);
		pause_piezo(750);
	}
}
void chimeneg_breathe(char color, int num_repeats) {
	int freq = 500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_up(color, 500, 0, 0.05);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down_off(color, 500, 0.05, 0);
		pause_piezo(750);
	}
}
void chimeneg_flash(char color, int num_repeats) {
	int freq = 500;
	int arr = frequency_to_arr(freq);
	__HAL_TIM_SET_AUTORELOAD(&htim16, arr);
	for (int j = 0; j < num_repeats; j++){
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		solid_LED(color, 500);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		synced_breathe_down(color, 500, 0.05, 0);
		pause_piezo(750);
	}
}
void chimeneg_solid(char color, int num_repeats) {
        int freq = 500;
	int arr = frequency_to_arr(freq);
	for (int j = 0; j < num_repeats; j++){
		on_LED(color);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		HAL_Delay(500);
		pause_piezo(100);
		__HAL_TIM_SET_COMPARE(&htim16, PIEZO_CHANNEL, arr/2);
		HAL_Delay(500);
		off_LED(color);
		pause_piezo(750);
	}
}