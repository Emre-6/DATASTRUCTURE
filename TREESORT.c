#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s *NODE;

typedef struct Node_s
{
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
}Node_t[1];


int main()
{
	Node_t node[8];
	
	node[0]->data=20;
	node[1]->data=10;
	node[2]->data=33;
	node[3]->data=66;
	node[4]->data=59;
	node[5]->data=79;	
	node[6]->data=82;
	node[7]->data=77;
	
	node[0]->left=node[1];
	node[0]->right=node[2];
	node[1]->left=NULL;
	node[1]->right=NULL;
	node[2]->left=NULL;
	node[2]->right=node[3];
	node[3]->left=node[4];
	node[3]->right=node[5];
	node[4]->left=NULL;
	node[4]->right=NULL;
	node[5]->left=node[7];
	node[5]->right=node[6];
	node[6]->left=NULL;
	node[6]->right=NULL;
	node[7]->left=NULL;
	node[7]->right=NULL;

	return 0;

}
