// ===============================================================================================================
// File: main.cpp
// Date: October 29, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: El programa implementa el problema de la mochila (Knapsack problem), donde se tiene un conjunto
//              de objetos con un peso y un valor y una mochila con una capacidad máxima de peso. El objetivo es
//              encontrar la combinación de objetos que puedes colocar en la mochila de forma que se maximice el 
//              valor total de los objetos sin excederse del peso máximo. Se pide como entrada la cantidad de 
//              objetos que se disponen, el valor de cada uno de ellos y sus respectivos pesos, así como la capa-
//              cidad máxima de la mochila. La salida es una matriz, donde cada celda representa el valor máximo
//              que puedes obtener considerando los primeros N elementos y una capacidad W de peso, así como la 
//              ganancia óptima después de este análisis.
// Complexity: La complejidad de todo el programa es o(N x M), debido a que pasa por todos los valores y por todos 
//             los pesos de los objetos para poder contruir la matriz y para imprimirla, por lo que el programa 
//             depende de la cantidad de elementos y sus pesos.
// ==============================================================================================================
#include <iostream>
#include <vector>

using namespace std;

int knapsack(int N, vector<int>& valores, vector<int>& pesos, int W) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    //Contrucción de la matriz
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (pesos[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], valores[i - 1] + dp[i - 1][w - pesos[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Imprimir la matriz generada
    cout << "Matriz generada durante el proceso:" << endl;
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[N][W];
}

int main() {
    int N;
    cout << "Ingrese el numero de elementos disponibles (N): ";
    cin >> N;

    vector<int> valores(N);
    vector<int> pesos(N);

    cout << "Ingrese los valores de los elementos:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> valores[i];
    }

    cout << "Ingrese los pesos de los elementos:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> pesos[i];
    }

    int W;
    cout << "Ingrese la capacidad maxima de la mochila (W): ";
    cin >> W;

    int resultado = knapsack(N, valores, pesos, W);
    cout << "La ganancia optima es: " << resultado << endl;

    return 0;
}