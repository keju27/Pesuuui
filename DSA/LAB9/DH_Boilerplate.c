#include <stdio.h>
#include<stdlib.h>
#define SIZE 13

void insertIntoHash(int key, int *hashtable)
{
    // TODO
}

void printHashTable(int *hashtable)
{
    // TODO
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}