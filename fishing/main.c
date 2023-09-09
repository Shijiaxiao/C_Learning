//
//  main.c
//  fishing!
//
//  Created by 史家箫 on 2021/12/6.
//

#include <stdio.h>

typedef struct {
    int pocker[100];
    int head;
    int tail;
} Queue;

typedef struct {
    int table[10];
    int top;
} Stack;

//typedef cant be initialized.
void Input(Queue *A,Queue *B);
void Output(Queue *A,Queue *B,Stack *T);

int main()
{
    int times=0;
    Queue A,B;
    Stack T;
    A.head=1;
    B.head=1;
    T.top=0;
    Input(&A,&B);
    Output(&A,&B,&T);
    while(A.head!=A.tail&&B.head!=B.tail) {
        //A.
        int flag=0;
        printf("\nRound %d!\n\n",++times);
        printf("A bids: %d\n",A.pocker[A.head]);//head is not a variable alone.
        T.top++;
        T.table[T.top]=A.pocker[A.head];
        A.head++;
        Output(&A,&B,&T);
        for(int i=1;i<=T.top-1;i++) {
            if(T.table[T.top]==T.table[i]) {
                flag=1;
                while(i<=T.top) {
                    A.pocker[A.tail]=T.table[T.top];
                    A.tail++;
                    T.top--;
                }
                break;
            }
        }
        if(flag) {
            printf("A nice move from player A!\n");
            Output(&A,&B,&T);
        }
        //B.
        flag=0;
        printf("B bids: %d\n",B.pocker[B.head]);//head is not a variable alone.
        T.top++;
        T.table[T.top]=B.pocker[B.head];
        B.head++;
        Output(&A,&B,&T);
        for(int i=1;i<=T.top-1;i++) {
            if(T.table[T.top]==T.table[i]) {
                flag=1;
                while(i<=T.top) {
                    B.pocker[B.tail]=T.table[T.top];
                    B.tail++;
                    T.top--;
                }
                break;
            }
        }
        if(flag) {
            printf("A nice move from player B!\n");
            Output(&A,&B,&T);
        }
    }
    if(A.head==A.tail)
        printf("\nB wins!\n\n");
    else if(B.head==B.tail)
        printf("\nA wins!\n\n");
    return 0;
}


void Input(Queue *A,Queue *B)
{
    int n;
    printf("How many pockers in each player's hand:");
    scanf("%d",&n);
    A->tail=n+1;
    B->tail=n+1;
    printf("Please enter %d pockers for player A in sequence:\n",n);
    for(int i=1;i<=n;i++)
        scanf("%d",A->pocker+i);
    printf("Please enter %d pockers for player B in sequence:\n",n);
    for(int i=1;i<=n;i++)
        scanf("%d",B->pocker+i);
}

void Output(Queue *A,Queue *B,Stack *T)
{
    int i;
    printf("The pockers now in A's hand are:");
    for(i=A->head;i<A->tail;i++)
        printf("%d ",A->pocker[i]);
    putchar('\n');
    printf("The pockers now in B's hand are:");
    for(i=B->head;i<B->tail;i++)
        printf("%d ",B->pocker[i]);
    putchar('\n');
    printf("The pockers now on table are:");
    for(i=1;i<=T->top;i++)
        printf("%d ",T->table[i]);
    putchar('\n');
}
