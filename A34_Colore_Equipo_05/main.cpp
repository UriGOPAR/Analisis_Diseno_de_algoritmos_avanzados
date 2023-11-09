// ===============================================================================================================
// File: main.cpp
// Date: November 08, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: El programa implementa el problema del coloreo, donde dado una matriz de adyacencia de un grafo,
//              se muetran los colores en los que se puede pintar un vértice de modo que, no se repita con los 
//              vértices adyacentes.
// To compile: g++ main.cpp -o app y después ./app
// Complexity: La complejidad algorítmica es O(n^m), pues n es el número de vértices del grafo y m es el número 
//             de colores con los que se colorea.
// ==============================================================================================================
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Función para comprobar si es seguro colorear un nodo con un color específico.
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Función recursiva de utilidad para resolver el problema de coloración de grafos.
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

// La función principal para resolver el problema de coloración de grafos.
// Devuelve false si los nodos no pueden ser coloreados con m colores.
bool graphColoring(vector<vector<int>>& graph) {
    int m = 1; // Comienza con un solo color
    while (true) {
        vector<int> color(graph.size(), 0);
        if (graphColoringUtil(graph, m, color, 0)) {
            cout << "Numero minimo de colores requeridos: " << m << endl;
            for (int i = 0; i < graph.size(); i++) {
                cout << "Vertice " << i << ", Color asignado: " << color[i] << endl;
            }
            return true;
        }
        m++; // Incrementa el número de colores y prueba nuevamente
    }
    return false;
}

int main() {
    string nombreArchivo;
    cout << "Por favor, ingrese el nombre del archivo sin poner .txt: ";
    cin >> nombreArchivo;

    ifstream file(nombreArchivo + ".txt");
    if (!file) {
        cout << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    int n; // Número de nodos
    file >> n; // Leer el número de nodos desde el archivo

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> graph[i][j];
        }
    }

    int m = 3; // Número de colores
    if (!graphColoring(graph)) {
        cout << "Solución no encontrada." << endl;
    }

    file.close(); // No olvides cerrar el archivo
    return 0;
}