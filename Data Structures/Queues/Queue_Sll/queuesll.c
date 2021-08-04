#include <stdio.h>
#include <stdlib.h>
#include "Queuesll.h"

#include "STD_TYPES.h"

typedef struct node
{
	s32 info;
	struct node* link;
	
}node_t;

static node_t * front;
static node_t * rear;


void Queue_Init(void)
{
	front = NULL;
	rear =  NULL;
}

u8 Queue_IsEmpty(void)
{
	
	if(front == NULL)
	{
		return 1;
	}
	else
	{
		return 0 ;
	}

}

u32 Queue_GetSize(void)
{
	node_t * ptr = front;
	u32 count=0;
	
	while(ptr != NULL)
	{
		count++;
		ptr= ptr->link;
	}
	return count;
}


u8 Queue_Insert(s32 data)
{
	u8 error_state = ok;
	
	node_t* temp =(node_t*)malloc(sizeof(node_t));
	if(temp == NULL)
	{
		printf("The heap is full , can't allocate!!\n ");
		error_state = nok;
	}
	else
	{
		
		
		/*insert in empty*/
		if(front == NULL)
		{
			temp->info =data;
			temp->link=NULL;
			
			front=temp;
			rear=temp;
		}
		else
		{
			temp->info =data;
			
			rear->link=temp;
			rear=temp;
			
			temp->link=NULL;
			
		}
		printf("Innsertion is done successfully\n");
	}
	
	return error_state;
	
}



u8 Queue_Delete(s32* data_ptr)
{
	u8 error_state =ok;
	
	node_t* temp;
	
	if(Queue_IsEmpty())
	{
		printf("Queue is empty \n");
		error_state =nok;
	}
	else if(data_ptr == NULL)
	{
		error_state=nok;
	}
	else
	{
		temp=front;
		*data_ptr=temp->info;
		front=front->link;
		free(temp);
		printf("deletion is done successfully\n");
	}
	return error_state;
	
}


u8 Queue_Peek(s32* data_ptr)
{
	u8 error_state =ok;
	
	node_t* temp;
	
	if(Queue_IsEmpty())
	{
		printf("Queue is empty \n");
		error_state =nok;
	}
	else if(data_ptr == NULL)
	{
		error_state=nok;
	}
	else
	{
		
		*data_ptr=temp->info;
	}
	return error_state;
	
}




void Queue_Display(void)
{
	
	node_t* ptr =front;
	
	if(Queue_IsEmpty())
	{
		
		printf("The Queue IS Empty\n");
	}
	else
	{ 
		printf("The Queue Is : \n");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->info);
			ptr=ptr->link;
		}		
		printf("\n");
	}
	
	
	
	
}




























