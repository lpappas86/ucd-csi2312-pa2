#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>

namespace clustering {

	//TODO: add lots of consts

	typedef Point *PointPtr;
	typedef struct LNode *LNodePtr;

	//Make private??????
	struct LNode {

		//TODO: more constructors

		LNode() : p(nullptr), next(nullptr) {};
		PointPtr p;
		LNodePtr next;
	};

	class Cluster {

	private:
		int size;
		LNodePtr points;

	public:
		//constructor with default values
		Cluster() : size(0), points(nullptr) {};

		//copy constructor
		Cluster(const Cluster &);

		//overload assignment operator
		Cluster &operator=(const Cluster &);

		//destructor
		~Cluster();

		//mutators
		void add(const PointPtr &);
		const PointPtr &remove(const PointPtr &);		//allows for C1.add(C2.remove(point))
		const void removeAtIndex(int);					//removes node at given index. Indexes start as 1
		void clear();		//deletes all nodes of a cluster

		//getters
		int getSize() const { return size; };

		//other member functions
		const int find(PointPtr) const;											//returns index of position if found, -1 otherwise. 
																				//index starts at 1

		friend std::ostream &operator<<(std::ostream &, const Cluster &);
		friend const Cluster operator+(const Cluster &, const Cluster &);		//Union of two clusters
		friend const Cluster operator-(const Cluster &, const Cluster &);
		friend bool operator==(const Cluster &, const Cluster &);
		friend Cluster &operator+=(Cluster &, const Cluster &);
		friend Cluster &operator-=(Cluster &, const Cluster &);

		//functions that use Point objects
		friend const Cluster operator+(const Cluster &, const Point &);			//adds a point object to cluster
		friend const Cluster operator-(const Cluster &, const Point &);			//removes all points with values equal to point parameter
		friend Cluster &operator+=(Cluster &, const Point &);
		friend Cluster &operator-=(Cluster &, const Point &);
	};	
}
#endif