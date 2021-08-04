#include <stdio.h>
#include"queuearr.h"

#define max 50

static s32 arr[max];
static s32 front;
static s32 rear;

void Queue_Init(void)
{
	front=-1;
	rear = -1;
}


u8 Queue_IsEmpty(void)
{
	
	if(front == -1 )
	{
		return  1;
	}
	else if( front == rear+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

u8 Queue_IsFull(void)
{
	if(rear == max-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

u32 Queue_GetSize(void)
{
	return ((rear-front)+1);
}


u8 Queue_Insert(s32 data)
{
	u8 error_state = ok ;
	
	if(Queue_IsFull())
	{
		printf("Queue Is Full !!\n");
		error_state = nok;
		
	}
	else
	{
		/*check if it is the first insertion */
		if(front == -1)
		{
			rear=rear+1;
			front = front+1;
			
			arr[rear]=data;
		}
		else
		{
			/*not the first insertion */
			
			rear=rear+1;
			arr[rear]=data;
		}
		printf("Insertion is done Successfully\n");
		
	}
	
	return error_state;

}


u8 Queue_Delete(s32* data_ptr)
{
	u8 error_state =ok;
	
	
	if(Queue_IsEmpty())
	{
		printf("Queue is empty !!!\n");
		error_state = nok;
	}
	else if(data_ptr ==NULL)
	{
		error_state=nok;
	}
	else
	{
		*data_ptr =arr[front];
		front=front+1;
		printf("Deletion Is Done successfully\n");
		
	}
	
	return error_state;
	
}



u8 Queue_Peek(s32* data_ptr)
{
	u8 error_state =ok;
	
	
	if(Queue_IsEmpty())
	{
		printf("Queue is empty !!!\n");
		error_state = nok;
	}
	else if(data_ptr ==NULL)
	{
		error_state=nok;
	}
	else
	{
		*data_ptr =arr[front];
		
	}
	return error_state;
}


void Queue_Display(void)
{
	s32 i=0;
	
	if(Queue_IsEmpty())
	{
		printf("The Queue is Empty !!!\n");
	}
	else
	{
		printf("The Queue IS : \n");
		
		for(i=front ; i<=rear ; i++)
		{
			
			printf("%d ",arr[i]);
		}
		
		printf("\n");
	
	}
}




















