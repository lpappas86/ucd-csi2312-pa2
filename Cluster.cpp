#include "Cluster.h"

namespace clustering {

	//TODO: remove dynamic allocation where possible

	Cluster::Cluster(const Cluster &cluster)
	{
		size = cluster.size;
				
		//case cluster is empty
		if (cluster.points == NULL) {
			points = NULL;
			return;
		}
		
		LNodePtr node;
		LNodePtr cPtr = cluster.points;
		LNodePtr lastPtr = nullptr;

		for (cPtr; cPtr != NULL; cPtr = cPtr->next) {
			node = new LNode;
			if (lastPtr != NULL)
				lastPtr->next = node;
			if (cPtr == cluster.points) {			//first run only
				points = node;
			}
			node->p = cPtr->p;				//copy point pointer
			lastPtr = node;
		}

	}
	
	Cluster & Cluster::operator=(const Cluster &cluster)
	{
		if (cluster == *this)
			return *this;

		clear();		//free up memory
		
		size = cluster.size;

		//case: cluster is empty
		if (cluster.points == NULL) {
			points = NULL;
			return *this;
		}

		LNodePtr node;
		LNodePtr cPtr = cluster.points;
		LNodePtr lastPtr = nullptr;

		for (int i = 0; i < cluster.size; i++) {
			node = new LNode;
			if (lastPtr != NULL)
				lastPtr->next = node;
			if (cPtr == cluster.points) {			//first run only
				points = node;
			}
			node->p = cPtr->p;				//copy point pointer
			cPtr = cPtr->next;
			lastPtr = node;
		}
		return *this;
	}

	Cluster::~Cluster()
	{
		if (points == NULL) return;		//empty cluster = nothing to delete

		LNodePtr current = points;		//the current node to delete
		LNodePtr next = nullptr;		//the address of the next node

		//delete nodes
		for (current; current != NULL; current = next) {
			next = current->next;
			delete current;
		}
	}

	
	void Cluster::add(const PointPtr &p)
	{
		if (points != NULL)
			assert(p->getDims() == points->p->getDims());				//make sure dimensions match
		
		if (find(p) != -1) {											//make sure p is not already in cluster
			return;
		}
		size++;
		LNodePtr node = new LNode;
		LNodePtr ptr = points;
		node->p = p;

		if (points == NULL) {											//case: empty cluster
			points = node;
			node->next = nullptr;
			return;
		}

		if (*node->p < *points->p) {									//case: new point is smallest point
			node->next = points;
			points = node;
			return;
		}

		LNodePtr last = nullptr;

		while ( *p > *ptr->p) {											//put in lexographic order
			last = ptr;
			if (ptr->next == NULL) {
				node->next = nullptr;
				last->next = node;
				return;
			}
			ptr = ptr->next;		
		}

		while (*p == *ptr->p && p > ptr->p) {							//if points are equal sort by memory address 
			last = ptr;													//for reasons of comparison
			if (ptr->next == NULL) {
				node->next = nullptr;
				last->next = node;
				return;
			}
				ptr = ptr->next;				
		}

		node->next = ptr;
		last->next = node;
	}

	const PointPtr & Cluster::remove(const PointPtr &point)
	{
		bool found = false;												//flags when the point is found
		LNodePtr node = points;
		LNodePtr nextNode = points->next;
		LNodePtr lastNode = points;
		for (node; node != NULL; node = nextNode) {
			nextNode = node->next;
			if (node->p == point) {
				found = true;
				if (node == points)										//if point is in first node
					points = nextNode;
				else
					lastNode->next = nextNode;
				
				delete node;
				break;
			}
			lastNode = node;
		}
		if (found)
			size--;
		else
			std::cout << "The cluster does not contain this point" << std::endl;
		return point;
	}

	const void Cluster::removeAtIndex(int index)
	{
		assert(index <= size && index >= 0); 
		LNodePtr node = points;
		LNodePtr nextNode = points->next;
		LNodePtr lastNode = points;
		if (index == 1)
			points = node->next;
		else {
			for (int i = 0; i < index - 1; i++) {
				lastNode = node;
				node = nextNode;
				nextNode = node->next;
			}
			lastNode->next = nextNode;
			size--;
		}
		delete node;
	}

