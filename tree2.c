#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char *name;
	char *surname;
	float gpa;
}STUDENT_t[1],*STUDENT;



typedef struct NODE_s *NODE;

typedef struct NODE_s
{
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
} NODE_t[1];

typedef struct
{
	NODE root;
}TREE_t[1],*TREE;

STUDENT student_init(char *name,char *surname,float gpa)
{
	STUDENT s=(STUDENT)malloc(sizeof(STUDENT_t));
	s->name=name;
	s->surname=surname;
	s->gpa=gpa;
	return s;
}

void student_kill(STUDENT s)
{
	free(s);
}

NODE tree_node_init()
{
	NODE n=(NODE)malloc(sizeof(NODE_t));
	n->left=NULL;
	n->right=NULL;
	n->key=key;
	n->data=data;
	return n;
}

void tree_node_kill(NODE n)
{
	free(n);
}

void tree_insert(TREE tree,unsigned long key,void *data)
{
	NODE curr;
	if(tree->root==NULL)
	{
		tree->root=tree_node_init(key,data);	
	}
	else
	{
		curr=tree->root;
		while(1)
		{
			if(key<curr->key)
			{
				if(curr->left=NULL)
				{
					curr->left=tree_node_init(key,data);
					break;
				}
				else
				{
					curr=curr->left;
				}
				
			}
			else if(key>curr->key)
			{
				if(curr->right==NULL)
				{
					curr->right=tree_node_init(key,data);
					break;
				}
				else
				{
					curr=curr->right;
				}
			
			}
			else
			{
				printf("Error: dublicate node.\n");
			}
		}
	}
}

int main()
{
	TREE t1=tree_init();
	
	STUDENT s1=student_init("Erol","Kaya",3.55);
	STUDENT s2=student_init("Gul","Tepe",3.67);
	
	tree_insert(t1,15,s1);
	tree_insert(t1,11,s2);
	tree_insert(t1,34,NULL);
	tree_insert(t1,23,NULL);
	tree_insert(t1,78,NULL);
	tree_insert(t1,28,NULL);
	tree_insert(t1,54,NULL);
	tree_insert(t1,99,NULL);

	tree_kill(t1);
	
	return 0;
}
