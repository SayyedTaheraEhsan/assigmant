#include<stdio.h>
int main()
{
    {
    int j,i;
    printf("enter the no \n");
    scanf("%d",&i);
    j=sizeof(int(i));
    printf("%d",j);
     
    }{
    float j,i;
    printf("enter the no \n");
    scanf("%d",&i);
    j=sizeof(float(i));
    printf("%d",j);
    }
    {
  char j,i;
    printf("enter the char\n");
    scanf("%d",&i);
    j=sizeof(char(i));
    printf("%d",j);
    }
    return 0;
    
}