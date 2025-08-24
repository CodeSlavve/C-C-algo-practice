#include<iostream>
#include<vector>

int recursion(int N, std::vector<char> V, std::vector<std::vector<int>> adj, char toFind, std::vector<int> visited, int u){
    visited[u] = 1;
    if(V[u] == toFind){
        return u;
    }

    for(int v = 0; v < N; v++){
        if(adj[u][v] != 0 && !visited[v]){
            int found = recursion(N, V, adj, toFind, visited, v);
            if(found != -1){
                return found;
            }
        }
    }
    return -1;
}

void DFS(int N, std::vector<char> V, std::vector<std::vector<int>> adj, char toFind){
    std::vector<int> visited;
    for(int i = 0; i < N; i++){
        visited.push_back(0);
    }

    int found = recursion(N, V, adj, toFind, visited, 0);
    if(found != -1){
        std::cout << "Found " << toFind << " at location " << found + 1 << std::endl;
    } else{
        std::cout << "Count find " << toFind << " in the given Tree." << std::endl;
    }
}

int main(){
    int N;                   //Number of nodes 
    std::cout << "\nEnter the number of nodes in tree : ";
    std::cin >> N;
    
    std::vector<char> V;      //Vector declare

    char node;
    std::cout << "\nEnter the set of nodes : ";
    for(int i = 0; i < N; i++){
        std::cin >> node;
        V.push_back(node);
    }

    std::cout << "\nEnter the adjacency matrix : \n";
    std::vector<std::vector<int>> adj(N, std::vector<int>(N,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cin >> adj[i][j];
        }
    }

    char toFind;
    std::cout << "\nEnter the character to find : ";
    std::cin >> toFind;

    std::cout << "\nEntered Tree : \n";
    for(int i = 0; i < N; i++){
        std::cout << V.at(i) << " -> "; 
        for(int j = 0; j < N; j++){
            if(adj[i][j] == 1){
                std::cout << V[j] << " ";
            }
        }
        std::cout << "\n"; 
    }

    DFS(N, V, adj, toFind);
    return 0;
}