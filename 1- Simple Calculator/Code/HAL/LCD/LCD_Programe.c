/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  LCD            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

/*
 * RS: Register Select, Data/Instruction select, driven
       high for data, and low for instruction.
*/

#include "../../LIB/Error_State.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Confiq.h"
#include "LCD_Private.h"

#define F_CPU 8000000UL
#include <util/delay.h>


ES_t LCD_enu_SendCommand  (u8 Copy_u8_command)
 {
#if COPY_MODE_flag == LCD_u8_8BIT_MODE

	/*RS=0*/
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/*RW=0*/
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

	DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_command);
	/*Sending enable signal*/
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(2);
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	return STD_TYPES_OK;

#elif  COPY_MODE_flag == LCD_u8_4BIT_MODE


    DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);

    DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
    //first
    DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_command);

    DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH );
    _delay_us(2);

    DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW );
    //shift
    DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_command << SHIFT_4BIT);

    DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH );
    _delay_us(2);

     DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW );

	return STD_TYPES_OK;
#endif
}

ES_t LCD_enu_Init_8bit_Mode(void)
 {

/*Directions of Rs-Rw-E*/
	
	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPortDirection(LCD_u8_DATA_PORT,DIO_u8_OUTPUT);

	
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	DIO_enu_SetPortValue(LCD_u8_DATA_PORT,DIO_u8_LOW);
	_delay_ms(35);

	LCD_enu_SendCommand(LCD_FUNCTION_SET_8BIT_MODE); /*Function Set*/
	_delay_us(40);

	LCD_enu_SendCommand(LCD_DISPLAY_CONTROL);
	_delay_us(40);

	LCD_enu_SendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	_delay_ms(2);

	LCD_enu_SendCommand(LCD_ENTRY_MODE);

//	COPY_MODE_flag=LCD_u8_8BIT_MODE;

	return STD_TYPES_OK;
}
ES_t LCD_enu_Init_4bit_Mode(void)
{
	/*Set directions for DIO connected to LCD*/

	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPinDirection(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_OUTPUT);
	DIO_enu_SetPortDirection(LCD_u8_DATA_PORT,DIO_u8_OUTPUT);


	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	DIO_enu_SetPortValue(LCD_u8_DATA_PORT,DIO_u8_LOW);
	/* Delay 35ms to ensure the initialization of the LCD driver */
	_delay_ms(35);

	LCD_enu_SendCommand(LCD_HOME);
	_delay_ms(15);

	LCD_enu_SendCommand(LCD_FUNCTION_SET_4BIT_MODE);
	_delay_us(40);

	/* Display ON OFF Control */
	LCD_enu_SendCommand(LCD_DISPLAY_ON);
	_delay_ms(2);

	/* Clear Display */
	LCD_enu_SendCommand(LCD_CLEAR_SCREEN);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_enu_SendCommand(LCD_ENTRY_MODE);
	_delay_ms(2);

//	COPY_MODE_flag=LCD_u8_4BIT_MODE;
	return STD_TYPES_OK;

}

ES_t LCD_enu_WriteCharacter(u8 Copy_u8_char)
{
#if COPY_MODE_flag==LCD_u8_8BIT_MODE

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

    DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_char);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1);
    
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
//	_delay_ms(5);
	return STD_TYPES_OK;
#elif COPY_MODE_flag == LCD_u8_4BIT_MODE

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);

    DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_char);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH );
	_delay_us(1);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW );

    DIO_enu_SetPortValue_v2(LCD_u8_DATA_PORT,Copy_u8_char << SHIFT_4BIT);

	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH );
	_delay_us(1);
	/* E = 0 */
	DIO_enu_SetPinValue(LCD_u8_CONTROL_PORT,LCD_u8_E_PIN,DIO_u8_LOW );

	return STD_TYPES_OK;
#endif

	}

ES_t LCD_enu_WriteString(s8 * Copy_ps8_String)
 {	
	do {
		LCD_enu_WriteCharacter(*Copy_ps8_String);
		(Copy_ps8_String++);
	}while(*Copy_ps8_String != '\0');

	return STD_TYPES_OK;
 }

ES_t LCD_enu_WriteSizedString(s8 * Copy_ps8_String,u8 Copy_u8_size)
{	
	u8 Local_u8_iterator = 0;
	do {
		LCD_enu_WriteCharacter(*Copy_ps8_String);
		(Copy_ps8_String++);
		Local_u8_iterator++;
	}while(Copy_u8_size > Local_u8_iterator);

	return STD_TYPES_OK;
}

