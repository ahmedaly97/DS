#include<stdio.h>
#include<stdlib.h>
#include "sll.h"
#include"help.h"


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
** Print List : A function that			  							**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**    Returns:													  	**
**  		  Nothing  												**
**	 																**
**********************************************************************/

void Print_single_list(node_t * start)
{
	/*checking if the list is empty*/
	if(start == NULL)
	{
		printf("The list is Empty !!\n");
	}
	else
	{
		/*creating a pointer to traverse the list through*/
		node_t* ptr = start; 	
		
		printf("\nThe List : \n");
		while(ptr != NULL)
		{
			/*print the content of each node*/
			printf("%d\t",ptr->info);
			
			/*traverse*/
			ptr=ptr->link;
		}
	}
	printf("\n");
	
	
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Count Nodes in a List Function : A function that 			  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			Number of nodes contaained in the list			  **
**	 															  **
********************************************************************/


int Count_Nodes( node_t * start)
{
	/*As we want to keep the start pointer pointing at first 
	  We created another pointer (ptr) , initialized it with start*/
	node_t *ptr = start;
	
	/*counter initialized by zero to store the number of nodes*/
	int  ctr=0;
	
	/*loop until ptr points to the last node , after last node , ptr= NULL*/
	while(ptr != NULL)
	{
		/*increment the counter by 1*/
		ctr++;
		
		/*traverse through the pointer to the next node */
		ptr = ptr->link ;
		
	}
	
	
	printf("Number of nodes is %d\n",ctr);
	
   /*the function returns integer value denoting the number of nodes*/ 
   return ctr ;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Search Node a List Function : A function that 				  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**              2- Data                                           **
**      Returns:												  **
**  			Position of the node at which the data exists	  **
**	 															  **
********************************************************************/



int Search_Nodes( node_t * start , int data)
{
	
	/*As we want to keep the start pointer pointing at first 
	  We created another pointer (ptr) , initialized it with start*/
	node_t *ptr = start;
	
	/*integer variable to store the position*/
	int pos=1;
	
	/*loop until ptr points to the last node , after last node , ptr= NULL*/
	while(ptr != NULL)
	{
		/*check on the info of each node*/
		if(ptr->info == data)
		{
			break;	
		}
		else
		{
			/*Traverse throught the ptr to the next node*/
			ptr=ptr->link;
			
			/*increment the position by 1*/
			pos++;
		}
		
		
	}
	
	/* after traversing through all the list , check */
	/* the loop finished because of the breaking condition*/
	if(ptr == NULL)
	{
		printf("%d Not Found in the list !!",data);
		
		/*give pos an invalid value */
		pos=-1;
	}
	else
	{
		/* The value is found , the loop is terminated because of the break statement*/
		
		printf("%d is found at position: %d\n",data,pos);
		
	}
	return pos ;
	
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

node_t * Insert_at_beginning ( node_t * start , int data)
{
	
	/*create new node , receive malloc return address in temp poiner(pointer to the new node)*/
	node_t * temp =(node_t*) malloc(sizeof(node_t));
	
	/*assign the data into info part*/
	temp->info = data ;
	
	/*rearranging links*/
	temp->link = start;
	
	/*update start*/
	start=temp;
	
	/*return new start*/
	return start ;
	
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  Insert Node at the end of a List : A function that		 	  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**              2- Data to be inserted in the new inserted node   **
**      Returns:												  **
**  			nothing									  		  **
**	 															  **
********************************************************************/

void Insert_at_end( node_t * start , int data)
{
	node_t* ptr=start;
	
	/*Alocate an  new node*/
	node_t* temp = (node_t*) malloc(sizeof(node_t));
	
	/*Initialize new node info*/
	temp->info = data;
	
	while(ptr->link !=NULL)
	{
		ptr= ptr->link;
	}
	/*Make the last node point to temp*/
	ptr->link = temp;
	
	/*Make temp point to null*/
	temp->link = NULL;
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**  create a single linked List : A function that			 	  **
**  	Takes  :												  **
**	 			1- pointer to the first node (called : start)	  **
**      Returns:												  **
**  			pointer to the starting node of the created list  **
**	 															  **
********************************************************************/


node_t * Create_single_list ( node_t * start )
{
	/*declare some variables*/
	int i , data ,n ;
	
	
	/*As we want to keep the start pointer pointing at first 
	  We created another pointer (ptr) , initialized it with start*/
	node_t *ptr = start;
	

	
	printf("Enter the number of nodes you need : ");
	scanf("%d",&n);
	
	if(n>0)
	{
		
		printf("enter the value of node 1 : ");
		scanf("%d",&data);
		start= Insert_at_beginning(start , data);
		
		for(i=1 ; i<n ; i++)
		{
			printf("enter the value of node %d : ",i+1);
			scanf("%d",&data);
			Insert_at_end(start,data);
			
		}
		
	}
	else
	{
		printf("\nNumber of nodes must be positive\n");
	}
	
	return start ;
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Insert after a node in a List : A function that			 	  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- afterval(the value after which we need to insert new node **
**	   3- the data to be inserted in the new created node			**
**      Returns:												  	**
**  			nothing											  	**
**	 															  	**
**********************************************************************/

void Insert_after(node_t* start, int after_val, int data)
{
	
	
	/*As we want to keep the start pointer pointing at first 
	  We created another pointer (ptr) , initialized it with start*/
	
	node_t *ptr = start;
	
	/*getting to the end of the list*/
	while(ptr != NULL)
	{
		/*check for the afterval*/
		if(ptr->info == after_val)
		{
			/*exit the loop if the after val is found*/
			break;
		}			
		else
		{
			/*traverse*/
			ptr=ptr->link;
		}
	
	}
	/* check for the reason that terminated the loop*/
	/*1- the loop is terminated as the end of the list is reached without finding afterval */
	if(ptr == NULL)
	{
		printf("\n%d not found in the list",after_val);
	}
	else
	{
		/*2-the loop is terminted due to break statement,the afterval is found*/
		
		/*create a new node , receive its address in temp pointer*/
		node_t * temp = (node_t*)malloc(sizeof(node_t));
		
		/*assign the data in the new node*/
		temp->info = data;
		
		/*rearrnge the links after inserting the new node*/
		temp->link = ptr ->link;  
		ptr->link  = temp ;
		
		/*last 2 statements can't be replaced by each other as the order is important
		  to keep linking to the nodes after the node we search for 
		  
		  --> dont overwrite ptr->link unless u save it in temp->link*/
		
	}
	
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Insert before a node in a List : A function that			  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- afterval(the value after which we need to insert new node **
**	   3- the data to be inserted in the new created node			**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**	 	(start may be updated in case of inserting before first)	**
**********************************************************************/

node_t* Insert_before(node_t* start, int before_val, int data)
{
	node_t* ptr =start;
	/*check if the given start is empty */
	if(start == NULL)
	{
		printf("The list is empty, There is no value to insert before");
		return start;
		
	}
	/*Check if the value to insert before is the first*/
	 else if(start->info==before_val)
	{
		
		start= Insert_at_beginning(start , data);
		
	}
	else
	{
		/*the goal is to find a pointer to the node after which we will insert a new node */
		/*getting to the end of the list*/
		while (ptr->link != NULL)
		{
			
			if(ptr->link->info == before_val)
			{
				break;
			}
			else
			{
				ptr=ptr->link;
			}
		}
		
		/* check for the reason that terminated the loop*/
		/*1- the loop is terminated as the end of the list is reached without finding afterval */
		if(ptr == NULL)
		{
			printf("\n%d not found in the list",before_val);
			
		}
		else
		{
			/*2-the loop is terminted due to break statement,the before val is found*/
		
			/*create a new node , receive its address in temp pointer*/
			node_t * temp = (node_t*)malloc(sizeof(node_t));
		
			/*assign the data in the new node*/
			temp->info = data;
			
			/*rearranging the linkages*/
			temp->link = ptr->link ; 
			ptr->link = temp;

		}
	
	}
	
	return start ;
	
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Insert before a node in a List : A function that			  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- position at which we need to insert new node 				**
**	   3- the data to be inserted in the new created node			**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**	(start may be updated in case of insert at the first position)	**
**********************************************************************/



node_t* Insert_at_position(node_t* start, int pos, int data)
{
	
	int  i ; 

	node_t * ptr = start ;
	
	/*checking if  the needed position is the first position*/
	if(pos == 1)
	{
		/*calling insert at beginning function*/
		start=Insert_at_beginning(start ,data);
		return start ; 
	}
	
	/*getting the ptr pointing at th node that is before the position we need to insert in*/
	for( i =1 ; i< (pos-1) && (ptr!= NULL) ; i++)
	{	
		ptr=ptr->link ; 
	}
	
	
	/*checking for the reason that terminated the loop */
	if(ptr == NULL)
	{
		printf("The position is not found in the list !! \n");
	}
	else
	{
		/*the loop is terminated due to the ptr is pointing at the previous node to the needed position*/
		node_t* temp = (node_t*)malloc(sizeof(node_t));
		temp->info = data ;
		temp->link = ptr->link;
		ptr->link = temp ;
		
		
	}
	
	return start ;
	
}



/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*********************************************************************
**  Delete  node in a List : A function that					  	**
**    Takes  :												 	    **
**	   1- pointer to the first node (called : start)				**
**	   2- position at which we need to insert new node 				**
**	   3- the data to be inserted in the new created node			**
**    Returns:													  	**
**  			pointer to the starting node					  	**
**	(start may be updated in case of delete  the first position)	**
**********************************************************************/

node_t* Delete_node (node_t* start , int data)
{
	if(start== NULL)
	{
		printf("The list is empty , nothing can be deleted !!");
	}
	
	node_t * temp ;
	node_t * ptr  ;
		
		
	/*delete the only node or the first node*/
	if(start->info == data)
	{
		temp=start;
		start= temp->link;
		free(temp);	
	}

	
	/*delete in between nodes or the last node*/
	else
	{
		/*initialize the ptr  with start*/
		ptr= start;
		
		while(ptr->link != NULL)
		{
			/*we need to get a ptr to the previous node to be deleted*/
			if(ptr->link->info == data)
			{
				break;
			}
			else
			{
				/*traverse*/
				ptr=ptr->link;
			}
		}
		/*checking for the reason that terminated the loop*/
		/* 1- ptr reached the end of the end ? */
		if(ptr->link == NULL)
		{
			printf("\n%dNot Found int he list !!",data);
		}
		/*2- the loop is terminated de to break statement*/
		else
		{
			/* as the ptr is pointing to the node that is previous to the needed node
			   we assign the node to be deleted to temp pointer */
			temp=ptr->link;
			
			/*making short circuit over the temp (deleted node)*/
			ptr->link=temp->link;
			
			/* delete the temp  */
			free(temp);
		}
		
	}
	
	return start ;
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

node_t * Reverse_list (node_t* start)
{
	
	node_t * ptr  = start;
	node_t * prev = NULL;
	node_t * next ;
	
	while(ptr != NULL)
	{
		/*reverse links*/
		next=ptr->link;
		ptr->link=prev;
		
		/*update pointers to reverse linkages of the next node*/
		prev=ptr;
		ptr=next;
		
	}
	/*update the start*/
	start=prev;
	
	/*return start*/
	return start;
}































































































