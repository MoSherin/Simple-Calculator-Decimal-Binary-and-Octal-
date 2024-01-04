#include "hal_ext_interupt.h"


static void(*IN0_Interupt_Handler)(void) = NULL;
static void(*IN1_Interupt_Handler)(void) = NULL;
static void(*IN2_Interupt_Handler)(void) = NULL;




Std_ReturnType EXT_Interupt_Init(const EXT_Interupt_t * Interupt_Obj){
    Std_ReturnType ret = E_OK;
    if(Interupt_Obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(Interupt_Obj->source == INT0_PIN)
        {
            IN0_EXT_Interupt_Disable();
            IN0_Interupt_CLEAR_FLAG();
#if INTERRUPT_PRIORITY == DISABLE
            Glopal_Interupt_Enable();
            Peripheral_Interupt_Enable();
#else
            Interupt_Priority_Enable();
            HIGH_PRIORITY_Interupt_Enable();
#endif
            if(Interupt_Obj->Edge == Rising_Edge)
            {
                IN0_Rising_Edge_Interupt();
            }
            else if(Interupt_Obj->Edge == Falling_Edge)
            {
                IN0_Falling_Edge_Interupt();
            }
            else 
            {
            ret = E_NOT_OK;    
            }
            ret = gpio_pin_direction_inti(&(Interupt_Obj->interupt_pin));
            IN0_Interupt_Handler = Interupt_Obj->EXT_InteruptHandler;
            IN0_EXT_Interupt_Enable();
        }
        else if(Interupt_Obj->source == INT1_PIN)
        {
            IN1_EXT_Interupt_Disable();
            IN1_Interupt_CLEAR_FLAG();
#if INTERRUPT_PRIORITY == DISABLE
            Glopal_Interupt_Enable();
            Peripheral_Interupt_Enable();
#else
            Interupt_Priority_Enable();
            HIGH_PRIORITY_Interupt_Enable();
#endif
            if(Interupt_Obj->Edge == Rising_Edge)
            {
                IN1_Rising_Edge_Interupt();
            }
            else if(Interupt_Obj->Edge == Falling_Edge)
            {
                IN1_Falling_Edge_Interupt();
            }
            else 
            {
            ret = E_NOT_OK;    
            }
            ret = gpio_pin_direction_inti(&(Interupt_Obj->interupt_pin));
            IN1_Interupt_Handler = Interupt_Obj->EXT_InteruptHandler;
            IN1_EXT_Interupt_Enable();
        }
        else if(Interupt_Obj->source == INT2_PIN)
        {
            IN2_EXT_Interupt_Disable();
            IN2_Interupt_CLEAR_FLAG();
#if INTERRUPT_PRIORITY == DISABLE
            Glopal_Interupt_Enable();
            Peripheral_Interupt_Enable();
#else
            Interupt_Priority_Enable();
            HIGH_PRIORITY_Interupt_Enable();
#endif
            if(Interupt_Obj->Edge == Rising_Edge)
            {
                IN2_Rising_Edge_Interupt();
            }
            else if(Interupt_Obj->Edge == Falling_Edge)
            {
                IN2_Falling_Edge_Interupt();
            }
            else 
            {
            ret = E_NOT_OK;    
            }
            ret = gpio_pin_direction_inti(&(Interupt_Obj->interupt_pin));
            IN2_Interupt_Handler = Interupt_Obj->EXT_InteruptHandler;
            IN2_EXT_Interupt_Enable();
        }
        else
        {
            
        }
                
    }
    return ret;
}
Std_ReturnType EXT_Interupt_DeInit(const EXT_Interupt_t * Interupt_Obj){
    Std_ReturnType ret = E_OK;
    if(Interupt_Obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(Interupt_Obj->source == INT0)
        {
            IN0_EXT_Interupt_Disable();
        }
        else if(Interupt_Obj->source == INT1)
        {
            IN1_EXT_Interupt_Disable();
        }
        else if(Interupt_Obj->source == INT2)
        {
            IN2_EXT_Interupt_Disable();
        }
        else
        {
            
        }
                
    }
    return ret;
}

void INT0_ISR(void){
    IN0_Interupt_CLEAR_FLAG();
    if(IN0_Interupt_Handler)
    {
        IN0_Interupt_Handler();
    }
    else
    {
        
    }
}
void INT1_ISR(void){
    IN1_Interupt_CLEAR_FLAG();
    if(IN1_Interupt_Handler)
    {
        IN1_Interupt_Handler();
    }
    else
    {
        
    }
}
void INT2_ISR(void){
    IN2_Interupt_CLEAR_FLAG();
    if(IN2_Interupt_Handler)
    {
        IN2_Interupt_Handler();
    }
    else
    {
        
    }
}