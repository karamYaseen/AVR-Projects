/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  STEPPER_MOTOR  **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#ifndef CONFIG_H_
#define CONFIG_H_
/*  Options For     STEPPER_MOTOR_PORT  :   1-DIO_u8_PORTA
                                            2-DIO_u8_PORTB
                                            3-DIO_u8_PORTC
                                            4-DIO_u8_PORTD
    Options For     IN1_PIN 
                Or  IN2_PIN
                Or  IN3_PIN
                Or  IN4_PIN             :   0-DIO_u8_PIN0
                                            1-DIO_u8_PIN1
                                            2-DIO_u8_PIN2
                                            3-DIO_u8_PIN3
                                            4-DIO_u8_PIN4
                                            5-DIO_u8_PIN5
                                            6-DIO_u8_PIN6
                                            7-DIO_u8_PIN7

*/

#define F_CPU                   8000000UL

#define STEPPER_MOTOR_PORT      DIO_u8_PORTD

#define IN1_PIN                  DIO_u8_PIN3
#define IN2_PIN                  DIO_u8_PIN4
#define IN3_PIN                  DIO_u8_PIN5
#define IN4_PIN                  DIO_u8_PIN6

#define STEP_ANGLE               45

#endif /* CONFIG_H_ */
