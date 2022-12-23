#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Self referential structure to create node.
typedef struct tmp
{
	int 	item;
	struct tmp *  next;
}Node;


//structure for create linked list.
typedef struct
{
	Node * head;
	Node * tail;

}List;

//Initialize List
void initList(List * lp)
{
	lp->head = NULL;
	lp->tail = NULL;
}

//Create node and return reference of it.
Node * createNode(int item)
{
	Node * nNode;

	nNode = (Node *) malloc(sizeof(Node));

	nNode->item = item;
	nNode->next = NULL;

	return nNode;
}


//Add new item at the end of list.
void addAtTail(List * lp,int item)
{
	Node * node;
	node = createNode(item);

	//if list is empty.
	if(lp->head == NULL)
	{
		lp->head = node;
		lp->tail = node;
	}
	else
	{
		lp->tail->next  = node;
		lp->tail 	= lp->tail->next;
	}		
}

//Delete item from the end of list.
int delFromTail(List * lp)
{
	Node * temp;
	int i = 0;

	int item = 0;


	if(lp->tail == NULL)
	{	
		printf("\nList is Empty ..."); 	
		return -1;
	}
	else
	{
		temp = lp->head;

		while(temp->next != lp->tail)
		{ temp = temp->next;}

		item = lp->tail->item;

		lp->tail = temp; 
		lp->tail->next = NULL;		
	}	

	return item;
}

//Add new item at begning of the list.
void addAtHead(List * lp,int item)
{
	Node * node;
	node = createNode(item);

	//if list is empty.
	if(lp->head == NULL)
	{
		lp->head = node;
		lp->tail = node;
	}
	else
	{
		node->next 	= lp->head	;
		lp->head 	= node		;
	}		
}

//Delete item from Start of list.
int delFromHead(List * lp)
{
	int item = 0;

	if(lp->head == NULL)
	{	
		printf("\nList is Empty ..."); 	
		return -1;
	}
	else
	{
		item = lp->head->item;
		lp->head = lp->head->next;		
	}	

	return item;
}

//To print list from start to end of the list.
void printList(List *lp)
{
	Node * node;

	if(lp->head == NULL)
	{
		printf("\nEmpty List");
		return;
	}
	
	node = lp->head;

	printf("\nList: \n\n\t"); 
	while(node != NULL)
	{
		printf("| %05d |",node->item);
		node = node->next;

		if(node !=NULL)
			printf("--->");
	}
	printf("\n\n");
}

void Enqueue(List *lp, int value) {
    Node *node;
    node = createNode(value);

    if(lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    } else {
        lp->tail->next = node;
        lp->tail = lp->tail->next;
    }
}

void Dequeue(List *lp) {
    int item = 0;

    if(lp->head == NULL){
        printf("List is empty\n");
        return;
    } else {
        item = lp->head->item;
        lp->head = lp->head->next;
    }
}

bool Empty(List *lp) {
    if(lp->head == NULL) {
        return(true);
    } else {
        return(false);
    }
}

//Main function to execute program.
int main()
{
	List *queue;

	queue = (List *) malloc(sizeof(List));

	Enqueue(queue, 15);
    Enqueue(queue, 27);
    printList(queue);
    Dequeue(queue);
    Dequeue(queue);

    printf("%d\n", Empty(queue));

	return 0;
}
