#include<stdio.h>
#define MAX 50

void topDownHeap(int h[],int n);
int main()
{
	int h[MAX];
	int n;
	
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
		
	topDownHeap(h,n);
    printf("%c","|");
	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	for(int i=1;i<n;i++)
	{
		c=i;
		p=(c-1)/2;
		key=h[c];
		
		while(c>0 && key > h[p])
		{
			h[c]=h[p];
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
}
/* 
#include<stdio.h>
#define MAX 50

void topDownHeap(int h[],int n);
int main()
{
	int h[MAX];
	int n;
	
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	topDownHeap(h,n);

	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
}

void topDownHeap(int h[],int n)
{
	int c,p,key;
	
	scanf("%d",&h[0]);
	
	for(int i=1;i<n;i++)
	{
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		
		while(c>0 && key > h[p])
		{
			h[c]=h[p];
			c=p;
			p=(c-1)/2;
		}
		h[c]=key;
	}
} */