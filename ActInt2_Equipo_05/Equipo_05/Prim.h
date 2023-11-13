// ===========================================================================
// File: Prim.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This program implemets Prim's algorithm for the search of
//              the minimum spanning tree of a given graph.
// Complexity: The complexity of this algorithm is O(n^2), where n is the number
//             of vertices in the graph.
// ===========================================================================
#ifndef PRIM_H
#define PRIM_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

struct Edge {
    int from, to, distance;

    Edge(int u, int v, int dist) : from(u), to(v), distance(dist) {}
};

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
// Function: primMST
// Description: This function finds the minimum spanning tree of a given graph
//              using Prim's algorithm.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
// Return value: vector<Edge> MST: vector with the edges of the MST.
// Complexity: O(n^2)
// ===========================================================================
vector<Edge> primMST(vector<vector<int>>& graph) {
    int numColonies = graph.size();
    vector<Edge> MST;
    vector<int> parent(numColonies, -1);
    vector<int> dist(numColonies, INT_MAX);
    vector<bool> inMST(numColonies, false);

    dist[0] = 0;

    for (int count = 0; count < numColonies - 1; count++) {
        int u = minDistance(dist, inMST);
        inMST[u] = true;

        for (int v = 0; v < numColonies; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = graph[u][v];
            }
        }
    }

    for (int i = 1; i < numColonies; i++) {
        MST.push_back(Edge(parent[i], i, graph[i][parent[i]]));
    }

    return MST;
}

#endif // PRIM_H