
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

LINKED_LIST linked_list_init() {
	LINKED_LIST new;

	new = malloc(sizeof(LINKED_LIST_t));
	if (new != NULL){
		new->head = NULL;
	} else {
		printf("Error @linked_list_init");
	}

	return new;
}

int *init_integer(int val) {
	int *ptr;

	ptr = malloc(sizeof(int));
	*ptr = val;

	return ptr;
}

void linked_list_append(LINKED_LIST list, void *data) {
	LINKED_LIST_NODE node, node_new;

	node_new = malloc(sizeof(LINKED_LIST_NODE_t));
	if (node_new != NULL) {
		node_new->data = data;
		node_new->next = NULL;
		node = (LINKED_LIST_NODE)list;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = node_new;
	} else{
		printf("Error @linked_list_append_init");
	}
}

int linked_list_size(LINKED_LIST list) {
	LINKED_LIST_NODE node;
	int size = 0;

	node = list->head;
	while (node != NULL) {
		node = node->next;
		size++;
	}
	return size;
}

void linked_list_print(LINKED_LIST list) {
	LINKED_LIST_NODE node;
	int i, size;

	if(list != NULL) {
		node = list->head;
		size = linked_list_size(list);
		for (i = 0; i < size; i++) {
			printf("%d ", *(int *)node->data);
			node = node->next;
		}
		printf("\n");
	} else{
		printf("\n");
	}
}

void breathfirstsearch(int v)
{
	int i;
	
	insert_queue(v);
	int state[v] = waiting;
	
	while(!isEmpty_queue())
	{
		v = delete_queue( );
		printf("%d ",v);
		state[v] = visited;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial) 
			{
				insert_queue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
	
}
