#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H
#include <iostream>
#include <cassert>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

namespace clustering {



	class Point {

	private:
		int dim;
		double *values;

	public:
		// Constructors
		Point(int dim);                   //initializes point with dimension dim and all values = 0
		Point(int d, double[]);             //initialiuzes point with dim d and values array
		Point(const Point &);                    //copy constructor
		// Destructor
		~Point();

		// Mutator methods
		void setDim(int index, double val);  //sets point value at dimension of index to val


		// Accessor methods
		int getDims() const { return dim; };       //returns dimension
		double getvalues(int index) const;                  //returns value at dimenstion of index

		//other methods
		double distanceTo(Point &p);

		//overloaded operators
		Point &operator=(const Point &);

		//friends
		friend std::ostream &operator<<(std::ostream &, const Point &);
		friend std::istream &operator>>(std::istream &, Point &);
		friend bool operator==(const Point &, const Point &);
		friend bool operator!=(const Point &, const Point &);
		friend bool operator<(const Point &, const Point &);
		friend bool operator>(const Point &, const Point &);
		friend bool operator<=(const Point &, const Point &);
		friend bool operator>=(const Point &, const Point &);
		friend const Point operator+(const Point &, const Point &);			
		friend const Point operator-(const Point &, const Point &);			
		friend const Point operator*(const Point &, double);
		friend const Point operator/(const Point &, double);
		friend Point &operator+=(Point &, const Point &);
		friend Point &operator-=(Point &, const Point &);
		friend Point &operator*=(Point &, double);
		friend Point &operator/=(Point &, double);
	};

}
#endif // __point_h