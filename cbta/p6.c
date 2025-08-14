#include<stdio.h>
int main()
{
    int i,j;
    printf("enter 1st no\n");
    scanf("%d",&i);
    printf("enter 1st no\n");
    scanf("%d",&j);
    i=(i+j)-i;
    j=(j+i)-j;
    printf("your swaping value is %d and %d\n",i,j);
    return 0;
}