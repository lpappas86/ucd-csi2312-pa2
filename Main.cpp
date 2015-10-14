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

	/*cout << "Testing find(PointPtr)" << endl;
	cout << "C2" << endl << C2 << endl << endl;
	cout << "ptr1: " << *ptr1 << endl;
	cout << "C2.find(ptr1)->next-> p:" << endl << *C2.find(ptr1)->next->p << endl;
	
	cout << "ptr2: " << *ptr2 << endl;
	cout << "C2.find(ptr2)->next-> p:" << endl << *C2.find(ptr2)->next->p << endl;

	cout << "ptr3: " << *ptr3 << endl;
	cout << "C2.find(ptr3)->next-> p:" << endl << *C2.find(ptr3)->next->p << endl;
	

	cout << "ptr4: " << *ptr4 << endl;
	cout << "C2.find(ptr4)->next-> p:" << endl << *C2.find(ptr4)->next->p << endl;*/

	////find overloaod
	//cout << "Testing find(Point)" << endl;

	//cout << "C2" << endl << C2 << endl << endl;
	//cout << "p1: " << p1 << endl;
	//cout << "C2.find(p1)->next-> p:" << endl << *C2.find(p1)->next->p << endl;

	//cout << "p2: " << p2 << endl;
	//cout << "C2.find(p2)->next-> p:" << endl << *C2.find(p2)->next->p << endl;

	//cout << "p3: " << p3 << endl;
	//cout << "C2.find(p3)->next-> p:" << endl << *C2.find(p3)->next->p << endl;


	//cout << "p4: " << p4 << endl;
	//cout << "C2.find(p4)->next-> p:" << endl << *C2.find(p4)->next->p << endl;


	/*cout << "C" << endl << C << endl << endl;
	if (C2 == C)
		cout << endl << "T" << endl;
	else
		cout << endl << "F" << endl;*/

	/*Cluster C3(C2);
	C3.remove(ptr);
	C3.add(ptr);
	C2.remove(ptr2);
	C2.add(ptr2);
	cout << "C2" << endl << C2 << endl << endl;
	cout << "C" << endl << C << endl << endl;*/
	//cout << C2.getSize() << endl << C3.getSize();

	
	/*cout << endl << endl << "Testing Remove" << endl;
	cout << "C" << endl << C << endl << endl;

	cout << "remove ptr1" << endl;
	C.remove(ptr1);
	cout << "done" << endl;
	cout << "C" << endl << C << endl << endl;

	cout << "remove ptr2" << endl;
	C.remove(ptr2);
	cout << "done" << endl;
	cout << "C" << endl << C << endl << endl;

	cout << "remove ptr" << endl;
	C.remove(ptr);
	cout << "Done" << endl;
	cout << "C" << endl << C << endl << endl;

	cout << "remove ptr4" << endl;
	C.remove(ptr4);
	cout << "Done" << endl;
	cout << "C" << endl << C << endl << endl;*/



	////*****************Remove after
	//cout << endl << endl << "Testing removeAfter()" << endl;
	//cout << "C2" << endl << C2 << endl << endl;

	//cout << "C2.removeAfter(C2.find(ptr1))";
	//C2.removeAfter(C2.find(ptr1));
	//cout << "C2" << endl << C2 << endl << endl;

	//cout << "C2.removeAfter(C2.find(ptr4))";
	//C2.removeAfter(C2.find(ptr4));
	//cout << "C2" << endl << C2 << endl << endl;

	//cout << "C2.removeAfter(C2.find(ptr2))";
	//C2.removeAfter(C2.find(ptr2));
	//cout << "C2" << endl << C2 << endl << endl;

	//**********************************Operator-
	cout << endl << endl << "testing operator-";
	cout << "C2" << endl << C2 << endl << endl;

	/*C2.removeAfter(C2.find(p2));
	C2.removeAfter(C2.find(p2));
	C2.removeAfter(C2.find(p2));*/

	/*cout << "C2 - p2" << endl;
	C2 = C2 - p2;
	cout << "C2" << endl << C2 << endl << endl;
	C2 = C2 - p2;*/



	/*C3.remove(ptr3);
	C3.remove(ptr4);
*/

	/*cout << "C2" << endl << C2 << endl << endl;
	C3.add(ptr4);
	C3.add(ptr3);
	C3.add(ptr2);
	cout << "C3" << endl << C3 << endl << endl;
	cout << "C3 - p" << endl;
	C3 = C3 - p;
	cout << "C3" << endl << C3 << endl << endl;
	Point threeD(3);
	cout << C3 << endl;
	C3 += p;
	
	C3 += p2;
	cout << "C3" << endl << C3 << endl;

	cout << C3.find(ptr2) << endl;
	C3.removeAtIndex(5);
	cout << "C3" << endl << C3 << endl;*/


	/*C3 -= p;
	cout << C3 << endl;*/

	//cout << C3.find(ptr2) << endl;

	//C3.remove(ptr3);
	//cout << C3.find(ptr1) << endl;

	//cout << "C3" << endl << C3 << endl << endl;
	//C3 = C3;
	//cout << "C3" << endl << C3 << endl << endl;


	//**********************Point----> operator>>
	/*cout << "Testing point operator>>" << endl;
	point << */

	ifstream inFile;
	inFile.open("input.txt");
	
	if (inFile.is_open())
		cout << "bueno" << endl;
	else
		cout << "no bueno" << endl;
	
	//cout << "infile dimension: " << Point::getInFileDim(inFile) << endl;
	//PointPtr test = new Point(Point::getInFileDim(inFile));
	//inFile >> *test;
	//cout << "test size: " << test->getDims() << endl << *test;

	//cout << "infile dimension: " << Point::getInFileDim(inFile) << endl;


	//Point test2(Point::getInFileDim(inFile));
	//inFile >> test2;
	//cout << "test2 size: " << test2.getDims() << endl << test2;


	Cluster cluster;
	inFile >> cluster;
	cout << cluster;
	inFile.clear();
	cout << Cluster::numLines(inFile) << endl;

	cluster.setCentroid();
	cout << "Centroid = " << cluster.getCentroid() << endl;
	cout << "comp centroid" << endl;
	cluster.compCentroid();
	cout << "Centroid = " << cluster.getCentroid() << endl;

	
    return 0;
}
