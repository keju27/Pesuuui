typedef struct node
{
	int info;
    struct node *left,*right;
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;

void initTree(TREE *pt);
void insertNode(TREE *pt,int ele);
void inorderTraversal(TREE *pt);
void preorderTraversal(TREE *pt);
void postorderTraversal(TREE *pt);
void destroyTree(TREE *pt);
void insertRec(TREE *pt,int ele);
NODE* searchIterative(TREE *pt,int ele);
NODE* searchRecursive(TREE *pt,int ele);
void deleteNode(TREE *pt,int ele);