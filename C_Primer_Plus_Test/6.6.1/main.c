//
//  main.c
//  6.6.1
//
//  Created by 史家箫 on 2021/9/26.
//

#include<stdio.h>
#define SIZE 26
int main()
{
    char CH[SIZE],c='a';
    int index;
    for(index=0;index<26;index++,c++)
    {
        CH[index]=c;
        printf("%c",CH[index]);
    }
    printf("\n");
    return 0;
}
