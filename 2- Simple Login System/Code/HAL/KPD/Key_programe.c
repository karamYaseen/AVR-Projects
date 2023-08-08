/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  7/7/2023      **************************************/
/*************************** SWC      :  Keypad           ************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*********************************************************************************************/

/*Lib Layer*/
#include "../../lib/BIT_MATH.h"
#include "../../lib/STD_TYPES.h"
#include "../../lib/Error_State.h"

/* MCAL */
#include "../../MCAL/DIO/DIO_Interface.h"

/* HAL */
#include "Key_Confiq.h"

#define F_CPU 8000000UL

#include <util/delay.h>

u8 KPD_Au8_RowsPins[4]={KPD_U8_R1_PIN,KPD_U8_R2_PIN,KPD_U8_R3_PIN,KPD_U8_R4_PIN};
u8 KPD_Au8_ColsPins[4]={KPD_U8_C1_PIN,KPD_U8_C2_PIN,KPD_U8_C3_PIN,KPD_U8_C4_PIN};
char KPD_Au8_Keys[4][4] = KEY_KEYS;

ES_t KPD_enu_GetKey(u8 *Copy_pu8_ReturnKey)
{
    u8 Local_u8_RowCounter, Local_u8_ColCounter, Local_u8_PinVal, Local_u8_Flag = 0;
    *Copy_pu8_ReturnKey = KPD_U8_UNPRESED;

    if (Copy_pu8_ReturnKey != NULL)
    {
        for (Local_u8_RowCounter = 0; Local_u8_RowCounter <= 3; Local_u8_RowCounter++)
        {
            DIO_enu_SetPinValue(KPD_U8_R_PORT, KPD_Au8_RowsPins[Local_u8_RowCounter], DIO_u8_LOW);

            for (Local_u8_ColCounter = 0; Local_u8_ColCounter <= 3; Local_u8_ColCounter++)
            {
                DIO_enu_GetPinValue(KPD_U8_C_PORT, KPD_Au8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);

                if (Local_u8_PinVal == DIO_u8_LOW)
                {
                    _delay_ms(20);
                    DIO_enu_GetPinValue(KPD_U8_C_PORT, KPD_Au8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);

                    while (Local_u8_PinVal == DIO_u8_LOW)
                    {
                        DIO_enu_GetPinValue(KPD_U8_C_PORT, KPD_Au8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);
                    }

                    *Copy_pu8_ReturnKey = KPD_Au8_Keys[Local_u8_RowCounter][Local_u8_ColCounter];
                    Local_u8_Flag = 1;
                    break;
                }
            }

            DIO_enu_SetPinValue(KPD_U8_R_PORT, KPD_Au8_RowsPins[Local_u8_RowCounter], DIO_u8_HIGH);

            if (Local_u8_Flag)
            {
                break;
            }
        }
    }
    else
    {
        return STD_TYPES_NOK;
    }

    return STD_TYPES_OK;
}



ES_t KeyPad_enu_Init()
{
	for(int i = 0 ; i<=3 ; i++)
	{
		// Set columns as outputs and enable pull-up resistors
		DIO_enu_SetPinDirection(KPD_U8_C_PORT, KPD_Au8_ColsPins[i], DIO_u8_INPUT);
		DIO_enu_SetPinValue(KPD_U8_C_PORT, KPD_Au8_ColsPins[i], DIO_u8_HIGH);

		// Set rows as inputs
		DIO_enu_SetPinDirection(KPD_U8_R_PORT,KPD_Au8_RowsPins[i], DIO_u8_OUTPUT);
		DIO_enu_SetPinValue(KPD_U8_R_PORT, KPD_Au8_RowsPins[i], DIO_u8_HIGH);
	}
    return STD_TYPES_OK;
}
