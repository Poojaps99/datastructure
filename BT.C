#include<stdio.h>
#include<conio.h>
struct tnode
{
struct tnode *lchild;
int data;
struct tnode *rchild;
};
typedef struct tnode tnode;
tnode *getnode();
main()
{
tnode *rt;
rt=NULL;
tcreate(&rt,6);
tcreate(&rt,4);
tcreate(&rt,8);
tcreate(&rt,3);
tcreate(&rt,7);
tcreate(&rt,5);
tcreate(&rt,9);
tcreate(&rt,11);
tcreate(&rt,10);
clrscr();
tdisplay(rt,1);
getch();
}
tcreate(tnode **rt,int v)
{
tnode *c=(*rt),*t;
if((*rt)==NULL)
{
(*rt)=getnode();
(*rt)->data=v;
(*rt)->lchild=NULL;
(*rt)->rchild=NULL;
return;
}
while(c!=NULL)
{
if(v<c->data)
{
if(c->lchild!=NULL)
c=c->lchild;
else
{
t=getnode();
c->lchild=t;
t->data=v;
t->rchild=NULL;
t->lchild=NULL;
return;
}
}
else
if (v>c->data)
{
if(c->rchild!=NULL)
c=c->rchild;
else
{
t=getnode();
c->rchild=t;
t->data=v;
t->rchild=NULL;
t->lchild=NULL;
return;
}
}
else
{
printf("Wrong data");
exit(0);
}
}
}
tdisplay(tnode *rt,int l)
{
int i;
if((rt)!=NULL)
{
tdisplay((rt)->rchild,l+1);
printf("\n");
for(i=0;i<l;i++)
printf("  ");
printf("%d",(rt)->data);
tdisplay((rt)->lchild,l+1);
}
}
tnode *getnode()
{
tnode *t;
t=(tnode *)malloc(sizeof(tnode));
return t;
}