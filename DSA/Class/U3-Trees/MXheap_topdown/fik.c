#include<stdio.h>
#define MAX 50

int topDownHeap(int h[],int n);
int n;

printf("enter the elements/n");

int topDownHeap(int h[], int n)
{
    int c,p,key;
    for (int i=1;i<n;i++)
    {
        c=i;
        p=(c-1)/2;
        key=h[c];

        while(c>0 && key >h[p])
        {
            h[c]=h[p];
            c=p;
            p=(c-1)/2;
        }
        h[c]=key;
    }
}