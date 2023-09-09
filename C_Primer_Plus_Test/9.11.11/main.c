//
//  main.c
//  9.11.11
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
/*int Fibonacci(int n);
int main()
{
    int n;
    printf("Please tell many numbers your Fibonacci consists:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        printf("Fibonacci(%d)=%d\n",i,Fibonacci(i));
    return 0;
}
int Fibonacci(int n)
{
    if(n<=2)
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}*/
int main()
{
    int a=1,b=1;
    int i=3;
    int n;
    printf("Please tell many numbers your Fibonacci consists:");
    scanf("%d",&n);
    printf("Fibonacci(1)=1\nFibonacci(2)=1\n");
    while(i<=n)
    {
        a+=b;
        printf("Fibonacci(%d)=%d\n",i++,a);
        if(i>n)
            break;
        b+=a;
        printf("Fibonacci(%d)=%d\n",i++,b);
    }
    return 0;
}
