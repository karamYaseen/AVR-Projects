/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  29/4/2023      **************************************/
/*************************** SWC      :  DIO            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

#include "../../LIB/BIT_MATH.h"
#include "DIO_Register.h"
#include "DIO_Confiq.h"


/* MACROS FOR PORTS */
    #define DIO_u8_PORTA   0
    #define DIO_u8_PORTB   1
    #define DIO_u8_PORTC   2
    #define DIO_u8_PORTD   3

/* MACROS FOR PINS */
    #define DIO_u8_PIN0     0
    #define DIO_u8_PIN1     1
    #define DIO_u8_PIN2     2
    #define DIO_u8_PIN3     3
    #define DIO_u8_PIN4     4
    #define DIO_u8_PIN5     5
    #define DIO_u8_PIN6     6
    #define DIO_u8_PIN7     7

/****************** Pins Direction & Values ****************/
	#define DIO_u8_INITIAL_OUTPUT                             1
	#define DIO_u8_INITIAL_INPUT                              0

	#define DIO_u8_OUTPUT_LOW                                 0
	#define DIO_u8_OUTPUT_HIGH                                1
	#define DIO_u8_INPUT_FLOATING                             0
	#define DIO_u8_INPUT_PULLUP                               1

/* MACROS FOR PINS DIRECTION */
    #define DIO_u8_OUTPUT  1
    #define DIO_u8_INPUT   0

    #define DIO_u8_PORT_INPUTDIR  0x00
    #define DIO_u8_PORT_OUTPUTDIR 0xFF

/* MACROS FOR PINS VALUE */
    #define DIO_u8_HIGH    1
    #define DIO_u8_LOW     0



#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                     CONC_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_Help(b7,b6,b5,b4,b3,b2,b1,b0)                0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
