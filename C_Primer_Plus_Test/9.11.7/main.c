//
//  main.c
//  9.11.7
//
//  Created by 史家箫 on 2021/11/11.
//

#include <stdio.h>
#include <ctype.h>
int judge(char a);
int main()
{
    char a;
    printf("Please give me a sentence:");
    while((a=getchar())!='\n')
    {
        if(judge(a))
            printf("The sequence of '%c' in alphabet is %d.\n",a,toupper(a)-64);
        else
            printf("'%c' is not an alpha!\n",a);
    }
    return 0;
}
int judge(char a)
{
    if(isalpha(a))
        return 1;
    else
        return 0;
}
