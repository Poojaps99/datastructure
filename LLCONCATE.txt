#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *link;
	int data;
};
typedef struct node nd;

nd *get()
{
	nd *t;
	t=(nd *)malloc(sizeof(nd));
	return t;
}

nd *s;

void in(int it)
{
	nd *t;
	t=get();
	if (t==NULL)
		printf("\n\nNOT qpossible\n");
	else
	{
		t->data=it;
		t->link=s;
		s=t;
	}
}

nd *q;

void in2(int it)
{
	nd *t=get();
	if(t==NULL)
		printf("\nNOT POSSible");
	else 
	{
		t->data=it;
		t->link=q;
		q=t;
	}
}

void dis()
{
	nd *t;
	t=s;
	if(t==NULL)
		printf("\n\nnot happening");
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->link;
	}
}

void dis2()
{
	nd *t;
	t=q;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->link;
	}
}

void con()
{
	nd *a,*b;
	b=s;
	a=b;
	while(a->link!=NULL)
		a=a->link;
	a->link=q;
}

void main()
{
	//int a;
	clrscr();
	in(2);
	in(5);
	in(7);
	in2(1);
	in2(9);
	in2(4);
	dis();
	printf("\n\n\n");
	dis2();
	printf("\n\n\n");
	con();
	dis();
	getch();
}