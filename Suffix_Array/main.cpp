#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> obtenerSubcadenas(const std::string& cadena) {
    std::vector<std::string> subcadenas;
    int longitud = cadena.length();
    for (int i = 0; i < longitud; ++i) {
        for (int j = i+1; j <= longitud; ++j) {
            subcadenas.push_back(cadena.substr(i, j - i));
        }
    }
    return subcadenas;
}

int main() {
    std::string cadena;
    std::cout << "Introduce una cadena: ";
    std::cin >> cadena;

    std::vector<std::string> subcadenas = obtenerSubcadenas(cadena);

    // Ordenar alfabéticamente
    std::sort(subcadenas.begin(), subcadenas.end());

    // Mostrar las subcadenas ordenadas
    for (const std::string& subcadena : subcadenas) {
        std::cout << subcadena << std::endl;
    }

    return 0;
}