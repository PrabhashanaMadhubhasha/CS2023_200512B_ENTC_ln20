#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// Number of vertices
#define vertices 6
//The vertex with minimum distance
int min_distance(int distance[], bool spt_set[]){
    // Define minimum value
    int minimum = INT_MAX, min_index;

    for (int i=0; i<vertices; i++){
        if (spt_set[i] == false && distance[i]<=minimum){
            minimum = distance[i];
            min_index = i;
        }
    }
    return min_index;
}
void print_solution(int distance[], int source){
    for (int i=0; i<vertices; i++){
        printf("The shortest time between %d and %d is: %d \n", source, i, distance[i]);
    }
}
//Dijkstra's single source shortest path algorithm
void dijkstra(int graph[vertices][vertices], int source){
    int distance[vertices];

    bool spt_set[vertices];
    for (int i=0; i<vertices; i++){
        distance[i] = INT_MAX;
        spt_set[i] = false;
    }
    distance[source] = 0;
    //Find shortest path
    for (int count=0; count<vertices-1; count++){
        int s = min_distance(distance, spt_set);
        spt_set[s] = true;
        for (int vertex=0; vertex<vertices; vertex++){
            if (!spt_set[vertex] && graph[s][vertex] && distance[s]!=INT_MAX && distance[s]+graph[s][vertex]<distance[vertex]){
                    distance[vertex] = distance[s] + graph[s][vertex];
            }
        }
    }
    //The solution
    print_solution(distance, source);
}
int main(){
    //The adjacency matrix
    int graph[vertices][vertices] = {{0, 10, 0, 0, 15, 5},
    {10, 0, 10, 30, 0, 0},
    {0, 10, 0, 12, 5, 0},
    {0, 30, 12, 0, 0, 20},
    {15, 0, 5, 0, 0, 0},
    {5, 0, 0, 20, 0, 0}};
dijkstra(graph, 4);
return 0;
}