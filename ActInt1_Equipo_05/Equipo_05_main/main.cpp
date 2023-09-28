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

    KMP KMP1 = KMP();
    KMP KMP2 = KMP();
    cout<<"Archivo Transmision 1"<<endl;
    cout<<KMP1.processFiles(transmission01)<<endl;
    cout<<"\n"<<endl;

    cout<<"Archivo Transmosion 2"<<endl;
    cout<<KMP1.processFiles(transmission02)<<endl;
    cout<<"\n"<<endl;

    cout<<"Archivo mcode1"<<endl;
    cout<<KMP1.processFiles(mcode01)<<endl;

    cout<<"Archivo mcode2"<<endl;
    cout<<KMP1.processFiles(mcode02)<<endl;

    cout<<"Archivo mcode3"<<endl;
    cout<<KMP1.processFiles(mcode03)<<endl;
    cout<<"\n"<<endl;
    
    cout<<"T R A N S M I S S I O N   1 \n"<<endl;
    KMP1.checkForMaliciousCode(transmission01, mcode01);
    KMP1.checkForMaliciousCode(transmission01, mcode02);
    KMP1.checkForMaliciousCode(transmission01, mcode03);
    cout<<"\n"<<endl;

    cout<<"T R A N S M I S S I O N   2 \n"<<endl;
    KMP2.checkForMaliciousCode(transmission02, mcode01);
    KMP2.checkForMaliciousCode(transmission02, mcode02);
    KMP2.checkForMaliciousCode(transmission02, mcode03);
    cout<<"\n"<<endl;
    
	return 0;
}
