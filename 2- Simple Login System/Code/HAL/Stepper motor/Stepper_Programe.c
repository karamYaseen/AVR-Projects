/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  STEPPER_MOTOR  **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/
#include "../../LIB/Error_State.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "Stepper_Config.h"
#include "Stepper_Privite.h"

#include <util/delay.h>

ES_t StepperMotor_enu_Init  (void) {
    // Set the pins as output
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT,IN1_PIN,DIO_u8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT,IN2_PIN,DIO_u8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT,IN3_PIN,DIO_u8_OUTPUT);
    DIO_enu_SetPinDirection(STEPPER_MOTOR_PORT,IN4_PIN,DIO_u8_OUTPUT);

    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN1_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN2_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN3_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN4_PIN,DIO_u8_LOW);

    return STD_TYPES_OK;
}
ES_t StepperMotor_enu_Move(u16 Copy_u16_STeeperangle, u8 Copy_u8_STeeperdirection) {
	 u8 Local_u8_errorState = STD_TYPES_OK;
	    if ((Copy_u8_STeeperdirection == STEPPER_Rotate_CW || Copy_u8_STeeperdirection == STEPPER_Rotate_CCW) && (Copy_u16_STeeperangle >= 0 && Copy_u16_STeeperangle <= 360))
	    {
	        u8 Local_u8_STeeperState = MOTOR_PINS_STATE; // 0000 1111
	        u16 Local_u16_STeeperSteps = Copy_u16_STeeperangle / STEP_ANGLE;
	        if (Copy_u8_STeeperdirection == STEPPER_Rotate_CW)
	        {
	            for (u8 Local_u8_Iterator = 0; Local_u8_Iterator < Local_u16_STeeperSteps; Local_u8_Iterator++)
	            {
	            	Local_u8_STeeperState &=  3<<(Local_u8_Iterator%NUM_OF_STEPS);
	                if((Local_u8_Iterator%NUM_OF_STEPS) == 3) Local_u8_STeeperState = EDGE_STATE;
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN4_PIN, (Local_u8_STeeperState>>SHIFT_0BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN3_PIN, (Local_u8_STeeperState>>SHIFT_1BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN2_PIN, (Local_u8_STeeperState>>SHIFT_2BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN1_PIN, (Local_u8_STeeperState>>SHIFT_3BIT)&MASK_BIT);
	                _delay_ms(100);
	                Local_u8_STeeperState = 0x0F;
	            }
	        }
	        else if (Copy_u8_STeeperdirection == STEPPER_Rotate_CCW)
	        {
	            for (u8 Local_u8_Iterator = 0; Local_u8_Iterator < Local_u16_STeeperSteps; Local_u8_Iterator++)
	            {
	            	Local_u8_STeeperState &=  3<<(Local_u8_Iterator%NUM_OF_STEPS);
	                if((Local_u8_Iterator%NUM_OF_STEPS) == 3) Local_u8_STeeperState = EDGE_STATE;
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN4_PIN, (Local_u8_STeeperState>>SHIFT_0BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN3_PIN, (Local_u8_STeeperState>>SHIFT_1BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN2_PIN, (Local_u8_STeeperState>>SHIFT_2BIT)&MASK_BIT);
	                DIO_enu_SetPinValue(STEPPER_MOTOR_PORT, IN1_PIN, (Local_u8_STeeperState>>SHIFT_3BIT)&MASK_BIT);
	                _delay_ms(100);
	                Local_u8_STeeperState = 0x0F;
	            }
	        }
	    }else
	    {
	        Local_u8_errorState = STD_TYPES_NOK;
	    }
	    return Local_u8_errorState;
	}
ES_t Stepper_enu_Stop  (void) {
	StepperMotor_enu_Move(STEPPER_Rotate_CCW,STEP0);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN1_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN2_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN3_PIN,DIO_u8_LOW);
    DIO_enu_SetPinValue(STEPPER_MOTOR_PORT,IN4_PIN,DIO_u8_LOW);

    return STD_TYPES_OK;
}
