//
//  main.c
//  6.6.11
//
//  Created by 史家箫 on 2021/9/26.
//
/*
#include <stdio.h>
#define SIZE 8
int F(int i,int index,int a[SIZE],int b[SIZE])
{
    if(a[index]==b[i]) return 1;
    else return 0;
}
int main()
{
    int a[SIZE],b[SIZE],index,i;
    printf("Please enter 8 integers as inputs:");
    for(index=0;index<8;index++)
        scanf("%d",&a[index]);
    printf("Let me see if you are smart enough to reverse the 8 numbers?[smirk]\n");
    for(i=7;i>=0;i--)
        scanf("%d",&b[i]);
    if(F(i,index,a[SIZE],b[SIZE])==1)
    {
        printf("Holy shit!\nI am pretty fucking sorry for looking down upon you![doge]\n");
    }
    else
    {
    printf("Wow, you fucking asshole!\nThe reverse data must be ");
    for(index=7;index>=0;index--)
        printf("%d ",a[index]);
    printf("\n");
    printf("You see? What a fucking smart computer am I!\n");
    }
    return 0;
}
*/

//


#include <stdio.h>
#define SIZE 8
int F(int fa[],int fb[])
{
    int i;
    for(i=0;i<SIZE;i++)//需要有一个递推，取得所有的i
    {
        if(fa[i]!=fb[SIZE-i-1])
        {
            /*
            printf("a[%d]=%d\n",i,fa[i]);
            printf("b[%d]=%d\n",SIZE-i-1,fb[SIZE-i-1]);
            */
            return 1;
        }
    }
    return 0;
}
int main()
{
    int a[SIZE],b[SIZE],index,i;
    printf("Please enter 8 integers as inputs:\n");
    for(index=0;index<SIZE;index++)
        scanf("%d[^,]",&a[index]);
    printf("Let me see if you are smart enough to reverse the 8 numbers?[smirk]\n");
    for(i=0;i<SIZE;i++)
        scanf("%d[^,]",&b[i]);
    if(F(a,b)==0)
    {
        printf("Holy shit!\nI am pretty fucking sorry for looking down upon you![doge]\n");
    }
    else
    {
        printf("Wow, you fucking asshole!\nThe reverse data must be ");
        for(index=SIZE-1;index>=0;index--)
            printf("%d ",a[index]);
        printf("\n");
        printf("You see? What a fucking smart computer am I!\n");
    }
    return 0;
}
