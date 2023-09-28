#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> processFiles(string txt){
    ifstream inFile(txt);
    vector<char> txtContent;
    char ch;

    if (!inFile) {
        // cerr << "Error al abrir el archivo." << endl;
        return txtContent;
    }

    while (inFile.get(ch)) {
        if (ch != '\n'){
            txtContent.push_back(ch);
        }
    }

    return txtContent;
}

string LCS(vector<char> txt1, vector<char> txt2){
    int m = txt1.size();
    int n = txt2.size();
    int maximum = 0;
    int endIndex = -1;  // Final del LCS en txt1

    vector<vector<int>> M(m, vector<int>(n, 0));

    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if (txt1[i] == txt2[j]){
                M[i][j] = 1 + M[i - 1][j -1];
                if (M[i][j] > maximum) {
                    maximum = M[i][j];
                    endIndex = i;
                }
            }
            else{
                M[i][j] = 0;
            }
        }
    }

    if (maximum == 0) {
        return "No se encontro un substring compartido en ambas transmiciones";  // No hay subcadena en común
    }

    // Construir la subcadena en común
    string lcs(txt1.begin() + endIndex - maximum , txt1.begin() + endIndex + 1);
    return lcs;
}

#endif