#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;

typedef struct NODE_s
{
	NODE left;
	NODE right;	
}NODE_t[1];

int main()
{
	NODE_t node1,node2,node3;
	
	node1->left=node2;
	node1->right=node3;
	
	node2->left=NULL;
	node2->right=NULL;
	
	node3->left=NULL;
	node3->right=NULL;
	
	return 0;
}

