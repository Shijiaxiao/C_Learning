//
//  main.c
//  6.6.2
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>
int main()
{
    int i,j;
    for(i=1;i<6;i++)
    {
        for(j=1;j<=i;j++)
            printf("$");
        printf("\n");
    }
    return 0;
}
