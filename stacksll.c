#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
int data;
struct node *link;
};
struct node *top;

void main ()
{
 int ch,n;
 printf("\n\t****Stack using linked list*****\n");
 while(ch != 4)
 {
 printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
 printf("\n Enter your choice :
");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1: push(); break;
 case 2: pop();break;
 case 3: display(); break;
 default: printf("Invalid choice ");
 }
}
}
void push ()
{
 int ele;
 struct node *newNode;
 newNode= (struct node*)malloc(sizeof(struct node));
 if(newNode== NULL)
 printf("");

 else
 {
 printf("Enter the element :
");
 scanf("%d",&ele); 
 newNode
->data = ele;
 if(top==NULL)
 {
 newNode
-> link = NULL;
 }
 else
 {
 newNode
->link = top;
 }
 top=newNode;
 }
}

void pop()
{
 int item;
 struct node *temp;
 if (top == NULL)
 {
 printf("Underflow");
 }
 else
 {
 item = top
->data;
 temp = top;
 top = top
->link;
 free(temp);
 printf("%d is deleted",item);

 }
}
void display()
{
 int i;
 struct node *ptr;
 if(top == NULL)
 {
 printf("Stack is empty
\n");
 }
 else
 {
 ptr=top;
 printf("Stack elements are :");
 while(ptr!=NULL)
 {

printf("
\t%d-->",ptr
->data);
 ptr = ptr
->link; 
 }
 }
}