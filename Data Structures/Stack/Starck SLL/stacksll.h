#ifndef   	STACK_SINGLE_H_
#define 	STACK_SINGLE_H_

#include "STD_TYPES.h"
#define ok			1
#define nok			0
typedef struct node
{
	s32 info;
	struct node * link;
}node_t;



void Stack_Init(void);

u8 Stack_IsEmpty(void);

u32 Stack_GetSize(void);

u8 Stack_Push(s32 Data );

u8 Stack_Pop(s32 * DataPtr);

u8 Stack_Peek(s32 * DataPtr);

void Stack_Display(void);






#endif








