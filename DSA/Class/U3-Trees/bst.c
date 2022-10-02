#include<stdio.h>
#include"bst.h"

int main()
{
	TREE tobj;
	initTree(&tobj);
	int choice;
	int ele;
	NODE *res=NULL;
	do
	{
		printf("1.Insert 2.Inorder 3.Preorder 4.Postorder 5.InsertNodeRec\n");
		printf("6.Search Iterative 7.Search recursive 8.deleteNode\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an integer element\n");
					scanf("%d",&ele);
					insertNode(&tobj,ele);
					break;
			case 2:printf("Inorder:\n");
					inorderTraversal(&tobj);
					break;
			case 3:printf("Preorder:\n");
					preorderTraversal(&tobj);
					break;
			case 4:printf("Postorder\n");
					postorderTraversal(&tobj);
					break;
			case 5:printf("Enter an integer element\n");
					scanf("%d",&ele);
					insertRec(&tobj,ele);
					break;
			case 6: printf("Enter an integer element\n");
					scanf("%d",&ele);
					res=searchIterative(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					break;
			case 7: printf("Enter an integer element\n");
					scanf("%d",&ele);
					res=searchRecursive(&tobj,ele);
					if(res==NULL)
						printf("%d not found\n",ele);
					else
						printf("%d found\n",res->info);
					break;
			case 8:printf("Enter an integer element\n");
					scanf("%d",&ele);
					deleteNode(&tobj,ele);					
		}
	}while(choice<9);
	destroyTree(&tobj);
}