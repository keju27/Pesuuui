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

NODE *insert_pos(NODE *head, int ele, int pos)
{
    NODE *p = head, *q = NULL, *temp = getNode(ele);
    int i = 1;
    while (p != NULL && i < pos)
    {
        q = p;
        p = p->next;
        i++;
    }
    if (q == NULL)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    q->next = temp;
    temp->next = p;
    return head;
}

NODE *delete_alt(NODE *head)
{
    NODE *p = head, *q = NULL;
    while (p != NULL && p->next != NULL)
    {
        q = p->next;
        p->next = q->next;
        free(q);
        p = p->next;
    }
    return head;
}

int count(NODE *head)
{
    NODE *p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
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

int main()
{
    NODE *head = NULL;
    int ch, ele, pos;
    while (1)
    {
        printf("1.Insert at position 2.Delete alternate nodes 3.Count 4.Display 5.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element and position");
            scanf("%d %d", &ele, &pos);
            head = insert_pos(head, ele, pos);
            break;
        case 2:
            head = delete_alt(head);
            break;
        case 3:
            printf("Count= %d\n", count(head));
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}