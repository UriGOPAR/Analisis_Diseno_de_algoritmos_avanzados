// ===========================================================================
// File: FordFulkerson.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This file contains the implementation of the Ford-Fulkerson
//              algorithm.
// Complexity: O(n^2)
// ===========================================================================

#ifndef FORDFULKERSON_H
#define FORDFULKERSON_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
#include <queue>

using namespace std;

// ===========================================================================
// Function: bfs
// Description: This function finds if there is a path from source 's' to sink
//              't' in residual graph. It fills parent[] to store the path.
// Parameters: vector<vector<int>>& rGraph: residual graph.
//             int s: source vertex.
//             int t: sink vertex.
//             vector<int>& parent: vector with the parent of each vertex.
// Return value: bool: true if there is a path from source 's' to sink 't' in
//                     residual graph.
// Complexity: O(n^2)
// ===========================================================================
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int numColonies = rGraph.size();
    vector<bool> visited(numColonies, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < numColonies; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

// ===========================================================================
// Function: fordFulkerson
// Description: This function finds the maximum flow from source 's' to sink
//              't' in the graph.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
//             int s: source vertex.
//             int t: sink vertex.
// Return value: int: maximum flow from source 's' to sink 't' in the graph.
// Complexity: O(n^2)
// ===========================================================================
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int numColonies = graph.size();
    vector<vector<int>> rGraph(numColonies, vector<int>(numColonies));

    for (int u = 0; u < numColonies; u++) {
        for (int v = 0; v < numColonies; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(numColonies);
    int maxFlow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

// ===========================================================================
// Function: print max flow
// Description: This function prints the maximum flow from source 's' to sink
//              't' in the graph.
// Parameters: vector<vector<int>>& graph: adjacency matrix of the graph.
//             int s: source vertex.
//             int t: sink vertex.
// Return value: void
// Complexity: O(n^2)
// ===========================================================================
void printMaxFlow(vector<vector<int>>& graph, int s, int t) {
    int maxFlow = fordFulkerson(graph, s, t);
    cout << "Flujo maximo: " << maxFlow << endl;
}

#endif // FORDFULKERSON_H