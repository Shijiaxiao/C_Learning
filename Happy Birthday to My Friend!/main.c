//
//  main.c
//  Happy Birthday to My Friend!
//
//  Created by 史家箫 on 2021/11/13.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Answer(char *answer);
void Name(char *name);
void Age(int *age);
void Wishes(char *wishes);
int Special(void);
void Cake(char *name,int age,char *wishes);
void Heart(void);

int main()
{
    int age;
    char answer[20],name[20],wishes[100];
    putchar('\n');
    printf("        Welcome to Drogba's Bakery! We can make customized gifts for Birthdays for you!\n");
    if(!Answer(answer))//run an int-type function is legal.
        return 0;
    Name(name);
    Age(&age);
    Wishes(wishes);
    if(Special())
    {
        Cake(name,age,wishes);
        Heart();
    }
    else
        Cake(name,age,wishes);
    printf("        Thanks for coming! Take care and looking forward to your next visit!\n\n\n\n\n\n");
    return 0;
}

int Answer(char *answer)
{
    int dirty=0,out=0;
    printf("        What can I make for you:");
    while(1)
    {
        scanf(" %[^\n]",answer);
        if(strcmp(answer, "Cake")==0||strcmp(answer, "cake")==0)
            return 1;
        else if(toupper(answer[0])=='H'||toupper(answer[0])=='S'||toupper(answer[0])=='F')
        {
            while(getchar()!='\n');
            dirty++;
            if(dirty==2)
            {
                printf("        Get out of my Bakery you fool!\n");
                return 0;
            }
            printf("        No dirty words please!\n");
            printf("        I offer you another chance out of mercy:");
            
        }
        else
        {
            out++;
            if(out==2)
            {
                printf("        We don't have that either. The last chance, three strikes and you're out!\n");
                printf("        Prefering anything else:");
            }
            else if(out==3)
            {
                printf("        Get out of my Bakery you fool!\n");
                return 0;
            }
            else
            {
                printf("        Sorry sir, we don't provide the service of making a %s.\n",answer);
                printf("        Prefering anything else:");
            }
        }
    }

}

void Name(char *name)
{
    printf("        Ok, what's his/her name:");
    scanf(" %[^\n]",name);
}

void Age(int *age)
{
    printf("        Great, what's his/her age:");
    while(1)
    {
        while(scanf(" %d",age)!=1)
        {
            scanf("%*[^\n]");
            printf("        That's is not an integer, idiot!\n        Again please:");
        }
        if(*age<=0||*age>120)
        {
            printf("        ???Are you kidding me???\n");
            printf("        Again please:");
        }
        else
            break;
    }
}

void Wishes(char *wishes)
{
    printf("        Any wishes for him/her to be decorated on the cake?\n");
    printf("        ");
    scanf(" %[^\n]",wishes);//mind the last '\n'.
}

int Special(void)
{
    char response[100];
    printf("        Is he/she your lover:");
    scanf(" %[^\n]",response);
    if(strcmp(response, "yes")==0)
    {
        printf("        OMG! That's so sweet! Best wishes!\n\n");
        return 1;
    }
    else
    {
        printf("        Oh, I actually mean do you love him/her:");
        scanf(" %[^\n]",response);
        if(strcmp(response, "yes")==0)
        {
            printf("        Get it!\n\n");
            return 1;
        }
        else
        {
            printf("        Sorry for asking that. v_v\n\n");
            return 0;
        }
    }
}

void Cake(char *name,int age,char *wishes)
{
    int age1=age;
    while(age1>31)
        age1/=2;
    int a=age1/5,b=age1%5,s1,s;
    if(strlen(wishes)>=53)
    {
        s1=8+(53-age1)/2+(int)(strlen(wishes)-53)/2;
        s=8+(int)(strlen(wishes)-53)/2;
    }
    else
    {
        s1=8+(53-age)/2;
        s=8;
    }
    int i;
    printf("        ...ticktock...ticktock...Just a moment!...Already in production!...\n\n");
    printf("        Haha! Sorry to keep you waiting! Here is your birthday cake!\n\n\n");
    for(i=0;i<s1;i++)
        putchar(' ');
    for(i=0;i<a;i++)
        printf("ÎÏÍĪÌ");
    for(i=0;i<b;i++)
    {
        if(i%5==0)
            printf("Î");
        else if(i%5==1)
            printf("Í");
        else if(i%5==2)
            printf("Ï");
        else
            printf("Í");
    }
    putchar('\n');
    for(i=0;i<s1;i++)
        putchar(' ');
    for(i=0;i<age1;i++)
        putchar('|');
    putchar('\n');
    for(i=0;i<s;i++)
        putchar(' ');
    printf("         ([$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$]) \n");
    for(i=0;i<s;i++)
        putchar(' ');
    printf("    * *  ([                               ])  * * \n");
    for(i=0;i<s;i++)
        putchar(' ');
    if(age>=10&&age<100)
    {
        if(age%10==1)
            printf("     *   ([      Happy %dst Birthday      ])   * \n",age);
        else if(age%10==2)
            printf("     *   ([      Happy %dnd Birthday      ])   * \n",age);
        else if(age%10==3)
            printf("     *   ([      Happy %drd Birthday      ])   * \n",age);
        else
            printf("     *   ([      Happy %dth Birthday      ])   * \n",age);
    }
    else if(age<10)
    {
        if(age%10==1)
            printf("     *   ([      Happy %dst Birthday       ])   * \n",age);
        else if(age%10==2)
            printf("     *   ([      Happy %dnd Birthday       ])   * \n",age);
        else if(age%10==3)
            printf("     *   ([      Happy %drd Birthday       ])   * \n",age);
        else
            printf("     *   ([      Happy %dth Birthday       ])   * \n",age);
    }
    else
    {
        if(age%10==1)
            printf("     *   ([     Happy %dst Birthday      ])   * \n",age);
        else if(age%10==2)
            printf("     *   ([     Happy %dnd Birthday      ])   * \n",age);
        else if(age%10==3)
            printf("     *   ([     Happy %drd Birthday      ])   * \n",age);
        else
            printf("     *   ([     Happy %dth Birthday      ])   * \n",age);
    }
    for(i=0;i<s;i++)
        putchar(' ');
    printf("    * *  ([");
    for(i=0;i<(27-(int)strlen(name))/2;i++)
        putchar(' ');
    printf("to %s~",name);
    for(i=0;i<27-(int)strlen(name)-(27-(int)strlen(name))/2;i++)
        putchar(' ');
    printf("])  * * \n");
    for(i=0;i<s;i++)
        putchar(' ');
    printf(" ________([_______________________________])________ \n");
    for(i=0;i<s;i++)
        putchar(' ');
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n");
    for(i=0;i<8;i++)
        putchar(' ');
    if(strlen(wishes)>=53)
        printf("%s\n\n\n",wishes);
    else
    {
        for(i=0;i<(53-(int)strlen(wishes))/2;i++)
            putchar(' ');
        printf("%s\n\n\n",wishes);
    }
}

void Heart(void)
{
    float x,y,a;
    printf("        And a sprcial gift for him/her!\n\n");
    for(y=1.5f;y>-1.5f;y-=0.1f)
    {
        for(x=-1.5f;x<1.5f;x+=0.05f)
        {
            a=x*x+y*y-1;
            putchar(a*a*a-x*x*y*y*y<=0.0f ? '*' : ' ');
        }
        putchar('\n');
    }
}






































