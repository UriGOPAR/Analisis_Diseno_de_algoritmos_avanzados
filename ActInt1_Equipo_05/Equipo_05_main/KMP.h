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

using namespace std;

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
void computeLPSArray(char* pat, int M, int* lps)
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
void KMPSearch(char* pat, char* txt, string texto, string patron)
{
	int M = strlen(pat);
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
			cout << "True " << texto <<" contiene el codigo " << pat << " contenido en el archivo " << patron << " en la posicion: " << i - j << endl;
			found = true;
            j = lps[j - 1];
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

// ===========================================================================
// Function: checkForMaliciousCode
// Description: This function reads the text and pattern files and calls
//              the KMPSearch function to search for the pattern in the text.
// Parameters: string txt: name of the text file
//             string mcode: name of the pattern file
// Return value: void
// Complexity: O(n + m)
// ===========================================================================
void checkForMaliciousCode(string txt, string mcode)
{
    string transmissionContent = "";
    string mcodeContent = "";
    ifstream inFile(txt);
    ifstream inFile2(mcode);

    if (!inFile || !inFile2) {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) {
        transmissionContent += ch;
    }

    while (inFile2.get(ch)) {
        mcodeContent += ch;
    }

    char txt2[transmissionContent.length() + 1];
    char pat[mcodeContent.length() + 1];
    strcpy(txt2, transmissionContent.c_str());
    strcpy(pat, mcodeContent.c_str());

    KMPSearch(pat, txt2, txt, mcode);
}

#endif