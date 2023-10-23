#include <stdio.h>

void DFS(int G[][7],int start, int n){
    static int visited[7]={0};
    if(visited[start]==0){
        printf("%d -> ",start);
        visited[start]=1;

        for(int j=0;j<n;j++){
            if(G[start][j]==1 && visited[j]==0)
                DFS(G,j,n);
        }
    }
}


int main()
{
    printf("\n");
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    DFS(G,4,7);
    printf("\n");
    return 0;
}
