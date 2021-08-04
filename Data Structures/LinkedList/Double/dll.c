#include<stdio.h>
#include<stdlib.h>
#include"dll.h"



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Print the double linked list List : A function that 		  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			Nothing									  		  **
**	 															  **
********************************************************************/

void Print_double_list(dnode_t * start)
{
	dnode_t * ptr = start;
	
	if(start == NULL)
	{
		printf("Thel list is empty");
	}
	
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->info);
		
		ptr=ptr->next;
	}
	printf("\n");
	
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Insert Node at the beginning of a List : A function that 	  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**              2- Data to be inserted in the new inserted node   **
**      Returns:												  **
**  			Pointer to the new start of the list	  		  **
**	 															  **
********************************************************************/


dnode_t * InsertAtBeginning(dnode_t* start , int data)
{
	/*creating a pointer to hold the address of the new node*/
	dnode_t* temp;
	
	/*allocating a new node in heap memory*/
	temp=(dnode_t*)malloc(sizeof(dnode_t));
	
	/*assinging the passed data in the info part of the new node*/
	temp->info = data;
	
	/*allocating the temp in the beginning of the list */
	temp->next=start;
	
	/*As temp is the first node its prev should point to null*/
	temp->prev = NULL;
	
	/*As temp is the first node , so start should point at temp*/
	start=temp;
	
	/*return the new start which is the address of the new node (temp) */
	return start;
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Insert Node in an empty List : A function that			 	  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**              2- Data to be inserted in the new inserted node   **
**      Returns:												  **
**  			Pointer to the new start of the list	  		  **
**	 															  **
********************************************************************/

dnode_t* InsertInEmpty(dnode_t* start , int data)
{
	
	/*creating a pointer to hold the address of the new node*/
	dnode_t* temp;
	
	/*allocating a new node in heap memory*/
	temp=(dnode_t*)malloc(sizeof(dnode_t));
	
	/*assinging the passed data in the info part of the new node*/
	temp->info = data;
	
	/*As temp is the first node its next should point to null*/
	temp->next=NULL;
	
	/*As temp is the first node its prev should point to null*/
	temp->prev = NULL;
	
	/*As temp is the only node , so start should point at temp*/
	start=temp;
	
	/*return the new start which is the address of the new and the only node (temp) */
	return start;
}






/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Insert At end  double linked list  : A function that 		  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			Nothing									  		  **
**	 															  **
********************************************************************/

void InsertAtEnd (dnode_t* start , int data)
{
	dnode_t* temp = (dnode_t*)malloc(sizeof(dnode_t));
	dnode_t* ptr = start;
	
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
		
	}

	temp->info=data;
	
	ptr->next =temp;
	temp->prev=ptr;
	temp->next=NULL;

}



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
** Create Double Linked List : A function that				 	  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			Pointer to the  start of the list	  			  **
**	 															  **
********************************************************************/


dnode_t* CreateList(dnode_t* start)
{
	dnode_t* ptr= start;
	
	int n, var , i;
	
	printf("please enter number of nodes: ");
	scanf("%d",&n);
	
	if( n>0)
	{
		printf("enter the value of node 1 : ");
		scanf("%d",&var);
		start=InsertInEmpty(start, var);
		
		for(i=1 ; i<n ; i++)
		{
			printf("enter the value of node %d : ", i+1);
			scanf("%d",&var);
			InsertAtEnd(start, var);
			
		}
		
	}
	else
	{
		printf("Invalid Number of nodes , Must be positive \n");
	}
	
	return start;
	
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
** Count Nodes in a  Double Linked List : A function that		  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			nothing (prints number of nodes)	  			  **
**	 															  **
********************************************************************/

void CountNodes(dnode_t* start)
{
	dnode_t* ptr = start;
	int ctr=0;
	
	
	while( ptr != NULL)
	{
		ctr++;
		ptr=ptr->next;
		
	}
	
	printf("The nuumber of nodes is : %d", ctr);

}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
** Search for a node  in a  Double Linked List : A function that  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)     **
**				2- Data to search for 							  **
**      Returns:												  **
**  			The position at which the data exists	  		  **
**	 															  **
********************************************************************/

int SearchNode(dnode_t* start , int data )
{
	int pos=1;
	
	dnode_t* ptr =start;
	
	while(ptr != NULL)
	{
		if(ptr->info == data)
		{
			break;
		}
		else
		{
			pos++;
			ptr=ptr->next;
		}
		
		
	}
	
	if(ptr == NULL)
	{
		printf("%d is not fount in the list!! \n");
	}
	else
	{
		printf("%d is found at position: %d\n",data,pos);
	}
		
	
	
	return pos ;
}





