/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  29/4/2023      **************************************/
/*************************** SWC      :  DIO            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#include "../../LIB/Error_State.h"
#include "../../LIB/STD_TYPES.h"

/* =========================================================================================== */
/*                                Macros DEfinitions                                           */ 
/* =========================================================================================== */

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

/* MACROS FOR PINS DIRECTION */    
    #define DIO_u8_OUTPUT  1
    #define DIO_u8_INPUT   0

    #define DIO_u8_PORT_INPUTDIR  0x00
    #define DIO_u8_PORT_OUTPUTDIR 0xFF

/* MACROS FOR PINS VALUE */        
    #define DIO_u8_HIGH    1
    #define DIO_u8_LOW     0


/* =========================================================================================== */
/*                                Function modules                                             */
/* =========================================================================================== */
   
    ES_t DIO_enu_Init                        (void);

    ES_t  DIO_enu_SetPinDirection            (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 Copy_u8_PinDirection);

    ES_t  DIO_enu_SetPinValue                (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 Copy_u8_PinValue);

    ES_t  DIO_enu_GetPinValue                (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinValue);
    
    ES_t  DIO_enu_GetPinDir                  (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinDirection);

    ES_t  DIO_enu_SetPortDirection           (u8 Copy_u8_PortId,u8 Copy_u8_PortDirection);

    ES_t  DIO_enu_SetPortValue               (u8 Copy_u8_PortId,u8 Copy_Port_Value);

    ES_t DIO_enu_SetPortValue_v2             (u8 Copy_u8_PortId, u8 Copy_u8_PortValue);

    ES_t  DIO_enu_GetPortValue               (u8 Copy_u8_PortId,u8 * Copy_pu8_ReturnPortValue);

#endif
