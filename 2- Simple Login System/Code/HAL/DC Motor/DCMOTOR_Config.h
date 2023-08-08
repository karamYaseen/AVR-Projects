/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  DC_MOTOR       **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/


#ifndef DCMOTOR_Config_H_
#define DCMOTOR_Config_H_
/*  Options For     DCM_U8_PORT         :   1-DIO_u8_PORTA
                                            2-DIO_u8_PORTB
                                            3-DIO_u8_PORTC
                                            4-DIO_u8_PORTD

    Options For     DCM_U8_PIN0 
                Or  DCM_U8_PIN1
                Or  DCM_U8_PINE         :   0-DIO_u8_PIN0
                                            1-DIO_u8_PIN1
                                            2-DIO_u8_PIN2
                                            3-DIO_u8_PIN3
                                            4-DIO_u8_PIN4
                                            5-DIO_u8_PIN5
                                            6-DIO_u8_PIN6
                                            7-DIO_u8_PIN7
*/

#define DCM_U8_PORT				DIO_u8_PORTD

#define DCM_U8_PIN0				DIO_u8_PIN0
#define DCM_U8_PIN1				DIO_u8_PIN1
#define DCM_U8_PINE				DIO_u8_PIN2

#define CCW                     1
#define CW                      0

#endif
