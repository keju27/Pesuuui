#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};


void insertIntoHash(int size, int value, struct node** chain)
{
    // TODO
    int temp=0;
    int i;
    for(i = 0; i < size; i++)
    {
        temp=value%size;
        insertLast(temp,chain[i]);
    }

}

void insertLast(int value,struct node* chain)
{   
    struct node* ele=malloc(sizeof(struct node));
    ele->data=value;
    struct node* q=chain;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=ele;

}

void print(int size, struct node** chain)
{
    int i;
    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("[%d]",i);
        while(temp)
        {
            printf("->%d",temp->data);
            temp = temp->next;
        }
        printf("->NULL\n");
    }
}

void createHash(int size, int *stk, int n, struct node** chain)
{
    for(int i=0;i<n;i++){
        insertIntoHash(size, stk[i], chain);
    }
}

int main()
{
    int i;
    int size;
    scanf("%d", &size);

    struct node *chain[size];

    for(i = 0; i < size; i++){
        chain[i] = NULL;
    }

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    createHash(size, stk, n, chain);
    print(size, chain);

    return 0;
}