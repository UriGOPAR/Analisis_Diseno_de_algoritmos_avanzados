// ================================================================================================================
// File: main2.cpp
// Date: September 24, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: El programa recibe una cadena de máximo 12 caracteres, donde  se sacan sus sufijos y posteriormente
//              estos sufijos son ordenados con el ordenamiento radix para poder calcular el arreglo de substrings
// To compile: g++ main.cpp -o app y después ./app
// Complexity: La complejidad del programa sin imprimirlo es O(n log n) (explicación en cada función del programa)
// ================================================================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype> 

using namespace std;

//Función que ordena los elementos del Suffix Array (SA) que son los índices
//del vector, basado en los valores del Ranking Array (RA) con un desplazamiento k
//Tiene una complejidad algorítmica de O(n+m) -> O(n), pues depende de n que es el tamaño de vector SA y de m, que es c, o sea, el valor máximo el vector de conteo
void countingSort(vector<int>& SA, vector<int>& RA, int k) {
    int n = SA.size(); //n es el número de sufijos
    int maxSize = max(300, n); //Valor máximo para el tamaño del vector de conteo
    vector<int> c(maxSize, 0), tempSA(n); //c es el vector de contar, mientras que tempSa es un arreglo temporal para el SA
    //Contar la cantidad de veces que cada valor apareec en RA en las posiciones i+k
    for (int i = 0; i < n; i++) {
        c[i + k < n ? RA[i + k] : 0]++; //Cuenta las ocurrencias de los valores RA con el desplazamiento k
    }
    //Calcular las posiciones de inicio para cada Suffix Array ordenado
    for (int i = 1; i < maxSize; i++) {
        c[i] += c[i - 1]; //Acumula los valores de c para obtener las posiciones de los elementos en el ordenamiento
    }
    //Colocar cada sufijo en la posición correcta en tempSA basándose en los valores RA, SA se actualiza para hacer el ordenamiento
    for (int i = n - 1; i >= 0; i--) {
        tempSA[--c[SA[i] + k < n ? RA[SA[i] + k] : 0]] = SA[i]; //Coloca los elementos en su posición ordenada en el vector tempSA
    }
    SA = tempSA; //Actualiza SA con tempSA
}

//Función que usa un ordenamiento Radix basado en contingSort para ordenar los sufijos
//Ordena los elementos de los menos significativos a los más significativos, donde se ordenan
//primero los sufijos por el primer caracter, luego el segundo y así, doblando la longitud de 
//las subcadenas consideradas en cada paso.
//La complejidad algorítmica de esta función es O(n log n), pues hay un ciclo que tiene como base 2 del tamaño de la cadena T veces, ya que k se duplica en cada iteración del ciclo hasta que k excede n, además de que se manda a llamar dos veces a countingSort que es O(n)
void createSuffixArray(string T, vector<int>& SA, vector<int>& RA) {
    int n = T.size(); //n es la longitud de la cadena T

    SA.resize(n); //Darle el tamaño de n
    RA.resize(n); //Darle el tamaño de n
    vector<int> tempRA(n); //Vector temporal para almacenar el ranking del array
    //El ciclo inicializa SA con los índices de los sufijos y RA con los valores de los caracteres de T
    for (int i = 0; i < n; i++) {
        SA[i] = i;
        RA[i] = T[i];
    }

    //Ciclo de ordenamiento Radix, que ordena los sufijos primero por el segundo caracter y luego por el primer caracter
    for (int k = 1; k < n; k <<= 1) {
        countingSort(SA, RA, k); //Segundo caracter
        countingSort(SA, RA, 0); //Primer caracter

        //Actualizar los rangos de los sufijos, donde si dos sufijos son iguales en las primeras 2*k posiciones, reciben el mismo rango, sino, el rango se incrementa.
        int r = 0;
        tempRA[SA[0]] = r;
        for (int i = 1; i < n; i++) {
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k]) ? r : ++r;
        }

        //Actualizar RA con los nuevos rangos de los sufijos
        for (int i = 0; i < n; i++) {
            RA[i] = tempRA[i];
        }

        //Si todos los sufijos tienen un rango único, se termina el ciclo
        if (RA[SA[n-1]] == n - 1) break;
    }
}

int main() {
    string T;
    cout << "Introduce una palabra (maximo 12 caracteres): ";
    cin >> T;

    // Verifica y corrige la longitud de la cadena si es necesario
    if (T.size() > 12) {
        cout << "La cadena es demasiado larga. Se corto a 12 caracteres." << endl;
        T = T.substr(0, 12);
    }

    // Convierte todas las letras a mayúsculas
    for (char& c : T) {
        c = toupper(c);
    }

    // Asegurarse de que la cadena termine con un '$'
    if (T.back() != '$') {
        T += '$';
    }

    vector<int> SA, RA;

    createSuffixArray(T, SA, RA);

    cout << "Suffix Array para \"" << T << "\":" << endl;
    for (int i = 0; i < SA.size(); i++) {
        cout << T.substr(SA[i]) << endl;
    }

    return 0;
}
