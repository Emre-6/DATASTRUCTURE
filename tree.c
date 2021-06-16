#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;

typedef struct NODE_s
{
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
} NODE_t[1];


// Let n be the number nodes.
//Binary Search Tree (BST): 
//Search,Insertion,Delete. 0(log_2.n).

//Linked List(LL):
// Search,Insertion,Delete. 0(n).
// Example: n=1000000000. log_2(n)-=30

//Form a BST with insertions:
// 15,34,78,23,11,54,28,99


int main()
{
	
	
	NODE_t node[8];
	
	node[0]->data=15;
	node[1]->data=11;
	node[2]->data=34;
	node[3]->data=23;
	node[4]->data=78;
	node[5]->data=28;
	node[6]->data=54;
	node[7]->data=99;
	
	node[0]->left=node[1];
	node[0]->right=node[2];
	node[1]->left=NULL;
	node[1]->right=NULL;
	node[2]->left=node[3];
	node[2]->right=node[4];
	node[3]->left=NULL;
	node[3]->right=node[5];
	node[4]->left=node[6];
	node[4]->right=node[7];
	node[5]->left=NULL;
	node[5]->right=NULL;
	node[6]->left=NULL;
	node[6]->right=NULL;
	node[7]->left=NULL;
	node[7]->right=NULL;
	
	
	
	
	
	return 0;
}



