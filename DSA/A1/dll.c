#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* nn=malloc(sizeof(node_t));
	nn->prev=NULL;
	nn->next=NULL;
	nn->data=data; 

	if(list->head=NULL)
	{
		list->head=nn;
		list->tail=nn;
	}
	else
	{
		nn->next=list->head;
		list->head->prev=nn;
		list->head=nn;
	}
	list->size++;

}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* nn=malloc(sizeof(node_t));
	nn->prev=NULL;
	nn->next=NULL;
	nn->data=data; 
	node_t* temp=list->head;
	if(list->head==NULL)
	{
		list->head=nn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		nn->prev=temp;
		temp->next=nn;
		nn->next=NULL;
	}
	list->tail=nn;
	list->size++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* nn=malloc(sizeof(node_t));
	nn->prev=NULL;
	nn->next=NULL;
	nn->data=data; 

	node_t* temp=list->head;
	if(list->head==NULL)
	{
		list->head=nn;
		list->tail=nn;
	}
	else
	{
		temp=temp->next;
		while(temp->prev->data!=data)
		{
			temp=temp->next;
		}
		if (temp->next==NULL)
			list->tail=nn;
		nn->next=temp;
		nn->prev=temp->prev;
		temp->prev->next=nn;
		temp->prev=nn;	
		
	}
	list->size++;
	
	
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	if(list->head==NULL)
	return;
	else if(list->head->next==NULL)
	{
		free(list->head);
		list->head=NULL;
	}
	else	
	{
		
		list->head=list->head->next;
		free(list->head->prev);
		list->head->prev=NULL;
	}
	list->size--;
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	if (list->head==NULL)
	{
		return;
	}
	else if(list->head->next==NULL)
	{
		list->head=NULL;
		list->tail=NULL;
	}
	else
	{
		list->tail=list->tail->prev;
		list->tail->next->prev=NULL;
		free(list->tail->next);
		list->tail->next=NULL;
	}
	list->size--;
}


void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
    node_t *p=list->head;
    while(p!=NULL)
    {
        if(p->data==data)
        {
            if(p==list->tail)
            {
                list->tail=p->prev;
            }
            if(p==list->head)
            {
                list->head=p->next;
                p->next->prev=NULL;
                free(p);
                return;
            }
            else
            {
                p->prev->next=p->next;
                p->next->prev=p->prev;
                free(p);
                return;
            }
        }

        p=p->next;
    }
    list->size--;
}

node_t *search(list_t *list, int data) // returns the pointer to the node with “data” field. Return NULL if not found.
{
	if (list->head)
	{
		node_t *current = list->head;
		while (current && current->data != data)
		{
			current = current->next;
		}
		return current;
	}
	return NULL;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}