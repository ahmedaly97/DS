#ifndef CIRCULARLINKEDLIST_H_
#define CIRCULARLINKEDLIST_H_


typedef struct node{
	
	int info ; 
	struct node * link; 
	
}cnode_t;


void DisplayCircularList(cnode_t* last);

cnode_t* InsertInEmpty(cnode_t* last , int data);

void InsertAtBeginning(cnode_t* last , int data);

cnode_t* CreateList(cnode_t* last);

cnode_t* InsertAtEnd(cnode_t* last , int data);

cnode_t* InsertAfter(cnode_t* last, int afterdata , int data);

void CountNodes(cnode_t* last);

int SearchNodes(cnode_t* last, int data);

void InsertBefore(cnode_t* last, int beforedata , int data);

cnode_t* DeleteNode(cnode_t* last , int data);



#endif