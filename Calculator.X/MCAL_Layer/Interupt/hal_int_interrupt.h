/* 
 * File:   hal_int_interrupt.h
 * Author: lenovo
 *
 * Created on December 1, 2023, 8:46 PM
 */

#ifndef HAL_INT_INTERRUPT_H
#define	HAL_INT_INTERRUPT_H

#include "hal_interrupt_confg.h"


/*Section: Includes*/

/*Section: Macro Declarations*/



/*Section: Macro Functions*/
#if TIMER0_INTERRUPT == ENABLE


#define TIMER0_INTERRUPT_ENABLE() (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE() (INTCONbits.TMR0IE = 0)
#define TIMER0_CLEAR_INTERRUPT_FLAG() (INTCONbits.TMR0IF = 0)


#if INTERRUPT_PRIORITY == ENABLE


#define TIMER0_HIGH_PRIORITY_INTERRUPT() (INTCON2bits.TMR0IP = 1)
#define TIMER0_LOW_PRIORITY_INTERRUPT() (INTCON2bits.TMR0IP = 0)


#endif

#endif
/*Section: Data Type Declarations*/

/*Section: Functions Declarations*/


#endif	/* HAL_INT_INTERRUPT_H */

