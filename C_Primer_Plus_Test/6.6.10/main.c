//
//  main.c
//  6.6.10
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>
int main()
{
    int x,y,i;
    long sum;
    printf("please enter lower and upper integer limits:");
    scanf("%d%d",&x,&y);
    if(x<=y)
    {
        for(i=x,sum=0;i<=y;i++)
            sum+=i*i;
        printf("the sum of the squares from %d to %d is %ld\n",x*x,y*y,sum);
    }
    else
    {
        printf("wrong!\n");
    }
    return 0;
}
