#include<stdio.h>
#include<math.h>
int main()
{   
    int a,b,c;
    float ans1,ans2;
    printf("enter the value of a\n");
    scanf("%d",&a);
    printf("enter the value of b\n");
    scanf("%d",&b);
    printf("enter the value of c\n");
    scanf("%d",&c);
    ans1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
    ans2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
    printf("your ans is %f,%f\n",ans1,ans2);
    return 0;
}