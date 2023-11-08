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
    ifstream file("test1.txt"); // Asegúrate de que el archivo está en el mismo directorio que tu ejecutable, o proporciona una ruta completa.

    if (!file) {
        cout << "No se pudo abrir el archivo." << endl;
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