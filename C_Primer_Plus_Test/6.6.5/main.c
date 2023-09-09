//
//  main.c
//  6.6.5
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>
#include <ctype.h>
int main()
{
    int i,j,k;
    char c,ch = 'A';
    printf("please enter a letter you prefer:");
    scanf("%c",&c);
    /*
    if(c>=97&&c<=122)
    {
        c-=32;
    }
    */
    
    c=toupper(c);
    k = c - ch + 1;
    if(c>=65&&c<=90)
    {
        for(i=1;i<=k;i++)
        {
            for(j=1;j<k-i+1;j++)
                printf(" ");
            for(j=1,ch='A';j<=i;j++,ch++)//也可以不初始化j，利用和行数k的关系和上一个for已有的j值计算
                //例如j<=k
                printf("%c",ch);
            for(j=1,ch-=2;j<i;j++,ch--)//已经加1，必须减2
                printf("%c",ch);
            printf("\n");
        }
    }
    else
    {
        printf("Invalid character!\n");
    }
    return 0;
}
