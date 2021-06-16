#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 10

typedef struct LINKED_TREE_NODE_s *LINKED_TREE_NODE;
typedef struct LINKED_TREE_NODE_s{
	LINKED_TREE_NODE right;
	LINKED_TREE_NODE left;
	int key;
	void* data;
} LINKED_TREE_NODE_t[1];

typedef struct LINKED_TREE_s *LINKED_TREE;
typedef struct LINKED_TREE_s{
	LINKED_TREE_NODE root;
} LINKED_TREE_t[1];

LINKED_TREE linked_tree_init();
LINKED_TREE_NODE linked_tree_node_init(int key, void* data);
void linked_tree_free(LINKED_TREE tree);
void linked_tree_insert(LINKED_TREE tree, int key, void* data);
void insert_recursive(LINKED_TREE_NODE node, int key, void* data);
void linked_tree_printHorizontal(LINKED_TREE_NODE node, int l);

LINKED_TREE linked_tree_init(){
	LINKED_TREE t = (LINKED_TREE)malloc(sizeof(LINKED_TREE_t));
	return t;
}

LINKED_TREE_NODE linked_tree_node_init(int key, void* data){
	LINKED_TREE_NODE node = (LINKED_TREE_NODE)malloc(sizeof(LINKED_TREE_NODE_t));
	if(node != NULL){
		node->key = key;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else{
		printf("Error @ linked_tree_node_init: Cannot allocate memory.\n");
	}
	return node;
}

void linked_tree_free(LINKED_TREE tree){
	free(tree->root);
}

void linked_tree_insert(LINKED_TREE tree, int key, void *data) {
	if (tree->root == NULL) {
		tree->root = linked_tree_node_init(key, data);
	} else {
		insert_recursive(tree->root, key, data);
	}
}

void insert_recursive(LINKED_TREE_NODE tree, int key, void *data) {
	if (key > tree->key) {
		if (tree->right == NULL) {
			tree->right = linked_tree_node_init(key, data);
		} else {
			insert_recursive(tree->right, key, data);
		}
	} else {
		if (tree->left == NULL) {
			tree->left = linked_tree_node_init(key, data);
		} else {
			insert_recursive(tree->left, key, data);
		}
	}
}

void linked_tree_printHorizontal(LINKED_TREE_NODE node, int l) {
	if(node != NULL) {
		linked_tree_printHorizontal(node->right,l + 1);
		int i;
		for(i = 0; i < l; i++){
			printf("  ");
		}
		printf("%d\n", node->key);
		linked_tree_printHorizontal(node->left, l + 1);
	}
}

int main(){
	LINKED_TREE tree = linked_tree_init();

	int keys[SIZE] = {
			5, 15, 25, 65, 10, 70, 80, 90, 55, 40
	};

	for (int i = 0; i < SIZE; i++) {
		linked_tree_insert(tree, keys[i], NULL);
	}

	printf("\nFIRST STATE\n\n");
	linked_tree_printHorizontal(tree->root, 0);
	printf("\n\n--------------\n\n");

	linked_tree_free(tree);
	exit(0);
}


