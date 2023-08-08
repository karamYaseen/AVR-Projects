#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KPD/Key_Interface.h"
#include "../HAL/DC Motor/DCMOTOR_Interface.h"
#include "../HAL/Stepper motor/Stepper_interface.h"

#include <util/delay.h>

#define PASSWORD_LENGTH       4
#define CORRECT_PASSWORD      "1234"
#define MAX_TRYS              3

int main()
{
    DIO_enu_Init();
    KeyPad_enu_Init();
    LCD_enu_Init_8bit_Mode();
    StepperMotor_enu_Init();

    LCD_enu_WriteString("Enter Password:");
    LCD_enu_GoToXY(1, 0);

    char Local_Achar_enteredPassword[PASSWORD_LENGTH + 1] = {0};
    u8 Local_u8_passwordIndex = 0;
    u8 Local_u8_numoftry = 0;

    while (1)
    {
        u8 Local_u8_key;
        KPD_enu_GetKey(&Local_u8_key);

        // If a key is pressed
        if (Local_u8_key != KPD_U8_UNPRESED)
        {
            // Check if it is a valid number key (0-9)
            if (Local_u8_key >= '0' && Local_u8_key <= '9')
            {
                Local_Achar_enteredPassword[Local_u8_passwordIndex] = Local_u8_key;
                LCD_enu_WriteCharacter('*');
                Local_u8_passwordIndex++;
                if (Local_u8_passwordIndex == PASSWORD_LENGTH)
                {
                    u8 Local_u8_isPasswordCorrect = 1;
                    for (u8 i = 0; i < PASSWORD_LENGTH; i++)
                    {
                        if (Local_Achar_enteredPassword[i] != CORRECT_PASSWORD[i])
                        {
                            Local_u8_isPasswordCorrect = 0;
                            break;
                        }
                    }

                    if (Local_u8_isPasswordCorrect)
                    {
                        LCD_enu_Clear();
                        LCD_enu_WriteString("Correct Password");
                        _delay_ms(100);
                        LCD_enu_Clear();
                        LCD_enu_WriteString("WELCOME");
                        _delay_ms(100);
                        LCD_enu_Clear();
                        LCD_enu_WriteString("Choose Option");
                        _delay_ms(100);
                        LCD_enu_Clear();
					    LCD_enu_WriteString("1:DC  2:Stepper");
					    LCD_enu_GoToXY(1, 0);
					    LCD_enu_WriteString("   3:EXIT   ");
						_delay_ms(100);
						u8 Local_u8_key2 ;
						takeUserOption_1(&Local_u8_key2);
					    switch(Local_u8_key2){
					    case '1':
							// User chose DC motor control
					    	ControlDCMotor();
							break;
						case '2':
							// User chose stepper motor control
							ControlStepperMotor();
							break;
						case '3':
	                        LCD_enu_Clear();
	                        LCD_enu_WriteString("CLosed");
							break;
						default:
							// Invalid option, display an error message
	                        LCD_enu_Clear();
							LCD_enu_WriteString("Invalid Option");
							_delay_ms(1000);
							break;
					      }

                        Local_u8_numoftry = 0;
                        Local_u8_passwordIndex = 0;
                        for (u8 i = 0; i < PASSWORD_LENGTH + 1; i++)
                        {
                            Local_Achar_enteredPassword[i] = 0;
                        }
                    }
                    else
                    {
                        LCD_enu_Clear();
                        LCD_enu_WriteString(" Incorrect ");
                        LCD_enu_GoToXY(1, 0);
                        LCD_enu_WriteString(" Password!!");
                        Local_u8_numoftry++;
                        Local_u8_passwordIndex = 0;
                        for (u8 i = 0; i < PASSWORD_LENGTH + 1; i++)
                        {
                            Local_Achar_enteredPassword[i] = 0;
                        }
                    }
                    if (Local_u8_numoftry >= MAX_TRYS)
                    {
                        LCD_enu_Clear();
                        LCD_enu_WriteString("CLosed");
                        break;
                    }
                    _delay_ms(1000);
                    LCD_enu_Clear();
                    LCD_enu_WriteString("Enter Password:");
                    LCD_enu_GoToXY(1, 0);
                }
            }else{
                LCD_enu_WriteString("Wrong Input");
                _delay_ms(1000);
                 }
        }
    }

    return 0;
}

