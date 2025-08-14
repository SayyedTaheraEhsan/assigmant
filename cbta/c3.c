#include<stdio.h>
int main()
{
    int i,j,k;
    printf("enter a 3 no\n");
    scanf("%d%d%d",&i,&j,&k);
    if(i>j&&i>k)
    printf("your 1st no %d is largest value\n",i);
    else if(j>i&&j>k)
    printf("your 2nd no %d is largest value\n",j);
    else
    printf("your 3rd no %d is largest value\n",k);
    return 0;
}