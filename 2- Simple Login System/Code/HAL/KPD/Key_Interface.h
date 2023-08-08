#ifndef KEY_INTERFACE_H
#define KEY_INTERFACE_H

#define KPD_U8_UNPRESED         0xff

#include "../../lib/STD_TYPES.h"
#include "../../lib/Error_State.h"


ES_t KPD_enu_GetKey(u8 *Copy_pu8_ReturnKey);
ES_t KeyPad_enu_Init(void);

#endif