void takeUserOption_1(u8 *option)
{
    while (1)
    {
        KPD_enu_GetKey(option);
        if (*option == '1' || *option == '2' || *option == '3' || *option == 'C')
            break;
    }
}

u8 KPD_enu_GetNumberInput()
{
    u8 inputLength = 0;
    u8 digits[3] = {0}; // Array to store the digits of the number

    while (inputLength < 3)
    {
        u8 key = KPD_U8_UNPRESED;
        while (key == KPD_U8_UNPRESED)
        {
            KPD_enu_GetKey(&key);
        }

        if (key >= '0' && key <= '9')
        {
            digits[inputLength] = key - '0'; // Convert ASCII digit to numerical digit
            inputLength++;
        }
    }

    // Convert the digits array into an integer
    u16 result = digits[0] * 100 + digits[1] * 10 + digits[2];
    return result;
}

void ControlDCMotor()
{
    LCD_enu_Clear();
    LCD_enu_WriteString("1: CW  2: CCW");
    u8 Local_u8_key;
    takeUserOption_1(&Local_u8_key);

    if (Local_u8_key == '1')
    {
        // Clockwise rotation
        LCD_enu_Clear();
        LCD_enu_WriteString(" CW ");
        DC_Motor_enu_Rotate(1);
        while (1)
        {
            u8 Local_u8_key3;
            takeUserOption_1(&Local_u8_key3);
            if (Local_u8_key3 == 'C')
            {
                LCD_enu_Clear();
                DC_Motor_enu_Stop();
                break;
            }
        }
    }
    else if (Local_u8_key == '2')
    {
        // Counterclockwise rotation
        LCD_enu_Clear();
        LCD_enu_WriteString(" CCW ");
        DC_Motor_enu_Rotate(0);
        while (1)
        {
            u8 Local_u8_key3;
            takeUserOption_1(&Local_u8_key3);
            if (Local_u8_key3 == 'C')
            {
                LCD_enu_Clear();
                DC_Motor_enu_Stop();
                break;
            }
        }
    }
    else
    {
        LCD_enu_Clear();
        LCD_enu_WriteString("Invalid Direction");
        _delay_ms(1000);
    }
}

void ControlStepperMotor()
{
    LCD_enu_Clear();
    LCD_enu_WriteString("1: CW  2: CCW");
    u8 Local_u8_key;
    takeUserOption_1(&Local_u8_key);

    if (Local_u8_key == '1')
    {
        // Clockwise rotation
        LCD_enu_Clear();
        LCD_enu_WriteString("Angel: in (3DIG) ");
        LCD_enu_GoToXY(1, 0);
        LCD_enu_WriteString("EX: 090 ");
        u8 Local_u8_Angle = KPD_enu_GetNumberInput();
        _delay_ms(100);
        LCD_enu_Clear();
        LCD_enu_WriteString("Angle is :");
        LCD_enu_GoToXY(1, 0);
        LCD_enu_WriteNumber(Local_u8_Angle);
        StepperMotor_enu_Move(Local_u8_Angle, 1);

        while (1)
        {
            u8 Local_u8_key3;
            takeUserOption_1(&Local_u8_key3);

            if (Local_u8_key3 == 'C')
            {
                LCD_enu_Clear();
                Stepper_enu_Stop();
                break;
            }
        }
    }
    else if (Local_u8_key == '2')
    {
        // Counterclockwise rotation
        LCD_enu_Clear();
        LCD_enu_WriteString("Angel: in (3DIG) ");
        LCD_enu_GoToXY(1, 0);
        LCD_enu_WriteString("EX: 090 ");
        u8 Local_u8_Angle = KPD_enu_GetNumberInput();
        _delay_ms(100);
        LCD_enu_Clear();
        LCD_enu_WriteString("Angle is :");
        LCD_enu_GoToXY(1, 0);
        LCD_enu_WriteNumber(Local_u8_Angle);
        StepperMotor_enu_Move(Local_u8_Angle, 0);

        while (1)
        {
            u8 Local_u8_key3;
            takeUserOption_1(&Local_u8_key3);

            if (Local_u8_key3 == 'C')
            {
                LCD_enu_Clear();
                Stepper_enu_Stop();
                break;
            }
        }
    }
    else
    {
        LCD_enu_Clear();
        LCD_enu_WriteString("Invalid Direction");
        _delay_ms(1000);
    }
}
