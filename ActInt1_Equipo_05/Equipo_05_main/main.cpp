// ===========================================================================
// File: main.cpp
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

// ===========================================================================
// libraries
// ===========================================================================
#include "KMP.h"
#include "Substring.h"
#include "Manacher.h"

// ===========================================================================
// Function: main
// Description: This function tests the Knuth-Morris-Pratt algorithm
//              for the search of a given pattern in a given text, in
//              this case its used for searching malicious code in a
//              received transmission.
// Parameters: none
// Return value: int
// Complexity: O(n + m)
// ===========================================================================
int main()
{
    //Define main function, read .txt files, 2 for the strings and 3 for the patterns
    KMP kmp;
    string transmission01 = "transmission01.txt";
    string transmission02 = "transmission02.txt";
    string mcode01 = "mcode01.txt";
    string mcode02 = "mcode02.txt";
    string mcode03 = "mcode03.txt";
    //Asign to a vector the pattern codes
    vector<string> mcodes = {mcode01, mcode02, mcode03};
    string txt1 = kmp.processFiles(transmission01);
    string txt2 = kmp.processFiles(transmission02);

    //Create objects KMP1 and KMP2 to search for malicious code
    KMP KMP1 = KMP();
    KMP KMP2 = KMP();

    //Create variables res, inicio and fin to keep operation's results
    pair<int, int> res;
    int inicio;
    int fin;

    //Print the content of the files: the strings files and the pattern ones
    cout << "Archivo Transmision 1" << endl;
    cout << KMP1.processFiles(transmission01) << endl;
    cout << "\n" << endl;

    cout << "Archivo Transmision 2" << endl;
    cout << KMP1.processFiles(transmission02) << endl;
    cout << "\n" << endl;

    cout << "Archivo mcode1" << endl;
    cout << KMP1.processFiles(mcode01) << endl;

    cout << "Archivo mcode2" << endl;
    cout << KMP1.processFiles(mcode02) << endl;

    cout << "Archivo mcode3" << endl;
    cout << KMP1.processFiles(mcode03) << endl;
    cout << "\n" << endl;
    
    cout << "T R A N S M I S S I O N   1 \n" << endl;
    KMP1.checkForMaliciousCode(transmission01, mcodes);
    cout << "\n" << endl;
    
    //Search for malicious code from objects KMP1 and KMP2 and printed it out on the console
    cout << "T R A N S M I S S I O N   2 \n" << endl;
    KMP2.checkForMaliciousCode(transmission02, mcodes);
    cout << "\n" << endl;
    
    //Use the Manacher algorithm to find the largest palindrome on the transmission files and print the results
    cout << "Palindromo mas largo en transmission 1: " << endl;
    res = Manacher(txt1);
    inicio = res.first;
    fin = res.second;
    cout << "Palindromo mas largo en el archivo" << transmission01 
         << " desde la posicion: " << inicio << " hasta la posicion: " << fin << endl;
    cout << "\n" << endl;

    cout << "Palindromo mas largo en transmission 2: " << endl;
    res = Manacher(txt2);
    inicio = res.first;
    fin = res.second;
    cout << "Palindromo mas largo en el archivo " << transmission02 
         << " desde la posicion: " << inicio << " hasta la posicion: " << fin << endl;
    cout << "\n" << endl;

    //Longest-Common-Subsequence (LCS) algorithm to find the largest common substring between two files and printed it out on the console 
    cout << "Sub-String comun mas largo: ";
    cout << LCS(processFiles(transmission01), processFiles(transmission02));
    cout << "\n" << endl;
    
	return 0;
}
