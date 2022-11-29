//Creation of an ordered SLL
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int info;
	struct node *next;
}NODE;

typedef struct list
{
	NODE *head;
}LIST;
void initList(LIST *pl)
{
	pl->head=NULL;
}
void revoll(LIST *pl,LIST *rev);
void insertfirst(LIST *pl,int ele);
NODE* createNode(int ele)
{
	NODE* nn=malloc(sizeof(NODE));
    nn->info=ele;
    nn->next=NULL;
    return nn;
}

void ordInsrt(LIST *pl,int ele)
{
	NODE* nn=createNode(ele);
	NODE* p=pl->head;
    NODE* q=NULL;
    while (p!=NULL && nn->info>p->info)
    {
        q=p;
        p=p->next;
    }
    if(q==NULL) //insert front(empty list)
	{
		nn->next=pl->head;
		pl->head=nn;
	}
	else
	{
		nn->next=p;
		q->next=nn;
	}
	
}


void display(LIST *pl)
{
	if(pl->head==NULL)
		printf("Empty List\n");
	else
	{
		NODE *p=pl->head;
        while(p!=NULL)
        {
            printf("%d ",p->info);
            p=p->next;
        }
	}
}

void revoll(LIST *pl,LIST *rev)
{
    NODE* p=pl->head;
    NODE* q=NULL;
    while (p!=NULL)
    {
        q=p;
        insertfirst(rev,p->info);
        
        p=q->next;
    }
    
}
void insertfirst(LIST *pl,int ele)
{
	NODE* nn=createNode(ele);
	nn->next=pl->head;
	pl->head=nn;
    
}

void destroyList(LIST *pl)
{
	NODE *p=pl->head;
	while(pl->head!=NULL)
	{
		pl->head=pl->head->next;
        printf("%d freed \n",p->info);
        free(p);
        p=pl->head;
	}
}

int main()
{
	LIST lobj;
    LIST rev;
	
    initList(&rev);
	initList(&lobj);
	
	ordInsrt(&lobj,10);
	ordInsrt(&lobj,100);
	ordInsrt(&lobj,50);
	ordInsrt(&lobj,5);
	
	display(&lobj);
    revoll(&lobj,&rev);
    display(&rev);
	printf("\n");
	destroyList(&lobj);
}