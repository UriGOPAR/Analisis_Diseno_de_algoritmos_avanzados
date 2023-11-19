// ===========================================================================
// File: EculideanDistance.h
// Date: November 13, 2023
// Author: María Fernanda Moreno Gómez A01708653
//         Uri Jared Gopar Morales A01709413
//         Ricardo Rosales Castañeda A01709449
// Description: This file contains the implementation of the Eculidean Distance
//              algorithm.
// Complexity: O(n)
// ===========================================================================

#ifndef ECULIDEANDISTANCE_H
#define ECULIDEANDISTANCE_H

// ===========================================================================
// libraries
// ===========================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

// ===========================================================================
// Function: calculateDistance
// Description: This function calculates the distance between two points.
// Parameters: int x1: x coordinate of the first point.
//             int y1: y coordinate of the first point.
//             int x2: x coordinate of the second point.
//             int y2: y coordinate of the second point.
// Return value: double distance: distance between the two points.
// Complexity: O(1)
// ===========================================================================
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// ===========================================================================
// Function: euclideanDistance
// Description: This function finds closest point in a vector to 
//              a given point.
// Parameters: vector<pair<int, int>>& points: vector with the points.
//             int x: x coordinate of the point.
//             int y: y coordinate of the point.
// Return value: int closestPoint: index of the closest point.
// Complexity: O(n)
// ===========================================================================
int euclideanDistance(vector<pair<int, int>>& points, int x, int y) {
    int closestPoint = 0;
    double minDistance = numeric_limits<double>::infinity();

    for (int i = 0; i < points.size(); i++) {
        double distance = calculateDistance(x, y, points[i].first, points[i].second);
        if (distance < minDistance) {
            minDistance = distance;
            closestPoint = i;
        }
    }

    return closestPoint;
}

// ===========================================================================
// Function: printClosest
// Description: This function prints the closest point to a given point.
// Parameters: vector<pair<int, int>>& points: vector with the points.
//             int x: x coordinate of the point.
//             int y: y coordinate of the point.
// Return value: void.
// Complexity: O(n)
// ===========================================================================
void printClosest(vector<pair<int, int>>& points, int x, int y) {
    int closestPoint = euclideanDistance(points, x, y);
    cout << "La central mas cercana a [" << x << ", " << y << "] es [" << 
        points[closestPoint].first << ", " << points[closestPoint].second << "] " << 
        "con una distancia de " << calculateDistance(x, y, points[closestPoint].first,
        points[closestPoint].second) << "." << endl;
}

#endif // ECULIDEANDISTANCE_H