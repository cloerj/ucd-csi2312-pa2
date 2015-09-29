//
// Edited by John-Marc Cloer
//

#include "Point.h"
#include <cmath>


// Default constructor
// Initializes the point to (0.0, 0.0, 0.0)
Point::Point() {
    x = 0.0;
    y = 0.0;
    z = 0.0;                                                    // Initialized Point z to 0.0 (Instruction 2)
}

// Constructor
// Initializes the point to (initX, initY, initZ)
Point::Point(double initX, double initY, double initZ) {
    x = initX;
    y = initY;
    z = initZ;                                                 // Initialized Point Z to initZ (Instruction 2)
}

// Destructor
// No dynamic allocation, so nothing to do; if omitted, generated automatically
Point::~Point() {
    // no-op
}

// Mutator methods
// Change the values of private member variables

void Point::setX(double newX) {
    x = newX;
}

void Point::setY(double newY) {
    y = newY;
}

void Point::setZ(double newZ) {                                 // Added a mutator to change the value of z (Instruction 2)
    z = newZ;
}


// Accessors
// Return the current values of private member variables

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

double Point::getZ() {                                          // Added an accessor to return the current value of z (Instruction 2)
    return z;
}

double Point::distanceTo(Point &a) {                            // This function calculates the distance between points (Instruction 3)
    return sqrt(pow(a.getX()-x, 2) + pow(a.getY()-y, 2) + pow(a.getZ()-z, 2));
}
