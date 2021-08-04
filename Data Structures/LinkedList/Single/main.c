/*********************************************************************/
/*********************************************************************/
/************       A program to deal with various   	  ************/         
/*************      Single Linked List Functions     	  ************/ 
/*********************************************************************/
/*********************************************************************/
#include<stdio.h>
#include"sll.h"
#include"help.h"

int main()
{
	int select , data , val , pos;
	
	/*important to initialize it with null*/
	node_t * start =NULL ;
	
	printf("________________________________________________________________\n");
	printf("1-Insert at the beginning\n2-Insert at end \n3-Count Nodes\n4-Search for node value\n5-Insert After\n6-Insert before\n7-Insert at position\n\
8-Delete node\n9Reverse list\n");
	printf("_________________________________________________________________\n");
	
	printf("You need to Create List !!\n");
	start = Create_single_list(start);
	Print_single_list(start);
	
	
	
	printf("\nEnter the selector : ");
	scanf("%d",&select);
	
	switch(select)
	{
		
		case 1 : 
				printf("You choosed Insert at the beginning!!\n");
				printf("enter the data you need to insert : ");
				scanf("%d",&data);
				start=Insert_at_beginning (start ,data);
				Print_single_list(start);
				break;
				
				
		case 2 : 
				printf("You choosed Insert at end !!\n");
				printf("enter the data you need to insert : ");
				scanf("%d",&data);
				Insert_at_end (start ,data);
				Print_single_list(start);
				break;

		case 3 :
				printf("You choosed Count Nodes !!\n");
			    Count_Nodes(start);
				break;
		
		
		case 4 :
				printf("You choosed Search Node!!\n");
				printf("enter the data you need to search for : ");
				scanf("%d",&data);
				Search_Nodes(start ,data);
				break;
				
		case 5 :
				printf("You choosed Insert after value !!\n");
				printf("enter the value after which you need to insert : ");
				scanf("%d",&val);
				printf("enter data to insert in the new node : ");
				scanf("%d",&data);
				Insert_after(start,val,data);
				Print_single_list(start);
				break;
				
		case 6 :
				printf("You choosed Insert before value !!\n");
				printf("enter the value before which you need to insert : ");
				scanf("%d",&val);
				printf("enter data to insert in the new node : ");
				scanf("%d",&data);
				/*new start must be received */
				start=Insert_before(start,val,data);
				Print_single_list(start);
				break;	

		case 7 :
				printf("You choosed Insert at position !!\n");
				printf("enter the position at which you need to insert:  ");
				scanf("%d",&pos);
				printf("enter data to insert in the new node : ");
				scanf("%d",&data);
				/*new start must be received */
				start=Insert_at_position(start,pos, data);
				Print_single_list(start);
				break;
				
			
				
		case 8 :
				printf("You choosed Delete data in a certain anode !!\n");
				printf("enter the data u need to delete:  ");
				scanf("%d",&data);
				/*new start must be received */
				start=Delete_node ( start , data);
				Print_single_list(start);
				break;			
		
		case 9 :
				printf("You choosed Reverse a list !!\n");
				/*new start must be received */
				start=Reverse_list (start);
				Print_single_list(start);
				break;	
		
	}
	
	
	
	
}