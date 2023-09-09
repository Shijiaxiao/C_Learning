//
//  main.c
//  peanut
//
//  Created by 史家箫 on 2021/12/30.
//

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

int dis(int,int,int,int);
void find(int a[],int *p,int *q,int m,int n);

int main()
{
    int x=-1,y=-1,count=0,p,q,m,n,time,sum=0,sum2=0;
    int *a;

    int i;
    printf("请输入花生地的尺寸：\n");
    scanf("%d%d",&m,&n);
    a=(int*)malloc(sizeof(int)*m*n);
    if(a==NULL)
    {
        printf("can not get memorry!\n");
        exit(1);
    }
    printf("请输入花生地的情况：\n");
    
    for(i=0;i<m*n;i++)
        scanf("%d",&a[i]);
    
    fflush(stdin);
    printf("请输入限定的时间：\n");
    scanf("%d",&time);

    while((time-count)>=dis(x,y,-1,-1)) {
        // if it is able to get back to the way, then add the number of peanuts.
        sum+=sum2;
        find(a,&p,&q,m,n);
        sum2=a[p*n+q];
        a[p*n+q]=0;
        count+=dis(x,y,p,q)+1;  // 1 stands for the time for picking up the peanut.
        x=p;
        y=q;
    }
    
    printf("最多能拿到%d个花生。\n",sum);
    free(a);
}

int dis(int x,int y,int p,int q)
{
    if(x==-1) return(p+1);
    else if(p==-1) return(x+1);
    else return ((int)(fabs((double)(x-p))+fabs((double)(y-q))));
}

void find(int a[],int*p,int*q,int m,int n)
{
    int i,j,b=0;
    // find maxid, p = r, q = c
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            if(a[i*n+j]>b) {
                *p=i;
                *q=j;
                b=a[i*n+j];
            }
                
}
