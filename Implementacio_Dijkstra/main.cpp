#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

void dijkstra(int **graph, int n, int src) {
    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

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
            cout << "Distancia del nodo " << src << " al nodo " << i << ": ";
            if (dist[i] == INT_MAX)
                cout << "Infinito" << endl;
            else
                cout << dist[i] << endl;
        }
    }
}

int main() {
    string nombreArchivo;
    cout << "Por favor, ingrese el nombre del archivom sin poner .txt: ";
    cin >> nombreArchivo ;

    ifstream inputFile(nombreArchivo +".txt");
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

    dijkstra(graph, n, 0);

    for (int i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;

    inputFile.close();
    return 0;
}