ES_t LCD_enu_WriteNumber(u16 Copy_u16_Number)
{
	
	if(Copy_u16_Number < 10) {
		LCD_enu_WriteCharacter('0');
		LCD_enu_WriteCharacter(Copy_u16_Number+'0');
	}
	else {
		if (Copy_u16_Number < 100) {
			LCD_enu_WriteCharacter(Copy_u16_Number/10+'0');
			LCD_enu_WriteCharacter(Copy_u16_Number%10+'0');
		}
		else if (Copy_u16_Number < 1000) {
			LCD_enu_WriteCharacter((Copy_u16_Number/100)+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)/10+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)%10+'0');
		}
		else if (Copy_u16_Number < 10000)
		{
			LCD_enu_WriteCharacter((Copy_u16_Number/1000)+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%1000)/100+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)/10+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)%10+'0');
		}
	}

	return STD_TYPES_OK;
}

ES_t LCD_enu_WriteSizedNumber(u16 Copy_u16_Number, u8 Copy_u8_size)
{
	u8 Local_u8_iterator;
	if(Copy_u16_Number < 10) {
		for (Local_u8_iterator = 0; Local_u8_iterator < Copy_u8_size-1; Local_u8_iterator++)
		{		
			LCD_enu_WriteCharacter('0');
		}
		LCD_enu_WriteCharacter(Copy_u16_Number+'0');
	}
	else {
		if (Copy_u16_Number < 100) {
			for (Local_u8_iterator = 0; Local_u8_iterator < Copy_u8_size-2; Local_u8_iterator++)
			{		
				LCD_enu_WriteCharacter('0');
			}

			LCD_enu_WriteCharacter(Copy_u16_Number/10+'0');
			LCD_enu_WriteCharacter(Copy_u16_Number%10+'0');
		}
		else if (Copy_u16_Number < 1000) {
			for (Local_u8_iterator = 0; Local_u8_iterator < Copy_u8_size-3; Local_u8_iterator++)
			{		
				LCD_enu_WriteCharacter('0');
			}
			LCD_enu_WriteCharacter((Copy_u16_Number/100)+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)/10+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)%10+'0');
		}
		else if (Copy_u16_Number < 10000)
		{
			for (Local_u8_iterator = 0; Local_u8_iterator < Copy_u8_size-4; Local_u8_iterator++)
			{		
				LCD_enu_WriteCharacter('0');
			}
			LCD_enu_WriteCharacter((Copy_u16_Number/1000)+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%1000)/100+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)/10+'0');
			LCD_enu_WriteCharacter((Copy_u16_Number%100)%10+'0');
		}
	}

	return STD_TYPES_OK;
}

ES_t LCD_enu_GoToXY(u8 Copy_u8_LineNumber, u8 Copy_u8_Location) {
	if(Copy_u8_Location<=MAX_LOCATION)
	{
		switch(Copy_u8_LineNumber) {
			case LCD_u8_LINE0:LCD_enu_SendCommand(ADDRESS_OF_LINE0+Copy_u8_Location);break;
			case LCD_u8_LINE1:LCD_enu_SendCommand(ADDRESS_OF_LINE1+Copy_u8_Location);break;
			default: return STD_TYPES_NOK;
		}
	}else{
		return STD_TYPES_NOK;
	}
	return STD_TYPES_OK;
}

ES_t LCD_enu_CreateCustomChar( u8 Copy_u8_Location,u8 * Copy_pu8_Char) {
	if (Copy_pu8_Char != NULL && Copy_u8_Location < MAX_CHAR)
	    {
		LCD_enu_SendCommand(ADDRESS_OF_CGRAM + (Copy_u8_Location * MAX_CHAR));
	        for (u8 Local_u8_Counter = 0; Local_u8_Counter < MAX_CHAR; Local_u8_Counter++)
	        {
	        	LCD_enu_WriteCharacter(Copy_pu8_Char[Local_u8_Counter]);
	        }
	        LCD_enu_GoToXY(0,0);
	        return STD_TYPES_OK;
	    }
	    else
	        {
	        return STD_TYPES_NOK;
	        }
}

ES_t LCD_vidClearSpace(u8 Copy_u8_xPosStart, u8 Copy_u8_xPosEnd ,u8 Copy_u8_yPos)
{
	u8 Local_u8_iterator = INITIAL_VALUE;
	LCD_enu_GoToXY(Copy_u8_xPosStart,Copy_u8_yPos);
	for (Local_u8_iterator = 0; Local_u8_iterator < Copy_u8_xPosEnd; Local_u8_iterator++)
	{
		LCD_enu_WriteCharacter(' ');
	}
	LCD_enu_GoToXY(Copy_u8_xPosStart,Copy_u8_yPos);
	return STD_TYPES_OK;
}

ES_t LCD_enu_Clear(void){
	LCD_enu_SendCommand(LCD_CLEAR_SCREEN);
	return STD_TYPES_OK;
}
