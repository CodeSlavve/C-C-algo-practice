#include <stdio.h>
#include <limits.h>

int minWeight(int V, int weight[], int visited[]){
    int min = INT_MAX, minIdx;
    for(int u = 0; u < V; u++){
        if(!visited[u] && weight[u] < min){
            min = weight[u];
            minIdx = u;
        }
    }
    return minIdx;
}

void primsMST(int V, char Vertices[], int weight[], int parent[]){
    int sum = 0;
    printf("\nVertex\tParent\tWeight\n");
    for(int i = 0; i < V; i++){
        printf("%c\t%d\t%d\n", Vertices[i], parent[i], weight[i]);
        sum += weight[i]; 
    }
    printf("\nTotal weigth of MST : %d", sum);
}

void primsAlgo(int V, char Vertices[], int key, int Graph[V][V]){
    int parent[V], weight[V], visited[V];
    for(int i = 0; i < V; i++){
        parent[i] = -1;
        weight[i] = INT_MAX;
        visited[i] = 0;
    }
    weight[key] = 0;
    for(int count = 0; count < V-1; count++){
        int u = minWeight(V, weight, visited);
        visited[u] = 1;

        for(int v = 0; v < V; v++){
            if(!visited[v] && Graph[u][v] != 0 && Graph[u][v] < weight[v]){
                weight[v] = Graph[u][v];
                parent[v] = u;
            }
        }
    }

    primsMST(V, Vertices, weight, parent);

}

int main(){
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    char Vertices[V];
    printf("\nEnter the Vertices : ");
    for(int i = 0; i < V; i++){
        scanf("%c", &Vertices[i]);
    }
    
    int Graph[V][V], key;
    printf("Enter the adjacency matirx: \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            scanf("%d", &Graph[i][j]);
        }
    }

    printf("\nEnter the Key: ");
    scanf("%d", &key);

    printf("Adjacency matrix given :\n");
    for(int i = 0; i < V; i++){
        printf(" %c", Vertices[i]);
    }
    printf("\n");
    for(int i = 0; i < V; i++){
        printf("%c: ", Vertices[i]);
        for(int j = 0; j < V; j++){
            printf("%d", Graph[i][j]);
        }
    }
    printf("\n");

    primsAlgo(V, Vertices, key, Graph);
    printf("\n");

    return 0;
}