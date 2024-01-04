
#include <pic18f4620.h>

#include "hal_interupt_manager.h"


#if INTERRUPT_PRIORITY == ENABLE
void __interrupt() InteruptManagerHigh(void){
    if((INTCONbits.INT0IE) == INTERRUPT_ENABLED && (INTCONbits.INT0IF) == INTERRUPT_OCCURED)
    {
        INT0_ISR();
    }
}

void __interrupt(low_priority) InteruptManagerLow(void){
    if((INTCONbits.TMR0IE) == INTERRUPT_ENABLED && (INTCONbits.TMR0IF) == INTERRUPT_OCCURED)
    {
        TMR0_ISR();
    }
}
#else
void __interrupt() InteruptManager(void){
    if((INTCONbits.INT0IE) == INTERRUPT_ENABLED && (INTCONbits.INT0IF) == INTERRUPT_OCCURED)
    {
        INT0_ISR();
    }
    else {}
    if((INTCON3bits.INT1IE) == INTERRUPT_ENABLED && (INTCON3bits.INT1IF) == INTERRUPT_OCCURED)
    {
        INT1_ISR();
    }
    else {}
    if((INTCON3bits.INT2IE) == INTERRUPT_ENABLED && (INTCON3bits.INT2IF) == INTERRUPT_OCCURED)
    {
        INT2_ISR();
    }
    else {}
    if((INTCONbits.TMR0IE) == INTERRUPT_ENABLED && (INTCONbits.TMR0IF) == INTERRUPT_OCCURED)
    {
        TMR0_ISR();
    }
    else {}
}
#endif