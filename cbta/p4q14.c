#include<stdio.h>
int main()
{
    int i,i1,j1,t,k1,j,k;
    printf("enter your no\n");
    scanf("%d",i);
    printf("enter your no\n");
    scanf("%d",j);
     printf("enter your no\n");
    scanf("%d",k);
    i1=i*i;
    j1=j*j;
    k1=k*k;
    t=i1+j1;
    if(k1==t)
    printf("your form is pythagoran triplet");
    else
    printf("your form is not pythagoran triplet");
    return 0;
}