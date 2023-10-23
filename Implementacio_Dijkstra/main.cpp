// ===============================================================================================================
// File: main.cpp
// Date: October 22, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: El programa implementa el algoritmo Dijkstra para encontrar el camino más corto de un nodo a todos
//              los otros nodos de un grafo, representando estos caminos en una matriz de adyacencia.
// To compile: g++ main.cpp -o app y después ./app
// Complexity: La complejidad de todo el programa es o(N^2), debido a que existe un doble ciclo anidado, utiliza 
//             un O(N) para buscar en el nodo visitado, la distancia mínima, para luego actualizar la distancia 
//             de los vecinos no visitados, la cual, toma otro O(N) para revisar todas las aristas del grafo.
// ==============================================================================================================
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
using namespace std;

void dijkstra(int **graph, int n, int src) {
    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; ++i) {
        //Stores the shortest distances from the source node to each node in the graph
        dist[i] = INT_MAX;
        //Indicates whether a node has been visited or not during the algorithm 
        //process. Initialized to false to indicate that no nodes have been visited.
        visited[i] = false;
    }

    dist[src] = 0;

    //Main loop that executes n-1 times, where n is the number of nodes in the graph
    for (int count = 0; count < n - 1; ++count) {
        int minDist = INT_MAX, minIndex;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        int u = minIndex;
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != -1 &&
                dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != src) {
            cout << "node " << src + 1 << " to node " << i + 1 << ": " << dist[i] << endl;
        }
    }
}

int main() {
    string nombreArchivo;
    cout << "Por favor, ingrese el nombre del archivo sin poner .txt: ";
    cin >> nombreArchivo;

    ifstream inputFile(nombreArchivo + ".txt");
    if (!inputFile) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    int **graph = new int *[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            inputFile >> graph[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        dijkstra(graph, n, i);
    }

    for (int i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    inputFile.close();
    return 0;
}