//Universal Set is {1,2,3,4,5,6,7,8,9}
#include<stdio.h>;
void Input();
void Display();
void Union();
void Intersection();
void Difference();
int a[]={0,0,0,0,0,0,0,0,0};
int b[]={0,0,0,0,0,0,0,0,0};
int c[]={0,0,0,0,0,0,0,0,0};
void main()
{
    int ch;
    clrscr();
    printf("********************SET OPERATIONS********************\n");
    do
    {
        
        printf("1.Input\n2.Union\n3.Intersection\n4.Difference\n5.Exit\n");
        printf("Enter choice    :   ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Input();break;
            case 2:Union();break;
            case 3:Intersection();break;
            case 4:Difference();break;
            case 5:exit(0);
            default:printf("\n***********invalid choice********\n");
        }
    }while(ch!=5);
}
void Input() 
{
    int n1,n2,x,i;
    printf("\nEnter size of SET 1 :  ");
    scanf("%d",&n1);

    printf("Enter elements of SET 1   :   ");
    for(i=1;i<=n1;i++)
    {
        scanf("%d",&x);
        a[x]=1;
    }
    printf("\nEnter size of SET 2   :   ");
    scanf("%d",&n2);
    printf("Enter elements of SET 2   :   ");
    for(i=1;i<=n2;i++)
    {
        scanf("%d",&x);
        b[x]=1;
    }
    printf("\nSET 1 :   {");
    for(i=1;i<=9;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("}");
    printf("\nSET 2 :   {");
    for(i=1;i<=9;i++)
    {
        printf("%d\t",b[i]);
    }
     printf("}");
}
void Display(int c[])
{
    int i;
    printf("\n\t\t{");
    for(i=1;i<=9;i++)
    {
       if (c[i]!=0)
       printf("%d  ",i);
    }
    printf("}");   
}
void Union()
{
  int c[10],i;
  for(i=1;i<=9;i++) 
  {
    if(a[i]!=b[i])
        c[i]=1;
    else
        c[i]=a[i];
  }

  printf("\nSET is :   {");
  for(i=1;i<=9;i++)  
    {
        printf("%d  ",c[i]);
    }
  printf("}");
   Display(c);
}
void Intersection()
{
  int c[10],i;
  for(i=1;i<=9;i++)
  {
    if (a[i]==b[i])
        c[i]=a[i];
    else
        c[i]=0;
  }
  printf("\nSET is :   {");
  for(i=1;i<=9;i++)
  {
    printf("%d  ",c[i]);
  }
  printf("}");
   Display(c);
}
void Difference()
{
  int c[10],i;
  for(i=1;i<=9;i++)
  {
    if (a[i]==1 && b[i]==0)
        c[i]=1;
    else
        c[i]=0;
  }
  printf("\nSET is :   {");
  for(i=1;i<=9;i++)
  {
    printf("%d  ",c[i]);
  }
  printf("}");
   Display(c);
}