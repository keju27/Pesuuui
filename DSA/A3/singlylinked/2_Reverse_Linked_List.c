// Write code to reverse a singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE *getNode(int ele)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

NODE *ordIns(NODE *phead, int ele)
{
    NODE *p = phead, *q = NULL;
    NODE *temp = getNode(ele);

    while (p != NULL && temp->info > p->info)
    {
        q = p;
        p = p->next;
    }

    if (q == NULL) // if(p==phead)
    {
        temp->next = phead;
        phead = temp;
        return phead;
    }

    q->next = temp;
    temp->next = p;
    return phead;
}

void display(NODE *phead)
{
    if (phead == NULL)
    {
        printf("Empty List");
        return;
    }
    NODE *p = phead;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

NODE *reverse(NODE *phead)
{
    NODE *p = phead, *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    return q;
}

int main()
{
    NODE *head = NULL;
    int ele;
    printf("Enter elements to insert in sorted order. Enter -1 to stop.\n");
    scanf("%d", &ele);
    while (ele != -1)
    {
        head = ordIns(head, ele);
        scanf("%d", &ele);
    }
    printf("The list is:\n");
    display(head);
    head = reverse(head);
    printf("The reversed list is:\n");
    display(head);
    return 0;
}
