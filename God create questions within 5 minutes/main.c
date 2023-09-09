//
//  main.c
//  God create questions within 5 minutes
//
//  Created by 史家箫 on 2021/10/23.
//

#include <stdio.h>
#include <ctype.h>
int judge_a(char a,int begin)
{
    if(a=='(')
        return begin;
    else if(a=='[')
        return begin-1;
    return 0;
}

int judge_b(char b,int end)
{
    if(b==')')
        return end-2;
    else if(b==']')
        return end-1;
    return 0;
}

int judge_again(char *again)
{
    int i,j;
    char yes[3]="yes";
    char no[2]="no";
    if(tolower(again[0])=='y')
    {
        j=3;
        for(i=1;i<j;i++)
            if(again[i]!=yes[i])
                return 0;
        return 1;
    }
    else if(tolower(again[0])=='n')
    {
        j=2;
        for(i=1;i<j;i++)
            if(again[i]!=no[i])
                return 0;
        return 2;
    }
    else return 0;
}

int main()
{
    int A[1000];
    int n,Q,max,min,i,j;
    int begin,end;
    char a,b,rub[100],again[3];
    while(1)
    {
        printf("Please tell me the lenth of vector quantity and times of you inquires:");
        scanf("%d%[^0-9]%d",&n,rub,&Q);
        getchar();
        printf("Please enter the vector quantity:\n");
        while(1)
        {
            for(i=0;i<1000;i++)
            {
                scanf("%d",&A[i]);
                //scanf("%[^0-9]",rub);
                if(getchar()=='\n')
                    break;
            }
            if(i<n-1)
                printf("Please check your input:\n");
            else if(i==n-1)
                break;
            else
                printf("Please check your input:\n");
        }
        printf("Ok,your input is qualified.\n");
        for(j=1;j<=Q;j++)
        {
            printf("Then tell me the range of you input( '(' or '[' a,b ')' or ']' ):");
            while(1)
            {
                scanf(" %c%d%[^0-9]%d%c",&a,&begin,rub,&end,&b);
                getchar();//mind \n
                if((a!='('&&a!='[')||(b!=')'&&b!=']')||judge_a(a,begin)<0||judge_b(b,end)>n-1||judge_a(a,begin)>judge_b(b,end))
                    printf("Please check your input:");
                else break;
            }
            for(i=judge_a(a,begin),max=min=A[i];i<=judge_b(b,end);i++)
            {
                if(A[i]>max)
                    max=A[i];
                else if(A[i]<min)
                    min=A[i];
            }
            printf("The result of inquire %d is: max=%d,min=%d.\n",j,max,min);
        }
        printf("That's all, wanna play again(yes/no):");
        while(1)
        {
            scanf("%s",again);//mind \n, %s do not read ' '
            if(judge_again(again)==1) break;
            else if(judge_again(again)==2) return 0;
            else printf("Please check your input:");
        }
    }
    return 0;
}
