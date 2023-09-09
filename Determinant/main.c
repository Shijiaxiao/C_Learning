//
//  main.c
//  Determinant
//
//  Created by 史家箫 on 2021/12/15.
//

#include <stdio.h>

#define N 100

void swap(double A[][N],int row,int r,int *n);
void Get_matrix(double A[][N],int *n);
void Up_down(double A[][N],int *n);
double Determinant(double A[][N],int *n);

int main()
{
    double A[N][N]={0.0};
    int n;
    printf("Welcome to Drogba's Determinant Calculator!\n");
    Get_matrix(A,&n);
    Up_down(A,&n);
    double result=Determinant(A,&n);
    printf("The result of the determinant is %.2lf\n\n",result);
    return 0;
}

void swap(double A[][N],int row,int r1,int *n)//*row not neccesary, variable 'row' won't be modified.
{
    int c;
    float temp;
    for(c=0;c<*n;c++)
    {
        temp=A[row][c];
        A[row][c]=A[r1][c];
        A[r1][c]=temp;
    }
}

void Get_matrix(double A[][N],int *n)
{
    int row,column;
    printf("Please input the order(rank) of the matrix:");
    scanf("%d",n);
    printf("Now please input the matrix(%d*%d):\n\n",*n,*n);
    while(1)
    {
        int flag=1;
        for(row=0;row<*n;row++)
        {
            for(column=0;column<*n;column++)
                if(scanf("%lf",A[row]+column)==0)
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
}

void Up_down(double A[][N],int *n)
{
    int i,row,column,r1;
    int r,c;
    float k;
    printf("\n**************************************************************************************************************\n\n");
    for(row=0;row<*n;row++)
    {
        if(row==*n/2-1)
            printf("    === Start! ===>>>     ");
        else
            printf("                          ");
        printf("( ");
        for(column=0;column<*n;column++)
            printf("% 7.4f ",A[row][column]);
        //printf("| ");
        printf(")\n");
    }
    putchar('\n');
    for(row=0;row<*n-1;row++)
    {
        if(A[row][row]<=0.01&&A[row][row]>=-0.01)
        {
            for(r1=row+1;r1<*n;r1++)
                if(A[r1][row]!=0)
                {
                    swap(A,row,r1,n);
                    break;
                }
            for(r=0;r<*n;r++)
            {
                if(r==*n/2-1)
                    printf("    === r%d<->r%d ===>>>    ",row+1,r1+1);
                else
                    printf("                          ");
                printf("( ");
                for(c=0;c<*n;c++)
                    printf("% 7.4lf ",A[r][c]);
                //printf("| ");
                printf(")\n");
            }
            putchar('\n');
        }
        for(i=1;i<*n-row;i++)
        {
            k=A[row+i][row]/A[row][row];
            if(k==0)
                continue;
            for(column=0;column<*n;column++)
            {
                A[row+i][column]-=k*A[row][column];
            }
            if(A[row+i][column]<=0.01&&A[row+i][column]>=-0.01)
                A[row+i][column]=0;
            for(r=0;r<*n;r++)
            {
                if(r==*n/2-1)
                {
                    if(k<0)
                        printf(" === r%d+%7.4lf*r%d ===>>> ",row+i+1,-k,row+1);
                    else
                        printf(" === r%d-%7.4lf*r%d ===>>> ",row+i+1,k,row+1);
                }
                else
                    printf("                          ");
                printf("( ");
                for(c=0;c<*n;c++)
                    printf("% 7.4lf ",A[r][c]);
                //printf("| ");
                printf(")\n");
            }
            putchar('\n');
        }
    }
}

double Determinant(double A[][N],int *n)
{
    double result=1;
    for(int i=0;i<*n;i++)
        result*=A[i][i];
    return result;
}

