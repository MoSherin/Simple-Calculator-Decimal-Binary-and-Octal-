#include "hal_timer0.h"

static void(*TMR0_Interupt_Handler)(void) = NULL;
uint16 preload;

Std_ReturnType timer0_inti(const timer0_t* timer0){
    Std_ReturnType ret = E_OK;
    if(timer0 == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER0_DISABLE();
        if(timer0->bit_mode == TIMER0_8BIT_MODE)
        {
            TIMER0_8BIT_MODE();
        }
        else
        {
            TIMER0_16BIT_MODE();
        }
        if(timer0->mode == TIMER0_COUNTER_MODE)
        {
            TIMER0_COUNTER_MODE();
            if(timer0->edge == TIMER0_RISING_EDGE)
            {
                TIMER0_RISING_EDGE();
            }
            else
            {
                TIMER0_FALLING_EDGE();
            }
        }
        else
        {
            TIMER0_CLOCK_MODE();
        }
        if(timer0->prescaler == TIMER0_PRESCALER_ENABLE)
        {
            TIMER0_PRESCALER_ENABLE();
            TIMER0_PRESCALER_VALUE(timer0->prescaler_value);        
        }
        else
        {
            TIMER0_PRESCALER_DISABLE();
        }
        TMR0H = (timer0->preload_value) >> 8;
        TMR0L = (uint8)(timer0->preload_value);
        preload = timer0->preload_value;
#if TIMER0_INTERRUPT == ENABLE
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_CLEAR_INTERRUPT_FLAG();
        TMR0_Interupt_Handler = timer0->timer0_interrupt_handler;
#if INTERRUPT_PRIORITY == ENABLE
        Interupt_Priority_Enable();
        if(timer0->interrupt_priority == HIGH_PRIORITY)
        {
            HIGH_PRIORITY_Interupt_Enable();
            TIMER0_HIGH_PRIORITY_INTERRUPT();
        }
        else
        {
            LOW_PRIORITY_Interupt_Enable();
            TIMER0_LOW_PRIORITY_INTERRUPT();
        }
#else
      Glopal_Interupt_Enable();
      Peripheral_Interupt_Enable();  
#endif
        
#endif
        TIMER0_ENABLE();
                
    }
    return ret;
}
Std_ReturnType timer0_deinti(const timer0_t* timer0){
    Std_ReturnType ret = E_OK;
    if(timer0 == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER0_DISABLE();
    }
    return ret;
}

void TMR0_ISR(void){
    TIMER0_CLEAR_INTERRUPT_FLAG();
    TMR0H = preload >> 8;
    TMR0L = (uint8)(preload);
    if(TMR0_Interupt_Handler)
    {
        TMR0_Interupt_Handler();
    }
}