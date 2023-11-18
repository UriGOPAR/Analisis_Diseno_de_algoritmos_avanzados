// ===========================================================================
// File: main.cpp
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: 
// Complexity: 
// ===========================================================================

// ===========================================================================
// libraries
// ===========================================================================
#include "Dijkstra.h"

// ===========================================================================
// Function: main
// Description:
// Parameters:
// Return value: int
// Complexity:
// ===========================================================================
int main() {
    vector<int> dist;

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

    // Punto 1
    cout << "Punto 1" << endl;
    printMatrix(graph, N);


    return 0;
}
