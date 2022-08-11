/*
 * Piezo_Control.h
 *
 *  Created on: Jul 12, 2022
 *      Author: gopala4
 */

#ifndef INC_PIEZO_CONTROL_H_
#define INC_PIEZO_CONTROL_H_

//for systems notification purposes
int frequency_to_arr(int frequency);
void piezo_init(void);
void piezo_off(void);
void pause_piezo(int duration_in_ms);
void play_siren(int num_repeats);
void play_alarm1(int num_repeats);
void play_alarm2(int num_repeats);
void play_ascending(int num_repeats);
void play_descending(int num_repeats);
void chime_neutral(int num_repeats);
void chime_negative(int num_repeats);
void chime_positive(int num_repeats);
void chime_notify(int num_repeats);
void battery_chime(int num_repeats);

//for song playback purposes
float get_freq_from_note(char note[]);
void play_frequency(int duration_ms, float frequency);
void play_frequency_array(float beats[], float frequencies[], float tempo, int song_len);
void play_tune(float beats[], char *song_notes, float tempo);


#endif /* INC_PIEZO_CONTROL_H_ */