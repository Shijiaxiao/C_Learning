//
//  main.c
//  9.11.4
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
double har_me(double a,double b);
int main()
{
    double a,b;
    printf("Please tell me two numbers:");
    scanf("%lf%lf",&a,&b);
    printf("The harmonic mean of %lf and %lf is %lf.\n",a,b,har_me(a,b));
    return 'A';
}
double har_me(double a,double b)
{
    double av=2.0 / (1/a +1/b) ;
    return av;
}
