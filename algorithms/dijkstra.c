#include<stdio.h>
#include<limits.h>


int minDist(int V, int dist[], int visited[]){
    int min = INT_MAX, minIdx;
    for(int u = 0; u < V; u++){
        if(!visited[u] && dist[u] < min){
            min = dist[u];
            minIdx = u;
        }
    }
    return minIdx;
}


void solution(int V, int dist[]) {
    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}



void Dijkstra(int V, int Graph[V][V], int src){
    int dist[V];
    int visited[V], u;
    for(int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for(int count = 0; count < V; count++){
        u = minDist(V, dist, visited);
        visited[u] = 1;

        for(int v = 0; v < V; v++){
            if(!visited[v] && Graph[u][v] && dist[u] != INT_MAX && dist[u] + Graph[u][v] < dist[v]){
                dist[v] = Graph[u][v] + dist[u];
            }
        }
    }
    solution(V, dist);
}


int main(){
    int V, src;
    V = 6;
    printf("Enter the src: ");
    scanf("%d", &src);                                    //V -> vertices
    int Graph[6][6] = {
        {0,7,9,0,0,14},                   //1 , X
        {7,0,10,15,0,0},                  // 2,X
        {9,10,0,11,0,2},
        {0,15,11,0,6,0},
        {0,0,0,6,0,9},
        {14,0,2,0,9,0}
    };

    Dijkstra(V, Graph, src);
    return 0;
}