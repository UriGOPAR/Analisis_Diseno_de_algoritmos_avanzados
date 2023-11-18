// ===========================================================================
// File: utils.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This file contains the implementation of utility functions.
// ===========================================================================

#ifndef UTILS_H
#define UTILS_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// ===========================================================================
// Function: getNumColonies
// Description: This function returns the number of colonies in the graph.
// Parameters: string input: input file.
// Return value: int numColonies: number of colonies in the graph.
// Complexity: O(1)
// ===========================================================================
int getNumColonies(string input) {
    ifstream inputFile(input);
    int n;

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 0;
    }

    inputFile >> n;

    return n;
}

// ===========================================================================
// Function: readMatrix
// Description: This function reads the adjacency matrix of the graph.
// Parameters: string input: input file.
// Return value: graph: adjacency matrix of the graph.
// Complexity: O(n^2)
// ===========================================================================
vector<vector<int>> readMatrix(string input, int matrixIndex) {
    ifstream inputFile(input);
    int n;

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return vector<vector<int>>();
    }

    int N;
    inputFile >> N;

    // Saltar la lectura de la primera matriz si se va a leer la segunda
    if (matrixIndex == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                inputFile >> n;
            }
        }
    }

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inputFile >> graph[i][j];
        }
    }

    return graph;
}

#endif // UTILS_H