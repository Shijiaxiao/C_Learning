//
//  main.c
//  Listnode Insert Element
//
//  Created by 史家箫 on 2021/12/7.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct listnode{
    int a;
    struct listnode *next;
}Listnode;

Listnode* Createlist(void);
Listnode* Insert(Listnode *List);//update head.
void Output(Listnode *List);

int main()
{
    Listnode *List=Createlist();
    Output(List);
    List=Insert(List);
    Output(List);
    return 0;
}

Listnode* Createlist(void)
{
    int n;
    Listnode *head,*tail,*temp;
    head=(Listnode *)malloc(sizeof(Listnode));
    //head=NULL;
    head->next=NULL;
    tail=head;
    //temp=tail;
    printf("How many numbers do you want to have in the list:");
    scanf("%d",&n);
    printf("Now please input %d numbers in sequence:\n",n);
    for(int i=0;i<n;i++){
        temp=(Listnode*)malloc(sizeof(Listnode));
        scanf("%d",&temp->a);
        tail->next=temp;
        tail=temp;//mind the operating sequence.
        tail->next=NULL;
    }
    return head;
}

Listnode* Insert(Listnode *List)
{
    int new,left,right;
    int count=0,times,time,*position;
    Listnode *i,*temp;
    printf("Please tell me the element you want to insert:");
    scanf("%d",&new);
    while(666){
        printf("Please tell me the number on the left of the new element:");
        scanf("%d",&left);
        printf("Please tell me the number on the right of the new element:");
        scanf("%d",&right);
        for(Listnode *i=List->next;i->next!=NULL;i=i->next){
            if(i->a==left&&i->next->a==right)
                count++;
        }
        if(count==0)
            printf("Wrong input!\n");
        else break;
    }
    printf("How many times would you like to insert(less than %d):",count+1);
    scanf("%d",&times);
    position=(int *)malloc(times*sizeof(int));
    printf("Please tell me the position in sequence(separated them with space):");
    for(int i=0;i<times;i++)
        scanf("%d",position+i);
    for(i=List->next,count=0,time=0;i->next!=NULL&&time<times;i=i->next){
        if(i->a==left&&i->next->a==right){
            count++;
            if(count==*(position+time)){
                time++;
                temp=(Listnode *)malloc(sizeof (Listnode));
                temp->a=new;
                temp->next=i->next;
                i->next=temp;
            }
        }
    }
    return List;
}

void Output(Listnode *List)
{
    printf("The list is as below:\n");
    for(Listnode *i=List->next;i!=NULL;i=i->next){
        if(i==List->next)
            printf("%d",i->a);
        else
            printf(" -> %d",i->a);
    }
    putchar('\n');
}
