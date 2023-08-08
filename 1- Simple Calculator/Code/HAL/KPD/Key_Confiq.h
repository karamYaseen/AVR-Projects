
#ifndef KEY_CONFIG_H
#define KEY_CONFIG_H


/*  Options For     KPD_U8_R_PORT
				or	KPD_U8_C_PORT :         1-DIO_u8_PORTA 
                                            2-DIO_u8_PORTB
                                            3-DIO_u8_PORTC
                                            4-DIO_u8_PORTD

    Options For     KPD_U8_R1_PIN 
                Or  KPD_U8_R2_PIN
                Or  KPD_U8_R3_PIN 
                Or  KPD_U8_R4_PIN 
                Or  KPD_U8_C1_PIN 
                Or  KPD_U8_C2_PIN 
                Or  KPD_U8_C3_PIN 
                Or  KPD_U8_C4_PIN  :        0-DIO_u8_PIN0
                                            1-DIO_u8_PIN1
                                            2-DIO_u8_PIN2
                                            3-DIO_u8_PIN3
                                            4-DIO_u8_PIN4
                                            5-DIO_u8_PIN5
                                            6-DIO_u8_PIN6
                                            7-DIO_u8_PIN7

*/




#define KEY_KEYS              		{{'7', '8', '9', '/'},\
									{'4', '5', '6', '*'},\
									{'1', '2', '3', '-'},\
									{'C', '0', '=', '+'}}

#define  KPD_U8_R_PORT           DIO_u8_PORTC
#define  KPD_U8_C_PORT           DIO_u8_PORTC

#define  KPD_U8_R1_PIN           DIO_u8_PIN3
#define  KPD_U8_R2_PIN           DIO_u8_PIN2
#define  KPD_U8_R3_PIN           DIO_u8_PIN1
#define  KPD_U8_R4_PIN           DIO_u8_PIN0

#define  KPD_U8_C1_PIN           DIO_u8_PIN7
#define  KPD_U8_C2_PIN           DIO_u8_PIN6
#define  KPD_U8_C3_PIN           DIO_u8_PIN5
#define  KPD_U8_C4_PIN           DIO_u8_PIN4

#define KPD_U8_UNPRESED         0xff

#endif
