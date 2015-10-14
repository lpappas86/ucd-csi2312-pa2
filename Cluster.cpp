#include "Cluster.h"

namespace clustering {

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
			
			else if (cPtr == cluster.points) {			//first run only
				points = node;
			}
			node->p = cPtr->p;						//copy point pointer
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
			else if (cPtr == cluster.points) {			//first run only
				points = node;
			}
			node->p = cPtr->p;						//copy point pointer
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
		
		if (find(p) != NULL) {											//make sure p is not already in cluster
			return;
		}
		size++;
		LNodePtr node = new LNode;										// Dynamically allocate new node
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
			if (ptr->next == NULL) {//if end of list
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
		LNodePtr lastNode = find(point);		//node before one to be deleted

		if (lastNode != NULL) { //if point was found
			size--;
			LNodePtr xNode = lastNode->next;		//node to be removed

			if (lastNode->next == points) {
				points = xNode->next;
				delete lastNode;					//delete node created by find
			}
			else if (xNode->next == NULL)
				lastNode->next = nullptr;
			else 
				lastNode->next = xNode->next;	//remove node from list
				
			PointPtr thePoint = xNode->p;
			delete xNode;
			return thePoint;	
		}
		else
			std::cout << "The point was not found in the cluster" << std::endl;
	}

	void Cluster::removeAfter(LNodePtr lastNode)
	{
		if (lastNode == NULL)
			return;
		size--;
		LNodePtr xNode = lastNode->next;				// node to be removed
		LNodePtr nextNode = lastNode->next->next;
		if (lastNode->next == points)
			points = nextNode;
		else
			lastNode->next = nextNode;
		delete xNode;
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

	void Cluster::setCentroid(const Point &point)
	{
		__centroid = point;
	}

	void Cluster::compCentroid()
	{
		LNodePtr node = points;
		Point accumulator(points->p->getDims());

		// average cluster points
		for (node; node != NULL; node = node->next) {
			accumulator += *node->p / size;
		}

	}

	const LNodePtr Cluster::find(PointPtr point) const
	{
		if (points == NULL)
			return NULL;
		LNodePtr node = points;
		if (node->p == point) {				// case: point is found in first node
			LNodePtr newNode = new LNode;	// create new node to point to it
			newNode->next = node;			
			return newNode;
		}

		while(true) {
			if (node->next == NULL)			// case: point not found
				return NULL;
			if (node->next->p == point)		// case: point found
				return node;
			node = node->next;
		}
	}

	const LNodePtr Cluster::find(Point point) const
	{
		if (points == NULL)
			return NULL;
		LNodePtr node = points;
		if (*node->p == point) {				// case: point is found in first node
			LNodePtr newNode = new LNode;	// create new node to point to it
			newNode->next = node;
			return newNode;
		}

		while (true) {
			if (node->next == NULL)			// case: point not found
				return NULL;
			if (*node->next->p == point)		// case: point found
				return node;
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

	std::istream & operator>>(std::istream &in, Cluster &cluster)
	{
		// get number of points coming in
		int numPoints = Cluster::numLines(in);
		PointPtr point = nullptr;			//points to a point
		std::string lineString;				// holds line from input file

		//convert to stringStream

		for (int i = 0; i < numPoints; i++) {
			getline(in, lineString);
			std::stringstream line(lineString);
			point = new Point(Point::getInFileDim(line));
			line >> *point;
			cluster.add(point);
			//ptrArray[i] = point; 
		}
		return in;
		

		//delete ptrArray;
		return in;
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
		Cluster cluster(LHS);
		LNodePtr leftNode = LHS.points;
	
		for (int i = 0; i < LHS.size; i++) {
			if(RHS.find(leftNode->p) != NULL)
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

	const Cluster operator+(const Cluster &cluster, const Point &point)
	{
		//dynamically allocate point object
		PointPtr p = new Point(point);
		
		Cluster c(cluster);
		c.add(p);
		return c;
	}

	const Cluster operator-(const Cluster &cluster, const Point &point)
	{
		Cluster newCluster(cluster);
		LNodePtr node = cluster.find(point);

		if (node == NULL)
			std::cout << "Can't Remove: The point was not found" << std::endl;

		while (node != NULL){
			node = newCluster.find(point);
			newCluster.removeAfter(node);		
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
