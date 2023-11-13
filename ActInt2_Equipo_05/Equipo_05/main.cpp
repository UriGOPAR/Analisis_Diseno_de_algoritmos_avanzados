// ===========================================================================
// File: main.cpp
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: 
// Complexity: 
// ===========================================================================
#include "Prim.h"

int main() {
    // Read input
    ifstream inputFile("Equipo_05_Entrada_1.txt");
    if (!inputFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }
    int N;
    inputFile >> N;

    // Read graph
    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> graph[i][j];
        }
    }

    // Colony cable network
    vector<Edge> MST = primMST(graph);
    cout << "Forma de cablear las colonias (Aristas del MST):" << endl;
    for (const Edge& edge : MST) {
        cout << "Colonia " << edge.from << " a Colonia " << edge.to << " con distancia " << edge.distance << " km." << endl;
    }

    return 0;
}
