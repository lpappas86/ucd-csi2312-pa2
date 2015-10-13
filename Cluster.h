#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>

namespace clustering {

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
		/***************        constructors            ********************/

		// defaults to size 0 and null points
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

		// findes and removes node pointed to by PointPtr
		// allows for C1.add(C2.remove(point))
		const PointPtr &remove(const PointPtr &);		

		// removes node at lastNode->next
		void removeAfter(LNodePtr lastNode);			

		//deletes all nodes of a cluster
		void clear();		



		/**********************     	Getters		*************************/

		//returns size
		int getSize() const { return size; };



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
		friend const Cluster operator+(const Cluster &, const Cluster &);		//Union of two clusters
		friend const Cluster operator-(const Cluster &, const Cluster &);
		friend bool operator==(const Cluster &, const Cluster &);
		friend Cluster &operator+=(Cluster &, const Cluster &);
		friend Cluster &operator-=(Cluster &, const Cluster &);

			/*******functions that use Point objects************/
		friend const Cluster operator+(const Cluster &, const Point &);			//adds a point object to cluster
		friend const Cluster operator-(const Cluster &, const Point &);			//removes all points with values equal to point parameter
		friend Cluster &operator+=(Cluster &, const Point &);
		friend Cluster &operator-=(Cluster &, const Point &);
	};	
}
#endif