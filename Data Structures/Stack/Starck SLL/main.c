/*********************************************************************/
/*********************************************************************/
/************       A program to deal with various   	  ************/         
/*************     		Stack sll  Functions     	  	  ************/ 
/*********************************************************************/
/*********************************************************************/
#include<stdio.h>
#include"stacksll.h"
#include "STD_TYPES.h"

int main()
{
	s32 select , PushVal , PopVal,PeekVal,StackSize ,Check;
	
	Stack_Init();
	
	printf("________________________________________________________________\n");
	printf("1-Push\n2-pop \n3-stack display\n4-peek \n5-get size\n6-Exit\n");
	printf("_________________________________________________________________\n");
	
		
	
		while(1)
		{

				printf("\nEnter the selector : ");
				scanf("%d",&select);
			switch(select)
			{
		
				case 1 : 
						printf("Please enter the value to push : ");
						scanf ("%d" ,&PushVal);
						Stack_Push(PushVal);
						break;
						
						
				case 2 : 
						Check = Stack_Pop(&PopVal);
						if(Check == ok)
						{
							printf("The popped value is %d\n" ,PopVal);
						}
						else
						{
							
						}
						break;
		
				case 3 :
						Stack_Display();
						break;
				
				
				case 4 :
						Check = Stack_Peek(&PeekVal);
						if(Check == ok)
						{
							printf("The peek value is %d\n" , PeekVal);
						}
						else
						{
						 
						}
						break;
						
				case 5 :
						StackSize = Stack_GetSize();
						printf("The stack size is %d\n" , StackSize);
						break;
				
				case 6 :
					break;
			
			}
	
		}
		



}