#include<stdio.h>
int main()
{
    int a,b,c,i,j,k;
    printf("enter your 1st no\n");
    scanf("%d",&i);
    printf("enter your 2nd no\n");
    scanf("%d",&j);
    printf("enter your 2nd no\n");
    scanf("%d",&k);
    a=i+j;
    b=i+k;
    c=j+k;
    if(a>k&&b>j&&c>i)
    printf("the form sides of tringle\n");
    
     else 
      printf("the cant form sides of tringle\n");
      return 0;
}