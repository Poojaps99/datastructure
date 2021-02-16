#include<conio.h>
#include<stdio.h>
#define V 4

void init(int a[][V])
{
int i,j;
for(i=0;i<V;i++)
for(j=0;j<V;j++)
a[i][j]=0;
}

void add(int a[][V],int i,int j)
{
a[i][j]=1;
a[j][i]=1;
}

void print(int a[][V])
{
int i,j;
for(i=0;i<V;i++)
{
printf("%d:",i);
for(j=0;j<V;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}
}
void main()
{
int b[V][V];
clrscr();

init(b);

add(b,0,1);
add(b,0,2);
add(b,1,2);
add(b,2,0);
add(b,2,3);

print(b);

getch();
}