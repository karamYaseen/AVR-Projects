/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  STEPPER_MOTOR  **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/
#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "../../lib/STD_TYPES.h"
#include "../../lib/Error_State.h"


ES_t StepperMotor_enu_Init                           (void);
ES_t StepperMotor_enu_Move                           (u16 Copy_u16_STeeperangle, u8 Copy_u8_STeeperdirection) ;
ES_t Stepper_enu_Stop                                (void);

#endif /* INTERFACE_H_ */
