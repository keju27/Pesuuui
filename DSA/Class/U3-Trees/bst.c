#include<stdlib.h>
#include<stdio.h>
typedef struct node
{
	int info;
	struct node *left;
	struct node *right;
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
int main()
{
	TREE tobj;
	initTree(&tobj);
	int choice;
	int ele;
	NODE *res=NULL;
	do
	{
		printf("1.Insert 2.Inorder 3.Preorder 4.Postorder 5.InsertNodeRec\n");
		printf("6.Search Iterative 7.Search recursive 8.deleteNode\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an integer element\n");
					scanf("%d",&ele);
					insertNode(&tobj,ele);
					break;
			case 2:printf("Inorder:\n");
					inorderTraversal(&tobj);
					break;
			case 3:printf("Preorder:\n");
					preorderTraversal(&tobj);
					break;
			case 4:printf("Postorder\n");
					postorderTraversal(&tobj);
					break;
			case 5:printf("Enter an integer element\n");
					scanf("%d",&ele);
					insertRec(&tobj,ele);
					break;
			case 6: printf("Enter an integer element\n");
					scanf("%d",&ele);
					res=searchIterative(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					break;
			case 7: printf("Enter an integer element\n");
					scanf("%d",&ele);
					res=searchRecursive(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					break;
			case 8:printf("Enter an integer element\n");
					scanf("%d",&ele);
					deleteNode(&tobj,ele);					
		}
	}while(choice<9);
	destroyTree(&tobj);
}
void initTree(TREE *pt)
{
	pt->root=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

void insertNode(TREE *pt,int ele)
{
	NODE *p=pt->root;
	NODE *q=NULL;
	
	NODE *newNode=createNode(ele);
	
	if(pt->root==NULL)
		pt->root=newNode;
	else
	{
		while(p!=NULL)
		{
			q=p;
		
			if(newNode->info < p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(newNode->info < q->info)
			q->left=newNode;
		else
			q->right=newNode;
	}	
}

NODE* insertNodeRec(NODE* p,NODE* newNode)
{
	if(p==NULL)
		return newNode;
	else if(newNode->info < p->info)
		p->left=insertNodeRec(p->left,newNode);
	else
		p->right=insertNodeRec(p->right,newNode);
	
	return p;
}
void insertRec(TREE *pt,int ele)
{
	NODE *newNode=createNode(ele);
	pt->root=insertNodeRec(pt->root,newNode);
}

void inorder(NODE *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d ",p->info);
		inorder(p->right);
	}
}
void inorderTraversal(TREE *pt)
{
	inorder(pt->root);
}
void preorder(NODE *p)
{
	if(p!=NULL)
	{
		printf("%d ",p->info);
		preorder(p->left);
		preorder(p->right);
	}
}
void preorderTraversal(TREE *pt)
{
	preorder(pt->root);
}
void postorder(NODE *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ",p->info);
	}
}
void postorderTraversal(TREE *pt)
{
	postorder(pt->root);
}
void destroyNode(NODE *p)
{
	if(p!=NULL)
	{
		destroyNode(p->left);
		destroyNode(p->right);
		free(p);
	}
}
void destroyTree(TREE *pt)
{
	if(pt->root!=NULL)
		destroyNode(pt->root);
	
	pt->root=NULL;
}

NODE* searchIterative(TREE *pt,int ele)
{
	NODE *p=pt->root;
	
	while(p!=NULL)
	{
		if(ele == p->info)
			return p;
		else if(ele < p->info)
			p=p->left;
		else
			p=p->right;
	}
	return NULL;		//return p;
}

NODE* searchNode(NODE *p,int ele)
{
	if(p==NULL)
		return p;
	else if(ele == p->info)
		return p;
	else if(ele < p->info)
		return searchNode(p->left,ele);
	else 
		return searchNode(p->right,ele);
}
NODE* searchRecursive(TREE *pt,int ele)
{
	return searchNode(pt->root,ele);
}
NODE* delNode(NODE *p,int ele)
{
	NODE *q;
	if(p==NULL)
		return p;
	else if(ele<p->info)
		p->left=delNode(p->left,ele);
	else if(ele > p->info)
		p->right=delNode(p->right,ele);
	else
	{
		if(p->left==NULL)		//Single right child or leaf node
		{
			q=p->right;
			free(p);
			inorderTraversal(q);
			return q;
		}
		else if(p->right==NULL)			//single left child
		{
			q=p->left;
			free(p);
			return q;
		}
		else		//2 children: replace by inorder successor
		{
			q=p->right;
			while(q->left!=NULL)
				q=q->left;
			
			p->info=q->info;
			p->right=delNode(p->right,q->info);
		}
	}
	return p;
}
void deleteNode(TREE *pt,int ele)
{
	if(pt->root!=NULL)
	{
		pt->root=delNode(pt->root,ele);
	}
}