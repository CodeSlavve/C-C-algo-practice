#include<stdio.h>

int recursion(int N, char node[], int tree[N][N], char toFind,int visited[], int u) {
    visited[u] = 1;
    if (node[u] == toFind) {
        return u;    // found
    }

    for (int v = 0; v < N; v++) {
        if (tree[u][v] != 0 && !visited[v]) {
            int foundidx = recursion(N, node, tree, toFind, visited, v);
            if (foundidx != -1) {
                return foundidx;
            }
        }
    }
    return -1; // not found
}

void DFS(int N, char node[], int tree[N][N], char toFind){
    int visited[N];
    for(int i = 0; i < N; i++){
        visited[i] = 0;
    }

    int u = 0;
    int foundidx = recursion(N, node, tree, toFind, visited, u);
    if(foundidx != -1){
        printf("Found %c at %d\n", toFind, foundidx + 1);
    } else {
        printf("Can't find given %c in given tree.\n", toFind);
    }
}


int main(){
    int N;                          //N -> Number of nodes
    printf("Enter the number of nodes : ");
    scanf("%d", &N);

    char node[N], toFind;           //node[N] -> array of nodes, chars rahenge
    int tree[N][N];

    printf("Enter the set of nodes (enter root first) : ");
    for(int i = 0; i < N; i++){
        scanf(" %c", &node[i]);
    }

    printf("Enter ajacency matrix for the given set : \n");
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &tree[i][j]);
        }
    }

    printf("Enter node to find : ");
    scanf(" %c", &toFind);

    DFS(N, node, tree, toFind);
    return 0;
}