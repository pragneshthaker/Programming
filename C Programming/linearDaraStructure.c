#include<stdio.h>
#include<stdlib.h>

//define the node structure with single link and key value
struct SLNode{
	int key;
	struct SLNode *link;

};

typedef struct SLNode SLNode;
//define the stack structure

struct Stack{
	SLNode *Top;
};
typedef struct Stack Stack;

//create an empty stack
Stack* createStack(){
	Stack *s = (Stack*) malloc( sizeof(Stack) );
	s->Top = NULL;
	return s;
}

//Push the values in the Stack (One at a time)
void push(Stack *s, int value){
	// create new node
	SLNode *newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->key = value;
	//insert the new node in the stack
	newNode->link = s->Top;
	s->Top = newNode;
}

//Pop the last inserted element from the stack
int pop(Stack *s){
	if(s->Top == NULL){
		printf("Stack is empty so no value can be poped");
		return 0;
	}

	int tempKey = s->Top->key;
	SLNode *tempPtr = s->Top;
	s->Top = s->Top->link;
	free(tempPtr);
	return tempKey;
}


//define the structure of the queue
struct Queue{
	SLNode *head, *tail;
};
typedef struct Queue Queue;

//Create an empty queue
Queue* createQueue(){
	Queue* q = (Queue*) malloc( sizeof(Queue) );
	q->head = q->tail = NULL;
	return q;
}

//enqueue int value in the queue
void enqueue(Queue *q,int x){
		// crate new node
		SLNode *newNode = (SLNode*) malloc(sizeof(SLNode));
		newNode->key = x;

		//insert the newly created node in the queue
		//1st insertion
		if(q->head == NULL){
			q->head = q->tail = newNode;
			newNode->link = NULL;
			return;
		}
		//general insertion;
		q->tail->link = newNode;
		newNode->link = NULL;
		q->tail = newNode;
}

//dequeue an element from queue
int dequeue(Queue *q){
		SLNode *tempPtr;
		int temp;
		if(q->head == NULL){
			printf("Queue is empty\n");
			return 0;
		}
		//look for the last deletion
		if(q->head == q->tail){
			tempPtr = q->tail;
			temp = q->tail->key;
			q->tail = q->head = NULL;
			free(tempPtr);
		}
		//general deletion
		else{
			tempPtr = q->head;
			q->head = q->head->link;
			temp = tempPtr->key;
			free(tempPtr);
		}
		return temp;
}

struct SLList{
	SLNode *head;
};
typedef struct SLList SLList;
//insert the node in the simple link list at the end

SLList * createSLList(){
		SLList *sl = (SLList*) malloc( sizeof(SLList) );
		sl->head =NULL;
		return sl;
}

void SLLInsertion(SLList* sl,int x){

		SLNode *temp = sl->head;
		// crate new node
		SLNode *newNode = (SLNode*) malloc(sizeof(SLNode));
		newNode->key = x;
		newNode->link = NULL;

		if(sl->head == NULL)
			sl->head = newNode;
		else{
			while(temp->link !=NULL){
				temp = temp->link;
			}
			temp->link = newNode;
		}

}

int SLLDelete(SLList* sl){
	SLNode *temp = sl->head;
	int x;
	if(sl->head == NULL){
		printf("List is empty");
		return 0;
	}
	sl->head = sl->head->link;
	x = temp->key;
	free(temp);
	return x;
}

void SLLDisplay(SLList* sl){
		SLNode *temp = sl->head;
		if(sl->head == NULL)
			printf("List is empty");
		else{
			while(temp->link !=NULL){
				printf("\t %4d",temp->key);
				temp = temp->link;
			}
			//temp->link = newNode;
		}
}



struct SLListOrder{
	int key;
	SLNode *head;
};
typedef struct SLListOrder SLListOrder;

SLListOrder* createSLListOrder(){
		SLListOrder *slo = (SLListOrder*) malloc( sizeof(SLListOrder) );
		slo->head =NULL;
		return slo;
}
void SLLInsertionOrder(SLListOrder* sl,int x){}
int SLLDeleteOrder(SLListOrder* sl,int x){ return 1;}
void SLLDisplayOrder(SLListOrder* sl){
	    SLNode *temp= sl->head;
		if(sl->head == NULL)
			printf("List is empty");
		else{
			while(temp->link !=NULL){
				printf("\t %4d",temp->key);
				temp = temp->link;
			}
			//temp->link = newNode;
		}
}

int main(){
		int ch,x;
		Stack *s = createStack();//create an empty stack
		Queue *q = createQueue();
		SLList *sl = createSLList();
		SLListOrder *slo = createSLListOrder();
		while(1){

			printf("\n0: Exit \n1: Push \n2: Pop \n3: Enqueue \n4: Dequeue \nEter your Choice ");
			scanf("%d",&ch);
			switch(ch){
				case 0: return 1;

				case 1: printf("enter the value you want to push into the stack");
						scanf("%d",&x);
						push(s,x);
						break;

				case 2: x = pop(s);
						printf("\nLast poped value is %d",x);
						break;
				case 3: printf("enter the value you want to insert into queue");
						scanf("%d",&x);
						enqueue(q,x);
						break;
				case 4: x = dequeue(q);
						printf("Last dequeue value is %d",x);
						break;
				case 5:	printf("enter the value you want to insert into Singly Link List");
						scanf("%d",&x);
						SLLInsertion(sl,x);
						break;
				case 6: SLLDisplay(sl);
						break;
				case 7: x = SLLDelete(sl);
						printf("Deleted item from unorder list is %d",x);
						break;

				case 8:	printf("enter the value you want to insert into order Singly Link List");
						scanf("%d",&x);
						SLLInsertionOrder(slo,x);
						break;
				case 9: SLLDisplayOrder(slo);
						break;
				case 10:SLLDeleteOrder(slo,x);
						printf("Deleted item from unorder list is %d",x);
						break;
				default:printf("invalid choice");
			}
		}
		return 1;
}

