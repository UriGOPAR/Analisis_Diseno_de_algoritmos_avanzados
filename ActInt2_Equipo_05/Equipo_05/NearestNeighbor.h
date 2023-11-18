#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

// Función para encontrar la solución al TSP utilizando el Vecino más Cercano
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

    // Asegúrate de que el tour regrese al primer nodo
    tour.push_back(tour[0]);

    return tour;
}

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

    // Calcular la distancia total según los valores de la matriz de adyacencia
    for (int i = 0; i < N; ++i) {
        int node1 = tour[i];
        int node2 = tour[i + 1];
        totalDistance += graph[node1][node2];
    }

    cout << totalDistance << endl;
}

#endif // NEARESTNEIGHBOR_H
