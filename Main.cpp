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
	
	{
		Cluster C2;
		C2 = C1;
		cout << "C2" << endl << C2 << endl << endl;
	}
		
	Cluster C3;
	cout << "C3" << endl << C3 << endl << endl;

	Cluster C4;
	C4 = C3;
	cout << "C4" << endl << C4 << endl << endl;


	cout << endl << endl << endl << "Testing remove function: " << endl << endl;
	cout << "C1" << endl << C1 << endl << endl;
	C1.remove(ptr2);
	C1.remove(ptr1);
	C1.remove(ptr);
	cout << "C1" << endl << C1 << endl << endl;

	C3.add(ptr2);
	C3.add(ptr1);
	C3.add(ptr3);
	cout << "C3" << endl << C3 << endl << endl;

	cout << "C4 = C3 - C1" << endl << endl;
	C4 = C3 - C1;
	cout << "C4" << endl << C4 << endl << endl;
    return 0;
}
