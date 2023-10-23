#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 8
#define INF 9999
#define I __INT_MAX__

int primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V)
{
    int parent[MAX_VERTICES]; // to store the parent node of each vertex in MST.
    int key[MAX_VERTICES]; // to store the minimum edge weight for each vertex in MST.
    bool visited[MAX_VERTICES]; // to mark visited vertices.
    int i,j,minVertex,minWeight;
    // Initialize all keys as infinite
    for(i=0; i<V; i++)
    {
        key[i] = INF;
        visited[i] = false;
    }
    // Set the key of the starting vertex as 0
    key[0] = 0;
    parent[0] = -1; // Root node has no parent.
    // Find the MST
    for(i=0; i<V-1; i++)
    {
        // Find the vertex with minimum key value
        minVertex = -1;
        minWeight = INF;
        for(j=0; j<V; j++)
        {
            if(!visited[j] && key[j] < minWeight)
            {
                minVertex = j;
                minWeight = key[j];
            }
        }
        // Mark the vertex as visited
        visited[minVertex] = true;
        // Update the key values and parent for adjacent vertices
        for(j=0; j<V; j++)
        {
            if(graph[minVertex][j] && !visited[j] && graph[minVertex][j] < key[j])
            {
                parent[j] = minVertex;
                key[j] = graph[minVertex][j];
            }
        }
    }
    // Calculate the total weight of the MST and print it
    int weight = 0;
    for(i=1; i<V; i++)
    {
        weight += graph[parent[i]][i];
    }
    printf("\n");
    printf("Total weight of the MST: %d\n", weight);
    // Print the MST
    printf("MST:\n");
    for(i=1; i<V; i++)
    {
        printf("%d - %d\n", parent[i], i);
    }
    return weight;
}

int main()
{
    int graph[8][8]={{I , I , I , I , I , I , I , I } ,
                    {I , I , 25 , I , I , I ,15 ,I},
                    {I , 25 ,I , 15 , I , I ,I , 10},
                    {I , I , 15 , I , 8 , I , I , I },
                    {I , I , I , 8 , I , 16 , I , 14},
                    {I , I , I , I , 16 , I , 20 ,18},
                    {I , 15 , I , I , I , 20 , I , I},
                    {I , I , 10 , I , 14 , 18, I , I}};

    primMST(graph, 8);
    return 0;
}
