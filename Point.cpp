#include "Point.h"


namespace Clustering {

	// Constructors


	Point::Point(unsigned d) {
		dim = d;
		assert(dim > 0);
		values = new double[dim];
		for (unsigned i = 0; i < dim; i++)
			values[i] = 0;
	}

	Point::Point(unsigned d, double pvalues[]) {
		dim = d;
		values = new double[dim];
		for (unsigned i = 0; i < dim; i++)
			values[i] = pvalues[i];

	}
	
	Point::Point(const Point &p) {
		dim = p.getDims();
		values = new double[dim];
		for (int j = 0; j < dim; j++)
			values[j] = p.values[j];
	}


	Point::~Point() {
		delete[] values;
	}

	void Point::setValue(int index, double val) {		
		index--;
		assert(index >= 0 && index < dim);
		values[index] = val;
	}

	double Point::getValue(int index) const {					
		index--;
		return values[index];
	}

	double Point::distanceTo(Point& p) {
		assert(dim == p.dim);
		double sum = 0;
		for (int i = 0; i < dim; i++) {
			sum += (values[i] - p.getValue(i + 1))*(values[i] - p.getValue(i + 1));
		}
		return sqrt(sum);
	}

	std::ostream &operator<<(std::ostream &output, const Point &point) {
		output << point.values[0];
		for (int i = 1; i < point.dim; i++) {
			output << "," << point.values[i];
		}
		output << " ";
		return output;
	}

	std::istream & operator>>(std::istream &in, Point &point)
	{
	

		//put values in points
		std::string dString;
		int count = 1;
		while(in.good()){
			getline(in, dString, ',');
			char* cstr = new char [dString.length()+1];
			std::strcpy (cstr, dString.c_str());
			point.setValue(count, atof(cstr) );
			count++;
		}

		return in;
	}

	double &Point::operator[](int dimension) {
		dimension--;
		assert(dimension >= 0 && dimension < dim);
		return values[dimension];
	}



	Point &Point::operator=(const Point &p) {
		assert(this != &p);
		dim = p.getDims();
		delete[] values;
		values = new double[dim];
		for (int i = 0; i < dim; i++)
			values[i] = p.values[i];
		return *this;
	}

	bool operator==(const Point &LHS, const Point &RHS) {
		if (LHS.getDims() != RHS.getDims())
			return false;
		for (int i = 1; i < RHS.getDims() + 1; i++) {
			if (LHS.getValue(i) != RHS.getValue(i))
				return false;
		}

		return true;
	}

	bool operator!=(const Point &LHS, const Point &RHS) {
		if (LHS == RHS)
			return false;
		return true;
	}


	bool operator<(const Point &LHS, const Point &RHS) {
		assert(LHS.dim == RHS.dim);
		for (int i = 1; i < LHS.getDims() + 1; i++) {
			if (LHS.getValue(i) < RHS.getValue(i))
				return true;
		}
		return false;
	}

	bool operator>(const Point &LHS, const Point &RHS) {
		assert(LHS.dim == RHS.dim);
		for (int i = 1; i < LHS.getDims() + 1; i++) {
			if (LHS.getValue(i) > RHS.getValue(i))
				return true;
		}
		return false;
	}

	bool operator<=(const Point &LHS, const Point &RHS) {
		if (LHS > RHS)
			return false;
		return true;
	}

	bool operator>=(const Point &LHS, const Point &RHS) {
		if (LHS < RHS)
			return false;
		return true;
	}

	const Point operator+(const Point &LHS, const Point &RHS) {
		assert(LHS.getDims() == RHS.getDims());
		Point P(LHS.getDims());
		for (int i = 0; i < RHS.getDims(); i++)
			P.values[i] = LHS.getValue(i + 1) + RHS.getValue(i + 1);
		return P;
	}

	const Point operator-(const Point &LHS, const Point &RHS) {
		assert(LHS.getDims() == RHS.getDims());
		Point P(LHS.getDims());
		for (int i = 0; i < RHS.getDims(); i++)
			P.values[i] = LHS.getValue(i + 1) - RHS.getValue(i + 1);
		return P;
	}

	const Point operator*(const Point &point, double d) {
		Point p(point);
		for (int i = 0; i < p.dim; i++)
			p.values[i] = p.values[i] * d;
		return p;
	}

	const Point operator/(const Point &point, double d) {
		assert(d != 0);
		Point p(point);
		for (int i = 0; i < p.dim; i++)
			p.values[i] = p.values[i] / d;
		return p;
	}


	Point &operator+=(Point &LHS, const Point &RHS) {
		LHS = LHS + RHS;
		return LHS;
	}

	Point &operator-=(Point &LHS, const Point &RHS) {
		LHS = LHS - RHS;
		return LHS;
	}

	Point &operator*=(Point &LHS, double d) {
		LHS = LHS * d;
		return LHS;
	}

	Point &operator/=(Point &LHS, double d) {
		LHS = LHS / d;
		return LHS;
	}
}