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
		unsigned dim;
		double *values;

	public:
		
		/*******************************************************************
		     ****************     Constructors      *********************
		*******************************************************************/
		
		// Creates a 0 dimensional point to be initialized later
		Point() : dim(0) {};

		//initializes point with dimension dim and all values = 0
		Point(unsigned dim);			

		//initialiuzes point with dim d and values array
		Point(unsigned d, double[]);      

		//copy constructor
		Point(const Point &);               
		
		// Destructor
		~Point();



		/*******************************************************************
		    ****************        Mutators       ********************
		*******************************************************************/

		//sets point value at dimension of index to val
		void setDim(int index, double val);  



		/*******************************************************************
		      ****************      Accessors      ********************
		*******************************************************************/

		//returns dimension
		int getDims() const { return dim; };				
		
		//returns value at dimenstion of index
		double getvalues(int index) const;                  
		
																	

		/*******************************************************************
		      ****************     Other Methods     *****************
		*******************************************************************/

		// returns the distance from one point to another
		double distanceTo(Point &p);

		// returns dimension of next line in ifstream object
		static int getInFileDim(std::istream &in) {
			std::string lineString;			// holds line from input file

											// get position in file to restore after count is taken
			int pos = in.tellg();

			// save line to string
			getline(in, lineString);

			//convert to stringStream
			std::stringstream line(lineString);

			//count dimensions
			int count = 0;			//holds dimensions
			while (line.good()) {
				getline(line, lineString, ',');
				count++;
			}
			in.seekg(pos);

			return count;
		}


		/*******************************************************************
		     ****************  Overloaded operators   ****************
		*******************************************************************/

		Point &operator=(const Point &);
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