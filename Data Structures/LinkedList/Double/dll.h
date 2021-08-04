#ifndef  DLL_H_
#define  DLL_H_


typedef struct node{
	
	struct node * prev;
	int info;
	struct node * next;
	
	
}dnode_t;


void Print_double_list(dnode_t * start);

dnode_t * InsertAtBeginning(dnode_t* start , int data);

dnode_t* InsertInEmpty(dnode_t* start , int data);

void InsertAtEnd (dnode_t* start , int data);

dnode_t* CreateList(dnode_t* start);

void CountNodes(dnode_t* start);

int SearchNode(dnode_t* start , int data );

void InsertAfter(dnode_t* start, int afterval , int data);

dnode_t* InsertBefore(dnode_t* start, int afterval , int data);

dnode_t* InsertAtPosition(dnode_t* start , int pos , int data);

dnode_t* DeleteNode(dnode_t* start , int data);

dnode_t* ReveerseDoubleList(dnode_t* start);

#endif