/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  DC_MOTOR       **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

/*Lib Layer*/
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../lib/Error_State.h"

/* MCAL */
#include "../../MCAL/DIO/DIO_Interface.h"

/* HAL */
#include "DCMOTOR_Config.h"
#include "DCMOTOR_Privite.h"

#define F_CPU 8000000UL

#include <util/delay.h>

ES_t DC_Motor_enu_Init(void)
{
    DIO_enu_SetPinDirection(DCM_U8_PORT, DCM_U8_PINE, DIO_u8_OUTPUT);
    DIO_enu_SetPinDirection(DCM_U8_PORT, DCM_U8_PIN0, DIO_u8_OUTPUT);
    DIO_enu_SetPinDirection(DCM_U8_PORT, DCM_U8_PIN1, DIO_u8_OUTPUT);

    return STD_TYPES_OK;
}

ES_t DC_Motor_enu_Rotate(u8 Copy_u8_Direction)
{
    ES_t Local_u8_errorState = STD_TYPES_OK;
    switch (Copy_u8_Direction)
    {
    case CW:
    	DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PINE, DIO_u8_HIGH);
        DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN0, DIO_u8_HIGH);
        DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN1, DIO_u8_LOW);
        break;
    case CCW:
    	DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PINE, DIO_u8_HIGH);
        DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN0, DIO_u8_LOW);
        DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN1, DIO_u8_HIGH);
        break;
    default:
        Local_u8_errorState = STD_TYPES_NOK;
        break;
    }
    return Local_u8_errorState;
}

ES_t DC_Motor_enu_Stop(void)
{
	DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PINE, DIO_u8_LOW);
    DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN0, DIO_u8_LOW);
    DIO_enu_SetPinValue(DCM_U8_PORT, DCM_U8_PIN1, DIO_u8_LOW);

    return STD_TYPES_OK;
}
