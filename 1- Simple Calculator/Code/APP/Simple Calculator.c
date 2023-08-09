/*********************************************************************************************/
/*************************** Name     :  Karam Yaseen   **************************************/
/*************************** Data     :  9/8/2023       **************************************/
/*************************** SWC      :  Simple Calculator  **********************************/
/*************************** E_Mail   :  karamyaseen725@gmail.com    *************************/
/*************************** version  :  1.0            **************************************/
/*********************************************************************************************/

#include 					"../HAL/KPD/Key_Interface.h"
#include 					"../HAL/LCD/LCD_Interface.h"
#include 					"util/delay.h"

#define IP_INIT 			'#'
#define IP_CACHE_SZ 		16
#define MAX_UINT32 			4294967296UL  // Maximum value of an unsigned 32-bit integer

// Function prototypes
void takeUserOption			(u8 *option) ;
void GetInput				(u8 *Copy_Au8_IpCharacter, u8 Copy_u8_IpCharacterSize) ;
void Perform_Calculations	(u8 *Copy_Au8_IpCharacter, u8 Copy_u8_IpCharacterSize, f32 *Copy_pf32_Result) ;
void Display_Result			(f32 *Copy_pf32_Result) ;

int main() {
    // Initialize LCD and Keypad
    u8 Local_u8InputCache[IP_CACHE_SZ] = { IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT, IP_INIT };
    f32 Local_f32Result = 0;

    LCD_enu_Init_8bit_Mode();
    KeyPad_enu_Init();

    // Display welcome messages
    LCD_enu_WriteString("Hi There");
    _delay_ms(150);
    LCD_enu_Clear();
    _delay_ms(5);
    LCD_enu_WriteString("Simple Calc");
    LCD_enu_GoToXY(1, 0);
    LCD_enu_WriteString("BY K.A.Y");
    _delay_ms(250);
    LCD_enu_Clear();


    // Main loop
    while (1) {
       GetInput(Local_u8InputCache, IP_CACHE_SZ);
       Perform_Calculations(Local_u8InputCache, IP_CACHE_SZ, &Local_f32Result);
       Display_Result(&Local_f32Result);
    }
    return 0;
}

/*
 * --------------------------------------------------------------------------------------------
 *                                      Function Definitions
 * --------------------------------------------------------------------------------------------
 */

// Function to get user input from keypad
void takeUserOption(u8 *option) {
    while (1) {
        KPD_enu_GetKey(option);  // Get key from keypad
        if ((*option >= '0' && *option <= '9') || *option == '+' || *option == '-' || *option == '=' || *option == '*' || *option == '/' || *option == 'C')
            break;  // Break if a valid key is pressed
    }
}

// Function to get user input and display it on LCD
void GetInput(u8 *Copy_Au8_IpCharacter, u8 Copy_u8_IpCharacterSize) {

    s8 Local_s8_Iterator = 0;
    u8 Local_u8_PressedKeyValue = 0;

    while (Local_s8_Iterator < Copy_u8_IpCharacterSize) {
        do {
            takeUserOption(&Local_u8_PressedKeyValue);
        } while (Local_u8_PressedKeyValue == 0);

        // Clear display if it's the first input
        if (Copy_Au8_IpCharacter[0] == '#') {
            LCD_enu_Clear();
        }

        // Display the input and store it
        if (Local_u8_PressedKeyValue != KPD_U8_UNPRESED ) {
            Copy_Au8_IpCharacter[Local_s8_Iterator] = Local_u8_PressedKeyValue;
            LCD_enu_WriteCharacter(Copy_Au8_IpCharacter[Local_s8_Iterator]);
        }

        // Break if '=' key is pressed
        if (Local_u8_PressedKeyValue == '=') {
            break;
        }

        Local_s8_Iterator++;

        // Clear input cache if 'C' key is pressed
        if (Local_u8_PressedKeyValue == 'C') {
            LCD_enu_Clear();
            for (Local_s8_Iterator = 0; Local_s8_Iterator < 16; Local_s8_Iterator++) {
                Copy_Au8_IpCharacter[Local_s8_Iterator] = '$';
            }
            Local_s8_Iterator = 0;
        }
    }
}

