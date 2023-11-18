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
#include "NearestNeighbor.h"
#include "utils.h"

// ===========================================================================
// Function: main
// Description:
// Parameters:
// Return value: int
// Complexity:
// ===========================================================================
int main() {
    vector<int> dist;
    string input = "";

    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> input;

    // Read input file
    vector<vector<int>> graph = readMatrix(input, 0);

    // Punto 1
    cout << "Punto 1" << endl;
    printMatrix(graph);
    cout << endl << endl;

    // Punto 2
    cout << "Punto 2" << endl;
    printTour(graph);

    // Punto 3
    vector<vector<int>> graph2 = readMatrix(input, 1);

    return 0;
}
