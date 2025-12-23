#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v)
{
    int i;
    visited[v]= 1;
    for(int i=0; i<n; i++)
    {
        if(graph[v][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start=0, connected=1;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: \n");
    for(int i=0; i<n ; i++){
        visited[i]=0;
        for(int j=0; j< n; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    dfs(start);

    for(int i=0; i<n; i++){
        if(visited[i]==0){
            connected=0;
            break;
        }
    }

    if(connected){
        printf("The graph is CONNECTED");
    }else
    {
        printf("The graph is NOT CONNECTED");
    }
}
