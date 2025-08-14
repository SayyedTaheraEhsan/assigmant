#include<stdio.h>
int main()
{
    int i,j;
    printf("enter your 1st no\n");
    scanf("%d",&i);
    printf("enter your 2nd no\n");
    scanf("%d",&j);
    if(i<j)
    printf("2nd no is geter 1st no\n");
    else if(i>j)
      printf("first no is geter then 2nd no\n");
     else 
      printf("your no is equal\n");
      return 0;
}