// ===========================================================================
// File: Manacher.h
// Date: September 25, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This program implemets Manacher algorithm for the search of
//              the longest palindrome in a given text.
// Complexity: The complexity of this algorithm is O(n), where n is the length
//             of the text.
// ===========================================================================

#ifndef MANACHER_H
#define MANACHER_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ===========================================================================
// Function: Manacher
// Description: This function finds the longest palindrome in a given text.
// Parameters: const string &s: text to be searched.
// Return value: pair<int, int> : pair with the start and end position of the
//                               longest palindrome.
// Complexity: O(n)
// ===========================================================================
pair<int, int> Manacher(const string &s) {
    string cadenaNueva = "#";
    for (char c : s) {
        cadenaNueva += c;
        cadenaNueva += '#';
    }

    int n = cadenaNueva.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 0; i < n; i++) {
        int mirr = 2 * C - i;

        if (i < R) {
            P[i] = min(R - i, P[mirr]);
        }

        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < n && b >= 0 && cadenaNueva[a] == cadenaNueva[b]) {
            P[i]++;
            a++;
            b--;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLength = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLength) {
            maxLength = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - maxLength) / 2;
    int end = start + maxLength - 1;

    return make_pair(start, end);
}

#endif