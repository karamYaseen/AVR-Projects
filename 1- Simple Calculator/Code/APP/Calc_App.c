#include "../HAL/LCD/LCD_Interface.h"    // LCD interface header
#include "../HAL/KPD/Key_Interface.h"    // Keypad interface header
#include "../LIB/STD_TYPES.h"            // Standard types header

#include <util/delay.h>                  // Delay functions

// Function prototypes
void intToString(int num, char *str);   // Convert int to string
void setNum(int n);                     // Set current number
void clearCalculator();                 // Reset calculator state
void performOperation();                // Execute arithmetic operation
void takeUserOption(u8 *option);        // Get user input

// Global variables
u8 num1 = 0;                            // First operand
u8 num2 = 0;                            // Second operand
char operation = 0;                      // Selected operation (+, -, *, /)

int main() {
		// Initialize LCD and keypad
	    LCD_enu_Init_8bit_Mode();
	    LCD_enu_Clear();
	    KeyPad_enu_Init();

	    LCD_enu_WriteString("Hi There");     // Display welcome message
	    _delay_ms(150);                      // Delay for a short period
	    LCD_enu_Clear();
	    _delay_ms(5);
	    LCD_enu_WriteString("Simple Calc");
	    LCD_enu_GoToXY(1, 0);
	    LCD_enu_WriteString("BY K.A.Y");
	    _delay_ms(250);
	    LCD_enu_Clear();
    while (1) {
        u8 key;
        takeUserOption(&key);

        if (key != 0) {
            if (key >= '0' && key <= '9') {
                setNum(key - '0');        // Update entered number
                LCD_enu_WriteCharacter(key);

            } else if (key == '+' || key == '-' || key == '*' || key == '/') {
                operation = key;
                LCD_enu_WriteCharacter(' ');
                LCD_enu_WriteCharacter(key);
                LCD_enu_WriteCharacter(' ');

            } else if (key == '=') {
                performOperation();

            } else if (key == 'C') {
                clearCalculator();
            }
        }
    }

    return 0;
}

// Convert integer to string
void intToString(int num, char *str) {
    int i = 0;
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    while (num > 0) {
        int digit = num % 10;
        str[i++] = digit + '0';  // Convert digit to character and store
        num /= 10;
    }
    str[i] = '\0';

    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = temp;  // Reverse the string for correct representation
    }
}

// Set the current number being input
void setNum(int n) {
    if (operation == 0) {
        num1 = num1 * 10 + n;  // Update the first operand
    } else {
        num2 = num2 * 10 + n;  // Update the second operand
    }
}

// Clear calculator state
void clearCalculator() {
    num1 = 0;
    num2 = 0;
    operation = 0;
    LCD_enu_Clear();  // Clear the display
}

// Perform the selected arithmetic operation
void performOperation() {
    u8 result, N_flag = 0;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                LCD_enu_WriteString("division by zero!!");
                _delay_ms(50);
                LCD_enu_Clear();
                return;  // Prevent further processing on division by zero
            }
            break;
        case '-':
        	if (num1 >= num2) {
				result = num1 - num2;
			} else {
				N_flag = 1;
				result = num2 - num1;
			}
        	break;
        default:
            result = 0;
            break;
    }
    if(!N_flag){
    // Display result
    LCD_enu_Clear();
    LCD_enu_WriteString("Result: ");
    }else{
        LCD_enu_Clear();
        LCD_enu_WriteString("Result: -");
    }

    char buffer[16];
    intToString(result, buffer);
    LCD_enu_WriteString((u8 *)buffer);
    _delay_ms(100);

    // Reset for the next calculation
    num1 = result;
    num2 = 0;
    operation = 0;
}

// Get user input from the keypad
void takeUserOption(u8 *option) {
    while (1) {
        KPD_enu_GetKey(option);  // Get key from keypad
        if ((*option >= '0' && *option <= '9') || *option == '+' || *option == '-' || *option == '=' || *option == '*' || *option == '/' || *option == 'C')
            break;  // Break if a valid key is pressed
    }
}
