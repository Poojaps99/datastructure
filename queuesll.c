#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *link;
};
struct node *front = NULL,*rear = NULL;
void insert();
void delete();
void display();
void main()
{
int ch;
clrscr();
printf("\n***** Queue Implementation using Linked List *****\n");
while(ch!=4){
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
switch(ch){
case 1:
insert();
break;
case 2: delete(); break;
case 3: display(); break;
case 4: exit(0);
default: printf("\nInvalid choice!!!\n");
}
}
}
void insert()
{
struct node *newnode;
int value;
newnode = (struct node*)malloc(sizeof(struct node));
printf("Enter the value to be inserted : ");
scanf("%d", &value);
newnode->data = value;
newnode -> link = NULL;
if(front == NULL)
front = rear = newnode;

else
{
rear -> link = newnode;
rear = newnode;
}
printf("\n %d is inserted",value);
}
void delete()
{
if(front == NULL)
printf("\nUnderflow!!!\n");
else
{
struct node *temp = front;
front = front -> link;
printf("\n%d element is deleted\n", temp->data);
free(temp);
}
}
void display()
{
if(front == NULL)
printf("\nUnderflow!!!\n");
else
{
struct node *temp = front;
while(temp->link!= NULL)
{
printf("%d--->",temp->data);
temp = temp -> link;
}
printf("%d--->NULL\n",temp->data);
}
}