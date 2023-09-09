//
//  main.c
//  9.11.6
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
void compare(double *a,double *b,double *c);
int main()
{
    double a,b,c;
    printf("Please tell me 3 numbers, I can sort them for you:");
    scanf("%lf%lf%lf",&a,&b,&c);
    compare(&a,&b,&c);
    printf("The sequence of these numbers (max->min) are:%lf %lf %lf\n",a,b,c);
    return 0;
}
void compare(double *a,double *b,double *c)
{
    int temp;
    if(*a<*b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
    if(*b<*c)
    {
        temp=*b;
        *b=*c;
        *c=temp;
    }
    if(*a<*b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
}
