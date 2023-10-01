// ===========================================================================
// File: Substring.h
// Date: September 25, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This program implemets LCS algorithm for the search of
//              the longest substring in common in two given texts.
// Complexity: The complexity of this algorithm is O(n*m), where n is the length
//             of the first text and m is the length of the second text.
// ===========================================================================

#ifndef SUBSTRING_H
#define SUBSTRING_H

// ===========================================================================
// libraries
// ===========================================================================
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// ===========================================================================
// Function: processFiles
// Description: This function reads the content of a given file and stores it
//              in a vector of chars.
// Parameters: string txt: name of the file to be read.
// Return value: vector<char> txtContent: vector with the content of the file.
// Complexity: O(n)
// ===========================================================================
vector<char> processFiles(string txt){
    ifstream inFile(txt);
    vector<char> txtContent;
    char ch;

    if (!inFile) {
        return txtContent;
    }

    while (inFile.get(ch)) {
        if (ch != '\n'){
            txtContent.push_back(ch);
        }
    }

    return txtContent;
}

// ===========================================================================
// Functiob: LCS
// Description: This function finds the longest substring in common in two
//              given texts.
// Parameters: vector<char> txt1: first text.
//             vector<char> txt2: second text.
// Return value: string lcs: longest substring in common.
// Complexity: O(n*m)
// ===========================================================================
string LCS(vector<char> txt1, vector<char> txt2){
    int m = txt1.size();
    int n = txt2.size();
    int maximum = 0;
    int endIndex = -1;

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
        return "No se encontro un substring compartido en ambas transmiciones";
    }

    string lcs(txt1.begin() + endIndex - maximum , txt1.begin() + endIndex + 1);
    return lcs;
}

#endif