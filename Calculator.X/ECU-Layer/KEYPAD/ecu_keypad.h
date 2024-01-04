/* 
 * File:   ecu_keypad.h
 * Author: lenovo
 *
 * Created on January 2, 2024, 12:16 AM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/*Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*Section: Macro Declarations*/


/*Section: Macro Functions*/
#define KEYPAD_COLS 4
#define KEYPAD_ROWS 4
#define KEYPAD_PINS 8
/*Section: Data Type Declarations*/
typedef struct{
    pin_config_t keypad_cols_pins[4];
    pin_config_t keypad_rows_pins[4];
}keypad_t;


/*Section: Functions Declarations*/
Std_ReturnType keypad_initi(const keypad_t* keypad);
Std_ReturnType keypad_get_value(const keypad_t* keypad, uint8* value);

#endif	/* ECU_KEYPAD_H */

