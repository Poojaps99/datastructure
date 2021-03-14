//Universal set is {1,2,3,4,5,6,7,8,9}
#include<stdio.h>
#include<conio.h>
void input();
void output();
void setunion();
void setinter();
void setdiff();
int a[]={0,0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};
int main()
{
int ch,wish;
clrscr();
do
{
printf("\n Menu\n");
printf("1. input\n2. union\n3. intersection\n4.difference\n");
printf("\n Enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1: input();
	break;
case 2: setunion();
	break;
case 3: setinter();
	break;
case 4: setdiff();
	break;
}
printf("\nDo you want to continue?(1/0)\n");
scanf("%d",&wish);
}
while(wish==1);
}
void input()
{
int n,x,i;
printf("Enter size of 1 set\n");
scanf("%d",&n);
printf("Enter elements\n");
for(i=1;i<=n;i++)
{
scanf("%d",&x);
a[x]=1;
}
printf("Enter size of 2 set\n");
scanf("%d",&n);
printf("Enter elements\n");
for(i=1;i<=n;i++)
{
scanf("%d",&x);
b[x]=1;
}
printf("\n 1st set\n");
for(i=1;i<=9;i++)
{
printf("%d",a[i]);
}
printf("\n 2nd set\n");
for(i=1;i<=9;i++)
{
printf("%d",b[i]);
}
}
void output(int c[])
{
int i;
printf("\n Set is");
for(i=1;i<=9;i++)
{
if(c[i]!=0)
printf("%d",i);
}
}
void setunion()
{
int i,c[10];
for(i=1;i<=9;i++)
{
if(a[i]!=b[i])
c[i]=1;
else
c[i]=a[i];
}
for(i=1;i<=9;i++)
{
printf("%d",c[i]);
}
output(c);
}
void setinter()
{
int i,c[10];
for(i=1;i<=9;i++)
{
if(a[i]==b[i])
c[i]=a[i];
else
c[i]=0;
}
for(i=1;i<=9;i++)
{
printf("%d",c[i]);
}
output(c);
}
void setdiff()
{
int i,c[10];
for(i=1;i<=9;i++)
{
if(a[i]==1 && b[i]==0)
c[i]=1;
else
c[i]=0;
}
for(i=1;i<=9;i++)
{
printf("%d",c[i]);
}
output(c);
}
