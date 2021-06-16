#include <stdio.h>
#include <stdlib.h>

typedef struct BTREE_NODE_s *BTREE_NODE;
typedef struct BTREE_NODE_s {
	int isLeaf;
	int n;
	unsigned int *key;
	BTREE_NODE *child;
} BTREE_NODE_t[1];

typedef struct BTREE_s *BTREE;
typedef struct BTREE_s {
	BTREE_NODE root;
} BTREE_t[1];

BTREE_NODE btree_node_init(int m) {
	BTREE_NODE nodes = (BTREE_NODE) malloc(sizeof(BTREE_NODE_t));
	nodes->key = (unsigned int *) malloc(sizeof(unsigned int) * (2 * m - 1));
	nodes->child = (BTREE_NODE *) malloc(sizeof(BTREE_NODE) * (2 * m));
	nodes->isLeaf = 1;
	nodes->n = 0;
	return nodes;
}
BTREE btree_init() {
	BTREE tree = (BTREE) malloc(sizeof(BTREE_t));
	tree->root=NULL;
	
	return tree;
}

BTreeNode BTreeNode(int t,bool leaf) 
{ 
    int *keys;  
    int t;      
    BTreeNode **C; 
    int n;     
    bool leaf; 

   
    void insertNonFull(int k); 
  
    
    void splitChild(int i, BTreeNode *y); 
  
    
    void traverse(); 
  
    
    BTreeNode *search(int k); 
   
}; 
  

BTreeNode BTree(int t) 
{ 
    BTreeNode *root;  
    int t;   

    BTree(int _t) 
    {  root = NULL;  t = _t; } 
  
    
    void traverse() 
    {  if (root != NULL) root->traverse(); } 
  
    BTreeNode* search(int k) 
    {  return (root == NULL)? NULL : root->search(k); } 
  
    
    void insert(int k); 
}; 
  

BTREE_NODE insert(BTREE_NODE root,int k)
{

	
	if (root == NULL) 
    { 
        root = new BTreeNode(t, true); 
        root->keys[0] = k;   
        root->n = 1;   
    } 
    else 
    { 
         if (root->n == 2*t-1) 
        { 
             
            BTreeNode *s = new BTreeNode(t, false); 
  
            
            s->C[0] = root; 

            
            s->splitChild(0, root); 
  
          
            int i = 0; 
            if (s->keys[0] < k) 
                i++; 
            s->C[i]->insertNonFull(k); 
  
      
            root = s; 
        } 
        else  
            root->insertNonFull(k); 
    } 
}

BTreeNode search(int k) 
{ 
    
    int i = 0; 
    while (i < n && k > keys[i]) 
    {
		i++; 
	} 
	    
	if (keys[i] == k) 
    {
	  return this; 
    }
    
    if (leaf == true) 
    {
		return NULL;
	}     
  	
	return C[i]->search(k); 
} 


BTreeNode insertNonFull(int k) 
{ 
    int i = n-1; 
  
    if (leaf == true) 
    { 
        while (i >= 0 && keys[i] > k) 
        { 
            keys[i+1] = keys[i]; 
            i--; 
        } 
  
        keys[i+1] = k; 
        n = n+1; 
    } 
    else 
    { 
     	while (i >= 0 && keys[i] > k) 
            i--; 
 	 	if (C[i+1]->n == 2*t-1) 
        { 
            splitChild(i+1, C[i+1]); 
            if (keys[i+1] < k) 
                i++; 
        } 
        C[i+1]->insertNonFull(k); 
    } 
} 
  
BTreeNode splitChild(int i, BTreeNode *y) 
{ 
    
    BTreeNode *z = new BTreeNode(y->t, y->leaf); 
    z->n = t - 1; 
  
 
    for (int j = 0; j < t-1; j++) 
        z->keys[j] = y->keys[j+t]; 
  
    
    if (y->leaf == false) 
    { 
        for (int j = 0; j < t; j++) 
            z->C[j] = y->C[j+t]; 
    } 
  
    y->n = t - 1; 
  
    
    for (int j = n; j >= i+1; j--) 
        C[j+1] = C[j]; 
  
    C[i+1] = z; 
    
    for (int j = n-1; j >= i; j--) 
        keys[j+1] = keys[j]; 
  
    keys[i] = y->keys[t-1]; 
  
    n = n + 1; 
} 


BTreeNode traverse() 
{ 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        if (leaf == false) 
        C[i]->traverse(); 
        printf("%d\n",keys[i]); 
    } 
  
     
    if (leaf == false) 
        C[i]->traverse(); 
} 

BTREE_NODE BTreeNode(int t,bool leaf)
{
	
    t = t1; 
    leaf = leaf1; 
  
    
    keys = new int[2*t-1]; 
    C = new BTreeNode *[2*t]; 
   
    n = 0; 
}



BTree SplitChild(int x,int i)
{
	int z=malloc(sizeof(int));
	y=x.c;
	z.leaf=y.leaf;
	z.n=t-1;
	int j;
	for(j=1;j<t-1;j++)
	{
		z.key=y.key;
	}
	if(y.leaf!=NULL)
	{
		for(j=1;j<t;j++)
		{
			z.c=y.c;
		}
		y.n=t-1;
	}
	for(j=x;j<i+1;j++)
	{
		x.c=x.c;
	}
	for()
}

int main()
{
	BTREE t=btree_init(); 
    BTREE_NODE node=t->root;

  
    return 0; 
}
