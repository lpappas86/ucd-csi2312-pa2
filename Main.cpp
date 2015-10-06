#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace clustering;

int main() {
    double d[] = {2,3};
    double e[] = {2,3,4};
    Point p(2,d);
	Point p1(p);
	Point p2(p);
	p1.setDim(0,1);
	Point p3(p);
	p3.setDim(0,3);
	Point p4(p);
	p4.setDim(0, 4);
	Point p5(2);
	p5.setDim(0, 0);
	p5.setDim(1, 0);
	if (p2 < p4)
		cout << "p2 < p4" << endl;
	
	
	cout << "points" << endl << "p1" << p1 << "p2" << p2 << "p3" << p3 << "p4" <<  p4 << "p5" << p5 << endl;

	cout << "Testing cluster" << endl;
	Cluster C;
	Point *ptr = &p;
	Point *ptr1 = &p1;
	Point *ptr2 = &p2;
	Point *ptr3 = &p3;
	Point *ptr4 = &p4;
	Point *ptr5 = &p5;
	cout << C << endl << endl;
	
	C.add(ptr1);
	cout << C << endl << endl;
	C.add(ptr2);
	cout << C << endl << endl;
	C.add(ptr4);
	cout << C << endl << endl;
	C.add(ptr3);
	C.add(ptr);
	cout << "C" << endl << C << endl << endl;
	
	Cluster C1(C);
	cout << "C1" << endl << C1 << endl << endl;

	Cluster C2;
	C2.add(ptr1);
	//cout << C2 << endl << endl;
	C2.add(ptr2);
	//cout << C2 << endl << endl;
	C2.add(ptr4);
	//cout << C2 << endl << endl;
	C2.add(ptr3);
	C2.add(ptr);
	cout << "C2" << endl << C2 << endl << endl;
	cout << "C" << endl << C << endl << endl;
	if (C2 == C)
		cout << endl << "T" << endl;
	else
		cout << endl << "F" << endl;
	Cluster C3(C2);
	C3.remove(ptr);
	C3.add(ptr);
	C2.remove(ptr2);
	C2.add(ptr2);
	cout << "C2" << endl << C2 << endl << endl;
	cout << "C" << endl << C << endl << endl;
	//cout << C2.getSize() << endl << C3.getSize();
	C2.remove(ptr1);
	C2.remove(ptr2);
	C2.remove(ptr);

	C3.remove(ptr3);
	C3.remove(ptr4);
	cout << "C2" << endl << C2 << endl << endl;
	C3.add(ptr4);
	C3.add(ptr3);
	C3.add(ptr2);
	cout << "C3" << endl << C3 << endl << endl;
	C3 = C3 - p;
	cout << "C3" << endl << C3 << endl << endl;
	Point threeD(3);
	cout << C3 << endl;
	C3 += p;
	
	C3 += p2;
	cout << C3 << endl;

	C3 -= p;
	cout << C3 << endl;
    return 0;
}
