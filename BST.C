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
{int v;
tnode *root;
root=NULL;
tcreate(&root,6);
tcreate(&root,4);
tcreate(&root,8);
tcreate(&root,3);
tcreate(&root,7);
clrscr();
tdisplay(root,1);
printf("\nEnter item to search");
scanf("%d",&v);
tsearch(v);
printf("\nEnter item to delete");
scanf("%d",&v);
tdelete(&root,v);
printf("Tree after deletion");
tdisplay(root,1);
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
{
if(v>c->data)
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
}
tdisplay(tnode *rt,int level)
{
int i;
if(rt!=NULL)
{
tdisplay((rt)->rchild,level+1);
printf("\n");
for(i=0;i<level;i++)
printf("   ");
printf("%d",(rt)->data);
tdisplay((rt)->lchild,level+1);
}
}
tnode *getnode()
{
tnode *t;
t=(tnode *)malloc(sizeof(tnode));
return t;
}
tdelete(tnode **rt,int v)
{
tnode *c;
if(*rt==NULL)
{
printf("error");
getch();
return;
}
if(v<(*rt)->data)
tdelete(&((*rt)->lchild),v);
else
{
if(v>(*rt)->data)
tdelete(&((*rt)->rchild),v);
else
{
c=(*rt);
if(c->rchild==NULL)
{
(*rt)=(*rt)->lchild;
free(c);
}
else
{
if(c->lchild==NULL)
{
(*rt)=(*rt)->rchild;
free(c);
}
else
{
c=(*rt)->rchild;
while(c->lchild!=NULL)
c=c->lchild;
c->lchild=(*rt)->lchild;
c=(*rt);
(*rt)=(*rt)->rchild;
free(c);
}
}
}
}
}
tsearch(int v)
{
tnode *t,*root;
if(root==NULL)
{
printf("\n Tree empty");
return;
}
if(v==root->data)
{
printf("\nElement found at root");
return;
}
else if(v<root->data)
{
printf("\nElement found at leftsub");
return;
}
else
{
printf("Element at right sub");
return;
}
}