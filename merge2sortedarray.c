#include <stdio.h>
#include<conio.h>
void main()
{
 int arr1[100], arr2[100], merge[200];
 int s1, s2, s3;
 int i,j,k;
 int i;

 printf("Enter the size of first array : ");
 scanf("%d", &s1);
 printf("Enter elements in first array : ");
 for(i=0; i<s1; i++)
 {
 scanf("%d", &arr1[i]);
 }
 printf("\nEnter the size of second array : ");
 scanf("%d", &s2);
 printf("Enter elements in second array : ");
 for(i=0; i<s2; i++)
 {
 scanf("%d", &arr2[i]);
 }
 s3 = s1 + s2;
 i = 0;
 j = 0;
 for(k=0; k < s3; k++)
 {

 if(i >= s1 || j >= s2)
 {
 break;
 }
 if(arr1[i] < arr2[j])
 {
 merge[k] = arr1[i];
 i++;
 }
 else
 {
 merge[k] = arr2[j];
 j++;
 }
 }
 while(i< s1)
 {
 merge[k] = arr1[i];
 k++;
 i++;
 }
 while(j < s2)
 {
 merge[k] = arr2[j];
 k++;
 j++;
 }
 printf("\nMerged two sorted array : ");
 for(i=0; i<s3; i++)
 {
 printf("%d\t", merge[i]);
 }
 getch();
}