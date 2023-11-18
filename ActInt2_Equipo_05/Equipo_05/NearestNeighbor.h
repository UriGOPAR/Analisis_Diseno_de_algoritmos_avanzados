// ===========================================================================
// File: NearestNeighbor.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This file contains the implementation of the Nearest Neighbor
//              algorithm.
// Complexity: O(n^2)
// ===========================================================================

#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

// ===========================================================================
// Function: nearestNeighbor
// Description: This function finds the shortest path that visits each vertex
//              exactly once and returns to the starting vertex.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
// Return value: vector<int> tour: vector with the order of the vertices.
// Complexity: O(n^2)
// ===========================================================================
vector<int> nearestNeighbor(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> tour;
    vector<bool> visited(n, false);

    int current = 0;
    tour.push_back(current);
    visited[current] = true;

    for (int i = 1; i < n; ++i) {
        int next = -1;
        double minDistance = numeric_limits<double>::infinity();

        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                double distance = graph[current][j];
                if (distance < minDistance) {
                    minDistance = distance;
                    next = j;
                }
            }
        }

        tour.push_back(next);
        visited[next] = true;
        current = next;
    }

    tour.push_back(tour[0]);

    return tour;
}

// ===========================================================================
// Function: printTour
// Description: This function prints the tour and its cost.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
// Return value: none.
// Complexity: O(n)
// ===========================================================================
void printTour(const vector<vector<int>>& graph) {
    int N = graph.size();
    vector<int> tour = nearestNeighbor(graph);

    cout << "El recorrido: " << endl;
    for (int i = 0; i < tour.size() - 1; ++i) {
        cout << tour[i] + 1 << " -> ";
    }
    cout << tour.back() + 1 << endl;

    cout << "El costo: ";
    double totalDistance = 0;

    for (int i = 0; i < N; ++i) {
        int node1 = tour[i];
        int node2 = tour[i + 1];
        totalDistance += graph[node1][node2];
    }

    cout << totalDistance << endl;
}

#endif // NEARESTNEIGHBOR_H
