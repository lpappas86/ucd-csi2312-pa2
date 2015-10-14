#include "Point.h"
//ASK: operator>> wtf?
namespace clustering {

	// Constructors


	Point::Point(int d) {
		dim = d;
		assert(dim > 0);
		values = new double[dim];
		for (int i = 0; i < dim; i++)
			values[i] = 0;
	}

	Point::Point(int d, double pvalues[]) {
		dim = d;
		values = new double[dim];
		for (int i = 0; i < dim; i++)
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

	void Point::setDim(int index, double val) {
		assert(index >= 0 && index < dim);
		values[index] = val;
	}

	double Point::getvalues(int index) const {
		return values[index];
	}


	double Point::distanceTo(Point& p) {
		assert(dim == p.dim);
		double sum = 0;
		for (int i = 0; i < dim; i++) {
			sum += (values[i] - p.getvalues(i))*(values[i] - p.getvalues(i));
		}
		return sqrt(sum);
	}

	// TODO: update this
	std::ostream &operator<<(std::ostream &output, const Point &point) {
		output << "(" << point.values[0];
		for (int i = 1; i < point.dim; i++) {
			output << "," << point.values[i];
		}
		output << ")" << std::endl;

		return output;
	}

	std::istream & operator>>(std::istream &in, Point &point)
	{
		
		//assert(Point::getInFileDim(in) == point.getDims());
		//std::string lineString;			// holds line from input file
		//getline(in, lineString);

		//convert to stringStream
		//std::stringstream line(lineString);		

		//put values in points
		std::string dString;
		int count = 0;
		while(in.good()){
			getline(in, dString, ',');
			point.setDim(count, std::stod(dString));
			count++;
		}
		
		return in;
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
		for (int i = 0; i < RHS.getDims(); i++) {
			if (LHS.getvalues(i) != RHS.getvalues(i))
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
		if (RHS == LHS)
			return false;
		for (int i = 0; i < LHS.getDims(); i++) {
			if (LHS.getvalues(i) > RHS.getvalues(i))
				return false;
		}
		return true;
	}

	bool operator>(const Point &LHS, const Point &RHS) {
		assert(LHS.dim == RHS.dim);
		if (RHS == LHS)
			return false;
		for (int i = 0; i < LHS.getDims(); i++) {
			if (LHS.getvalues(i) < RHS.getvalues(i))
				return false;
		}
		return true;
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
			P.values[i] = LHS.getvalues(i) + RHS.getvalues(i);
		return P;
	}

	const Point operator-(const Point &LHS, const Point &RHS) {
		assert(LHS.getDims() == RHS.getDims());
		Point P(LHS.getDims());
		for (int i = 0; i < RHS.getDims(); i++)
			P.values[i] = LHS.getvalues(i) - RHS.getvalues(i);
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