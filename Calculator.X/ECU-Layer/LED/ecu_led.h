/* 
 * File:   ecu_led.h
 * Author: lenovo
 *
 * Created on October 2, 2023, 11:15 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h" 

/*Section: Macro Declarations*/

/*Section: Macro Functions*/

/*Section: Data Type Declarations*/
typedef enum{
    LED_OFF = 0,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port : 4;
    uint8 pin  : 3;
    uint8 led_status : 1;
}led_t;


/*Section: Functions Declarations*/
Std_ReturnType led_inti(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);

#endif	/* ECU_LED_H */

