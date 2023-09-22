// ===============================================================================================================
// File: main.cpp
// Date: September 21, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: El programa recibe el nombre de un archivo.txt seguido de n que es múltiplo de 4, es mayor o 
//              igual a 16 pero menor o igual a 64, n determina el número de columnas que tendrá la tabla para 
//              acomodar absolutamente todos los caracteres. Si el número de caracteres no es múltiplo de N, el 
//              último renglón de la tabla se rellena con el valor de n. De salida se da la concatenación de la
//              representación hexadecimal de la posición del arreglo.
// To compile: g++ main.cpp -o app y después ./app
// Complexity: La complejidad de todo el programa es o(N), ya que dependen los ciclos totalmente del tamaño de N
// ==============================================================================================================

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
    //Lee el archivo caracter por caracter y guarda los datos en el vector fila, hasta que fila sea del mismo tamaño que "n", por lo que 
    //la complejidad algorítmica aquí es O(n)
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
    //Creación de la tabla, donde cada fila tiene n caracteres. Complejidad de O(n) al depender de n en el ciclo
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
    //Recorre cada columna y suma los valores de los caracteres de esa columna en filas. 
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

    cout << "\nRepresentacion hexadecimal:\n";
    for (int i = 0; i < n; i++) {
        cout << salida.substr(i*2, 2);
        if ((i+1) % 4 == 0 && i != 2*n - 1) { 
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}