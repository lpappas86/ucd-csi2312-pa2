#include "Cluster.h"

namespace clustering {

	Cluster::Cluster(const Cluster &cluster)
	{
		
		if (cluster.points == NULL) {
			points = nullptr;
			return;
		}

		LNodePtr lastNode = nullptr;				//holds address of previous node
		for (LNodePtr ptr = cluster.points; ptr != NULL; ptr = ptr->next) {
			LNodePtr node = new LNode;
			if (points == NULL)				//covers case of empty cluster
				points = node;
			else
				lastNode->next = node;
			node->p = ptr->p;
			lastNode = node;
			if (ptr->next == NULL)
				node->next = nullptr;
			size++;
		}
	}
	// TODO Test ^^^^ with delete function

	Cluster & Cluster::operator=(const Cluster &cluster)
	{
		//case: cluster is empty
		if (cluster.points == NULL) {						
			points = nullptr;
			return *this;
		}

		LNodePtr lastNode = nullptr;				//holds address of previous node
		for (LNodePtr ptr = cluster.points; ptr != NULL; ptr = ptr->next) {
			LNodePtr node = new LNode;
			if (points == NULL)				//covers case of empty cluster
				points = node;
			else
				lastNode->next = node;
			node->p = ptr->p;
			lastNode = node;
			if (ptr->next == NULL)
				node->next = nullptr;
			size++;
		}
		return *this;
	}

	Cluster::~Cluster()
	{
		LNodePtr current = points;		//the current node to delete
		LNodePtr next = nullptr;		//the address of the next node

		//delete nodes
		for (int i = 0; i < size; i++) {
			next = current->next;
			delete current;
			current = next;
		}
	}

	

	void Cluster::add(const PointPtr &p)
	{
		size++;
		LNodePtr node = new LNode;
		LNodePtr ptr = points;
		node->p = p;

		//case: empty cluster
		if (points == NULL) {
			points = node;
			node->next = nullptr;
			return;
		}

		//case: new point is smallest point
		if (*node->p < *points->p) {
			node->next = points;
			points = node;
			return;
		}

		LNodePtr last = nullptr;

		//put in lexographic order
		while (*p > *ptr->p){
			last = ptr;
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
		bool found = false;							//flags when the point is found
		LNodePtr node = points;
		LNodePtr nextNode = points->next;
		LNodePtr lastNode = points;
		for (node; node != NULL; node = nextNode) {
			nextNode = node->next;
			if (node->p == point) {
				found = true;
				if (node == points)					//if point is in first node
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

	std::ostream & operator<<(std::ostream &output, const Cluster &cluster) {
		LNodePtr ptr = cluster.points;
		output << "Size: " << cluster.getSize() << std::endl;
		if (cluster.points == NULL)
			output << "The cluster is empty" << std::endl;
		else
			for (int i = 0; i < cluster.size; i++) {
				output << i+1 << ":\t" << *ptr->p;
				ptr = ptr->next;
			}
		return output;
	}

	const Cluster operator+(const Cluster &LHS, const Cluster &RHS)
	{
		Cluster cluster;						//cluster to be returned
		for (int i = 0; i < LHS.size; i++) {

		}
		return cluster;
	}

	const Cluster operator-(const Cluster &LHS, const Cluster &RHS)
	{
		bool shared;					//is true when the point is in both clusters
		Cluster cluster;
		LNodePtr leftNode = LHS.points;
		LNodePtr rightNode = RHS.points;
	
		for (int i = 0; i < LHS.size; i++) {
			shared = false;
			for (rightNode = RHS.points; rightNode != NULL; rightNode = rightNode->next) {
				if (leftNode->p == rightNode->p) {
					shared = true;
					break;
				}//end if
			}//end inner for
			if (!shared)
				cluster.add(leftNode->p);
			leftNode = leftNode->next;
		}//end outer for
		return cluster;
	}
	
}
