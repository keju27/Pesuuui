#include<stdio.h>
#include<stdlib.h>
#include"bst.h" 

void initTree(TREE *pt)
{
    pt->root=NULL;
}
NODE* createNode(int ele)
{
    NODE *nn=malloc(sizeof(NODE));
    nn->info=ele;
    nn->left=nn->right=NULL;
    return nn;
}
void insertNode(TREE *pt,int ele)
{
    NODE *nn=createNode(ele);
    NODE *p=pt->root;
    NODE *q=NULL;
    if(pt->root==NULL)
    {
       pt->root=nn;
    }
    else
    {
       while(p!=NULL)
       {
        q=p;
        if(p->info<nn->info)
        p=p->left;
        else
        p=p->right;
       }
       if(nn->info<q->info)
       q->left=nn;
       else
       q->right=nn;
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
