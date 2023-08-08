/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  29/4/2023      **************************************/
/*************************** SWC      :  DIO            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.5            **************************************/
/*********************************************************************************************/

/*HEADERS INCLUDED*/
    /*Lib Layer*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/Error_State.h"
#include "../../LIB/STD_TYPES.h"
/* MCAL */
#include "DIO_Private.h"
#include "DIO_Confiq.h"

ES_t DIO_enu_Init   (void)
	{
		DIO_u8_DDRA_REG = CONC(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION,
							DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);

		DIO_u8_DDRB_REG = CONC(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION,
							DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);

		DIO_u8_DDRC_REG = CONC(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION,
							DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);

		DIO_u8_DDRD_REG = CONC(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION,
							DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);

		DIO_u8_PORTA_REG = CONC(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,
				DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);

		DIO_u8_PORTB_REG = CONC(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,
							DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);

		DIO_u8_PORTC_REG = CONC(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,
							DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);

		DIO_u8_PORTD_REG = CONC(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,
							DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);
	return STD_TYPES_OK;
	}

ES_t DIO_enu_SetPinDirection  (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 Copy_u8_PinDirection)
	{

		u8 Local_u8_ErrorState = STD_TYPES_OK;
		if((Copy_u8_PortId <= DIO_u8_PORTD) && (Copy_u8_PinId <= DIO_u8_PIN7) && ((Copy_u8_PinDirection == DIO_u8_OUTPUT)||(Copy_u8_PinDirection == DIO_u8_INPUT))){
			switch (Copy_u8_PortId)
			{
			case DIO_u8_PORTA:BIT_WRT(DIO_u8_DDRA_REG, Copy_u8_PinId, Copy_u8_PinDirection);break;
			case DIO_u8_PORTB:BIT_WRT(DIO_u8_DDRB_REG, Copy_u8_PinId, Copy_u8_PinDirection);break;
			case DIO_u8_PORTC:BIT_WRT(DIO_u8_DDRC_REG, Copy_u8_PinId, Copy_u8_PinDirection);break;
			case DIO_u8_PORTD:BIT_WRT(DIO_u8_DDRD_REG, Copy_u8_PinId, Copy_u8_PinDirection);break;
			}
		}
		else
		{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;
		}

ES_t DIO_enu_SetPinValue      (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 Copy_u8_PinValue)
	{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		if((Copy_u8_PortId <= DIO_u8_PORTD) && (Copy_u8_PinId <= DIO_u8_PIN7) && ((Copy_u8_PinValue == DIO_u8_HIGH)||(Copy_u8_PinValue == DIO_u8_LOW))){
			switch (Copy_u8_PortId)
			{
			case DIO_u8_PORTA:
				switch (Copy_u8_PinValue)
				{
					case DIO_u8_HIGH:BIT_SET(DIO_u8_PORTA_REG,Copy_u8_PinId); break;
					case DIO_u8_LOW : BIT_CLR(DIO_u8_PORTA_REG,Copy_u8_PinId); break;
				}
			break;
			case DIO_u8_PORTB:
				switch (Copy_u8_PinValue)
				{
					case DIO_u8_HIGH:BIT_SET(DIO_u8_PORTB_REG,Copy_u8_PinId); break;
					case DIO_u8_LOW : BIT_CLR(DIO_u8_PORTB_REG,Copy_u8_PinId); break;
				}
			break;
			case DIO_u8_PORTC:
				switch (Copy_u8_PinValue)
				{
					case DIO_u8_HIGH:BIT_SET(DIO_u8_PORTC_REG,Copy_u8_PinId); break;
					case DIO_u8_LOW : BIT_CLR(DIO_u8_PORTC_REG,Copy_u8_PinId); break;
				}
			break;
			case DIO_u8_PORTD:
				switch (Copy_u8_PinValue)
				{
					case DIO_u8_HIGH:BIT_SET(DIO_u8_PORTD_REG,Copy_u8_PinId); break;
					case DIO_u8_LOW : BIT_CLR(DIO_u8_PORTD_REG,Copy_u8_PinId); break;
				}
			break;
			}
		}
		else
		{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;

	}

ES_t DIO_enu_GetPinValue      (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinValue)
	{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		u8 Local_u8_PinValue ;
		if((Copy_u8_PortId <= DIO_u8_PORTD) && (Copy_u8_PinId <= DIO_u8_PIN7) && (Copy_pu8_ReturnPinValue != NULL))
		{
			switch (Copy_u8_PortId)
			{
				case DIO_u8_PORTA:		Local_u8_PinValue = BIT_GET(DIO_u8_PINA_REG,Copy_u8_PinId);
										if(Local_u8_PinValue == STD_TYPES_OK) {*Copy_pu8_ReturnPinValue = DIO_u8_LOW;}
										else {*Copy_pu8_ReturnPinValue = DIO_u8_HIGH;}
				break;
				case DIO_u8_PORTB:      Local_u8_PinValue = BIT_GET(DIO_u8_PINB_REG,Copy_u8_PinId);
										if(Local_u8_PinValue == STD_TYPES_OK) {*Copy_pu8_ReturnPinValue = DIO_u8_LOW;}
										else {*Copy_pu8_ReturnPinValue = DIO_u8_HIGH;}
				break;
				case DIO_u8_PORTC:      Local_u8_PinValue = BIT_GET(DIO_u8_PINC_REG,Copy_u8_PinId);
										if(Local_u8_PinValue == STD_TYPES_OK) {*Copy_pu8_ReturnPinValue = DIO_u8_LOW;}
										else {*Copy_pu8_ReturnPinValue = DIO_u8_HIGH;}
				break;
				case DIO_u8_PORTD:      Local_u8_PinValue = BIT_GET(DIO_u8_PIND_REG,Copy_u8_PinId);
										if(Local_u8_PinValue == STD_TYPES_OK) {*Copy_pu8_ReturnPinValue = DIO_u8_LOW;}
										else {*Copy_pu8_ReturnPinValue = DIO_u8_HIGH;}
				break;
			}
		}
		else
		{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;

	}

ES_t DIO_enu_GetPinDir        (u8 Copy_u8_PortId,u8 Copy_u8_PinId,u8 * Copy_pu8_ReturnPinDirection)
{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		u8 Local_u8_PinDirection;
		if((Copy_u8_PortId <= DIO_u8_PORTD) && (Copy_u8_PinId <= DIO_u8_PIN7) && (Copy_pu8_ReturnPinDirection != NULL))
		{
			switch (Copy_u8_PortId)
			{
				case DIO_u8_PORTA:		Local_u8_PinDirection = BIT_GET(DIO_u8_PINA_REG,Copy_u8_PinId);
										if(Local_u8_PinDirection == STD_TYPES_OK) {*Copy_pu8_ReturnPinDirection = DIO_u8_INPUT;}
										else {*Copy_pu8_ReturnPinDirection = DIO_u8_OUTPUT;}
				break;
				case DIO_u8_PORTB:      Local_u8_PinDirection = BIT_GET(DIO_u8_PINB_REG,Copy_u8_PinId);
										if(Local_u8_PinDirection == STD_TYPES_OK) {*Copy_pu8_ReturnPinDirection = DIO_u8_INPUT;}
										else {*Copy_pu8_ReturnPinDirection = DIO_u8_OUTPUT;}
				break;
				case DIO_u8_PORTC:      Local_u8_PinDirection = BIT_GET(DIO_u8_PINC_REG,Copy_u8_PinId);
										if(Local_u8_PinDirection == STD_TYPES_OK) {*Copy_pu8_ReturnPinDirection = DIO_u8_INPUT;}
										else {*Copy_pu8_ReturnPinDirection = DIO_u8_OUTPUT;}
				break;
				case DIO_u8_PORTD:      Local_u8_PinDirection = BIT_GET(DIO_u8_PIND_REG,Copy_u8_PinId);
										if(Local_u8_PinDirection == STD_TYPES_OK) {*Copy_pu8_ReturnPinDirection = DIO_u8_INPUT;}
										else {*Copy_pu8_ReturnPinDirection = DIO_u8_OUTPUT;}
				break;
			}
		}
		else
		{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;
}

ES_t DIO_enu_SetPortDirection (u8 Copy_u8_PortId,u8 Copy_u8_PortDirection)
	{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		if((Copy_u8_PortId <= DIO_u8_PORTD) &&((Copy_u8_PortDirection == DIO_u8_OUTPUT)||(Copy_u8_PortDirection == DIO_u8_INPUT))){
			switch (Copy_u8_PortId)
			{
			case DIO_u8_PORTA:
				switch (Copy_u8_PortDirection)
				{
				case DIO_u8_OUTPUT: DIO_u8_DDRA_REG = 0xff; break;
				case DIO_u8_INPUT : DIO_u8_DDRA_REG = 0x00; break;
				}
			break;
			case DIO_u8_PORTB:
				switch (Copy_u8_PortDirection)
					{
					case DIO_u8_OUTPUT: DIO_u8_DDRB_REG = 0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRB_REG = 0x00; break;
					}
			break;
			case DIO_u8_PORTC:
				switch (Copy_u8_PortDirection)
					{
					case DIO_u8_OUTPUT: DIO_u8_DDRC_REG = 0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRC_REG = 0x00; break;
					}
			break;
			case DIO_u8_PORTD:
				switch (Copy_u8_PortDirection)
					{
					case DIO_u8_OUTPUT: DIO_u8_DDRD_REG = 0xff; break;
					case DIO_u8_INPUT : DIO_u8_DDRD_REG = 0x00; break;
					}
			break;
			}
		}else{
			Local_u8_ErrorState = STD_TYPES_NOK;
			}
		return Local_u8_ErrorState;
	}

ES_t DIO_enu_SetPortValue     (u8 Copy_u8_PortId,u8 Copy_u8_PortValue)
	{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		if((Copy_u8_PortId <= DIO_u8_PORTD) &&((Copy_u8_PortValue == DIO_u8_HIGH)||(Copy_u8_PortValue == DIO_u8_LOW))){
			switch (Copy_u8_PortId)
			{
			case DIO_u8_PORTA:
				switch (Copy_u8_PortValue)
					{
					case DIO_u8_HIGH: DIO_u8_PORTA_REG = 0xff; break;
					case DIO_u8_LOW : DIO_u8_PORTA_REG = 0x00; break;
					}
			break;
			case DIO_u8_PORTB:
				switch (Copy_u8_PortValue)
					{
					case DIO_u8_HIGH: DIO_u8_PORTB_REG = 0xff; break;
					case DIO_u8_LOW : DIO_u8_PORTB_REG = 0x00; break;
					}
			break;
			case DIO_u8_PORTC:
				switch (Copy_u8_PortValue)
					{
					case DIO_u8_HIGH: DIO_u8_PORTC_REG = 0xff; break;
					case DIO_u8_LOW : DIO_u8_PORTC_REG = 0x00; break;
					}
			break;
			case DIO_u8_PORTD:
				switch (Copy_u8_PortValue)
					{
					case DIO_u8_HIGH: DIO_u8_PORTD_REG = 0xff; break;
					case DIO_u8_LOW : DIO_u8_PORTD_REG = 0x00; break;
					}
			break;
			}
		}else{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;
	}


ES_t DIO_enu_SetPortValue_v2(u8 Copy_u8_PortId, u8 Copy_u8_PortValue){
u8 Local_u8_ErrorState = STD_TYPES_OK;
	if((Copy_u8_PortId <= DIO_u8_PORTD)){
		switch (Copy_u8_PortId)
		{
		case DIO_u8_PORTA:DIO_u8_PORTA_REG = Copy_u8_PortValue; break;
		case DIO_u8_PORTB:DIO_u8_PORTB_REG = Copy_u8_PortValue; break;
		case DIO_u8_PORTC:DIO_u8_PORTC_REG = Copy_u8_PortValue; break;
		case DIO_u8_PORTD:DIO_u8_PORTD_REG = Copy_u8_PortValue; break;
		}
	}else{
		Local_u8_ErrorState = STD_TYPES_NOK;
	}
	return Local_u8_ErrorState;
}



ES_t DIO_enu_GetPortValue  (u8 Copy_u8_PortId,u8 * Copy_pu8_ReturnPortValue)
	{
		u8 Local_u8_ErrorState = STD_TYPES_OK;
		if((Copy_u8_PortId<= DIO_u8_PORTD) && (Copy_pu8_ReturnPortValue != NULL)){
			switch (Copy_u8_PortId)
			{
			case DIO_u8_PORTA: *Copy_pu8_ReturnPortValue = DIO_u8_PINA_REG;break;
			case DIO_u8_PORTB: *Copy_pu8_ReturnPortValue = DIO_u8_PINB_REG;break;
			case DIO_u8_PORTC: *Copy_pu8_ReturnPortValue = DIO_u8_PINC_REG;break;
			case DIO_u8_PORTD: *Copy_pu8_ReturnPortValue = DIO_u8_PIND_REG;break;
			}
		}
		else{
			Local_u8_ErrorState = STD_TYPES_NOK;
		}
		return Local_u8_ErrorState;

	}
