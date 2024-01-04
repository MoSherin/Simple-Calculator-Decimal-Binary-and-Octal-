/* 
 * File:   app.h
 * Author: lenovo
 *
 * Created on October 2, 2023, 11:22 AM
 */

#ifndef APP_H
#define	APP_H


/*Section: Includes*/
#include "ECU-Layer/LED/ecu_led.h"
#include "ECU-Layer/BUTTON/ecu_button.h"
#include "ECU-Layer/LCD/ecu_lcd.h"
#include "ECU-Layer/KEYPAD/ecu_keypad.h"
/*Section: Macro Declarations*/
#define KEY_PRESSED      1
#define KEY_NOT_PRESSED  0
#define OPERATOR_DEFAULT 0
#define DECIMAL_MODE     '1'
#define OCTAL_MODE       '2'
#define BINARY_MODE      '3'
/*Section: Macro Functions*/

/*Section: Functions Declarations*/
void print_numbers(void);
void calculate_results_decimal(void);
void mode_select_menu(void);
void calculate_results_binary_octal(void);
uint16 a_power_b(uint8 a, uint8 b);

/*Section: Data Type Declarations*/
led_t led = {.port = PORTC_INDEX, .pin = PIN2, .led_status = LED_OFF};
led_t led1 = {.port = PORTB_INDEX, .pin = PIN7, .led_status = LED_OFF};
button_t button = {.button_connection = BUTTON_ACTIVE_HIGH, .button_state = BUTTON_RELEASED, Button_Pin(PORTB_INDEX, PIN0)};
lcd_4bit_t lcd = {LCD_4BIT_PIN(PIN4, PORTC_INDEX, PIN5, PORTC_INDEX, PIN0, PORTC_INDEX, PIN1, PORTC_INDEX, PIN2, PORTC_INDEX, PIN3, PORTC_INDEX)};
keypad_t keypad = {.keypad_rows_pins[0].pin = PIN0, .keypad_rows_pins[0].port = PORTD_INDEX, .keypad_rows_pins[0].direction = OUTPUT, .keypad_rows_pins[0].logic = LOW, 
                  .keypad_rows_pins[1].pin = PIN1, .keypad_rows_pins[1].port = PORTD_INDEX, .keypad_rows_pins[1].direction = OUTPUT, .keypad_rows_pins[1].logic = LOW, 
                  .keypad_rows_pins[2].pin = PIN2, .keypad_rows_pins[2].port = PORTD_INDEX, .keypad_rows_pins[2].direction = OUTPUT, .keypad_rows_pins[2].logic = LOW, 
                  .keypad_rows_pins[3].pin = PIN3, .keypad_rows_pins[3].port = PORTD_INDEX, .keypad_rows_pins[3].direction = OUTPUT, .keypad_rows_pins[3].logic = LOW,
                  .keypad_cols_pins[0].pin = PIN4, .keypad_cols_pins[0].port = PORTD_INDEX, .keypad_cols_pins[0].direction = INPUT, .keypad_cols_pins[0].logic = LOW, 
                  .keypad_cols_pins[1].pin = PIN5, .keypad_cols_pins[1].port = PORTD_INDEX, .keypad_cols_pins[1].direction = INPUT, .keypad_cols_pins[1].logic = LOW, 
                  .keypad_cols_pins[2].pin = PIN6, .keypad_cols_pins[2].port = PORTD_INDEX, .keypad_cols_pins[2].direction = INPUT, .keypad_cols_pins[2].logic = LOW, 
                  .keypad_cols_pins[3].pin = PIN7, .keypad_cols_pins[3].port = PORTD_INDEX, .keypad_cols_pins[3].direction = INPUT, .keypad_cols_pins[3].logic = LOW};

Std_ReturnType ret;
button_state_t button_state = BUTTON_RELEASED;
uint8 mode = DECIMAL_MODE;
uint8 key = KEY_NOT_PRESSED, Operator;
uint64 Num1, Num2, Num;

#endif	/* APP_H */

