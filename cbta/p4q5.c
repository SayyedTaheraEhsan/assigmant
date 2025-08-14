#include<stdio.h>
int main()
{
    int i;
    printf("enter your markse 0 to 100\n");
    scanf("%d",&i);
    if(i<35)
    printf("F\n");
    else if(i<40&&i>35)
      printf("P\n");
     else if(i<40&&i>55)
      printf("C\n");
     else if(i<55&&i>65)
      printf("B\n");
     else if(i<65&&i>85)
      printf("A\n");
     else if(i<85&&i>100)
      printf("O\n");
      else
      printf("marks is not more then 100\n");
      return 0;
}