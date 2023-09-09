//
//  main.c
//  9.11.3
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
void fun(char a,int times,int row);
int main()
{
    char a;
    int times,row;
    printf("Please tell me what character is your favorite:");
    scanf("%c",&a);
    printf("How many times do you want to print %c:",a);
    scanf("%d",&times);
    printf("How many rows do you want to print %c:",a);
    scanf("%d",&row);
    fun(a,times,row);
    return 0;
}
void fun(char a,int times,int row)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<times;j++)
        {
            putchar(a);
        }
        putchar('\n');
    }
}
