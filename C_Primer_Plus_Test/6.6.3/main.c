//
//  main.c
//  6.6.3
//
//  Created by 史家箫 on 2021/9/26.
//

#include <stdio.h>

/*
 可以现定义字母表
 char lets[26]="abedefghijklmnopqrstuvwxyz"
 lets[0]='a'
 26是因为末尾有空白
 */
/*
int main()
{
    char lets[26]="abedefghijklmnopqrstuvwxyz";
    int i,j;
    for(i=25;i>=0;i--)
    {
        for(j=25;j>=i;j--)
            printf("%c",lets[j]);
        printf("\n");
    }
    return 0;
}
*/

 int main()
 {
     char a,ch1,ch2;
     printf("please enter a lower-case letter:");
     scanf("%c",&a);
     for(ch1=a;ch1>='a';ch1--)
     {
         for(ch2=a;ch2>=ch1;ch2--)
             printf("%c",ch2);
         printf("\n");
     }
     return 0;
 }
 
