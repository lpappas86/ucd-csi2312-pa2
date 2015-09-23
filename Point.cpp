#include "Point.h"
#include <cmath>
#include <iostream>
#include <array>



// Constructors
Point::Point(int d) {
    dim = d;
    assert(dim > 0);
    data = new double[dim];
    for(int i; i < dim;i++)
        data[i] = 0;
}

Point::Point(int d, double pData[]) {
    dim = d;
    data = new double[dim];
    for(int i = 0;i < dim; i++)
        data[i] = pData[i];

}

//copy constructor
Point::Point(const Point &p) {
    dim = p.getDims();
    data = new double[dim];
    for(int j = 0; j < dim; j++)
        data[j] = p.data[j];
}

// Destructor
// delete dynamic array
Point::~Point() {
  delete [] data;
}

// Mutator methods
// Change the values of dimension index to val
void Point::setDim(int index, double val){
    assert(index >= 0 && index < dim);
    data[index] = val;
}
// Accessors
// Return the current values of private member variables
double Point::getData(int index) const {
    return data[index];
}


//computes the distance between this point and point p
double Point::distanceTo(Point& p) {
    assert(dim == p.dim);
    double sum = 0;
    for(int i = 0; i < dim; i++){
       sum += (data[i] - p.getData(i))*(data[i] - p.getData(i));
    }
    return sqrt(sum);
}


std::ostream &operator<<(std::ostream &ostream, const Point &point) {
    std::cout << "(" << point.data[0];
    for(int i = 1; i < point.dim; i++){
        std::cout << "," << point.data[i];
    }
    std::cout << ")" << std::endl;
}


Point &Point::operator=(const Point &p) {
    assert(this != &p);
    dim = p.getDims();
    delete [] data;
    data = new double[dim];
    for(int i=0;i<dim;i++)
        data[i] = p.data[i];
}

bool operator==(const Point &LHS, const Point &RHS) {
    if (LHS.getDims() != RHS.getDims())
        return false;
    for (int i = 0; i < RHS.getDims(); i++) {
        if (LHS.getData(i) != RHS.getData(i))
            return false;
    }

    return true;
}

bool operator!=(const Point &LHS, const Point &RHS) {
    if(LHS == RHS)
        return false;
    return true;
}

bool operator<(const Point &LHS, const Point &RHS) {
    assert(LHS.dim == RHS.dim);
    if(RHS == LHS)
        return false;
    for(int i = 0; i < LHS.getDims();i++){
        if  (LHS.getData(i) > RHS.getData(i))
            return false;
    }
    return true;
}

bool operator>(const Point &LHS, const Point &RHS) {
    assert(LHS.dim == RHS.dim);
    if(RHS == LHS)
        return false;
    for(int i = 0; i < LHS.getDims();i++){
        if  (LHS.getData(i) < RHS.getData(i))
            return false;
    }
    return true;
}

bool operator<=(const Point &LHS, const Point &RHS) {
    if(LHS > RHS)
        return false;
    return true;
}

bool operator>=(const Point &LHS, const Point &RHS) {
    if(LHS < RHS)
        return false;
    return true;
}

const Point operator+(const Point &LHS, const Point &RHS) {
    assert(LHS.getDims() == RHS.getDims());
    Point P(LHS.getDims());
    for(int i = 0; i < RHS.getDims();i++)
        P.data[i] = LHS.getData(i) + RHS.getData(i);
    return P;
}

const Point operator-(const Point &LHS, const Point &RHS) {
    assert(LHS.getDims() == RHS.getDims());
    Point P(LHS.getDims());
    for(int i = 0; i < RHS.getDims();i++)
        P.data[i] = LHS.getData(i) - RHS.getData(i);
    return P;
}

const Point operator*(const Point &point, double d) {
    Point p(point);
    for(int i = 0; i < p.dim;i++)
        p.data[i] = p.data[i] * d;
    return p;
}

const Point operator/(const Point &point, double d) {
    assert(d != 0);
    Point p(point);
    for(int i = 0; i < p.dim;i++)
        p.data[i] = p.data[i] / d;
    return p;
}


Point &operator+=(Point &LHS, const Point &RHS) {
    LHS = LHS + RHS;
    return LHS;
}

Point &operator-=(Point &LHS, const Point &RHS) {
    LHS = LHS - RHS;
    return LHS;
}

Point &operator*=(Point &LHS, double d) {
    LHS = LHS * d;
    return LHS;
}

Point &operator/=(Point &LHS, double d) {
    LHS = LHS / d;
    return LHS;
}