	void Cluster::clear()
	{
		LNodePtr node = points;
		LNodePtr nextNode = nullptr;
		for (node; node != NULL; node = nextNode) {
			nextNode = node->next;
			delete node;
		}
		size = 0;
		points = nullptr;
	}

	//TODO: overload this
	const int Cluster::find(PointPtr point) const
	{
		if (points == NULL)
			return -1;
		LNodePtr node = points;
		int count = 0;
		while(true) {
			if (node->p == point)
				return count+1;
			if (node->next == NULL)
				return -1;
			count++;
			node = node->next;
		}
	}

	std::ostream & operator<<(std::ostream &output, const Cluster &cluster) {
		LNodePtr ptr = cluster.points;
		output << "Size: " << cluster.getSize() << std::endl;
		if (cluster.points == NULL)
			output << "The cluster is empty" << std::endl;
		else {
			int count = 1;
			for (ptr; ptr != NULL; ptr = ptr->next) {
				output << count << ":\t" << *ptr->p;
				count++;
			}
		}
		return output;
	}

	const Cluster operator+(const Cluster &LHS, const Cluster &RHS)
	{
		Cluster cluster;						//cluster to be returned
		Cluster difference1 = LHS - RHS;		//LHS unshared points
		Cluster difference2 = RHS - LHS;		//RHS unshared Points
		Cluster shared = LHS - difference1;		//points shared by LHS and RHS

		// add LHS unshared points
		LNodePtr node = difference1.points;
		for (node; node != NULL; node = node->next)		
			cluster.add(node->p);

		//add RHS unshared points
		node = difference2.points;
		for (node; node != NULL; node = node->next)		
			cluster.add(node->p);

		//add shared points
		node = shared.points;
		for (node; node != NULL; node = node->next)		
			cluster.add(node->p);
		return cluster;
	}

	const Cluster operator-(const Cluster &LHS, const Cluster &RHS)
	{
		bool shared;													//is true when the point is in both clusters
		Cluster cluster(LHS);
		LNodePtr leftNode = LHS.points;
	
		for (int i = 0; i < LHS.size; i++) {
			shared = false;
			if(RHS.find(leftNode->p) != -1)
				shared = true;
			if (shared)
				cluster.remove(leftNode->p);
			leftNode = leftNode->next;
		}
		return cluster;
	}

	bool operator==(const Cluster &LHS, const Cluster &RHS)
	{
		if (LHS.getSize() != RHS.getSize())
			return false;
		LNodePtr lNode = LHS.points;
		LNodePtr rNode = RHS.points;
		
		for (lNode; lNode != NULL; lNode = lNode->next) {
			if (lNode->p != rNode->p)
				return false;
			rNode = rNode->next;
		}
		return true;
	}

	Cluster & operator+=(Cluster &LHS, const Cluster &RHS)
	{
		LHS = LHS + RHS;
		return LHS;
	}

	Cluster & operator-=(Cluster &LHS, const Cluster &RHS)
	{
		LHS = LHS - RHS;
		return LHS;
	}

	//use pointers?????
	const Cluster operator+(const Cluster &cluster, const Point &point)
	{
		//dynamically allocate point object
		PointPtr p = new Point(point);
		
		Cluster c(cluster);
		c.add(p);
		return c;
	}

	//TODO: upgrade
	const Cluster operator-(const Cluster &cluster, const Point &point)
	{
		Cluster newCluster(cluster);
		PointPtr p = new Point(point);
		LNodePtr node = new LNode;
		node = newCluster.points;
		int count = 0;
		for (node; node != NULL; node = node->next) {
			if (*node->p == *p) {
				newCluster.remove(node->p);
				node = newCluster.points;
		
				for (int i = 0; i < count-1; count++)
					node = node->next;
				continue;
			}
			count++;
		}
		
		return newCluster;
	}

	Cluster & operator+=(Cluster &cluster, const Point &point)
	{
		cluster = cluster + point;
		return cluster;
	}

	Cluster & operator-=(Cluster &cluster, const Point &point)
	{
		cluster = cluster - point;
		return cluster;
	}


	
}
