// ===========================================================================
// File: main.cpp
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: this file contains the main function.
// Complexity: O(n^2)
// How to compile: g++ main.cpp -o app
// How to run: ./app <inputFile.txt>
// ===========================================================================

// ===========================================================================
// libraries
// ===========================================================================
#include "Dijkstra.h"
#include "NearestNeighbor.h"
#include "FordFulkerson.h"
#include "EculideanDistance.h"
#include "utils.h"

// ===========================================================================
// Function: main
// Description: this function is the entry point of the program.
// Parameters: int argc: number of arguments.
//             char* argv[]: array of arguments.
// Return value: int
// Complexity: O(n^2)
// ===========================================================================
int main(int argc, char* argv[]) {
    vector<int> dist;

    if (argc != 2) {
        cerr << "Forma de uso: ./app <inputFile.txt>" << endl;
        return 0;
    }

    string input = argv[1];

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

    // Punto 3
    vector<vector<int>> graph2 = readMatrix(input, 1);
    cout << "Punto 3" << endl;
    printMaxFlow(graph2, 0, numColonies - 1);
    cout << endl << endl;

    // Punto 4
    vector<pair<int, int>> coordinates = readCoordinates(input);
    cout << "Punto 4" << endl;
    pair<int, int> newCentral = coordinates[coordinates.size()];
    printClosest(coordinates, newCentral.first, newCentral.second);

    return 0;
}
