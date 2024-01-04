/* 
 * File:   hal_interupt.h
 * Author: lenovo
 *
 * Created on November 24, 2023, 9:27 PM
 */

#ifndef HAL_INTERUPT_H
#define	HAL_INTERUPT_H

/*Section: Includes*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "../GPIO/hal_gpio.h"
#include "hal_interrupt_confg.h"
/*Section: Macro Declarations*/
/*Section: Macro Functions*/
#define IN0_EXT_Interupt_Enable() (INTCONbits.INT0IE = 1)
#define IN0_EXT_Interupt_Disable() (INTCONbits.INT0IE = 0)
#define IN0_Interupt_CLEAR_FLAG() (INTCONbits.INT0IF = 0)
#define IN0_Rising_Edge_Interupt() (INTCON2bits.INTEDG0 = 1)
#define IN0_Falling_Edge_Interupt() (INTCON2bits.INTEDG0 = 0)


#define IN1_EXT_Interupt_Enable() (INTCON3bits.INT1IE = 1)
#define IN1_EXT_Interupt_Disable() (INTCON3bits.INT1IE = 0)
#define IN1_Interupt_CLEAR_FLAG() (INTCON3bits.INT1IF = 0)
#define IN1_Rising_Edge_Interupt() (INTCON2bits.INTEDG1 = 1)
#define IN1_Falling_Edge_Interupt() (INTCON2bits.INTEDG1 = 0)


#define IN2_EXT_Interupt_Enable() (INTCON3bits.INT2IE = 1)
#define IN2_EXT_Interupt_Disable() (INTCON3bits.INT2IE = 0)
#define IN2_Interupt_CLEAR_FLAG() (INTCON3bits.INT2IF = 0)
#define IN2_Rising_Edge_Interupt() (INTCON2bits.INTEDG2 = 1)
#define IN2_Falling_Edge_Interupt() (INTCON2bits.INTEDG2 = 0)


#define Interupt_Pin(Port, Pin) .interupt_pin.port = Port, .interupt_pin.pin = Pin, .interupt_pin.direction = INPUT, .interupt_pin.logic = LOW

/*Section: Data Type Declarations*/
typedef enum{
    Rising_Edge = 0,
    Falling_Edge
}Edge_t;
typedef enum{
    INT0_PIN = 0,
    INT1_PIN,
    INT2_PIN
}interrupt_source_t;
typedef struct{
    void(*EXT_InteruptHandler)(void);
    pin_config_t interupt_pin;
    interrupt_source_t source;
    Edge_t Edge;
}EXT_Interupt_t;

/*Section: Functions Declarations*/
Std_ReturnType EXT_Interupt_Init(const EXT_Interupt_t * Interupt_Obj);
Std_ReturnType EXT_Interupt_DeInit(const EXT_Interupt_t * Interupt_Obj);
#endif	/* HAL_INTERUPT_H */

