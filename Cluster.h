#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>
#include<string>

namespace Clustering {
	
	typedef Point *PointPtr;
	typedef struct LNode *LNodePtr;

	struct LNode {
		LNode() : p(nullptr), next(nullptr) {};
		PointPtr p;
		LNodePtr next;
	};

	class Cluster {

	private:


		/*******************************************************************
		    *************       Member Variables      *******************
		*******************************************************************/
		
		int size;				// Number of points in cluster
		LNodePtr points;		// Pointer to first node of linked list
		unsigned dimensionality;	//dimension of points to go in cluster
			
		bool validity;			// Flags whether or not centroid is valid
		int __id;
		Point __centroid;

	public:

		/*******************************************************************
		   *********************    Move Class   ***********************
		*******************************************************************/

		class Move {
		private:
			Cluster *_from;
			Cluster *_to;
			PointPtr point;
		public:
			Move(const PointPtr &ptr, Cluster *from, Cluster *to) : _from(from), _to(to), point(ptr) {};
			void perform();
		};

		/*******************************************************************
		    *************         Constructor        *******************
		*******************************************************************/

		// defaults to size 0 and null points
		Cluster(unsigned);



		/*******************************************************************
		     *****************        Big 3        ********************
		*******************************************************************/

		//copy constructor
		Cluster(const Cluster &);

		//overload assignment operator
		Cluster &operator=(const Cluster &);

		//destructor
		~Cluster();



		/*******************************************************************
		    *****************        Mutators        *******************
		*******************************************************************/

		void add(const PointPtr &);

		// findes and removes node pointed to by PointPtr
		// allows for C1.add(C2.remove(point))
		const PointPtr &remove(const PointPtr &);		

		// removes node at lastNode->next
		void removeAfter(LNodePtr lastNode);			

		// deletes all nodes of a cluster
		void clear();	

		// initialize centroid with a copy of Point P
		void setCentroid(const Point &p) { __centroid = p; validity = true; }

		// compute centroid
		void computeCentroid();

		// validates/invalidates cluster
		void setValidity(bool v) { validity = v; }

		// generates ids for clusters
		static int idGenerator();

		




		/*******************************************************************
		    *****************        Getters       *********************
		*******************************************************************/

		// returns size
		int getSize() const { return size; };

		// retuns centroid
		Point getCentroid() const { return __centroid; }

		// returns the number of lines in an input file
		static int numLines(std::istream &in);

		// returns validity
		bool isCentroidValid() const { return validity; }

		// returns id
		int getId() const { return __id; }

		// Picks k points from a cluster to serve as initial centroids
		void pickPoints(int k,  PointPtr*);

		// sum of distance between every two points in the cluster
		double intraClusterDistance() const;

		// sum of distances between every pair of points between two clusters
		friend double interClusterDistance(const Cluster &, const Cluster &);

		// number of pairs in a cluster
		int getClusterEdges();

		// number of pairs between clusters
		friend double interClusterEdges(const Cluster &, const Cluster &);

		/*******************************************************************
			******************    Search functions    ******************
		 *******************************************************************/

		// Finds a pointPtr in a linked list
		// returns pointer to node before position where point is found
		// to access correct node use "find(pointPtr)->next"
		// returns NULL if point not found
		// Dynamically creates LNode if point is found in first node
		const LNodePtr find(const PointPtr) const;	

		// added to work with test suite
		// calls find function and returns a bool
		bool contains(const PointPtr &ptr) const;			

		// Finds the first instance of a point in a linked list
		//returns pointer to node before position where point is found
		//to access correct node use "find(point)->next"
		//returns NULL if point not found
		//Dynamically creates LNode if point is found in first node
		const LNodePtr find(Point) const;


		/*******************************************************************
		    *****************    Operator Overloads    ******************
		*******************************************************************/

		// in/out
		friend std::ostream &operator<<(std::ostream &, const Cluster &);
		friend std::istream &operator>>(std::istream &, Cluster &);	

		// Union of two clusters
		friend const Cluster operator+(const Cluster &, const Cluster &);	
		friend Cluster &operator+=(Cluster &, const Cluster &);

		// difference of two clusters
		friend const Cluster operator-(const Cluster &, const Cluster &);
		friend Cluster &operator-=(Cluster &, const Cluster &);

		// compare two clusters
		friend bool operator==(const Cluster &, const Cluster &);
		
		// get pointer to point at index
		PointPtr &operator[](int);				
		

			/*******functions that use Point objects************/

		//add a point object to cluster
		friend const Cluster operator+(const Cluster &, const Point &);
		friend const Cluster operator+(const Cluster &, const PointPtr);
		friend Cluster &operator+=(Cluster &, const Point &);

		//remove all points with values equal to point parameter
		friend const Cluster operator-(const Cluster &, const Point &);
		friend const Cluster operator-(const Cluster &, const PointPtr);
		friend Cluster &operator-=(Cluster &, const Point &);
	};	
}
#endif