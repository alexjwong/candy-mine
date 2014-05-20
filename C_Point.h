#ifndef C_POINT_H
#define C_POINT_H

#include <iostream>

#include "C_Vector.h"

class C_Point {

	friend std::ostream &operator<<(std::ostream &output, const C_Point p);
	friend C_Point operator+(const C_Point& p1, const C_Vector& v1);
	friend C_Point operator-(const C_Point& p1, const C_Point& p2);

	public:
		double x;		// X value of the point
		double y;		// Y value of the point

		// Constructors
		C_Point();
		C_Point(double inputx, double inputy);
};

// Returns the Cartesian distance between p1 and p2
double C_distance(C_Point p1, C_Point p2);

#endif