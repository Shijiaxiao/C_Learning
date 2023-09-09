//
//  main.c
//  8.11.4
//
//  Created by 史家箫 on 2021/11/9.
//

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main()
{
    bool inword=false;
    int characters=0,words=0,lines=0,ch_word;
    char a,last='\n',end;
    printf("Please tell me your ending mark:");
    end=getchar();
    getchar(); // get the '\n' away!!!
    printf("Please enter a sentence:");
    while((a=getchar())!=end)
    {
        if(isalpha(a)&&!inword) // counting only words but not characters.
        {
            inword=true;
            words++;
        }
        if(isalpha(a)) // counting characters.
            characters++;
        else  if(isspace(a)||ispunct(a))
            inword=false;
        if(a=='\n') // ispunct include '\n'.
            lines++;
        last=a; // remember the last character, for deciding whether to add in lines.
    }
    if(last!='\n')
        lines++;
    ch_word=characters/words;
    printf("Your sentence consists of %d lines, %d words and %d characters.\n",lines,words,characters);
    printf("There are %d characters in each word on average.\n",ch_word);
    return 0;
}
