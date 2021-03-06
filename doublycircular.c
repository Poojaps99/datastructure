#include<stdio.h>
#include<conio.h>
void createList(int);
void insertBeg();
void insertLast();
void insertAt();
void deleteBeg();
void deleteLast();
void deleteAt();
void searchList();
void traverseList();
struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node dNode;
dNode *getnode();
dNode *first;
void main()
{
int n,ch;
printf("******************DOUBLY LINKED LIST OPERATIONS***************
****\n");
printf("\nDoubly Linked list Creation\n");
printf("Enter the number of nodes : ");
scanf("%d",&n);
first=NULL;
createList(n);
while(1)
{
printf("\n\n1.Insert at beginning\n2.Insert at Last\n3.Insert at Position\n4.Delet
e at beginning\n5.Delete at Last\n6.Delete at Position\n7.Search an Element\n8.Trav
ersal\n9.Exit\nEnter your choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1 : insertBeg();break;

case 2 : insertLast();break;
case 3 : insertAt();break;
case 4 : deleteBeg();break;
case 5 : deleteLast();break;
case 6 : deleteAt();break;
case 7 : searchList();break;
case 8 : traverseList();break;
case 9 : exit(0);
default : printf("*********INVALID CHOICE*********");
}
}
}
dNode *getnode()
{
dNode *newnode;
newnode=(dNode *)malloc(sizeof(dNode));
return(newnode);
}
void createList(int n)
{
dNode *newNode,*curr;
int i;
for(i=1;i<=n;i++)
{
newNode=getnode();
printf("Enter Node %d data : ",i);
scanf("%d",&newNode->data);
newNode->right=NULL;
if(first==NULL)
{
first=newNode;
newNode->left=NULL;
}
else
{
curr->right=newNode;
newNode->left=curr;
}
curr=newNode;
}
}
void insertBeg()
{

dNode *newNode;
newNode=getnode();
printf("Enter element : ");
scanf("%d",&newNode->data);
newNode->left=NULL;
if(first==NULL)
newNode->right=NULL;
else
{
newNode->right=first;
first->left=newNode;
}
first=newNode;
printf("***********%d is inserted*********",newNode->data);
}
void insertLast()
{
dNode *newNode,*curr;
newNode=getnode();
printf("Enter element : ");
scanf("%d",&newNode->data);
newNode->right=NULL;
if(first==NULL)
{
newNode->left=NULL;
first=newNode;
}
else
{
curr=first;
while(curr->right!=NULL)
curr=curr->right;
newNode->left=curr;
curr->right=newNode;
}
printf("**********%d is inserted*********",newNode->data);
}
void insertAt()
{
dNode *newNode,*curr;
int pos,i;
newNode=getnode();
printf("Enter the position of element : ") ;

scanf("%d",&pos);
printf("Enter element : ");
scanf("%d",&newNode->data);
if(pos==1)
{
if(first!=NULL)
first->left=newNode;
newNode->right=first;
newNode->left=NULL;
first=newNode;
}
else
{
i=2;
curr=first;
while((i<pos)&&(curr->right!=NULL))
{
i++;
curr=curr->right;
}
newNode->left=curr;
newNode->right=curr->right;
if(curr->right!=NULL)
newNode->right->left=newNode;
curr->right=newNode;
}
printf("**********%d is inserted**********",newNode->data);
}
void deleteBeg()
{
dNode *curr;
if(first==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
curr=first;
first=first->right;
if(first!=NULL)
first->left=NULL;
printf("************%d is deleted***********",curr->data);
free(curr);
}

void deleteLast()
{
dNode *curr;
if(first==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
curr=first;
while(curr->right!=NULL)
curr=curr->right;
if(curr->left!=NULL)
curr->left->right=curr->right;
else
first=NULL;
printf("**********%d is deleted***********",curr->data);
free(curr);
}
void deleteAt()
{
dNode *curr,*prev;
int i=1,pos,item;
if(first==NULL)
{
printf("\nLIST IS EMPTY");
return;
}
printf("Enter the position of element : ") ;
scanf("%d",&pos);
curr=first;
while(curr!=NULL)
{
if(i==pos)
{
item=curr->data;
if(curr->left==NULL)
{
curr->right->left=NULL;
first=curr->right;
free(curr);
}
else if(curr->right==NULL)
{
curr->left->right=curr->right;

free(curr);
}
else
{
curr->left->right=curr->right;
curr->right->left=curr->left;
free(curr);
}
printf("*********%d is deleted**********",item);
return;
}
i++;
curr=curr->right;
}
printf("\n*******INVALID POSITION****");
}
void searchList()
{
int key;
dNode *temp;
if(first==NULL)
printf("\nLIST IS EMPTY");
printf("Enter search element : ");
scanf("%d",&key);
temp=first;
while(temp!=NULL)
{
if(temp->data==key)
{
printf("%d found in the list",key);
return;
}
else
temp=temp->right;
}
printf("%d is not found in the list",key);
}
void traverseList()
{
dNode *temp;
if(first==NULL)

printf("\nLIST IS EMPTY");
else
{
temp=first;
printf("\nDoubly Linked List : ");
while(temp!=NULL)
{
printf("%d->",temp->data);
temp=temp->right;
}
printf("End\n");
}
}