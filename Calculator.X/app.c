/*
 * File:   app.c
 * Author: Mohamed Sherin Mohmaed
 *
 * Created on October 2, 2023, 10:28 AM
 */

#include "app.h"




int main() {
    ret = lcd_4bit_initi(&lcd);
    ret = keypad_initi(&keypad);
    ret = button_initialize(&button);
    ret = lcd_4bit_print_string(&lcd, "  Decimal Mode  ");
    __delay_ms(1000);
    ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
    while(1)
    {
        ret = button_read_state(&button, &button_state);
        ret = keypad_get_value(&keypad, &key);
        if(BUTTON_PRESSED == button_state)
        {
            mode_select_menu();
            __delay_ms(500);
            
        }
        else {/* Nothing */}
        if(key)
        {
            if('=' == Operator)
            {
                Operator = OPERATOR_DEFAULT; Num1 = 0; Num2 = 0; Num = 0;
                ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                __delay_ms(10);
            }
            else {/* Nothing */}
            print_numbers();
            __delay_ms(500);
        }
        else {/* Nothing */}
        
    }    
        return 0;
}
    
    

void print_numbers(void){
    switch(key){
        case '1':
            if(!Operator)
            {
                Num1 = 1 + (10*Num1);
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                Num2 = 1 + (10*Num2);
                ret = lcd_4bit_print_char(&lcd, key);
            }
            break;
        case '2':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 2 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 2 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '3':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 3 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 3 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '4':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 4 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 4 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '5':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 5 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 5 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '6':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 6 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 6 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '7':
            if(DECIMAL_MODE == mode || OCTAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 7 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 7 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */}
            break;
        case '8':
            if(DECIMAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 8 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 8 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */} 
            break;
        case '9':
            if(DECIMAL_MODE == mode)
            {
                if(!Operator)
                {
                    Num1 = 9 + (10*Num1);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
                else
                {
                    Num2 = 9 + (10*Num2);
                    ret = lcd_4bit_print_char(&lcd, key);
                }
            }
            else {/* Nothing */} 
            break;
        case '0':
            if(!Operator)
            {
                Num1 = 10*Num1;
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                Num2 = 10*Num2;
                ret = lcd_4bit_print_char(&lcd, key);
            }
            break;
        case '/':
            if(!Operator)
            {
                Operator = '/';
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                /* Nothing */
            }
            break;
        case '*':
            if(!Operator)
            {
                Operator = '*';
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                /* Nothing */
            }
            break;
        case '-':
            if(!Operator)
            {
                Operator = '-';
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                /* Nothing */
            }
            break;
        case '+':
            if(!Operator)
            {
                Operator = '+';
                ret = lcd_4bit_print_char(&lcd, key);
            }
            else
            {
                /* Nothing */
            }
            break;
        case 'A':
            ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
            Num1 = 0; Num2 = 0; Operator = 0;
            break;
        case '=':
            ret = lcd_4bit_print_char(&lcd, key);
            if(DECIMAL_MODE == mode)
            {
                calculate_results_decimal();
            }
            else
            {
                calculate_results_binary_octal();
            }
            Operator = '=';
            break;
    }
    key = KEY_NOT_PRESSED;
}


void calculate_results_decimal(void){
    switch(Operator){
        case '+':
            Num = Num1 + Num2;
            ret = lcd_4bit_set_cursor(&lcd, 1, 2);
            ret = lcd_4bit_print_int(&lcd, Num);
            break;
        case '-':
            Num = Num1 - Num2;
            ret = lcd_4bit_set_cursor(&lcd, 1, 2);
            ret = lcd_4bit_print_int(&lcd, Num);
            break;
        case '*':
            Num = Num1 * Num2;
            ret = lcd_4bit_set_cursor(&lcd, 1, 2);
            ret = lcd_4bit_print_int(&lcd, Num);
            break;
        case '/':
            if(ZERO == Num2)
            {
                ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
                __delay_ms(10);
                ret = lcd_4bit_print_string(&lcd, "Math Error");
            }
            else
            {
                Num = Num1 / Num2;
                ret = lcd_4bit_set_cursor(&lcd, 1, 2);
                ret = lcd_4bit_print_int(&lcd, Num);
            }
            break;
    }
}


void mode_select_menu(void){
    key = KEY_NOT_PRESSED; Num1 = 0; Num2 = 0; Num = 0;
    ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
    __delay_ms(10);
    ret = lcd_4bit_print_string(&lcd, "1- Dec   2- Oct");
    ret = lcd_4bit_set_cursor(&lcd, 1, 2);
    ret = lcd_4bit_print_string(&lcd, "     3- Bin");
    while(!('1' == key || '2' == key || '3' == key))
    {
        ret = keypad_get_value(&keypad, &key);
    }
    switch(key){
        case DECIMAL_MODE:
            mode = DECIMAL_MODE;
            ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
            __delay_ms(10);
            ret = lcd_4bit_print_string(&lcd, "  Decimal Mode  ");
        case OCTAL_MODE:
            mode = OCTAL_MODE;
            ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
            __delay_ms(10);
            ret = lcd_4bit_print_string(&lcd, "   Octal Mode   ");
            break;
        case BINARY_MODE:
            mode = BINARY_MODE;
            ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
            __delay_ms(10);
            ret = lcd_4bit_print_string(&lcd, "  Binary Mode  ");
            break;
    }
    __delay_ms(1000);
    ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
    __delay_ms(10);
    key = KEY_NOT_PRESSED;
}

void calculate_results_binary_octal(void)
{
    uint64 temp = Num1;
    uint16 Dec1 = ZERO, Dec2 = ZERO; 
    uint8 remainder = ZERO, i = ZERO;
    while(temp)
    {
      remainder = temp%10;
      temp /= 10;
      if(BINARY_MODE == mode)
        {
            Dec1 += remainder * a_power_b(2, i);
        }
        else
        {
            Dec1 += remainder * a_power_b(8, i);
        }
      ++i;
    }
    temp = Num2;
    remainder = ZERO; i = ZERO;
    while(temp)
    {
      remainder = temp%10;
      temp /= 10;
      Dec2 += remainder * a_power_b(2, i);
      ++i;
    }
    if(ZERO == Dec2 && '/' == Operator)
    {
        ret = lcd_4bit_send_command(&lcd, LCD_CLEAR_DISPLAY);
        __delay_ms(10);
        ret = lcd_4bit_print_string(&lcd, "Math Error");
    }
    else
    {
     switch(Operator){
        case '+':
            Num = Dec1 + Dec2;
            break;
        case '-':
            Num = Dec1 - Dec2;
            break;
        case '*':
            Num = Dec1 * Dec2;
            break;
        case '/':
            Num = Dec1 / Dec2;
            break;
    }
    uint8 conversion_arr[65];
    i = ZERO;
    temp = Num;
    while(temp){
        if(BINARY_MODE == mode)
        {
            conversion_arr[i] = temp % 2;
            temp = temp / 2;
        }
        else
        {
            conversion_arr[i] = temp % 8;
            temp = temp / 8;
        }
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
      if(j==i-1){
      Num = conversion_arr[j];
      }
      else {
        Num = Num * 10 + conversion_arr[j];
      }
    }
    ret = lcd_4bit_set_cursor(&lcd, 1, 2);
    ret = lcd_4bit_print_int(&lcd, Num);   
    }
}

uint16 a_power_b(uint8 a, uint8 b){
    uint16 ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}
