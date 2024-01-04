/* 
 * File:   hal_interrupt_confg.h
 * Author: lenovo
 *
 * Created on December 1, 2023, 8:50 PM
 */

#ifndef HAL_INTERRUPT_CONFG_H
#define	HAL_INTERRUPT_CONFG_H

/*Section: Includes*/
#include "../mcal_std_types.h"

/*Section: Macro Declarations*/
#define INTERRUPT_PRIORITY DISABLE
#define TIMER0_INTERRUPT ENABLE
#define HIGH_PRIORITY 1
#define LOW_PRIORITY 0



/*Section: Macro Functions*/
#if INTERRUPT_PRIORITY == DISABLE


#define Glopal_Interupt_Enable() (INTCONbits.GIE = 1)
#define Glopal_Interupt_Disable() (INTCONbits.GIE = 0)
#define Peripheral_Interupt_Enable() (INTCONbits.PEIE = 1)
#define Peripheral_Interupt_Disable() (INTCONbits.PEIE = 0)



#else


#define Interupt_Priority_Enable() (RCONbits.IPEN = 1)
#define Interupt_Priority_Disable() (RCONbits.IPEN = 0)
#define HIGH_PRIORITY_Interupt_Enable() (INTCONbits.GIEH = 1)
#define HIGH_PRIORITY_Interupt_Disable() (INTCONbits.GIEH = 0)
#define LOW_PRIORITY_Interupt_Enable() (INTCONbits.GIEL = 1)
#define LOW_PRIORITY_Interupt_Disable() (INTCONbits.GIEL = 0)

#endif
/*Section: Data Type Declarations*/

/*Section: Functions Declarations*/


#endif	/* HAL_INTERRUPT_CONFG_H */

