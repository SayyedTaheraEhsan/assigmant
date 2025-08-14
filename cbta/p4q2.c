#include<stdio.h>
int main()
{
    int i,j,sum,mult,sub;
    {
    printf("enter the 1st no to add\n");
    scanf("%d",&i);
    printf("enter the 2st no to add\n");
    scanf("%d",&j);
    sum=i+j;
    }
    {
     printf("you sum is %d\n",sum);
     printf("enter the 1st no to sub\n");
     scanf("%d",&i);
     printf("enter the 2st no to sub\n");
     scanf("%d",&j);
     sub=i-j;
     printf("you sub is %d\n",sub);
    }
    {
    printf("enter the 1st no to mult\n");
    scanf("%d",&i);
    printf("enter the 2st no to mult\n");
    scanf("%d",&j);
    mult=i*j;
    printf("you mult is %d\n",mult);
    }
    
    return 0;
}