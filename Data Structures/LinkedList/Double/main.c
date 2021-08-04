/*********************************************************************/
/*********************************************************************/
/************       A program to deal with various   	  ************/         
/*************      Double Linked List Functions     	  ************/ 
/*********************************************************************/
/*********************************************************************/
#include<stdio.h>
#include"dll.h"


int main()
{
	int select , data , val , pos;
	
	/*important to initialize it with null*/
	dnode_t * start =NULL ;
	
	printf("________________________________________________________________\n");
	printf("1-Insert at the beginning\n2-Insert at end \n3-Count Nodes\n4-Search for node value\n5-Insert After\n6-Insert before\n7-Insert at position\n\
8-Delete node\n9Reverse list\n");
	printf("_________________________________________________________________\n");
	
	printf("You need to Create List !!\n");
	start= CreateList(start);
	Print_double_list(start);
	
	
	
	int tests=10;
	while (tests > 0)
	{
		
		printf("\nEnter the selector : ");
		scanf("%d",&select);
		
		switch(select)
		{
		
				case 1 : 
						printf("You choosed Insert at the beginning!!\n");
						printf("enter the data you need to insert : ");
						scanf("%d",&data);
						start=InsertAtBeginning(start , data);
						Print_double_list(start);
						break;
						
						
				case 2 : 
						printf("You choosed Insert at end !!\n");
						printf("enter the data you need to insert : ");
						scanf("%d",&data);
						InsertAtEnd (start ,data);
						Print_double_list(start);
						break;
		
				case 3 :
						printf("You choosed Count Nodes !!\n");
						CountNodes(start);
						break;
				
				
				case 4 :
						printf("You choosed Search Node!!\n");
						printf("enter the data you need to search for : ");
						scanf("%d",&data);
						SearchNode(start ,data);
						break;
						
				case 5 :
						printf("You choosed Insert after value !!\n");
						printf("enter the value after which you need to insert : ");
						scanf("%d",&val);
						printf("enter data to insert in the new node : ");
						scanf("%d",&data);
						InsertAfter(start,val ,data);
						Print_double_list(start);
						break;
				
				case 6 :
						printf("You choosed Insert before value !!\n");
						printf("enter the value before which you need to insert : ");
						scanf("%d",&val);
						printf("enter data to insert in the new node : ");
						scanf("%d",&data);
						//new start must be received 
						start=InsertBefore(start , data , val);
						Print_double_list(start);
						break;	
				
				case 7 :
						printf("You choosed Insert at position !!\n");
						printf("enter the position at which you need to insert:  ");
						scanf("%d",&pos);
						printf("enter data to insert in the new node : ");
						scanf("%d",&data);
						//new start must be received 
						start=InsertAtPosition( start, pos ,data);
						Print_double_list(start);
						break;
						
			    
				
				case 8 :
						printf("You choosed Delete data in a certain anode !!\n");
						printf("enter the data u need to delete:  ");
						scanf("%d",&data);
						//new start must be received 
						start = DeleteNode(start ,data);
						Print_double_list(start);
						break;			
				
				case 9 :
						printf("You choosed Reverse a list !!\n");
						//new start must be received 
						start=ReveerseDoubleList(start);
						Print_double_list(start);
						break;	
		}
	
	
	
	tests --;
	}



}