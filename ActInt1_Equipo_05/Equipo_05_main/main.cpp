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
    string transmission01 = "transmission01.txt";
    string transmission02 = "transmission02.txt";
    string mcode01 = "mcode01.txt";
    string mcode02 = "mcode02.txt";
    string mcode03 = "mcode03.txt";

    checkForMaliciousCode(transmission01, mcode01);
    checkForMaliciousCode(transmission01, mcode02);
    checkForMaliciousCode(transmission01, mcode03);

    checkForMaliciousCode(transmission02, mcode01);
    checkForMaliciousCode(transmission02, mcode02);
    checkForMaliciousCode(transmission02, mcode03);
    
	return 0;
}
