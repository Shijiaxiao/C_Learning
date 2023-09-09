//
//  main.c
//  8.10.3 essaycount
//
//  Created by 史家箫 on 2021/11/9.
//

#include <stdio.h>
int count(void)
{
    char a;
    int sum=0;
    while((a=getchar())!='.')
    {
        if(a>=65&&a<=116)
            sum++;
    }
    return sum;
}

int main()
{
    printf("Please give me an essay, enter '.' to quit:");
    printf("The essay have %d characters.\n",count());
    return 0;
}
