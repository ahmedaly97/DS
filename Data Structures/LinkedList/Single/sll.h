#ifndef singlelinkedlist_H_
#define singlelinkedlist_H_


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*******************************************************************
**   Structure Name : node										  **
**   Each node contains :										  **
**						 1- data part (content)     			  **
**     		       	  	 2- link part (pointer to the next node)  **
**   -> pointer Type : pointer to struct node                 	  **
**	 Created Object : node_t									  **
********************************************************************/

typedef struct node 
{
	int info;
	/*self refrential structure*/
	struct node * link;
	
}node_t;


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------------------------*/


void Print_single_list(node_t * start);

int Count_Nodes( node_t * start);

int Search_Nodes( node_t * start , int data);

node_t * Insert_at_beginning ( node_t * start , int data);

void Insert_at_end ( node_t * start , int data);

node_t * Create_single_list ( node_t * start );

void Insert_after(node_t* start, int after_val, int data);

node_t* Insert_before(node_t* start, int before_val, int data);

node_t* Insert_at_position(node_t* start, int pos, int data);

node_t* Delete_node (node_t* start , int data);

node_t * Reverse_list (node_t* start);

#endif






























