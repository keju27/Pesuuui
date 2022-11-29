#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node*deleteFriends(int key, struct node*users);
void refineFriends(struct node* root, struct node*user);
struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    //CODE HERE
    node *p=users;
	
	while(p!=NULL)
	{
		if(key == p->id)
			return p;
		else if(key < p->id)
			p=p->left;
		else
			p=p->right;
	}
	return NULL;	
}
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    while(search(user->id,users)!=NULL)
    {
        user->id++;
    }  
   node *temp_friend;
   int tempFriend[MAX];
   int validFriend=0;
   int i=0;

    for(i=0; i<user->numfren;i++)
    {

        temp_friend=search(user->friends[i],users);
        if(temp_friend!=NULL)
        {
            tempFriend[validFriend++]=user->friends[i];
            temp_friend->friends[temp_friend->numfren++]=user->id;
        }
    }  
    
    for(i=0;i< user->numfren;i++)
    {
        user->friends[i]=-1;
    }
    user->numfren=0;

    for(i=0; i<validFriend;i++)   
    {
        user->friends[i]= tempFriend[i];
    }
    user->numfren=i;
    return user;
}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
    //CODE HERE
    user->right=NULL;
    user->left=NULL;
    if (root==NULL) 
    {
        root=user; 
    }
    if (id > root->id) 
    {
        root->right = insertUser(root->right, id,user);
    }
    else if (id < root->id)
    {
        root->left = insertUser(root->left,id, user);
    }
    return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE
   node *user;
   user=search(id,users);
   int i=0;
   for(i=0; i<users->numfren;i++)
    {
        printf("%d\n",*(user->friends));
        user->friends++;
    }
}


bool inFriendlist(int key,struct node* user) //function to check if key is in friends list
{   
     for(int i=0; i<user->numfren;i++)
    {
        if (user->friends[i]==key)
        {
            return true;
        }
    
    }
    return false;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
    node *root=users;
    if (users==NULL)
    {
        return root;
    }
    else if(users!=NULL)
    {
        if (users->id==key)
        {
            
        }
        else
        {   
            deleteFriends(key,users->left);
            deleteFriends(key,users->right);
            for(int i=0; i<users->numfren;i++)
            {
                if(users->friends[i]==key)
                {
                    
                    for(int j=i; j<users->numfren;j++)
                    {
                        users->friends[j]=users->friends[j++];
                    }
                    users->numfren--;

                }
                if(users->numfren==0)
                {
                    users->friends[0]=-1;
                }
            }
            
        }
    
    }
    return root;
        
}  

//helper function for deletenode
struct node *delNode(struct node *root, int key)
{
    node* q;
    node *roots=root;
  if (roots==NULL)
  {
    return roots;
  }
  else if(key<roots->id)
    {   
        roots->left=delNode(roots->left,key);
    }
  else if (roots->id<key)  
  {
        roots->right=delNode(roots->right,key);
  }
  else
    {  
        if(roots->left==NULL)
        {   
            q=roots->right;
            free(roots);
            return q;
        } 
        else if(roots->right==NULL)			
		{
			q=roots->left;
			free(roots);
			return q;
		}
		else		
		{
			q=roots->right;
			while(q->left!=NULL)
				q=q->left;
			
			roots->id=q->id;
            roots->friends=q->friends;
            strcpy(roots->name,q->name);
            roots->numfren=q->numfren;
			roots->right=delNode(roots->right,q->id);
		}
	}
	return roots;
}
// Deleting a node Return root of updated tree
struct node *deleteNode(struct node *root, int key) {
  //CODE HERE
  struct node* newr=root;
  if (root!=NULL)
  newr=delNode(root,key);
  return newr;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if (myusers==NULL)
    {
        return;
    }
    else
    {   
        printInOrder(myusers->left);
        printf("%d %s\n",myusers->id,myusers->name);
        printInOrder(myusers->right);
    }   
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str);
                tbins=refineUser(tbins, users);
                users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                deleteFriends(id, users);
                users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}