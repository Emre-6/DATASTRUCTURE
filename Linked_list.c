#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

LINKED_LIST linked_list_init() {
	LINKED_LIST list_new;

	list_new = malloc(sizeof(LINKED_LIST_t));
	if (list_new != NULL) {
		list_new->head = NULL;
	} else {
		printf("Error @linked_list_init");
	}

	return list_new;
}

void linked_list_free(LINKED_LIST list){
	LINKED_LIST_NODE node, tmp;

	node = list->head;
	while(node != NULL) {
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(list->head);
}

void linked_list_prepend(LINKED_LIST list, void *data) {
	//TODO

	LINKED_LIST_NODE node, node_new;
	node_new = malloc(sizeof(LINKED_LIST_NODE_t));

	node_new->data = data;
	node_new->next = NULL;
	node_new->prev = NULL;

	node = (LINKED_LIST_NODE)list;

	node_new->next = node;
	node->prev = node_new;
}

void linked_list_append(LINKED_LIST list, void *data) {
	LINKED_LIST_NODE node, node_new;

	node_new = malloc(sizeof(LINKED_LIST_NODE_t));
	if (node_new != NULL) {
		node_new->data = data;
		node_new->next = NULL;
		node_new->prev = NULL;

		node = (LINKED_LIST_NODE)list;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = node_new;
		node_new->prev = node;
	} else{
		printf("Error @linked_list_append_init");
	}
}

void linked_list_insert(LINKED_LIST list, void *data, int idx) {
	//TODO
	LINKED_LIST_NODE node, node_new, node_next;
	node_new = malloc(sizeof(LINKED_LIST_NODE_t));

	node_new->data = data;
	node_new->next = NULL;
	node_new->prev = NULL;

	node = (LINKED_LIST_NODE)list;

	for (int i = 0; i < idx; i++)
	{
		node = node->next;
	}

	node_next = node->next;
	node->next = node_new;
	node_new->prev = node;

	node_next->prev = node_new;


}

void linked_list_set(LINKED_LIST list, void *data, int idx) {
	//TODO

	LINKED_LIST_NODE node;


	node = (LINKED_LIST_NODE)list;

	for (int i = 0; i < idx; i++)
	{
		node = node->next;
	}

	node->data = data;
}

void *linked_list_get(LINKED_LIST list, int idx) {
	//TODO
	LINKED_LIST_NODE node;

	node = (LINKED_LIST_NODE)list;

	for (int i = 0; i < idx; i++)
	{
		node = node->next;
	}

	return node->data;
}

void *linked_list_remove(LINKED_LIST list, int idx) {
	//TODO
	LINKED_LIST_NODE node_remove;

	node_remove = (LINKED_LIST_NODE)list;

	for (int i = 0; i < idx; i++)
	{
		node_remove = node_remove->next;
	}

	node_remove->prev->next = node_remove->next;
	node_remove->next->prev = node_remove->prev;

	return node_remove;
}

void linked_list_removeall(LINKED_LIST list) {
	//TODO
	LINKED_LIST_NODE node_remove;

	node_remove = (LINKED_LIST_NODE)list;
	while (node_remove->next != NULL) {
		node_remove = node_remove->next;
		node_remove->prev->next = NULL;
		node_remove->prev->data = NULL;
		node_remove->prev = NULL;
	}

}

void linked_list_concatenate(LINKED_LIST list, LINKED_LIST list2) {
	//TODO

	LINKED_LIST_NODE node, node2;

		node = (LINKED_LIST_NODE)list;
		node2 = (LINKED_LIST_NODE)list2;
		while (node->next != NULL) {
			node = node->next;
		}

		node->next = node2;
		node2->prev = node;

}

void linked_list_fprint(LINKED_LIST list, FILE *fp, void (*print_type) (FILE*, void*)) {
	//TODO

	LINKED_LIST_NODE node;

	node = (LINKED_LIST_NODE)list;
	
	while (node->next != NULL) {

		//print file 

		fprintf(fp, "%d", node->data);
		printf("%d",node->data);

		node = node->next;
	}
}

