//
//  main.c
//  One Always Leading the Score
//
//  Created by 史家箫 on 2021/12/30.
//

#include <stdio.h>
#define N 15

void Add_score(int a,int b);

int count=0;

int main()
{
    int a=0,b=0;
    Add_score(a,b);
    printf("%d\n",count);
    return 0;
}


void Add_score(int a,int b)
{
    if(a == N)
        return;
    
    if(a>b+1) {
        count++;
        Add_score(a,b+1);
    }
    
    count++;
    Add_score(a+1,b);
}
