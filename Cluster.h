#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>

namespace clustering {

	typedef Point *PointPtr;
	typedef struct LNode *LNodePtr;

	struct LNode {
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

		//getters
		int getSize() const { return size; };



		//friends and overloaded operators
		friend std::ostream &operator<<(std::ostream &, const Cluster &);
		friend const Cluster operator+(const Cluster &, const Cluster &);		//Union of two clusters
		friend const Cluster operator-(const Cluster &, const Cluster &);



	};	
}
#endif