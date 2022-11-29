// Josephus problem using circular linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

typedef struct list
{
    NODE *head, *tail;
} LIST;

void initQueue(LIST *pl)
{
    pl->head = pl->tail = NULL;
}

void createQueue(LIST *pl)
{
    int n;
    printf("Enter the no. of soldiers\n");
    scanf("%d", &n);

    NODE *temp = malloc(sizeof(NODE));
    temp->info = 1;
    temp->next = temp;
    pl->head = pl->tail = temp;

    for (int i = 2; i <= n; i++)
    {
        NODE *temp = malloc(sizeof(NODE));
        temp->info = i;
        temp->next = pl->head;
        pl->tail->next = temp;
        pl->tail = temp;
    }
}

void display(LIST *pl)
{
    NODE *p = pl->head;
    do
    {
        printf("%d ", p->info);
        p = p->next;
    } while (p != pl->head);
    printf("\n");
}

int winner(LIST *pl, int start, int skip)
{
    NODE *p = pl->head, *q = pl->tail;

    int count = 1;
    while (count != start)
    {
        count++;
        q = p;
        p = p->next;
    }
    while (p != p->next)
    {
        for (int i = 1; i != skip; i++)
        {
            q = p;
            p = p->next;
        }
        printf("%d killed\n", p->info);
        q->next = p->next;
        free(p);
        p = q->next;
    }
    int ele = p->info;
    free(p);
    pl->head = pl->tail = NULL;
    return ele;
}

int main()
{
    LIST l;
    int start, skip;

    initQueue(&l);
    createQueue(&l);
    display(&l);
    printf("Enter start value and skip value\n");
    scanf("%d %d", &start, &skip);
    printf("Winner is %d\n", winner(&l, start, skip));
    return 0;
}