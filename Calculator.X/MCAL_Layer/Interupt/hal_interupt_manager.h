/* 
 * File:   hal_interupt_manager.h
 * Author: lenovo
 *
 * Created on November 26, 2023, 12:14 AM
 */

#ifndef HAL_INTERUPT_MANAGER_H
#define	HAL_INTERUPT_MANAGER_H


/*Section: Includes*/
#include "hal_interrupt_confg.h"
/*Section: Macro Declarations*/
#define INTERRUPT_ENABLED 1
#define INTERRUPT_DISABLED 0
#define INTERRUPT_OCCURED 1
/*Section: Macro Functions*/
/*Section: Data Type Declarations*/
/*Section: Functions Declarations*/
void INT0_ISR();
void INT1_ISR();
void INT2_ISR();
void TMR0_ISR();

#endif	/* HAL_INTERUPT_MANAGER_H */

