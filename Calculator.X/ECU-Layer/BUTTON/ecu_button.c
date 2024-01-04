#include "ecu_button.h"

Std_ReturnType button_initialize(const button_t *btn){
    Std_ReturnType ret = E_OK;
    if(NULL == btn){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_inti(&(btn->button_pin));
    }
    return ret;
}
Std_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state){
    Std_ReturnType ret = E_NOT_OK;
    logic_t Pin_Logic_Status = LOW;
    if((NULL == btn) || (NULL == btn_state)){
        ret = E_NOT_OK;
    }
    else{
        Pin_Logic_Status = gpio_pin_read_logic(&(btn->button_pin));
        if(BUTTON_ACTIVE_HIGH == btn->button_connection){
            *btn_state = (button_state_t)(Pin_Logic_Status);
        }
        else if(BUTTON_ACTIVE_LOW == btn->button_connection){
            *btn_state = ~(Pin_Logic_Status) & 0x01;
        }
        else { /* Nothing */  }
        ret = E_OK;
    }
    return ret;
}