// Function to perform calculations based on user input
void Perform_Calculations(u8 *Copy_Au8_IpCharacter, u8 Copy_u8_IpCharacterSize, f32 *Copy_pf32_Result) {

    // Initialize variables

    u16 Local_u16_Operand = 0;
    s8 Local_s8_Iterator  = 0;
    u8 Local_u8_Operation = 0;
    *Copy_pf32_Result     = 0;

    while (Local_s8_Iterator < Copy_u8_IpCharacterSize && Copy_Au8_IpCharacter[Local_s8_Iterator] != '$') {
        // Process numeric input
        if (Copy_Au8_IpCharacter[Local_s8_Iterator] >= '0' && Copy_Au8_IpCharacter[Local_s8_Iterator] <= '9') {
            Local_u16_Operand = Local_u16_Operand * 10;
            Local_u16_Operand = Local_u16_Operand + (u16)(Copy_Au8_IpCharacter[Local_s8_Iterator] - '0');
        }

        // Process operation input
        if (Copy_Au8_IpCharacter[Local_s8_Iterator] == '/' || Copy_Au8_IpCharacter[Local_s8_Iterator] == '*' || Copy_Au8_IpCharacter[Local_s8_Iterator] == '+' || Copy_Au8_IpCharacter[Local_s8_Iterator] == '-' || Copy_Au8_IpCharacter[Local_s8_Iterator] == '=') {
            if (*Copy_pf32_Result == 0) {
                *Copy_pf32_Result = Local_u16_Operand;
            } else {
                switch (Local_u8_Operation) {
                    case '/':
                    	if (Local_u16_Operand != 0) {
                        *Copy_pf32_Result = *Copy_pf32_Result / Local_u16_Operand;
                        } else {
                            LCD_enu_Clear();
                        	LCD_enu_WriteString("division by zero!!");
                        	LCD_enu_GoToXY(1,0);
                        	LCD_enu_WriteString("Error");
                            _delay_ms(50);
                            LCD_enu_Clear();
                            *Copy_pf32_Result = 0;
                            return ;
                        	}
                    	break;
                    case '*':
                        *Copy_pf32_Result = *Copy_pf32_Result * Local_u16_Operand;
                        break;
                    case '+':
                        *Copy_pf32_Result = *Copy_pf32_Result + Local_u16_Operand;
                        break;
                    case '-':
                        *Copy_pf32_Result = *Copy_pf32_Result - Local_u16_Operand;
                        break;
                }
            }

            Local_u16_Operand = 0;
            Local_u8_Operation = Copy_Au8_IpCharacter[Local_s8_Iterator];
        }

        // Process result calculation
        if (Copy_Au8_IpCharacter[Local_s8_Iterator] == '=') {
            switch (Local_u8_Operation) {
                case '/':
                	if (Local_u16_Operand != 0) {
						*Copy_pf32_Result = *Copy_pf32_Result / Local_u16_Operand;
					} else {
						LCD_enu_Clear();
						LCD_enu_WriteString("division by zero!!");
						LCD_enu_GoToXY(1,0);
						LCD_enu_WriteString("Error");
						_delay_ms(150);
						*Copy_pf32_Result = 0;
						return ;
						}
				    break;
                case '*':
                    *Copy_pf32_Result = *Copy_pf32_Result * Local_u16_Operand;
                    break;
                case '+':
                    *Copy_pf32_Result = *Copy_pf32_Result + Local_u16_Operand;
                    break;
                case '-':
                    *Copy_pf32_Result = *Copy_pf32_Result - Local_u16_Operand;
                    break;
            }
        }

        Local_s8_Iterator++;
    }

    // Clear input cache
    for (Local_s8_Iterator = 0; Local_s8_Iterator < 16; Local_s8_Iterator++) {
        Copy_Au8_IpCharacter[Local_s8_Iterator] = '$';
    }
}

// Function to display calculation result on LCD
void Display_Result(f32 *Copy_pf32_Result) {
    u32 Local_u32_ResultSplit;
    LCD_enu_GoToXY(1, 0);

    // Display the result
    if (*Copy_pf32_Result < 0) {

    	LCD_enu_WriteString("Result: ");
        LCD_enu_WriteCharacter('-');
        *Copy_pf32_Result = MAX_UINT32 - (u32)*Copy_pf32_Result;
        LCD_enu_WriteNumber((u32)*Copy_pf32_Result);

    } else {

    	Local_u32_ResultSplit = (u32)*Copy_pf32_Result;
        Local_u32_ResultSplit = (*Copy_pf32_Result - Local_u32_ResultSplit) * 10;
        LCD_enu_WriteString("Result: ");
        LCD_enu_WriteNumber((u32)*Copy_pf32_Result);

        // Display decimal part if exists
        if (Local_u32_ResultSplit > 0) {
            LCD_enu_WriteCharacter('.');
            LCD_enu_WriteNumber(Local_u32_ResultSplit);
        }
    }
}
