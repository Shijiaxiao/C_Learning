//
//  main.c
//  9.11.8
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
double power(double a,int n);
int main()
{
    double a;
    int n;
    printf("Please give me a number:");
    scanf("%lf",&a);
    printf("Please tell me the power of the number:");
    scanf("%d",&n);
    printf("%lf to the power of %d is %lf\n",a,n,power(a,n));
    return 0;
}
double power(double a,int n)
{
    double r;
    if(a==0)
    {
        if(n==0)
            return 1;
        else
            return 0;
    }
    else
    {
        if(n<0)
        {
            r=1/a * power(a,n+1);
            return r;
        }
        else if(n>0)
        {
            r=a * power(a,n-1);
            return r;
        }
        else
            return 1;
    }
}
