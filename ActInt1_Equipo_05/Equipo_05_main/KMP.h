// ===========================================================================
// File: KMP.h
// Date: September 25, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This program implemets the Knuth-Morris-Pratt algorithm
//              for the search of a given pattern in a given text, in
//              this case its used for searching malicious code in a 
//              received transmission.
// Complexity: The complexity of this algorithm is O(n + m), where n is
//             the length of the text and m is the length of the pattern.
// ===========================================================================

#ifndef KMP_H
#define KMP_H

// ===========================================================================
// libraries
// ===========================================================================
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
class KMP{
    public:
        string transmissionContent;
        string mcodeContent;
        // Constructor
        KMP();
        void computeLPSArray(char* pat, int M, int* lps);
        void KMPSearch(char* pat, char* txt, string texto, string patron);
        string processFiles(string txt);
        void checkForMaliciousCode(string txt, vector<string> mcodes);
};

KMP::KMP(){
    transmissionContent = "HOLA";
    mcodeContent = "Adios";
}

// ===========================================================================
// Function: computeLPSArray
// Description: This function computes the longest prefix suffix array
//              for the Knuth-Morris-Pratt algorithm.
// Parameters: char* pat: pattern to be searched
//             int M: length of the pattern
//             int* lps: longest prefix suffix array
// Return value: void
// Complexity: O(m)
// ===========================================================================
void KMP::computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// ===========================================================================
// Function: KMPSearch
// Description: This function implements the Knuth-Morris-Pratt algorithm
//              for the search of a given pattern in a given text.
// Parameters: char* pat: pattern to be searched
//             char* txt: text where the pattern will be searched
//             string texto: name of the text file
//             string patron: name of the pattern file
// Return value: void
// Complexity: O(n + m)
// ===========================================================================
void KMP::KMPSearch(char* pat, char* txt, string texto, string patron)
{
    int M = strlen(pat) ;
    int N = strlen(txt);

    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    bool found = false;

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            int startPosition = i - j;
            int endPosition = startPosition + strlen(pat) - 1;  // Cambio aquí
            cout << "True " << texto << " contiene el codigo " << pat << " contenido en el archivo " << patron 
                 << " desde la posicion: " << startPosition << " hasta la posicion: " << endPosition   << endl;
            found = true;
            i = startPosition +lps[j-1  ] + 1;
            j = lps[j - 1];  // Reinicia 'j' a 0 para comenzar a buscar una nueva coincidencia desde el principio del patrón
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else{
                i = i + 1;
            }
        }
    }
    
    if (!found) {
        cout << "False " << texto << " no contiene el codigo " << pat << " contenido en el archivo " << patron << endl;
    }
}

string KMP::processFiles(string txt){
    ifstream inFile(txt);
    string txtContent = "";
    char ch;

    if (!inFile) {
        // cerr << "Error al abrir el archivo." << endl;
        return txtContent;
    }

    while (inFile.get(ch)) {
        if (ch != '\n'){
            txtContent += ch;
        }
    }

    return txtContent;
}

// ===========================================================================
// Function: checkForMaliciousCode
// Description: This function reads the text and pattern files and calls
//              the KMPSearch function to search for the pattern in the text.
// Parameters: string txt: name of the text file
//             string mcode: name of the pattern file
// Return value: void
// Complexity: O(n + m)
// ===========================================================================
void KMP::checkForMaliciousCode(string txt, vector<string> mcodes)
{
    transmissionContent = processFiles(txt);

    if (transmissionContent.empty()) {
        cout << "Archivo de transmisión no válido" << endl;
        return;
    }

    char txt2[transmissionContent.length() + 1];
    strcpy(txt2, transmissionContent.c_str());

    for (const string& mcode : mcodes) {
        mcodeContent = processFiles(mcode);

        // Si mcodeContent está vacío, continúa con el siguiente mcode en el vector
        if (mcodeContent.empty()) {
            cout << mcode << ": Archivo mcode no encontrado" << endl;
            continue;
        }

        char pat[mcodeContent.length() + 1];
        strcpy(pat, mcodeContent.c_str());

        KMPSearch(pat, txt2, txt, mcode);
    }
}

#endif