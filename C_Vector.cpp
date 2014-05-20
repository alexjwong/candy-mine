#include "C_Vector.h"

// Constructors
C_Vector::C_Vector(){
	x = 0;
	y = 0;
}

C_Vector::C_Vector(double inputx, double inputy){
	x = inputx;
	y = inputy;
}

std::ostream &operator <<(std::ostream &output, C_Vector &v){
	output << "<" << v.x << "," << v.y << ">";
	return output;
}

C_Vector operator*(const C_Vector& v, const double d){
	return C_Vector(v.x*d,v.y*d);
}

C_Vector operator/(const C_Vector& v, const double d){
	return C_Vector(v.x/d,v.y/d);
}