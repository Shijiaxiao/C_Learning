//
//  main.c
//  8.11.2
//
//  Created by 史家箫 on 2021/11/9.
//

#include <stdio.h>

int main()
{
    int i=0;
    char a[100];
    printf("Please give me a couple of characters('.' to quit):");
    scanf("%[^.]",a);
    for(i=0;a[i]!='\0';i++)
    {
        if(i%10==0)
            putchar('\n');
        if(a[i]=='\n')
            printf("%s %3d ","\\n",a[i]);
        else if(a[i]=='\t')
            printf("%s %3d ","\\t",a[i]);
        else if(a[i]>='\040')
            printf("%2c %3d ",a[i],a[i]);
        else
            printf("^%c %3d",'\101',a[i]);
    }
    putchar('\n');
    return 0;
}
