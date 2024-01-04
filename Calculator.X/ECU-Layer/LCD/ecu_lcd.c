#include "ecu_lcd.h"


static void LCD_SEND_4BITS(const lcd_4bit_t* LCD, uint8 command);
static void LCD_SEND_8BITS(const lcd_8bit_t* LCD, uint8 command);
static void LCD_4BIT_SEND_ENABLE(const lcd_4bit_t* LCD);
static void LCD_8BIT_SEND_ENABLE(const lcd_8bit_t* LCD);
static void convert_int_to_string(uint64 value, uint8 *str);


Std_ReturnType lcd_4bit_initi(const lcd_4bit_t* LCD){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_inti(&(LCD->Rs));
        ret = gpio_pin_direction_inti(&(LCD->E));
        for(int i = 0;i < 4;i++)
        {
            ret = gpio_pin_direction_inti(&(LCD->Dx[i]));
        }
        ret = gpio_pin_write_logic(&(LCD->Rs), LOW);
        __delay_ms(20);
        LCD_SEND_4BITS(LCD, 0x03);
        LCD_4BIT_SEND_ENABLE(LCD);
        __delay_ms(5);
        LCD_SEND_4BITS(LCD, 0x03);
        LCD_4BIT_SEND_ENABLE(LCD);
        __delay_us(150);
        LCD_SEND_4BITS(LCD, 0x03);
        LCD_4BIT_SEND_ENABLE(LCD);

        LCD_SEND_4BITS(LCD, 0x02);
        LCD_4BIT_SEND_ENABLE(LCD);
        ret = lcd_4bit_send_command(LCD, LCD_4BIT_INTERFACE);
        ret = lcd_4bit_send_command(LCD, LCD_CLEAR_DISPLAY);
        ret = lcd_4bit_send_command(LCD, LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(LCD, LCD_ENTRY_MODE_RIGHT);
        ret = lcd_4bit_send_command(LCD, LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
    }
    return ret;
}
Std_ReturnType lcd_4bit_send_command(const lcd_4bit_t* LCD, uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->Rs), LOW);
        LCD_SEND_4BITS(LCD, command >> 4);
        LCD_4BIT_SEND_ENABLE(LCD);
        LCD_SEND_4BITS(LCD, command);
        LCD_4BIT_SEND_ENABLE(LCD);
    }
    return ret;
}


Std_ReturnType lcd_4bit_print_char(const lcd_4bit_t* LCD, uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->Rs), HIGH);
        LCD_SEND_4BITS(LCD, data >> 4);
        LCD_4BIT_SEND_ENABLE(LCD);
        LCD_SEND_4BITS(LCD, data);
        LCD_4BIT_SEND_ENABLE(LCD);
    }
    return ret;
}


Std_ReturnType lcd_4bit_set_cursor(const lcd_4bit_t* LCD, uint8 Cols, uint8 Rows){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        Cols--;
        switch(Rows){
            case 1:
                ret = lcd_4bit_send_command(LCD, LCD_ROW_ONE_ADDRESS + Cols);
                break;
            case 2:
                ret = lcd_4bit_send_command(LCD, LCD_ROW_TWO_ADDRESS + Cols);
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}


Std_ReturnType lcd_4bit_print_string(const lcd_4bit_t* LCD, uint8 *Str){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        while(*Str)
        {
            ret = lcd_4bit_print_char(LCD, *(Str++));
        }
    }
    return ret;
}


Std_ReturnType lcd_4bit_print_int(const lcd_4bit_t* LCD, uint64 value){
    Std_ReturnType ret = E_OK;
    uint8 str[11];
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        convert_int_to_string(value, str);
        ret = lcd_4bit_print_string(LCD, str);
    }
    return ret;
}


Std_ReturnType lcd_8bit_initi(const lcd_8bit_t* LCD){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_inti(&(LCD->Rs));
        ret = gpio_pin_direction_inti(&(LCD->E));
        for(int i = 0;i < 8;i++)
        {
            ret = gpio_pin_direction_inti(&(LCD->Dx[i]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(LCD, LCD_8BIT_INTERFACE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(LCD, LCD_8BIT_INTERFACE);
        __delay_us(150);
        ret = lcd_8bit_send_command(LCD, LCD_8BIT_INTERFACE);

        ret = lcd_8bit_send_command(LCD, LCD_8BIT_INTERFACE);
        ret = lcd_8bit_send_command(LCD, LCD_CLEAR_DISPLAY);
        ret = lcd_8bit_send_command(LCD, LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(LCD, LCD_ENTRY_MODE_RIGHT);
        ret = lcd_8bit_send_command(LCD, LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
    }
    return ret;
}
Std_ReturnType lcd_8bit_send_command(const lcd_8bit_t* LCD, uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->Rs), LOW);
        LCD_SEND_8BITS(LCD, command);
        LCD_8BIT_SEND_ENABLE(LCD);
    }
    return ret;
}


Std_ReturnType lcd_8bit_print_char(const lcd_8bit_t* LCD, uint8 data){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->Rs), HIGH);
        LCD_SEND_8BITS(LCD, data);
        LCD_8BIT_SEND_ENABLE(LCD);
    }
    return ret;
}


Std_ReturnType lcd_8bit_set_cursor(const lcd_8bit_t* LCD, uint8 Cols, uint8 Rows){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        Cols--;
        switch(Rows){
            case 1:
                ret = lcd_8bit_send_command(LCD, LCD_ROW_ONE_ADDRESS + Cols);
                break;
            case 2:
                ret = lcd_8bit_send_command(LCD, LCD_ROW_TWO_ADDRESS + Cols);
                break;
            default:
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}


Std_ReturnType lcd_8bit_print_string(const lcd_8bit_t* LCD, uint8 *Str){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        ret = E_NOT_OK;
    }
    else{
        while(*Str)
        {
            ret = lcd_8bit_print_char(LCD, *(Str++));
        }
    }
    return ret;
}




static void LCD_SEND_8BITS(const lcd_8bit_t* LCD, uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        
    }
    else{
        for(int i = 0;i < 8;i++)
        {
            ret = gpio_pin_write_logic(&(LCD->Dx[i]), (command >> i) & (uint8)0x01);
        }
    }
}




static void LCD_SEND_4BITS(const lcd_4bit_t* LCD, uint8 command){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        
    }
    else{
        for(int i = 0;i < 4;i++)
        {
            ret = gpio_pin_write_logic(&(LCD->Dx[i]), (command >> i) & (uint8)0x01);
        }
    }
}

static void LCD_4BIT_SEND_ENABLE(const lcd_4bit_t* LCD){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->E), HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(LCD->E), LOW);
    }
}

static void LCD_8BIT_SEND_ENABLE(const lcd_8bit_t* LCD){
    Std_ReturnType ret = E_OK;
    if(NULL == LCD){
        
    }
    else{
        ret = gpio_pin_write_logic(&(LCD->E), HIGH);
        __delay_us(5);
        ret = gpio_pin_write_logic(&(LCD->E), LOW);
    }
}


static void convert_int_to_string(uint64 value, uint8 *str){
    if(NULL == str)
    {
        
    }
    else
    {
        memset(str, '\0', 11);
        sprintf(str, "%llu", value);
    }
    
}