/* 
 * File:   hal_gpio.h
 * Author: Mohamed Sherin Mohamed
 *
 * Created on October 2, 2023, 10:50 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/*Section: Includes*/
#include "../proc/pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"
#include "hal_gpio_cgf.h"


/*Section: Macro Declarations*/
#define BIT_MASK        (uint8)1
#define PORT_MASK       0XFF
#define PIN_MAX_INDEX   7
#define PORT_MAX_NO     4
#define PORT_PIN_CONFIG CONFIG_ENABLE
#define PORT_CONFIG     CONFIG_ENABLE

/*Section: Macro Functions*/
#define HWREG8(_X)                        (*((volatile uint8 *)(_X)))

#define SET_BIT(REG, BIT_POSN)      REG|=(BIT_MASK << BIT_POSN)
#define CLEAR_BIT(REG, BIT_POSN)    REG&=~(BIT_MASK << BIT_POSN)
#define TOGGLE_BIT(REG, BIT_POSN)   REG^=(BIT_MASK << BIT_POSN)
#define READ_BIT(REG, BIT_POSN)     ((REG >> BIT_POSN) & 1)

/*Section: Data Type Declarations*/
typedef enum{
    LOW = 0,
    HIGH
}logic_t;

typedef enum{
    OUTPUT = 0,
    INPUT
}direction_t;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pin_index_t;

typedef enum{
    PORTA_INDEX = 0,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX
}port_index_t;

typedef struct{
    uint8 port      :  3;
    uint8 pin       :  3;
    uint8 direction :  1;
    uint8 logic     :  1;
}pin_config_t;

/*Section: Functions Declarations*/
Std_ReturnType gpio_pin_direction_inti(const pin_config_t* pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* pin_config, direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config, logic_t logic);
uint8 gpio_pin_read_logic(const pin_config_t* pin_config);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config);
Std_ReturnType gpio_pin_inti(const pin_config_t* pin_config);

Std_ReturnType gpio_port_direction_inti(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);

#endif	/* HAL_GPIO_H */