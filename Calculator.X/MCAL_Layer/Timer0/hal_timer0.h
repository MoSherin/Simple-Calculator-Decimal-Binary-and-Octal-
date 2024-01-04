/* 
 * File:   hal_timer0.h
 * Author: lenovo
 *
 * Created on December 1, 2023, 4:51 PM
 */

#ifndef HAL_TIMER0_H
#define	HAL_TIMER0_H

/*Section: Includes*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../Interupt/hal_int_interrupt.h"
/*Section: Macro Declarations*/

/*Section: Macro Functions*/
#define TIMER0_ENABLE() (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE() (T0CONbits.TMR0ON = 0)
#define TIMER0_8BIT_MODE() (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_MODE() (T0CONbits.T016BIT = 0)
#define TIMER0_COUNTER_MODE() (T0CONbits.T0CS = 1)
#define TIMER0_CLOCK_MODE() (T0CONbits.T0CS = 0)
#define TIMER0_FALLING_EDGE() (T0CONbits.T0SE = 1)
#define TIMER0_RISING_EDGE() (T0CONbits.T0SE = 0)
#define TIMER0_PRESCALER_ENABLE() (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)
#define TIMER0_PRESCALER_VALUE(config) (T0CONbits.T0PS = config)
/*Section: Data Type Declarations*/
typedef enum{
    TIMER0_PRESCALE_DIV_BY_2 = 0,
    TIMER0_PRESCALE_DIV_BY_4,
    TIMER0_PRESCALE_DIV_BY_8,        
    TIMER0_PRESCALE_DIV_BY_16,        
    TIMER0_PRESCALE_DIV_BY_32,        
    TIMER0_PRESCALE_DIV_BY_64,        
    TIMER0_PRESCALE_DIV_BY_128,        
    TIMER0_PRESCALE_DIV_BY_256        
}timer0_prescaler_value_t;
typedef enum{
    TIMER0_16BIT_MODE = 0,
    TIMER0_8BIT_MODE
}timer0_bit_mode_t;
typedef enum{
    TIMER0_CLOCK_MODE = 0,
    TIMER0_COUNTER_MODE
}timer0_mode_t;
typedef enum{
    TIMER0_RISING_EDGE = 0,
    TIMER0_FALLING_EDGE        
}timer0_edge_t;
typedef enum{
    TIMER0_PRESCALER_ENABLE = 0,
    TIMER0_PRESCALER_DISABLE        
}timer0_prescaler_t;

typedef struct{
    uint8 bit_mode: 1;
    uint8 mode: 1;
    uint8 edge: 1;
    uint8 prescaler_value: 3;
    uint8 prescaler: 1;
    uint16 preload_value;
#if TIMER0_INTERRUPT == ENABLE
    uint8 interrupt_priority: 1;
    void(*timer0_interrupt_handler)(void);
#endif
}timer0_t;
/*Section: Functions Declarations*/

Std_ReturnType timer0_inti(const timer0_t* timer0);
Std_ReturnType timer0_deinti(const timer0_t* timer0);

#endif	/* HAL_TIMER0_H */

