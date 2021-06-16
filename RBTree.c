#include <stdio.h>
#include <stdlib.h>

typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s
{
	LINKED_TREE_NODE right;
	LINKED_TREE_NODE left;
	LINKED_TREE_NODE root;
	int key;
	int colour;
	void *data;
}LINKED_TREE_NODE_t[1];

LINKED_TREE_NODE newnode(int key)
{
	LINKED_TREE_NODE node=(LINKED_TREE_NODE)malloc(sizeof(LINKED_TREE_NODE_t));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->colour=1;
	return node;
}

LINKED_TREE_NODE right(LINKED_TREE_NODE p)
{
	LINKED_TREE_NODE f=p->left;
	p->left=f->right;
	f->right=p;
	return f;
}

LINKED_TREE_NODE left(LINKED_TREE_NODE f)
{
	LINKED_TREE_NODE p=f->right;
	f->right=p->left;
	p->left=f;
	return p;
}

LINKED_TREE_NODE insert(LINKED_TREE_NODE node,int key)
{
	if(node==NULL)
	return(newnode(key));
	if(key<node->key)
	{
		node->left=insert(node->left,key);
	}
	else if(key>node->key)
	{
		node->right=insert(node->right,key);
	}
	
	return node;
}

LINKED_TREE_NODE init()
{
	LINKED_TREE_NODE tree=malloc(sizeof(LINKED_TREE_NODE_t));
	tree->root=NULL;
	return tree;
}

int main()
{
	LINKED_TREE_NODE tree=init();
	LINKED_TREE_NODE node=tree->root;
	node=insert(node,40);
	node=insert(node,23);
	node=insert(node,65);
	node=insert(node,50);
	node=insert(node,77);
	printf("%d",node->key);
	
	return 0;
}



