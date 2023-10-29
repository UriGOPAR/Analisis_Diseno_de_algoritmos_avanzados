#include <iostream>
#include <vector>

using namespace std;

int knapsack(int N, vector<int>& valores, vector<int>& pesos, int W) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

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

    // Mostrar la matriz generada
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