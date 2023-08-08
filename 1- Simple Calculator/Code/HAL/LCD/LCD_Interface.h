/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  LCD            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#ifndef LCD_Interface_H
#define LCD_Interface_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/Error_State.h"

#define LCD_u8_CHAR0                          0
#define LCD_u8_CHAR1                          1
#define LCD_u8_CHAR2                          2
#define LCD_u8_CHAR3                          3
#define LCD_u8_CHAR4                          4
#define LCD_u8_CHAR5                          5
#define LCD_u8_CHAR6                          6
#define LCD_u8_CHAR7                          7


/*Function definitions*/
ES_t LCD_enu_Init_8bit_Mode     (void);

ES_t LCD_enu_Init_4bit_Mode     (void);

ES_t LCD_enu_SendCommand    	(u8 Copy_u8_command);

ES_t LCD_enu_WriteCharacter 	(u8 Copy_u8_char);

ES_t LCD_enu_WriteString    	(s8 * Copy_ps8_String);

ES_t LCD_enu_WriteSizedString   (s8 * Copy_ps8_String,u8 Copy_u8_size);

ES_t LCD_enu_WriteNumber        (u16 Copy_u16_Number);

ES_t LCD_enu_WriteSizedNumber   (u16 Copy_u16_Number, u8 Copy_u8_size);

ES_t LCD_enu_GoToXY				(u8 Copy_u8_LineNumber, u8 Copy_u8_Location);

ES_t LCD_enu_CreateCustomChar	(u8 * Copy_pu8_Char, u8 Copy_u8_Location);

ES_t LCD_vidClearSpace			(u8 Copy_u8_xPosStart, u8 Copy_u8_xPosEnd ,u8 Copy_u8_yPos);

ES_t LCD_enu_Clear				(void);

#endif
