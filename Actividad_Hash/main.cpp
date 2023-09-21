#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {
    string archivo;
    int n;

    cout << "Introduce el nombre del archivo (sin .txt): ";
    cin >> archivo;

    archivo +=".txt";
    
    cout << "Ingresa un multiplo de 'n' de entre 16 y 64: ";
    cin >> n;

    ifstream inFile(archivo);
    if (!inFile) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    vector<vector<char>> tabla;
    char ch;
    vector<char> fila;
    while (inFile.get(ch)) {
        fila.push_back(ch);
        if (fila.size() == n) {
            tabla.push_back(fila);
            fila.clear();
        }
    }

    // Rellenar si es necesario
    if (!fila.empty()) {
        while (fila.size() < n) {
            fila.push_back(static_cast<char>('['));
        }
        tabla.push_back(fila);
    }

    cout << "\nTabla:\n";
    for (auto& fila : tabla) {
        for (char c : fila) {
            if (c == '\n') {
                cout << "- ";
            } else {
                cout << c << " ";
            }
        }
        cout << endl;
    }
    vector<int> a(n, 0);
    for (int col = 0; col < n; ++col) {
        for (int row = 0; row < tabla.size(); ++row) {
            a[col] += static_cast<int>(tabla[row][col]);
        }
        a[col] %= 256;
    }

    cout << "\nArreglo a:\n";
    for (int val : a) {
        cout << val << " ";
    }
    cout << endl;

    string salida;
    stringstream ss;
    for (int i = 0; i < n; i++) {
        ss << setfill('0') << setw(2) << uppercase << hex << a[i];
    }
    salida = ss.str();

    cout << "\nSalida:\n";
    for (int i = 0; i < n; i++) {
        cout << salida.substr(i*2, 2);
        if ((i+1) % 4 == 0 && i != 2*n - 1) { 
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}