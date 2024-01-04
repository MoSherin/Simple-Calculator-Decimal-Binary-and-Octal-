/* 
 * File:   mcal_std_types.h
 * Author: lenovo
 *
 * Created on October 2, 2023, 11:04 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*Section: Includes*/
#include "std_libraries.h"
#include "compiler.h"


/*Section: Macro Declarations*/
#define STD_HIGH       0x01
#define STD_LOW        0x00
#define STD_ON         0x01
#define STD_OFF        0x00
#define STD_ACTIVE     0x01
#define STD_IDEAL      0x00
#define E_OK           (Std_ReturnType)0x01
#define E_NOT_OK       (Std_ReturnType)0x00
#define ENABLE         0x01
#define DISABLE        0x00
#define ZERO           0

/*Section: Macro Functions*/



/*Section: Data Type Declarations*/
typedef unsigned char          uint8;
typedef unsigned int           uint16;
typedef unsigned long          uint32;
typedef unsigned long long     uint64;
typedef signed char            sint8;
typedef signed int             sint16;
typedef signed long            sint32;
typedef signed long long       sint64;

typedef uint8          Std_ReturnType;


/*Section: Functions Declarations*/

#endif	/* MCAL_STD_TYPES_H */

