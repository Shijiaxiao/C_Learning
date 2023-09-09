//
//  main.c
//  hanoi
//
//  Created by 史家箫 on 2021/12/17.
//

#include <stdio.h>
#include <ctype.h>
#include <time.h>

void hanoi(int n,char from,char to)
{
    static int count=0;
    
    if(n<0)
        count=0;              //for the second time of playing hanoi.
    
    else if(n==0)
        return;
    
    else
    {
        char temp = 'A' + 'B' + 'C' - from - to;
        hanoi(n-1,from,temp);
        //hanoi(1,from,to);
        printf("Movement %2d: Move disk %d from %c -> %c\n",++count,n,from,to);
        hanoi(n-1,temp,to);
    }
}

/*
void hanoi(int n,char from,char to)
{
    if(n==1)
    {
        printf("Move %d: %c -> %c\n",from,to);
        times++;
    }
    else
    {
        char temp = 'A' + 'B' + 'c' - from - to;
        hanoi(n-1,from,temp);
        hanoi(1,from,to);
        hanoi(n-1,temp,to);
    }
}
*/

/*
void hanoi(int *times,int n,char from,char to)
{
    
    if(n==1)
    {
        printf("Movement %d: Move disk %d from %c -> %c\n",++(*times),n,from,to);
        //times++;
        //return ++(*times);
    }
    
    
    if(n==0)
        return;
    else
    {
        char temp = 'A' + 'B' + 'C' - from - to;
        hanoi(times,n-1,from,temp);
        //hanoi(1,from,to);
        printf("Movement %2d: Move disk %d from %c -> %c\n",++(*times),n,from,to);
        hanoi(times,n-1,temp,to);
    }
}
*/

/*
void hanoi(int n,char from,char to)
{
    if(n==1)
    {
        printf("Move disk%d: %c -> %c\n",n,from,to);
    }
    else
    {
        char temp = 'A' + 'B' + 'C' - from - to;
        hanoi(n-1,from,temp);
        //hanoi(1,from,to);
        printf("Move disk%d: %c -> %c\n",n,from,to);
        hanoi(n-1,temp,to);
    }
}
*/
 
int main()
{
    //int a=0;
    int n;
    printf("How many disks:");
    scanf("%d",&n);
    
    getchar();
    
    char from,to;
    printf("From:");
    from=toupper(getchar());
    
    getchar();
    
    printf("To:");
    to=toupper(getchar());
    //hanoi(&a,n,from,to);
    double start=clock();
    hanoi(n,from,to);
    double end=clock();
    printf("Running the program costs %lfs\n\n",(end-start)/CLOCKS_PER_SEC);
    return 0;
}
