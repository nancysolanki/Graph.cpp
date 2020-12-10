
 
#include <limits.h> 
#include <stdio.h> 
  
// Number of vertices in the graph 
#define V 9 
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  

void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
   
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
       
        int u = minDistance(dist, sptSet); 
  
      
        sptSet[u] = true; 
  
       
        for (int v = 0; v < V; v++) 
  
            
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printSolution(dist); 
} 
  

