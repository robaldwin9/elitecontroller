/****************************************
 * extrafunc.c
 * rev 1.0 shabaz Jan 2021
 * **************************************/

#include "controls.h"
#include "pico/stdlib.h"
#include "tusb.h"

Key makeKey( DigitalInput input, uint pin, char event[], char key[])
{
    Key newKey = {input, pin, event, key, true};
    gpio_init(LED_PIN);
    gpio_set_dir(pin, GPIO_OUT); 
    return newKey;
}

DigitalInput makeInput(uint pin)
{
    DigitalInput in = {pin, 0, 0};
    key_init(&in);
    return in;
}

void key_init(DigitalInput *input)
{
    gpio_init(input->pin);
    gpio_set_dir(input->pin, GPIO_IN);
    gpio_pull_up(input->pin);
    uint value = gpio_get(input->pin); 
}

void update_digital_value(DigitalInput *input)
{
    input->cur_value = gpio_get(input->pin);
    if(input->cur_value != input->prev_value)
    {
        input->prev_value = input->cur_value;
        input->valueChanged = true;
    }

    else
    {
        input->prev_value = input->cur_value;
        input->valueChanged = false;
    }
}

void update_key(Key *key)
{
    update_digital_value(&key->input);
    if(key->input.valueChanged)
    {
         key->active = !key->active;
         gpio_put(key->LED_OUTPUT, key->active);

         if(tud_hid_ready())
         {
             uint8_t keycode[6] = {0};
             keycode[0] = HID_KEY_A;
             tud_hid_keyboard_report(0, 0, keycode);
              
         }
   }
}
