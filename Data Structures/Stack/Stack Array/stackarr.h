#ifndef STACKARR_H_
#define STACKARR_H_

#define ok			1
#define nok		    0


#include "STD_TYPES.h"

void Stack_Init(void);

u8 Stack_IsEmpty(void);

u8 Stack_IsFull(void);

u32 Stack_GetSize(void);

u8 Stack_Push(s32 Data );

u8 Stack_Pop(s32 * DataPtr);

u8 Stack_Peek(s32 * DataPtr);

void Stack_Display(void);


#endif