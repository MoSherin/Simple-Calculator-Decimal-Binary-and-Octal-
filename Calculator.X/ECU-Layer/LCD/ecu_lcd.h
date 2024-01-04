/* 
 * File:   ecu_lcd.h
 * Author: lenovo
 *
 * Created on December 31, 2023, 9:05 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/*Section: Macro Declarations*/
#define LCD_CLEAR_DISPLAY                   0x01
#define LCD_RETURN_HOME                     0x02
#define LCD_ENTRY_MODE_RIGHT                0x06
#define LCD_ENTRY_MODE_LEFT                 0x04
#define LCD_DISPLAY_OFF                     0x08
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF 0x0C
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF  0x0E
#define LCD_DISPLAY_ON_CURSOR_OFF_BLINK_ON  0x0D
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON   0x0F
#define LCD_LEFT_SHIFT_CURSOR               0x10
#define LCD_RIGHT_SHIFT_CURSOR              0x14
#define LCD_LEFT_SHIFT_CURSOR_DISPLAY       0x18
#define LCD_RIGHT_SHIFT_CURSOR_DISPLAY      0x1C
#define LCD_8BIT_INTERFACE                  0x38
#define LCD_4BIT_INTERFACE                  0x28
#define LCD_ROW_ONE_ADDRESS                 0x80
#define LCD_ROW_TWO_ADDRESS                 0xC0

/*Section: Macro Functions*/
#define LCD_4BIT_PIN(RS_PIN, RS_PORT, E_PIN, E_PORT, D4_PIN, D4_PORT, D5_PIN, D5_PORT, D6_PIN, D6_PORT, D7_PIN, D7_PORT) .Rs.pin = RS_PIN, .Rs.port = RS_PORT, .Rs.direction = OUTPUT, .Rs.logic = LOW,.E.pin = E_PIN, .E.port = E_PORT, .E.direction = OUTPUT, .E.logic = LOW, .Dx[0].pin = D4_PIN, .Dx[0].port = D4_PORT, .Dx[0].direction = OUTPUT, .Dx[0].logic = LOW, .Dx[1].pin = D5_PIN, .Dx[1].port = D5_PORT, .Dx[1].direction = OUTPUT, .Dx[1].logic = LOW, .Dx[2].pin = D6_PIN, .Dx[2].port = D6_PORT, .Dx[2].direction = OUTPUT, .Dx[2].logic = LOW, .Dx[3].pin = D7_PIN, .Dx[3].port = D7_PORT, .Dx[3].direction = OUTPUT, .Dx[3].logic = LOW


/*Section: Data Type Declarations*/
typedef struct{
    pin_config_t Dx[4];
    pin_config_t Rs;
    pin_config_t E;
}lcd_4bit_t;

typedef struct{
    pin_config_t Dx[8];
    pin_config_t Rs;
    pin_config_t E;
}lcd_8bit_t;


/*Section: Functions Declarations*/
Std_ReturnType lcd_4bit_initi(const lcd_4bit_t* LCD);
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t* LCD, uint8 command);
Std_ReturnType lcd_4bit_print_char(const lcd_4bit_t* LCD, uint8 data);
Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t* LCD, uint8 Cols, uint8 Rows);
Std_ReturnType lcd_4bit_print_string(const lcd_4bit_t* LCD, uint8 *Str);
Std_ReturnType lcd_4bit_print_int(const lcd_4bit_t* LCD, uint64 value);

Std_ReturnType lcd_8bit_initi(const lcd_8bit_t* LCD);
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t* LCD, uint8 command);
Std_ReturnType lcd_8bit_print_char(const lcd_8bit_t* LCD, uint8 data);
Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t* LCD, uint8 Cols, uint8 Rows);
Std_ReturnType lcd_8bit_print_string(const lcd_8bit_t* LCD, uint8 *Str);

#endif	/* ECU_LCD_H */

