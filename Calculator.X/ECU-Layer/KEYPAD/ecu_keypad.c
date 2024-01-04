#include "ecu_keypad.h"

static uint8 keypad_content[KEYPAD_ROWS][KEYPAD_COLS] = {{'7', '8', '9', '/'},
                                                         {'4', '5', '6', '*'},
                                                         {'1', '2', '3', '-'},
                                                         {'A', '0', '=', '+'}};


Std_ReturnType keypad_initi(const keypad_t* keypad){
    Std_ReturnType ret = E_OK;
    if(NULL == keypad){
        ret = E_NOT_OK;
    }
    else{
        for(int i = 0;i < KEYPAD_ROWS;i++)
        {
            ret = gpio_pin_inti(&(keypad->keypad_rows_pins[i]));
        }
        for(int i = 0;i < KEYPAD_COLS;i++)
        {
            ret = gpio_pin_direction_inti(&(keypad->keypad_cols_pins[i]));
        }
    }
    return ret;
}


Std_ReturnType keypad_get_value(const keypad_t* keypad, uint8* value){
    Std_ReturnType ret = E_OK;
    uint8 logic_state = LOW;
    if(NULL == keypad || NULL == value){
        ret = E_NOT_OK;
    }
    else{
        for(int rows = 0;rows < KEYPAD_ROWS;rows++)
        {
            for(int i = 0;i < KEYPAD_ROWS;i++)
            {
                ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[i]), LOW);
            }
            ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[rows]), HIGH);
            __delay_ms(10);
            for(int cols = 0;cols < KEYPAD_COLS;cols++)
            {
                logic_state = gpio_pin_read_logic(&(keypad->keypad_cols_pins[cols]));
                if(logic_state == HIGH)
                {
                    *value = keypad_content[rows][cols];
                }
                else {}
            }
        }
    }
    return ret;
}
