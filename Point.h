// A 2-dimensional point class!
// Coordinates are double-precision floating point.

#ifndef __point_h
#define __point_h

#include <iostream>
#include <cassert>

class Point {

private:
    int dim;
    double *data;

public:
    // Constructors
    Point(int dim);                   //initializes point with dimension dim and all values = 0
    Point(int d, double[]);             //initialiuzes point with dim d and data array
    Point(const Point &);                    //copy constructor
    // Destructor
    ~Point();

    // Mutator methods
    void setDim(int index, double val);  //sets point value at dimension of index to val


    // Accessor methods
    double getDims() const { return dim; };       //returns dimension
    double getData(int index) const;                  //returns value at dimenstion of index

    //other methods
    double distanceTo(Point &p);

    //overloaded operators
    Point &operator=(const Point &);

    //friends
    friend std::ostream &operator<<(std::ostream &, const Point &);
    friend bool operator==(const Point &, const Point &);
    friend bool operator!=(const Point &, const Point &);
    friend bool operator<(const Point &, const Point &);
    friend bool operator>(const Point &, const Point &);
    friend bool operator<=(const Point &, const Point &);
    friend bool operator>=(const Point &, const Point &);
    friend const Point operator+(const Point &, const Point &);
    friend const Point operator-(const Point &, const Point &);
    friend const Point operator*(const Point &, double);
    friend const Point operator/(const Point &, double);
    friend Point &operator+=(Point &, const Point &);
    friend Point &operator-=(Point &, const Point &);
    friend Point &operator*=(Point &, double);
    friend Point &operator/=(Point &, double);
};
#endif // __point_h