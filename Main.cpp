#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    double d[] = {2,3};
    double e[] = {2,3,4};
    Point p(2,d);
    Point p1(p);
    p1.setDim(1,4);
    Point p2(p);
    Point p3(p);
    p3.setDim(0,0);
    cout << p << p1 << p2 << p3;
    p1 /= 4;
    cout << p1;
    return 0;

}
