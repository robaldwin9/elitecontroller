#ifndef _CONTROLS_HEADER_FILE_
#define _CONTROLS_HEADER_FILE_

/***********************************
 * extrafunc.h
 * rev 1.0 - shabaz Jan 2021
 * *********************************/

#define LED_PIN 25
#define BTN_PIN_0 0
#include "pico/stdlib.h"

typedef struct DigitalInput {
    uint pin;
    uint prev_value;
    uint cur_value;
    bool valueChanged;
} DigitalInput;

typedef struct Key {
    DigitalInput input;
    uint LED_OUTPUT;
    char event_text[100];
    char mapped_key[25];
    bool active;
} Key;

 Key makeKey( DigitalInput input, uint pin, char event[], char key[]);
 DigitalInput makeInput(uint pin);
 void key_init(DigitalInput *input);
 void update_digital_value(DigitalInput *input);
 void update_key(Key *key);


int led_setup(void); // sets LED pin as an output
int led_ctrl(int v); // turns LED on (v=1) or off (v=0)

#endif // _EXTRAFUNC_HEADER_FILE_
