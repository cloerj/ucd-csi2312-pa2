//
// Edited by John-Marc Cloer
//

#include "Point.h"
#include <cmath>        // Added cmath to get use of the sqrt() function
#include <iostream>     // Added iostream to gain use of cout and cin
#include <iomanip>      // Added iomanip to gain use of the setpersision and fixed features

using namespace std;


double computeArea(Point &a, Point &b, Point &c) {          //This guy uses Heron's formula to calculate the area.

    double aToB, aToC, bToC, semiperimeter, triarea;

    aToB = a.distanceTo(b);
    aToC = a.distanceTo(c);
    bToC = b.distanceTo(c);

    semiperimeter = (aToB + aToC+ bToC) / 2;

    triarea = sqrt( semiperimeter * (semiperimeter-aToB) * (semiperimeter-aToC) * (semiperimeter-bToC) );

    return triarea;
}


int main(void) {
    Point a, b, c;                                      // The three points that were given to us with the doubleCompute function
    double x, y, z;                                     // The three points that were given to us at the beginning


    cout << "This program takes user submitted points and uses them to calculate the area of a triangle floating in Three-Dimensional Space." << endl;
    cout << "Each point on the triangle will need 3 coordinates (X, Y, & Z)." << endl; // Intro message to explain what the program does


    cout << "Please enter the X coordinate for the first point:" << endl;               // Sets the coordinates for the first point
    cin >> x;
    a.setX(x);
    cout << "Please enter the Y coordinate for the first point:" << endl;
    cin >> y;
    a.setX(y);
    cout << "Please enter the Z coordinate for the first point:" << endl;
    cin >> z;
    a.setX(z);

    cout << "Please enter the X coordinate for the second point:" << endl;              // Sets the coordinates for the second point
    cin >> x;
    b.setX(x);
    cout << "Please enter the Y coordinate for the second point:" << endl;
    cin >> y;
    b.setX(y);
    cout << "Please enter the Z coordinate for the second point:" << endl;
    cin >> z;
    b.setX(z);

    cout << "Please enter the X coordinate for the third point:" << endl;               // Sets the coordinates for the third point
    cin >> x;
    c.setX(x);
    cout << "Please enter the Y coordinate for the third point:" << endl;
    cin >> y;
    c.setX(y);
    cout << "Please enter the Z coordinate for the third point:" << endl;
    cin >> z;
    c.setX(z);

    cout << "The area of the three-dimensional triangle is " << setprecision(2) << computeArea(a, b, c) << "." << endl; // Displays the area of the triangle

    return 0;
}
