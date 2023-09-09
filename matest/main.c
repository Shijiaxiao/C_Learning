//
//  main.c
//  matest
//
//  Created by 史家箫 on 2021/11/14.
//

#include <stdio.h>
#define N 100

float A[N][N]={0.0};
//float E[N][N]={0.0};
int n,row,column;

void Get_matrix(void)
{
    printf("Please input the order(rank) of the matrix:");
    scanf("%d",&n);
    printf("Now please input the matrix(%d*%d):\n",n,n);
    while(1)
    {
        int flag=1;
        for(row=0;row<n;row++)
        {
            for(column=0;column<n;column++)
                if(scanf("%f",A[row]+column)==0)
                {
                    flag=0;
                    break;
                }
            if(!flag)
                break;
        }
        if(flag)
            break;
        else
            printf("Please check your input:\n");
        fflush(stdin);
        //while(getchar()!='\n');
        //scanf("%*[^\n]");
        //2 traditional ways of disposing wrong input.
    }
    /*for(row=0;row<n;row++)
        for(column=0;column<n;column++)
            printf("%.2f ",A[row][column]);*/
}

int Judge(void)
{
    int i,r,c;
    float k;
    for(row=0;row<n-1;row++)
        for(i=1;i<n-row;i++)
        {
            k=A[row+i][row]/A[row][row];
            for(column=0;column<n;column++)
                A[row+i][column]-=k*A[row][row];
            for(r=0;r<n;r++)
            {
                for(c=0;c<n;c++)
                    printf("%.2f ",A[r][c]);
                putchar('\n');
            }
            if(A[row+i][row+i]<=0.0001&&A[row+i][row+i]>=-0.0001)
                return 0;
        }
    return 1;
}
int main()
{
    Get_matrix();
    if(!Judge())
    {
        printf("The matrix is uninvertible!\n");
        return 0;
    }
    else
        printf("yes!\n");
}

