// ===========================================================================
// File: Dijkstra.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This file contains the implementation of the Dijkstra's
//              algorithm.
// Complexity: O(n^2)
// ===========================================================================

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

// ===========================================================================
// Function: minDistance
// Description: This function finds the vertex with the minimum distance value
//              from the set of vertices not yet included in MST.
// Parameters: vector<int>& dist: vector with the distances from the source.
//             vector<bool>& inMST: vector with the vertices included in MST.
// Return value: int minIndex: index of the vertex with the minimum distance.
// Complexity: O(n)
// ===========================================================================
int minDistance(vector<int>& dist, vector<bool>& inMST) {
    int minDist = INT_MAX, minIndex;

    for (int i = 0; i < dist.size(); i++) {
        if (!inMST[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// ===========================================================================
// Function: dijkstra
// Description: This function finds the shortest paths from a source vertex to
//              all other vertices in the graph.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
//             int src: source vertex.
// Return value: vector<int> dist: vector with the distances from the source.
// Complexity: O(n^2)
// ===========================================================================
vector<int> dijkstra(vector<vector<int>>& graph, int src) {
    int numColonies = graph.size();
    vector<int> dist(numColonies, INT_MAX);
    vector<bool> inMST(numColonies, false);

    dist[src] = 0;

    for (int count = 0; count < numColonies - 1; count++) {
        int u = minDistance(dist, inMST);
        inMST[u] = true;

        for (int v = 0; v < numColonies; v++) {
            if (!inMST[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    return dist;
}

// ===========================================================================
// Function: printMatrix
// Description: This function prints the distance matrix in the specified format.
// Parameters: vector<vector<int>>& matrix: distance matrix.
//             int numColonies: number of colonies.
// Return value: void
// Complexity: O(n^2)
// ===========================================================================
void printMatrix(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (i != j) {
                vector<int> dist = dijkstra(matrix, i);
                cout << "Colonia " << i + 1 << " a colonia " << j + 1 << ": " << dist[j] << endl;
            }
        }
        cout << endl;
    }
}

#endif /* DIJKSTRA_H */