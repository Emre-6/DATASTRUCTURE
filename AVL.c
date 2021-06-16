#include <stdio.h>
#include <stdlib.h>
typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s
{
	LINKED_TREE_NODE right;
	LINKED_TREE_NODE left;
	int key;
	int height;
	void *data;
}LINKED_TREE_NODE_t[1];


int max(int a,int b);


int height(LINKED_TREE_NODE T)
{
	if(T==NULL)
	{
		return 0;
	}

	return T->height;
}

int max(int a,int b)
{
	if(a>b)
	{
		return a>b;
	}
	else if(a<b)
	{
		return a<b;
	}	
}

LINKED_TREE_NODE newnode(int key)
{
	LINKED_TREE_NODE node=(LINKED_TREE_NODE)malloc(sizeof(LINKED_TREE_NODE_t));
	node->key=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}

LINKED_TREE_NODE right(LINKED_TREE_NODE p)
{
	LINKED_TREE_NODE f=p->left;
	LINKED_TREE_NODE A=p->right;
	
	p->right=f;
	f->left=A;
	
	p->height=max(height(p->left),height(p->right));
	f->height=max(height(f->left),height(f->right));
	
	return f;
	
}

LINKED_TREE_NODE left(LINKED_TREE_NODE f)
{
	LINKED_TREE_NODE p=f->right;
	LINKED_TREE_NODE A=p->left;
	
	f->left=p;
	p->right=A;
	
	f->height=max(height(f->left),height(f->right));
	p->height=max(height(p->left),height(p->right));
	
	return p;
}

int balance(LINKED_TREE_NODE T)
{
	if(T==NULL)
	return 0;
	return height(T->left)-height(T->right);
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
	int b=balance(node);
	
	
	if (b > 1 && key < node->left->key) 
        return right(node); 
  
    
    if (b < -1 && key > node->right->key) 
        return left(node); 
  
    
    if (b > 1 && key > node->left->key) 
    { 
        node->left =  left(node->left); 
        return right(node); 
    } 
  
    
    if (b < -1 && key < node->right->key) 
    { 
        node->right = right(node->right); 
        return left(node); 
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
	LINKED_TREE tree=init();
	LINKED_TREE_NODE node =tree->root;
	insert(node,30);
	insert(node,25);
	insert(node,45);
	insert(node,42);
	insert(node,52);
	
	printf("%d\n",root->key);
	
	return 0;
}










