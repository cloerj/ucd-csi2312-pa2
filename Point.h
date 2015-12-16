//
// John-Marc Cloer
//

#ifndef PA2_POINT_H
#define PA2_POINT_H

#include <iostream>

namespace Clustering {

    class Point {

    private:                    // Declaring Private as a reminder
        int dim;                // number of dimensions of the point
        double *values;         // values of the point's dimensions

    public:
        Point(int);
        Point(int, double *);

        // Big Three:
        Point(const Point &);                   //Copy Constructor
        Point &operator=(const Point &);        //Assignment operator
        ~Point();                               //Destructor

        // Accessors & Mutators
        void pointToConsole();
        int getDims() const { return dim; }
        void setValue(int, double);
        double getValue(int) const;

        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        //Members
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const;
        const Point operator/(double) const;

        //1-based index!
        double& operator[](int index);

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &);
    };
}


#endif //PA2_POINT_H
