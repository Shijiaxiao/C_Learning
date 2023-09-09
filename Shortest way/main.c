//
//  main.c
//  Shortest way 
//
//  Created by 史家箫 on 2021/12/30.
//


/*
 
 0 1 12
 0 6 14
 0 5 16
 1 5 7
 6 5 9
 1 2 10
 5 2 6
 5 4 2
 6 4 8
 2 4 5
 2 3 3
 3 4 4
 
 3 -> 4 -> 5 -> 0
 The distance from 3 to 0 is: 22
 3 -> 2 -> 1
 The distance from 3 to 1 is: 13
 3 -> 2
 The distance from 3 to 2 is: 3
 3 -> 4
 The distance from 3 to 4 is: 4
 3 -> 4 -> 5
 The distance from 3 to 5 is: 6
 3 -> 4 -> 6
 The distance from 3 to 6 is: 12
 
 */


#include <stdio.h>
#include <stdlib.h>

#define INF 0x7fffffff

void Initialize(int *matrix,int *find,int *dist,int *prev,int start,int v,int e);
void Shortest_path(int *matrix,int *find,int *dist,int *prev,int start,int v);
void Previous(int *dist,int *prev,int start,int terminal);
void Output(int *dist,int start,int terminal);

int main()
{
    int v,e,start;
    //int terminal;
    
    printf("Please input the number of vertices:");
    scanf("%d",&v);
    printf("Please input the number of edges:");
    scanf("%d",&e);
    printf("Please input the start point:");
    scanf("%d",&start);
    //printf("Please input the terminal point:");
    //scanf("%d",&terminal);
    
    fflush(stdin);
    
    int * matrix = (int *)malloc(v * v * sizeof(int));
    int * find = (int *)malloc(v * sizeof(int));
    int * dist = (int *)malloc(v * sizeof(int));
    int * prev = (int *)malloc(v * sizeof(int));
    
    Initialize(matrix, find, dist, prev, start, v, e);
    Shortest_path(matrix, find, dist, prev, start, v);
    
    for (int i = 0; i < v; i++) {
        if (i == start) continue;
        Previous(dist, prev, start, i);
        Output(dist, start, i);
    }
    
    return 0;
}

void Initialize(int *matrix,int *find,int *dist,int *prev,int start,int v,int e)
{
    // matrix.
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            matrix[i * v + j] = INF;
    printf("Please input the weight of each edge:\n");
    for(int i = 0; i < e; i++) {
        int v1, v2, weight;
        scanf(" %d%d%d", &v1, &v2, &weight);
        fflush(stdin);
        matrix[v1 * v + v2] = weight;
        matrix[v2 * v + v1] = weight;
    }
    
    // find.
    for(int i = 0; i < v; i++)
        find[i]=0;
    find[start] = 1;
    
    // dist.
    for(int i = 0; i < v; i++)
        dist[i] = matrix[start * v + i];
    
    // prev.
    for(int i = 0; i < v; i++)
        prev[i] = -1;
}

void Shortest_path(int *matrix,int *find,int *dist,int *prev,int start,int v)
{
    int min,minid;
    
    // traversal all the vertices.
    for (int i=0;i<v;i++) {
        min = INF;
        minid = i;
        
        for(int j=0;j<v;j++) {
            if(dist[j] < min && find[j] == 0) {
                min = dist[j];
                minid = j;
            }
        }
        
        // already found a shortest path for node minid.
        find[minid] = 1;
        
        // update dist.
        for(int j=0;j<v;j++) {
            int temp = (matrix[minid * v + j] == INF) ? INF : (min + matrix[minid * v + j]);
            if(find[j] == 0 && temp < dist[j]) {
                dist[j] = temp;
                prev[j] = minid;
            }
        }
        
    }
}

void Previous(int *dist,int *prev,int start,int terminal)
{
    if (prev[terminal] == -1) {
        printf("%d -> ",start);
        return;
    }
    
    Previous(dist,prev,start,prev[terminal]);
    printf("%d -> ",prev[terminal]);
    
}

void Output(int *dist,int start,int terminal)
{
    printf("%d\n",terminal);
    printf("The distance from %d to %d is: %d\n",start,terminal,dist[terminal]);
}
