//
//  main.c
//  6.6.6
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>
#include<string.h>
int main()
{
    int i;
    char word[100];
    printf("please enter the word you like:");
    scanf("%s",word);
    for(i=strlen(word)-1;i>=0;i--)
        printf("%c",word[i]);
    printf("\n");
    return 0;
}
