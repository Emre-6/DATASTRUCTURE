#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char *name;
	char *surname;
	float gpa;
} STUDENT_t[1], *STUDENT;

typedef struct NODE_s *NODE;
typedef struct NODE_s {
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
} NODE_t[1];

typedef struct {
	NODE root;
} TREE_t[1], *TREE;

STUDENT student_init(char *name, char *surname, float gpa){
	STUDENT s = (STUDENT)malloc(sizeof(STUDENT_t));
	s->name = name;
	s->surname = surname;
	s->gpa = gpa;
	return s;
}

void student_kill(STUDENT s){
	free(s);
}


TREE tree_init(){
	TREE t = (TREE)malloc(sizeof(TREE_t));
	t->root = NULL;
	return t;
}

void tree_kill(TREE t){
	free(t);
}

NODE tree_node_init(unsigned long key, void *data){
	NODE n = (NODE)malloc(sizeof(NODE_t));
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	n->data = data;
	return n;
}

void tree_node_kill(NODE n){
	free(n);
}

/* Iterative insert for binary trees. */
/*
void tree_insert(TREE tree, unsigned long key, void *data){
	NODE node;
	if(tree->root == NULL){
		tree->root = tree_node_init(key, data);
	}else{
		node = tree->root;
		while(node != NULL){
			if(key < node->key){
				if(node->left == NULL){
					node->left = tree_node_init(key, data);
					node = NULL;
				}else{
					node = node->left;
				}
			}else if(key > node->key){
				if(node->right == NULL){
					node->right = tree_node_init(key, data);
					node = NULL;
				}else{
					node = node->right;
				}
			}else{
				printf("Error: dublicate node.\n");
			}
		}
	}
}
*/

/*
void tree_insert_recursive(NODE node, unsigned long key, void *data){
	if(node != NULL){
		if(key < node->key){
			if(node->left == NULL){
				node->left = tree_node_init(key, data);
			}else{
				tree_insert_recursive(node->left, key, data);
			}
		}else if(key > node->key){
			if(node->right == NULL){
				node->right = tree_node_init(key, data);
			}else{
				tree_insert_recursive(node->right, key, data);
			}
		}else{
			printf("Error: dublicate node.\n");
		}
	}
}
*/

NODE tree_insert_recursive(NODE node, unsigned long key, void *data){
	if(node != NULL){
		if(key < node->key){
			node->left = tree_insert_recursive(node->left, key, data);
		}else if(key > node->key){
			node->right = tree_insert_recursive(node->right, key, data);
		}else{
			printf("Error: dublicate node %lu.\n", key);
		}
	}else{
		node = tree_node_init(key, data);
	}
	return node;
}

void tree_insert(TREE tree, unsigned long key, void *data){
	if(tree->root == NULL){
		tree->root = tree_node_init(key, data);
	}else{
		tree->root = tree_insert_recursive(tree->root, key, data);
	}
}

/*
						15



		11					  	 		34


								23				   78

									28  	    54    99

	15, 11, 34, 23, 78, 28, 54, 99  (breath first tree traverse, next week!)


	Sideways print:

                       99
                 78
                       54
         34
                       28
                 23
   15
         11


   99, 78, 54, 34, 28, 23, 15, 11. (Reverse Inorder.)


Preorder tree traverse (Discrete Computational Structures):
	Visit
	Left
	Right
Preorder: 15, 11, 34, 23, 28, 78, 54, 99.

Postorder tree traverse
	Left
	Right
	Visit
Postorder: 11, 28, 23, 54, 99, 78, 34, 15.

Inorder tree traverse
	Left
	Visit
	Right
Inorder: 11, 15, 23, 28, 34, 54, 78, 99.

*/

void tree_traverse_preorder(NODE node){
	if(node != NULL){
		printf("%lu %p %p %p \n", node->key, node, node->left, node->right);
		fflush(stdout);
		tree_traverse_preorder(node->left);
		tree_traverse_preorder(node->right);
	}
}

void tree_print(NODE node, int k){
	int i;
	if(node != NULL){
		tree_print(node->right, k+3);
		for (i = 0; i < k; i++){
			printf(" ");
		}
		printf("%lu\n", node->key);
		fflush(stdout);
		tree_print(node->left, k+3);
	}
}

void tree_delete_node(TREE tree, unsigned long key){
	NODE parent, node;
	char last;

	last = 0;
	parent = (NODE)tree;   // tree->root  ===  parent->left
	node = tree->root;
	while(node != NULL){
		if(key < node->key){
			parent = node;
			node = node->left;
			last = 0;
		}else if(key > node->key){
			parent = node;
			node = node->right;
			last = 1;
		}else{
			break;
		}
	}
	if(node == NULL){
		printf("The node does not exist!\n");
		return;
	}
	if((node->left == NULL) && (node->right == NULL)){       //No child.
		free(node->data); // May have special data deletion!!!
		tree_node_kill(node);
		if(last == 0){
			parent->left = NULL;
		}else{
			parent->right = NULL;
		}
	}else if((node->left != NULL) && (node->right == NULL)){ //Left child.
		if(last==0)
		{
			parent->left=node->left;
			
		}
		else
		{
			parent->right=node->left;
		}
		free(node->data);
		tree_node_kill(node);
	}else if((node->left == NULL) && (node->right != NULL)){ //Right child.
		if(last==0)
		{
			parent->left=node->right;
		}
		else
		{
			parent->right=node->right;
		}
		free(node->data);
		tree_node_kill(node);
	}else{                                                   // Two children.
		NODE min=node->right;
		while(min->left!=NULL)
		{
			min=min->left;
		}
		min->left=node->left;
		if(last==0)
		{
			parent->left=node->right;
		}
		else
		{
			parent->right=node->right;
		}
		free(node->data);
		tree_node_kill(node);
	}

}


int main(){
	int i;
	TREE t1 = tree_init();

	STUDENT s1 = student_init("Erol", "Kaya", 3.55);
	STUDENT s2 = student_init("Gül", "Tepe", 3.67);

	tree_insert(t1, 15, s1);
	tree_insert(t1, 34, s2);
	tree_insert(t1, 78, NULL);
	tree_insert(t1, 23, NULL);
	tree_insert(t1, 11, NULL);
	tree_insert(t1, 54, NULL);
	tree_insert(t1, 28, NULL);
	tree_insert(t1, 99, NULL);

	srand(88);

	for (i = 0; i < 200; ++i) {
		tree_insert(t1, random() % 10000, NULL);
	}



	tree_print(t1->root, 0);

	tree_delete_node(t1,34);
	printf("After deleting 34:\n\n");
	tree_print(t1->root, 0);
	tree_delete_node(t1,28);
	printf("After deleting 28:\n\n");
	tree_print(t1->root, 0);
	tree_delete_node(t1,23);
	printf("After deleting 23:\n\n");
	tree_print(t1->root, 0);
	
	tree_kill(t1);

	return 0;
}




