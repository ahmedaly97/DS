#include <stdio.h>


#include"queuearr.h"



int main()
{
	char Input;
	s32 InsertVal , DeleteVal ,PeekVal;
	u32 QueueSize;
	u8 Check ;
	
	Queue_Init();
	while(1)
	{
		printf("Press 1 to Insert\nPress 2 to Delete\nPress 3 to display\nPress 4 peek\nPress 5 to get size\nPress 6 to Exit\n");
		scanf(" %c" , &Input);
		switch(Input)
		{
			case '1':
				printf("Please enter the value to Insert : ");
				scanf ("%d" , &InsertVal);
				Queue_Insert(InsertVal);
				break;
			case '2':
				Check = Queue_Delete(&DeleteVal);
				if(Check == ok)
				{
					printf("The Deleted value is %d\n" , DeleteVal);
				}
				else
				{
					
				}
				break;
			case '3':
				Queue_Display();
				break;
			case '4':
				Check = Queue_Peek(&PeekVal);
				if(Check == ok)
				{
					printf("The peek value is %d\n" , PeekVal);
				}
				else
				{
					
				}
				break;
			case '5':
				QueueSize = Queue_GetSize();
				printf("The Queue size is %d\n" , QueueSize);
				break;
			case '6':
				break;
			default :
				printf("Wrong Number !!! Try again\n ");
				break;
		}
		if(Input == '6')
		{
			break;
		}
	}
	
	return 0;
}