/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
** Insert node after a certain node in a D L L : A function that  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)     **
**				2- Data to be inserted							  **	
**				3- the afterdata	 							  **
**      Returns:												  **
**  			Nothing									  		  **
**	 															  **
********************************************************************/



void InsertAfter(dnode_t* start, int afterval , int data)
{
	dnode_t *ptr = start; 


	while(ptr != NULL)
	{
		if(ptr->info == afterval)
		{
			break;
		}
		else
		{
			ptr=ptr->next;
		}
		
	}
	if(ptr == NULL)
	{
		printf("\n%d is not found !!\n",afterval);
	}
	else
	{
		dnode_t *temp = (dnode_t*)malloc(sizeof(dnode_t));
		temp->info = data;
		temp->next = ptr->next;
		temp->prev = ptr;	
		ptr->next  = temp;
	}

}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
** Insert node before a certain node in a D L L : A function that **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)     **
**				2- Data to be inserted							  **	
**				3- the beforedata	 							  **
**      Returns:												  **
**  			start of the list								  **
**	(start may be updated in case of inserting before first)	  **
********************************************************************/

dnode_t* InsertBefore( dnode_t* start , int data , int beforeval)
{
	
	dnode_t*ptr=start;
	
	if(start ==NULL)
	{
		printf("\nThe list is Empty\n");
	}
	else if(start->info == beforeval)
	{
		start=InsertAtBeginning(start,data);
		
	}
	else
	{
		while(ptr->next != NULL)
		{
			if(ptr->next->info == beforeval)
			{
				break;
			}
			else
			{
				ptr=ptr->next;
			}				
		}
		
		
		if(ptr->next == NULL )
		{
			printf("\n%d is not found in the list !!",beforeval);
		}
		else
		{
			dnode_t *temp = (dnode_t*)malloc(sizeof(dnode_t));
			temp->info = data;
			temp->next= ptr->next;
			temp->prev=ptr;
			ptr->next = temp;
			
		
			
		}
		
	}
	return start;
	
}



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Insert before a node in a DLL : A function that		     	  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- position at which we need to insert new node 				**
**	   3- the data to be inserted in the new created node			**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**	(start may be updated in case of insert at the first position)	**
**********************************************************************/

dnode_t* InsertAtPosition(dnode_t* start , int pos , int data)
{
	
	dnode_t*ptr=start;
	
	if(pos == 1)
	{
		start=InsertAtBeginning(start, data);
	}
	else
	{
		int i;
		
		for(i=1 ; i<(pos-1)&&(ptr!=NULL) ; i++ )
		{
			ptr=ptr->next;
		}
		
		if(ptr==NULL)
		{
			printf("\nthis %d is not found\n",pos);
		}
		else
		{
			dnode_t* temp = (dnode_t*)malloc(sizeof(dnode_t));
			
			temp->info=data;
			
			temp->next=ptr->next;
			
			ptr->next->prev=temp;			
			ptr->next = temp;
			temp->prev=ptr;
			

		}
		
	}
	return start;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Delete  node in a List : A function that					  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- Datat to be deleted										**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**	(start may be updated in case of delete  the first position)	**
**********************************************************************/


dnode_t* DeleteNode(dnode_t* start , int data)
{
	dnode_t* temp,*ptr;
	
	if(start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	
	/*delete the only node ?*/
	if((start->next == NULL)&& (start->info==data))
	{
		
		temp=start;
		start =NULL;
		free(temp);
		return start;
	}
	
	/*delete the 1st node ?*/
	if(start->info==data)
	{
		temp=start;
		start=temp->next;
		start->prev=NULL;
		free(temp);
		return start;
	}	
	
	/*delete in between or the last node*/
	temp=start->next;
	
	while(temp->next != NULL)
	{
		if(temp->info == data)
		{
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	/*delete in between */
	if(temp->next !=NULL)
	{
		temp->prev->next = temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}
	/*delete the last node*/
	else
	{
		if(temp->info == data)
		{
			temp->prev->next=NULL;
			free(temp);
		}
		else
		{
			printf("\nNot Found\n");
		}
		
	}
	return start;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**   Reverse  List : A function that					  			**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**																	**
**********************************************************************/


dnode_t* ReveerseDoubleList(dnode_t* start)
{
	dnode_t   *p1, *p2 , temp;
	
	
	p1=start;
	p2=p1->next;
	
	p1->next=NULL;
	p1->prev = p2;
	
	
	while(p2 != NULL)
	{
		
		p2->prev = p2->next;
		p2->next=p1;
		/*move on */
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	return start;
}





