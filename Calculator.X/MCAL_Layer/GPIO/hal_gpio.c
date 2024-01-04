/*
 * File:   hal_gpio.c
 * Author: Mohamed Sherin Mohmaed
 *
 * Created on October 2, 2023, 10:28 AM
 */

#include "hal_gpio.h"

/*Reference to the Data Direction Control Registers*/
volatile uint8 *tris_register[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*Reference to the Data Latch Registers*/
volatile uint8 *lat_register[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/*Reference to the PORT Status Registers*/
volatile uint8 *port_register[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_inti(const pin_config_t* pin_config){
    
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX_INDEX)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(pin_config->direction){
            case OUTPUT:
                CLEAR_BIT(*tris_register[pin_config->port], pin_config->pin);
                break;
            case INPUT:
                SET_BIT(*tris_register[pin_config->port], pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
                
    }
    return ret;
}
#endif


/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @param direction_status
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t* pin_config, direction_t *direction_status){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || direction_status == NULL || pin_config->pin > PIN_MAX_INDEX)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = READ_BIT(*tris_register[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif


/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @param logic
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t* pin_config, logic_t logic){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX_INDEX)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(logic){
            case LOW:
                    CLEAR_BIT(*lat_register[pin_config->port], pin_config->pin);
                    break;
                case HIGH:
                    SET_BIT(*lat_register[pin_config->port], pin_config->pin);
                    break;
                default:
                    ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif


/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @param logic
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
uint8 gpio_pin_read_logic(const pin_config_t* pin_config){
    if(pin_config == NULL ||pin_config->pin > PIN_MAX_INDEX)
    {
        return 5;
    }
    else
    {
        return (READ_BIT(*port_register[pin_config->port], pin_config->pin));
    }
}
#endif


/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX_INDEX)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*lat_register[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif

/**
 * 
 * @param pin_config pointer to the configurations of the pin
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_PIN_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_pin_inti(const pin_config_t* pin_config){
    Std_ReturnType ret = E_OK;
    if(pin_config == NULL || pin_config->pin > PIN_MAX_INDEX)
    {
        ret = E_NOT_OK;
    }
    
    else
    {
        ret = gpio_pin_direction_inti(pin_config);
        ret = gpio_pin_write_logic(pin_config, pin_config->logic);
    }
    return ret;
}
#endif


/**
 * 
 * @param port the index of the port
 * @param direction INPUT or OUTPUT
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_direction_inti(port_index_t port, uint8 direction){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NO)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *tris_register[port] = direction;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param direction_status
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NO || direction_status == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NO)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_register[port] = logic;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NO || logic == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = *lat_register[port];
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return Status of the function
 *                      (E_OK): The function done successfully
 *                      (E_NOT_OK): The function has an issue
 */
#if PORT_CONFIG == CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
    Std_ReturnType ret = E_OK;
    if(port > PORT_MAX_NO)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *lat_register[port] ^= PORT_MASK;
    }
    return ret;
}
#endif