#include<stdio.h>
#include<limits.h>

void BFS(int V, char Vertices[], int Graph[V][V], int rootNum, char toFind){
    int queue[V], visited[V], front = -1, rear = -1;
    for(int i = 0; i < V; i++){
        visited[i] = 0;
    }

    front = rear = 0;
    queue[rear] = rootNum - 1;
    rear++;
    visited[rootNum - 1] = 1;

    while(front < rear){
        int u = queue[front];
        front++;
        if(Vertices[u] == toFind){
            printf("Found %c at location %d\n", toFind, u + 1);
            printf("BFS traversal queue : ");
            for(int i = 0; i < V; i++){
                printf("%c ", Vertices[queue[i]]);
            }
            printf("\n");
            return;
        }

        for(int v = 0; v < V; v++){
            if(Graph[u][v] != 0 && !visited[v]){
                queue[rear] = v;
                visited[v] = 1;
                rear++;
            }
        }
    }

    printf("Can't find %c in the given set of vertices.\n", toFind);
}

int main(){
    int V;
    printf("Enter the number of Vertices : ");
    scanf("%d", &V);

    char Vertices[V];
    printf("Enter the set of Vertices : \n");
    for(int i = 0; i < V; i++){
        scanf(" %c", &Vertices[i]);
    }

    int Graph[V][V];
    printf("Enter the adjacency matrix : \n");
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            scanf("%d", &Graph[i][j]);
        }
    }

    printf("Given Array : ");
    for(int i = 0; i < V; i++){
        printf(" %c", Vertices[i]);
    }
    printf("\n");

    int rootNum;
    printf("Enter the root character number : ");
    scanf("%d", &rootNum);

    char toFind;
    printf("Enter the character to find : ");
    scanf(" %c", &toFind);
    
    BFS(V, Vertices, Graph, rootNum, toFind);
    return 0;
}