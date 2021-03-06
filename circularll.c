#include<stdio.h>
#include<conio.h>
void createList(int);
void insertList();
void deleteList();
void traverseList();
struct node
{
int data;
struct node *link;
};
typedef struct node Node;
Node *getnode();
Node *first=NULL,*last=NULL;
void main()
{
int ch=0,n;
clrscr();
printf("*********CIRCULAR LINKED LIST***********\n");
printf("CIRCULAR LINKED LIST CREATION : ");
printf("\nEnter the number of nodes : ");
scanf("%d",&n);
createList(n);
while(ch!=4)
{
printf("\n1.INSERTION\n2.DELETION\n3.TRAVERSE\n4.Exit");
printf("\nEnter your choice : ");
scanf("%d",&ch);
switch (ch)
{
case 1 : insertList();
break;
case 2 : deleteList();
break;
case 3 : traverseList();
break;

case 4 :exit(0);
default: printf("*********INVALID CHOICE********");
}
}
getch();
}
Node *getnode()
{
Node *newnode;
newnode=(Node *)malloc(sizeof(Node));
return newnode;
}
void createList(int n)
{
int i;
Node *newNode;
for(i=1;i<=n;i++)
{
newNode=getnode();
printf("Enter Node %d data : ",i);
scanf("%d",&newNode->data);
if(first==NULL)
first=newNode;
else
last->link=newNode;
newNode->link=first;
last=newNode;
}
}
void traverseList()
{
Node *temp;
if(first==NULL)
printf("\nList is Empty!!!!");
temp=first;
printf("\nCircular Linked List : ");
do
{
printf("%d->",first->data);
first=first->link;
} while(temp!=first);
printf("End\n");

}
void insertList()
{
Node *curr,*newNode;
int i,pos;
newNode=getnode();
if(newNode==NULL)
{
printf("\nNO MORE EMPTY NODES");
return;
}
printf("Enter the position of element : ") ;
scanf("%d",&pos);
printf("Enter the element : ");
scanf("%d",&newNode->data);
if((pos==1)||(first==NULL))
{
newNode->link=first;
if(last==NULL)
last=newNode;
else
last->link=newNode;
first=newNode;
}
else
{
curr=first;
for(i=2;i<=pos-1;i++)
{
curr=curr->link;
}
newNode->link=curr->link;
curr->link=newNode;
}
printf("Element inserted !!!!");
}
void deleteList()
{
Node *curr,*temp;
int pos,i;
if(first==NULL)

{printf("\nList is Empty!!");
return;}
printf("Enter position of element to be deleted : ");
scanf("%d",&pos);
curr=first;
if(pos==1)
{
if(first->link==first)
{
first=last=NULL;
}
else
{
first=first->link;
last->link=first;
}
printf("*****%d is deleted*****\n",curr->data);
free(curr);
}
else
{
i=2;
while(curr->link!=first)
{
if(i==pos)
{
temp=curr->link;
curr->link=temp->link;
printf("******%d is deleted******\n",temp->data);
free(temp);
return;
}
else
curr=curr->link;
i++;
}
printf("Invalid position!!!");
}
}