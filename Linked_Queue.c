// A C program to demonstrate linked list based implementation of queue 
#include <stdio.h> 
#include <stdlib.h> 

typedef struct LINKED_QUEUE_NODE_s *LINKED_QUEUE_NODE;

typedef struct LINKED_QUEUE_NODE_s {
	void *data;
	LINKED_QUEUE_NODE next;
}LINKED_QUEUE_NODE_t[1];

typedef struct LINKED_QUEUE_s *LINKED_QUEUE;

typedef struct LINKED_QUEUE_s {
	LINKED_QUEUE_NODE head, tail;
} LINKED_QUEUE_t[1];;

LINKED_QUEUE linked_queue_init();
int linked_queue_is_empty(LINKED_QUEUE q1);
void linked_queue_enqueue(LINKED_QUEUE q1,void *k);
int linked_queue_size(LINKED_QUEUE q1);
void linked_queue_enqueue(LINKED_QUEUE q1,void *k);
void *linked_queue_dequeue(LINKED_QUEUE q1);

void bfs(int **adjMatrix,int numbeerOfVertez,int startVertex);
void bft(int g,int s);

LINKED_QUEUE linked_queue_init()
{
	LINKED_QUEUE q1 = (struct LINKED_QUEUE*)malloc(sizeof(LINKED_QUEUE));
	q1->head = NULL;
	q1->tail = NULL;
	return queue;
}

int linked_queue_is_empty(LINKED_QUEUE q1)
{
	if (q1->tail == NULL)
		return 1;
	else
		return 0;
}

void linked_queue_enqueue(LINKED_QUEUE q1e, void *k)
{
	
	LINKED_QUEUE_NODE temp = (LINKED_QUEUE_NODE*)malloc(sizeof(LINKED_QUEUE_NODE));
	temp->data = k;
	temp->next = NULL;

	// If queue is empty, then new node is front and rear both 
	if (q1->tail == NULL) {
		q1->head = q1->tail = temp;
		return;
	}

	// Add the new node at the end of queue and change rear 
	q1->tail->next = temp;
	q1->tail = temp;
}

int linked_queue_size(LINKED_QUEUE q1)
{
	int counter = 0;
	LINKED_QUEUE_NODE temp = q1->tail;

	while (temp != NULL)
	{
		temp = q1->tail->next;
		counter++;
	}
	
	return counter;
}

void linked_queue_dequeue(LINKED_QUEUE q1)
{
	// If queue is empty, return NULL. 
	if (q1->head == NULL)
		return;

	// Store previous front and move front one node ahead 
	LINKED_QUEUE_NODE *temp = q1->head;

	q1->head = q1->head->next;

	// If front becomes NULL, then change rear also as NULL 
	if (q1->head == NULL)
		q1->tail = NULL;

	free(temp);
}
void bfs(int **adjMatrix,int numbeerOfVertez,int startVertex)
{
	int N=9
	int adjMatrix[N][N]={{0,1,0,1,1,0,0,0,0},{0,0,1,0,1,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,1,0,1,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,1,0},{0,0,0,0,0,1,0,0,1},{0,0,0,0,0,0,0,0,0}};
	
}

void bft(int g,int s)
{
	LINKED_QUEUE p1=linked_queue_init();
	LINKED_QUEUE dmap=linked_queue_init();
	linked_queue_enqueue(s,p1);
	
	while(p1!=NULL)
	{
		int v,w;
		linked_queue_dequeue(p1,v);
		printf("%d\n",v);
		for(v=0;v<w;v++)
		{
			if(w!=dmap)
			{
				linked_queue_enqueue(w,p1);
			}	
		}	
	}	
	
}

int main()
{
	LINKED_QUEUE q = linked_queue_init();
	linked_queue_enqueue(q, 10);
	linked_queue_enqueue(q, 20);
	linked_queue_dequeue(q);
	linked_queue_dequeue(q);
	linked_queue_enqueue(q, 30);
	linked_queue_enqueue(q, 40);
	linked_queue_enqueue(q, 50);
	linked_queue_dequeue(q);
	printf("Queue HEAD : %d \n", q->head->data);
	printf("Queue TAIK : %d", q->tail->data);
	return 0;
}
