#include <stdio.h>
#include <stdlib.h>
#include "stacksll.h"

#include "STD_TYPES.h"

static node_t* top;


void Stack_Init(void)
{
	
	top=NULL;
}


u8 Stack_IsEmpty(void)
{
	if(top == NULL)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}


u32 Stack_GetSize(void)
{
	node_t* ptr=top;
	u32 ctr=0;
	while(ptr != NULL)
	{
		ctr++;
		ptr=ptr->link;
	}
	return ctr;
}




u8 Stack_Push(s32 data)
{
	u8 error_state = ok;
	
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	
	if(temp == NULL)
	{
		printf("No Heap Memory to allocatee your data");
		error_state = nok ;
	}
	else
	{
		temp->info =data;
		temp->link = top;
		top = temp;
		
		printf("Pushing operation is done successfully\n");
	}
	
	return error_state;
	
}


u8 Stack_Pop(s32 * data_ptr)
{
	u8 error_state = ok ; 
	
	if(Stack_IsEmpty())
	{
		printf("The Stack is Empty !!! , pop will result underflow\n");
		
		error_state = nok;
	}
	else if (data_ptr == NULL)
	{
		error_state = nok;
	}
	else
	{
		node_t* temp;
		
		*data_ptr = top->info;
		
		temp = top ;
		top=top->link;
		
		free(temp);
		printf("Poping is Done successfully\n\n");
	}
	
	return error_state;
}


u8 Stack_Peek(s32 * data_ptr)
{
	u8 error_state = ok ; 
	
	if(Stack_IsEmpty())
	{
		printf("The Stack is Empty !!! , pop will result underflow\n");
		
		error_state = nok;
	}
	else if (data_ptr == NULL)
	{
		error_state = nok;
	}
	else
	{
		node_t* temp;
		
		*data_ptr = top->info;
		
	}
	
	return error_state;
	
}



void Stack_Display(void)
{
	node_t* ptr =top;
	if(Stack_IsEmpty())
	{
		printf("The Stack is Empty !!!\n");
		
	
	}
	else
	{
		printf("The Stack is :\n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->info);
			ptr=ptr->link;
		}
		printf("\n");
	}
}




































