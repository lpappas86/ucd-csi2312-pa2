#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>
#include<sstream>

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
		int size;
		LNodePtr points;

	public:
		/***************constructor with default values********************/
		Cluster() : size(0), points(nullptr) {};



		/*******************************************************************
		      ****************        Big 3        ********************
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
		const PointPtr &remove(const PointPtr &);		//allows for C1.add(C2.remove(point))

		void removeAfter(LNodePtr lastNode);				//removes node at given index. Indexes start as 1
		void clear();									//deletes all nodes of a cluster

		//getters
		int getSize() const { return size; };

		// returns the number of lines in an input file 
		static int numLines(std::istream &in);




		/*******************************************************************
			******************    Search functions    ******************
		 *******************************************************************/

		// Finds a pointPtr in a linked list
		// returns pointer to node before position where point is found
		// to access correct node use "find(pointPtr)->next"
		// returns NULL if point not found
		// Dynamically creates LNode if point is found in first node
		const LNodePtr find(PointPtr) const;	

		// Finds the first instance of a point in a linked list
		//returns pointer to node before position where point is found
		//to access correct node use "find(point)->next"
		//returns NULL if point not found
		//Dynamically creates LNode if point is found in first node
		const LNodePtr find(Point) const;


		/*******************************************************************
		    *****************    Operator Overloads    ******************
		*******************************************************************/

		friend std::ostream &operator<<(std::ostream &, const Cluster &);
		friend std::istream &operator>>(std::istream &, Cluster &);
		friend const Cluster operator+(const Cluster &, const Cluster &);		//Union of two clusters
		friend const Cluster operator-(const Cluster &, const Cluster &);
		friend bool operator==(const Cluster &, const Cluster &);
		friend Cluster &operator+=(Cluster &, const Cluster &);
		friend Cluster &operator-=(Cluster &, const Cluster &);

			/*******functions that use Point objects************/
		friend const Cluster operator+(const Cluster &, const Point &);			//adds a point object to cluster
		friend const Cluster operator+(const Cluster &, const PointPtr);			//adds a point object to cluster
		friend const Cluster operator-(const Cluster &, const Point &);			//removes all points with values equal to point parameter
		friend const Cluster operator-(const Cluster &, const PointPtr);			//removes all points with values equal to point parameter
		friend Cluster &operator+=(Cluster &, const Point &);
		friend Cluster &operator+=(Cluster &, const PointPtr);
		friend Cluster &operator-=(Cluster &, const Point &);
		friend Cluster &operator-=(Cluster &, const PointPtr);
	};	
}
#endif