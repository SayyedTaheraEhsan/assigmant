#include<stdio.h>
int main()
{
    int i,j,k;
    printf("enter 1st no\n");
    scanf("%d",&i);
    printf("enter 1st no\n");
    scanf("%d",&j);
    k=i;
    i=j;
    j=k;
    printf("your no swap ans is %d and %d\n",i,j);
    return 0;
}
