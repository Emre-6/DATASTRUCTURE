/*
 * library.h
 *
 *  Created on: May 14, 2020
 *      Author: berkan
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s{
	LINKED_LIST_NODE next; /* Do not change order */
	void *data;
} LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s{
  	LINKED_LIST_NODE head; /* May overlap with next. */
} LINKED_LIST_t[1], *LINKED_LIST;


LINKED_LIST linked_list_init();
void linked_list_free(LINKED_LIST list);
void linked_list_prepend(LINKED_LIST list, void *data);
void linked_list_append(LINKED_LIST list, void *data);
int *init_integer(int val);
void linked_list_insert(LINKED_LIST list, void *data, int idx);
int linked_list_size(LINKED_LIST list);
void linked_list_print(LINKED_LIST list);
void breadthfirstsearch(int v);


#endif /* LINKED_LIST_H_ */
