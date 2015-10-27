#include <iostream>
#include "Point.h"
#include "Cluster.h"
#include"KMeans.h"


using namespace std;
using namespace clustering;

int main() {
 //   double d[] = {2,3};
 //   double e[] = {2,3,4};
 //   Point p(2,d);
	//Point p1(p);
	//Point p2(p);
	//p1.setDim(0,1);
	//Point p3(p);
	//p3.setDim(0,3);
	//Point p4(p);
	//p4.setDim(0, 4);
	//Point p5(2);
	//p5.setDim(0, 0);
	//p5.setDim(1, 0);
	//if (p2 < p4)
	//	cout << "p2 < p4" << endl;
	//
	//
	//cout << "points" << endl << "p1" << p1 << "p2" << p2 << "p3" << p3 << "p4" <<  p4 << "p5" << p5 << endl;

	//cout << "Testing cluster" << endl;
	//Cluster C;
	//Point *ptr = &p;
	//Point *ptr1 = &p1;
	//Point *ptr2 = &p2;
	//Point *ptr3 = &p3;
	//Point *ptr4 = &p4;
	//Point *ptr5 = &p5;
	//cout << C << endl << endl;
	//
	//C.add(ptr1);
	//cout << C << endl << endl;
	//C.add(ptr2);
	//cout << C << endl << endl;
	//C.add(ptr4);
	//cout << C << endl << endl;
	//C.add(ptr3);
	//C.add(ptr);
	//cout << "C" << endl << C << endl << endl;
	//
	//Cluster C1(C);
	//cout << "C1" << endl << C1 << endl << endl;

	//Cluster C2;
	//C2.add(ptr1);
	////cout << C2 << endl << endl;
	//C2.add(ptr2);
	////cout << C2 << endl << endl;
	//C2.add(ptr4);
	////cout << C2 << endl << endl;
	//C2.add(ptr3);
	//C2.add(ptr);

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
	/*cout << endl << endl << "testing operator-";
	cout << "C2" << endl << C2 << endl << endl;*/

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

	//ifstream inFile;
	//inFile.open("input.txt");
	
	//if (inFile.is_open())
	//	cout << "bueno" << endl;
	//else
	//	cout << "no bueno" << endl;
	
	//cout << "infile dimension: " << Point::getInFileDim(inFile) << endl;
	//PointPtr test = new Point(Point::getInFileDim(inFile));
	//inFile >> *test;
	//cout << "test size: " << test->getDims() << endl << *test;

	//cout << "infile dimension: " << Point::getInFileDim(inFile) << endl;


	//Point test2(Point::getInFileDim(inFile));
	//inFile >> test2;
	//cout << "test2 size: " << test2.getDims() << endl << test2;


	//Cluster cluster;
	//cout << "Cluster" << endl << cluster;

	//inFile >> cluster;
	//cout << "Cluster" << endl << cluster;
	//inFile.clear();
	//cout << Cluster::numLines(inFile) << endl;
	//cluster.setCentroid(ptr);
	//cout << cluster.getCentroid() << endl;
	//cluster.compCentroid();
	//cout << cluster.getCentroid() << endl;

	//Cluster::Centroid.setCentroid;
	//cout << endl << endl;
	//cout << cluster[0] << endl;
	//cout << cluster[1] << endl;
	//cout << cluster[2] << endl;
	//cout << *cluster[3];


	//cout << "Testing Move" << endl;
	//Cluster cluster1;
	//cout << "Cluster1 new" << endl << cluster1 << endl;
	///*PointPtr movedP = cluster.remove(cluster[0]);
	//cluster1.add(movedP);*/
	////cluster1.add(cluster.remove(cluster[1]));
	//Cluster::Move(cluster[2], &cluster, &cluster1).perform();
	//Cluster::Move(cluster[1], &cluster, &cluster1).perform();
	//Cluster::Move(cluster[0], &cluster, &cluster1).perform();

	//cout << "Cluster" << endl << cluster;
	//cout << "Cluster1" << endl << cluster1;
	//cout << endl << "end move test" << endl;

	//cout << "Testing PickPoints" << endl << endl;
	//	int k = 6;
	//	PointPtr *pArray = new PointPtr[k];
	//	cout << "Cluster" << endl << cluster;
	//	cout << endl << endl;
	//	cluster.pickPoints(k, pArray);
	//	for (int i = 0; i < k; i++) {
	//		cout << *pArray[i] << endl;
	//	}
	//cout << "end PickPoints test" << endl << endl;

	//// INTRTACLUSTERDISTANCE TEST
	//cout << "Testing intraClusterDistance" << endl << endl;
	//cout << "Cluster" << endl << cluster;
	//cout << cluster.intraClusterDistance() << endl;
	//cout << cluster[0].distanceTo(cluster[1]) << endl;
	//cout << cluster[0].distanceTo(cluster[2]) << endl;
	//cout << cluster[1].distanceTo(cluster[2]) << endl;
	////cout << cluster[1].distanceTo(cluster[2]) << endl;
	//cout << "end intraclusterdistance test" << endl << endl;


	//// INTERCLUSTERDISTANCE TEST
	//cout << "testing interclusterDistance" << endl << endl;
	//cout << "Cluster" << endl << cluster;
	//Cluster cluster1;
	//cout << cluster.getSize();
	//cout << endl << "Cluster1 new" << endl << cluster1 << endl;
	//Cluster::Move(&cluster[9], &cluster, &cluster1).perform();
	//Cluster::Move(&cluster[8], &cluster, &cluster1).perform();
	//Cluster::Move(&cluster[7], &cluster, &cluster1).perform();
	//Cluster::Move(&cluster[6], &cluster, &cluster1).perform();
	//Cluster::Move(&cluster[5], &cluster, &cluster1).perform();
	//cout << "Cluster1" << endl << cluster1;
	//cout << endl;
	//cout << "Cluster" << endl << cluster;
	//cout << interClusterDistance(cluster, cluster1) << endl;
	//cout << "end interclusterdistance test" << endl;

	//// GET CLUSTER EDGES
	//cout << "cluster edges: " << endl << cluster.getClusterEdges() << endl;

	//// INTERCLUSTER EDGES
	//cout << "InterCLuster edges" << endl << interClusterEdges(cluster, cluster1) << endl;
	//


	/////////////////////////////////////////////////////////////////////
////	Testing KMeans
	/////////////////////////////////////////////////////////////////////

	ifstream inFile;
	inFile.open("input.txt");

	//Cluster cluster(2);
	//inFile >> cluster;
	//cout << cluster << endl;

	if (!inFile) cout << "WTF" << endl;
	else cout << "sweet" << endl;

	ofstream outFile;
	outFile.open("OutPut.txt");

	int K = 4;
	KMeans k(K, inFile, outFile);

	// algorithm//////////////////////////////////////
	
	// set up and initialization
	k.createClusters();
	k.readPoints();			//cout << "Initial Cluster: " << *k.getClusters(0) << endl;
	k.setCentroids();		//cout << "Centroids: " << k.getClusters(0)->getCentroid() << k.getClusters(1)->getCentroid() << k.getClusters(2)->getCentroid() << k.getClusters(3)->getCentroid();
	/*for (int i = 0; i < K; i++)
		cout << *k.getClusters(i);*/

	// recoompute clusters
	//cout << endl << k.computeClusteringScore() << endl;
	k.recomputeClusters();
	k.printResults();



	/*for (int i = 0; i < K; i++)
		cout << endl << "Cluster " << i << ": " <<  *k.getClusters(i) << endl;*/

	cout << "Centroids: " << k.getClusters(0)->getCentroid() << k.getClusters(1)->getCentroid() << k.getClusters(2)->getCentroid() << k.getClusters(3)->getCentroid();

    return 0;
}

