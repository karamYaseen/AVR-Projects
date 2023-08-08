/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  4/5/2023       **************************************/
/*************************** SWC      :  LCD            **************************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#ifndef LCD_Private_H
#define LCD_Private_H

/*Deprecated definitions*/


#define LCD_ENTRY_MODE                        0x06
#define LCD_DISPLAY_CONTROL                   0x0f
#define LCD_FUNCTION_SET_8BIT_MODE            0x38
#define LCD_CLEAR_SCREEN                      0x01

#define LCD_DISPLAY_OFF                       0x08
#define LCD_DISPLAY_ON                        0x0C

#define LCD_HOME                              0x02
#define LCD_FUNCTION_SET_4BIT_MODE            0x28
#define SHIFT_4BIT                            4


#define ADDRESS_OF_CGRAM                      0x40
#define LCD_4BIT_INIT1                        0x33
#define LCD_4BIT_INIT1                        0x32
#define LCD_u8_CHAR0                          0
#define LCD_u8_CHAR1                          1
#define LCD_u8_CHAR2                          2
#define LCD_u8_CHAR3                          3
#define LCD_u8_CHAR4                          4
#define LCD_u8_CHAR5                          5
#define LCD_u8_CHAR6                          6
#define LCD_u8_CHAR7                          7


#define LCD_u8_LINE0                          0
#define LCD_u8_LINE1                          1
#define ADDRESS_OF_LINE1                      0xc0
#define ADDRESS_OF_LINE0                      0x80

#define MAX_LOCATION                          39
#define MAX_CHAR                              8
#define ROWS_NUMBER                           2

#define CHAR_0                                0
#define CHAR_1                                1
#define CHAR_2                                2
#define CHAR_3                                3
#define CHAR_4                                4
#define CHAR_5                                5
#define CHAR_6                                6
#define CHAR_7                                7


#endif
