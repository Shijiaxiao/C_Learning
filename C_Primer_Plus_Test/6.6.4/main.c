//
//  main.c
//  6.6.4
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>
int main()
{
    int i,j;
    char letter='a';
    for(i=1;i<=6;i++)//定义行数
    {
        for(j=1;j<=i;j++,letter++)//并未初始化letter，故可以
            printf("%c",letter);
        printf("\n");
    }
    return 0;
}
        
