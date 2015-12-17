//
// John-Marc Cloer
//

#include <iostream>
#include <math.h>

#include "Point.h"

using namespace std;

namespace Clustering {
    //Default Constructor
    Point::Point(int newDims)          //Can't use the dim variable because it throws an error
    {
        dim = newDims;
        values = new double[newDims];

        for (int i = 0; i < newDims; i++) {
            values[i] = 0;
        }
    }

    //Constructor
    Point::Point(int newDims, double *array) {
        //Does the same thing as the default
    }

    // Copy Constructor
    Point::Point(const Point &newDims) {
        dim = newDims.getDims();
        values = new double[newDims.getDims()];
        for (int i = 0; i < newDims.getDims(); i++) {
            values[i] = newDims.getValue(i);
        }
    }

    // Overloaded assignment operator
    Point &Point::operator=(const Point &point) {
        if (this == &point) {
            return *this;
        }
        if (values != NULL) {
            delete[] values;
        }
        else {
            dim = point.getDims();
            double *newArray = new double[point.getDims()];
            for (int i = 0; i < point.getDims(); i++) {
                newArray[i] = point.getValue(i);
            }
            values = newArray;
        }
    }

    // Destructor
    Point::~Point() {
        delete[] values;
    };

    // Accessors & Mutators
    void Point::pointToConsole()
    {
        while (dim != 0)
        {
            if (dim == 1)
            {
                cout << "[" << values[dim - 1] << "]";
                return;
            }
            if (dim != 1)
            {
                for (int i = 0; ++i < dim; i++)
                {
                    cout << values[i];
                }
            }
        }
    }

    void Point::setValue(int i, double value)
    {
        values[i] = value;
    }

    // getValue Function
    double Point::getValue(int i) const
    {
        return values[i];
    }


    //Functions

    // distanceTo Function
    double Point::distanceTo(const Point &comparedPoint) const {
        double distanceTo;
        distanceTo = 0;

        for (int i = 0; i < dim; i++) {
            distanceTo = 2 * (comparedPoint.getValue(i) - values[i]);
            return distanceTo;
        }
        return sqrt(distanceTo);
    }

    // Members
    // Multiplication assignment operator
    Point &Point::operator*=(double prod)
    {
        for (int i = 0; i < getDims(); i++)
        {
            setValue(i, (getValue(i) * prod));
        }
        return *this;
    }

    // Division assignment operator
    Point &Point::operator/=(double num)
    {
        for (int i = 0; i < getDims(); i++)
        {
            setValue(i, (getValue(i) / num));
        }
        return *this;
    }

    // Multiplication operator
    const Point Point::operator*(double prod) const
    {
        Point multi(dim);

        for (int i = 0; i < dim; i++)
        {
            multi.setValue(i, (values[i] * prod));
        }

        return multi;
    }

    // Division operator
    const Point Point::operator/(double quo) const
    {
        Point div(dim);

        for (int i = 0; i < dim; i++)
        {
            div.setValue(i, (values[i] / quo));
        }
        return div;
    }

    double &Point::operator[](int i)
    {
        return values[i];
    }

    // Equality Operator
    bool operator==(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() == rhs.getDims())
        {
            return true;
        }
        for (int i = 0; i < rhs.getDims(); i++)
        {
            if (lhs.getValue(i) == rhs.getValue(i))
            {
                return true;
            }
        }
    }

    // Inequality Operator
    bool operator!=(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() == rhs.getDims())
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // Less Than operator
    bool operator<(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() < rhs.getDims())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Greater Than Operator
    bool operator>(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() > rhs.getDims())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Less than or equal to operator
    bool operator<=(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() < rhs.getDims())
        {
            return true;
        }
        else if (lhs.getDims() == rhs.getDims())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Greater than or equal to  operator
    bool operator>=(const Point &lhs, const Point &rhs)
    {
        if (lhs.getDims() > rhs.getDims())
        {
            return true;
        }
        else if (lhs.getDims() == rhs.getDims())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Addition assignment operator
    Point &operator+=(Point &lhs, const Point &rhs)
    {
        for (int i = 0; i < lhs.getDims(); i++)
        {
            lhs.setValue(i, lhs.getValue(i) + rhs.getValue(i));
        }
        return lhs;
    }

    // Subtraction assignment operator
    Point &operator-=(Point &lhs, const Point &rhs)
    {
        for (int i = 0; i < lhs.getDims(); i++)
        {
            lhs.setValue(i, lhs.getValue(i) - rhs.getValue(i));
        }
        return lhs;
    }

    // Addition operator
    const Point operator+(const Point &lhs, const Point &rhs)
    {
        Point addit(lhs.getDims());

        for (int i = 0; i < lhs.getDims(); i++)
        {
            addit.values[i] = lhs.values[i] + rhs.values[i];
        }
        return addit;
    }

    // Subtraction operator
    const Point operator-(const Point &lhs, const Point &rhs)
    {
        Point subtra(lhs.getDims());

        for (int i = 0; i < lhs.getDims(); i++)
        {
            subtra.values[i] = lhs.values[i] - rhs.values[i];
        }
        return subtra;
    }

    std::ostream &operator<<(std::ostream &, const Point &point)
    {
        cout << "Your values are:";
        for (int i = 0; i < point.getDims(); i++)
            cout << " " << point.values[i];

        cout << endl << "Your dimensions are: " << point.getDims();
    }

    std::istream &operator>>(istream &iStream, Point &point)
    {
        for (int i = 0; i < point.getDims(); i++)
        {
            iStream >> point.values[i];
        }
        return iStream;
    }
}
