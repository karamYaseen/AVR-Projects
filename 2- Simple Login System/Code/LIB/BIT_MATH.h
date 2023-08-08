#ifndef BIT_MATH_H
#define BIT_MATH_H



//  WRT_BIT is to assign 1 or 0 to  a specific bit in a register
//  while maintaining all the bits' value as it is.
//  Steps:
// 		1- Clear the specific bit you want to write on
// 		2- Insert the new value you want to write

#define BIT_WRT(REG, BIT, VAL)       ( (REG) = ( ( (REG) & (~(1<<(BIT))) ) | ( (VAL) << (BIT)  ) ) )

#define BIT_SET(REG, BIT_NUM)  		 ( (REG) |=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '1'    */
#define BIT_CLR(REG, BIT_NUM)   	 ( (REG) &= (~(1 << ((BIT_NUM)))) ) /* Sets the bits as '0'    */
#define BIT_TOG(REG, BIT_NUM)   	 ( (REG) ^=   (1 << ((BIT_NUM)))  ) /* Sets the bits as '~BIT' */
#define BIT_GET(REG, BIT_NUM)   	 ( (REG)  &   (1 << (BIT_NUM))    ) /* Reads the bit  		   */



#define MASK_BIT                     1
#define SHIFT_0BIT                  0
#define SHIFT_1BIT                  1
#define SHIFT_2BIT                  2
#define SHIFT_3BIT                  3
#define SHIFT_4BIT                  4
#define SHIFT_5BIT                  5
#define SHIFT_6BIT                  6
#define SHIFT_7BIT                  7

#endif
