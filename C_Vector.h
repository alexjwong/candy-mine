#ifndef C_VECTOR_H
#define C_VECTOR_H

#include <iostream>

class C_Vector {

	friend std::ostream &operator <<(std::ostream &output, C_Vector &v);
	friend C_Vector operator*(const C_Vector& v, const double d);
	friend C_Vector operator/(const C_Vector& v, const double d);

	public:
		double x;		// X value of the point
		double y;		// Y value of the point

		// Constructors
		C_Vector();
		C_Vector(double inputx, double inputy);
};

#endif