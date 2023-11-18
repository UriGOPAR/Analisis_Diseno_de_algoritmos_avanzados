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
#include "FordFulkerson.h"
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
    cout << endl << endl;

    // Read input file
    vector<vector<int>> graph = readMatrix(input, 0);
    // Get number of colonies
    int numColonies = getNumColonies(input);

    // Punto 1
    cout << "Punto 1" << endl;
    printMatrix(graph);
    cout << endl;

    // Punto 2
    cout << "Punto 2" << endl;
    printTour(graph);
    cout << endl << endl;

    vector<vector<int>> graph2 = readMatrix(input, 1);
    // Punto 3
    cout << "Punto 3" << endl;
    printMaxFlow(graph2, 0, numColonies - 1);
    cout << endl << endl;

    return 0;
}
