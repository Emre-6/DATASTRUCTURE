#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *left;
	struct nod *right;	
};

struct node* newNode(int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left=temp->right=NULL;
	return temp;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->key);
		inorder(root->right);
	}
}


struct node* insert(struct node* node,int key)
{
	if(node==NULL)
	return newNode(key);
	if(key<node->key)
	node->left=insert(node->left,key);
	else if(key>node->key)
	node->right=insert(node->right,key);
	
	return node;
}


int main()
{
	struct node* root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	
	inorder(root);
	
	return 0;
}












