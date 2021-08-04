#ifndef   	QUEUE_SLL_H_
#define 	QUEUE_SLL_H_



#include "STD_TYPES.h"

#define ok			1
#define nok			0



void Queue_Init(void);

u8 Queue_IsEmpty(void);

u32 Queue_GetSize(void);

u8 Queue_Insert(s32 data);

u8 Queue_Delete(s32 * data_ptr);

u8 Queue_Peek(s32 * data_ptr);

void Queue_Display(void);


#endif