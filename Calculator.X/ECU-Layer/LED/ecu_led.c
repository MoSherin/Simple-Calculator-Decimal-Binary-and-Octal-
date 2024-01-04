/* 
 * File:   ecu_led.c
 * Author: Mohamed Sherin Mohamed
 *
 * Created on October 2, 2023, 11:15 AM
 */


#include "ecu_led.h"



Std_ReturnType led_inti(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(led == NULL)
    {
        ret = E_NOT_OK;
    }
    else{
    pin_config_t pin_config = {.pin = led->pin, .port = led->port, .direction = OUTPUT, .logic = LOW};
    ret = gpio_pin_inti(&pin_config);
    }
    return ret;
}
Std_ReturnType led_turn_on(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(led == NULL)
    {
        ret = E_NOT_OK;
    }
    else{
    pin_config_t pin_config = {.pin = led->pin, .port = led->port, .direction = OUTPUT, .logic = LOW};
    ret = gpio_pin_write_logic(&pin_config, HIGH);
    }
    return ret;
}
Std_ReturnType led_turn_off(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(led == NULL)
    {
        ret = E_NOT_OK;
    }
    else{
    pin_config_t pin_config = {.pin = led->pin, .port = led->port, .direction = OUTPUT, .logic = LOW};
    ret = gpio_pin_write_logic(&pin_config, LOW);
    }
    return ret;
}
Std_ReturnType led_toggle(const led_t *led){
    Std_ReturnType ret = E_OK;
    if(led == NULL)
    {
        ret = E_NOT_OK;
    }
    else{
    pin_config_t pin_config = {.pin = led->pin, .port = led->port, .direction = OUTPUT, .logic = LOW};
    ret = gpio_pin_toggle_logic(&pin_config);
    }
    return ret;
}