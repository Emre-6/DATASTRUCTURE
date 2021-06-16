#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct PAIR_s{
	int data;
	LINKED_LIST next;
} PAIR_t[1], *PAIR;

PAIR pair_init(int data) {
	PAIR p;

	p = malloc(sizeof(PAIR_t));
	p->data = data;
	p->next = linked_list_init();

	return p;
}

void print_graph(LINKED_LIST list) {
	LINKED_LIST_NODE node;
	int i, size;
	PAIR p;

	node = list->head;
	size = linked_list_size(list);
	for (i = 0; i < size; ++i) {
		p = node->data;
		printf("%d --> ", p->data);
		linked_list_print(p->next);
		node = node->next;
	}
}

int main(void) {

	LINKED_LIST list;
	list = linked_list_init();

	/* Firstly, create a small list */
	PAIR p0, p1, p2, p3, p4, p5, p6, p7, p8;

	p0 = pair_init(0); p4 = pair_init(4);
	p1 = pair_init(1); p5 = pair_init(5);
	p2 = pair_init(2); p6 = pair_init(6);
	p3 = pair_init(3); p7 = pair_init(7);
	p8 = pair_init(8);

	/* 0-1, 0-3, 0-4 */
	linked_list_append((LINKED_LIST)p0->next, init_integer(1));
	linked_list_append((LINKED_LIST)p0->next, init_integer(3));
	linked_list_append((LINKED_LIST)p0->next, init_integer(4));

	/* 1-2, 1-4 */
	linked_list_append((LINKED_LIST)p1->next, init_integer(2));
	linked_list_append((LINKED_LIST)p1->next, init_integer(4));

	/* 2-5 */
	linked_list_append((LINKED_LIST)p2->next, init_integer(5));

	/* 3-4, 3-6 */
	linked_list_append((LINKED_LIST)p3->next, init_integer(4));
	linked_list_append((LINKED_LIST)p3->next, init_integer(6));

	/* 4-5 */
	linked_list_append((LINKED_LIST)p4->next, init_integer(5));

	/* 6-4, 6-7 */
	linked_list_append((LINKED_LIST)p6->next, init_integer(4));
	linked_list_append((LINKED_LIST)p6->next, init_integer(7));

	/* 7-5, 7-8 */
	linked_list_append((LINKED_LIST)p7->next, init_integer(5));
	linked_list_append((LINKED_LIST)p7->next, init_integer(8));


	/* Secondly, add these small lists into the big list */
	linked_list_append(list, p0);
	linked_list_append(list, p1);
	linked_list_append(list, p2);
	linked_list_append(list, p3);
	linked_list_append(list, p4);
	linked_list_append(list, p5);
	linked_list_append(list, p6);
	linked_list_append(list, p7);
	linked_list_append(list, p8);


	print_graph(list);

	return 1;
}
