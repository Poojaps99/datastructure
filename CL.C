#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
};
 typedef struct node node;
 node *getnode();
int main()
  {
  node *first,*last;
  int ch,item,pos,n;
  InitializeCList(&first,&last);
  clrscr();
  printf("\nCreating a circular linked list");
  printf("\nEnter the no of elements:");
  scanf("%d",&n);
  CreateCList(&first,&last);
  while(ch!=4)
  {
   printf("\n1.Inserton\n2.Deletion\n3.Display\n4.Exit");
   printf("\nEnter the choice:");
   scanf("%d",&ch);
   switch(ch)
    {
    case 1:{
	   printf("\nEnter the item:");
	   scanf("%d",&item);
	   printf("\nEnter the position to insert the element:");
	   scanf("%d",&pos);
	   InsertCList(&first,&last,item,pos);
	   break;
	   }
    case 2:{
	    printf("\nEnter the node to delete:");
	    scanf("%d",&pos);
	    DeleteCList(&first,&last,pos);
	    break;
	    }
    case 3:DisplayCList(first,last);
	   break;
    case 4:printf("\nExiting");
	   exit(0);
    default:printf("Invalid");
    }
    }
    getch();
}
InitializeCList(node **first,node **last)
  {
  (*first)=NULL;
  (*last)=NULL;
  }
CreateCList(node **f,node **l,int n)
 {
 node *t,*c;
 int i,item;
 for(i=1;i<=n;i++)
  {
   printf("\nEnter the element %d",i);
   scanf("%d",&item);
   t=getnode();
   t->data=item;
   if(*f==NULL)
     *f=t;
   else
     (*l)->next=t;
   (*l)=t;
   }
    }
DisplayCList(node *first,node *last)
 {
  if(first==NULL)
   {
   printf("\nList is empty");
   return;
   }
  printf("\nThe elements in the list is: \n");
  printf("\nStart->");
  do
  {
   printf("%d ->",first->data);
   first=first->next;
   }while(last->next!=first);
  printf("End\n");
   }
InsertCList(node **first,node **last,int item,int pos)
 {
  node *c,*prev,*t;
  int i;
  t=getnode();
  if(t==NULL)
   {
   printf("\nUnable to insert");
   return;
   }
  if((*first==NULL)||(pos==1))
  {
  t->data=item;
  t->next=(*first);
  if(*last==NULL)
    (*last)=t;
  else
    (*last)->next=t;
  (*first)=t;
  return;
  }
  c=(*first);
  i=2;
  while(c->next!=NULL)
  {
  if(i==pos)
   {
    t->data=item;
    t->next=c->next;
    c->next=t;
    return;
   }
  else
   {
   i++;
   c=c->next;
   }
   }
   t->data=item;
   t->next=c->next;
   c->next=t;
   (*last)=t;
   }
DeleteCList(node **first,node **last,int pos)
   {
   node *current,*temp;
   int item,i;
   if(*first==NULL)
    {
    printf("\nList is empty");
    return;
    }
   if(pos==1)
    {
    current=(*first);
    item=current->data;
    if((*first)->next==(*first))
      (*first)=(*last)=NULL;
    else
      {
      (*first)=(*first)->next;
      (*last)->next=(*first);
      }
    freenode(current);
    printf("\nDeleted element = %d",item);
    }
    current=(*first);
    i=2;
    while(current->next!=(*first))
     {
     if(i==pos)
      {
      temp=current->next;
      item=temp->data;
      current->next=temp->next;
      freenode(temp);
      printf("\nDeleted element = %d",item);
      return;
      }
     else
       current=current->next;
     i++;
      }
     printf("\nInvalid node num");
     }
     node *getnode()
     {
     node *t;
     t=(node *)malloc(sizeof(node));
     return t;
     }
     freenode(node *t)
     {
     free(t);
     }










