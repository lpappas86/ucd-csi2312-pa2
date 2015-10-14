#ifndef CLUSTERING_CLUSTER_H
#define CLUSTERING_CLUSTER_H

#include"Point.h"
#include<iostream>
#include<cassert>

// CLASS: use shared pointers
// TODO: everywhere a PointPtr is an argument it should be const
// TODO: inner move class that forces you to never do an add without a remove
// TODO: inner centroid class??
// TODO: destructer deletes points?
// TODO: make inner class friend of outer to access private members
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
		Point __centroid;

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

		//initialize centroid
		void setCentroid(const Point&);

		// compute centroid
		void compCentroid();


		/*******************************************************************
		    *****************        Getters       *********************
		*******************************************************************/
		// returns size
		int getSize() const { return size; };

		// retuns centroid
		const Point getCentroid() { return __centroid; }

		// returns the number of lines in an input file
		static int numLines(std::istream &in) {
			
			//save position of file pointer 
			int pos = in.tellg();
			
			// account for possible eof bit
			in.clear();			

			// move file pointer to beginning of file
			in.seekg(0);				

			std::string aString;			//holds unused information
			int lines = 0;					//counts lines

			//count
			while (getline(in, aString))
				lines++;

			// clear eof bit
			in.clear();		

			// recover previous position in file
			in.seekg(pos);

			return lines;
		}



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
		
		

			/*******functions that use Point objects************/

		//add a point object to cluster
		friend const Cluster operator+(const Cluster &, const Point &);		
		friend Cluster &operator+=(Cluster &, const Point &);

		//remove all points with values equal to point parameter
		friend const Cluster operator-(const Cluster &, const Point &);			
		friend Cluster &operator-=(Cluster &, const Point &);
	};	
}
#endif