#include "C_Point.h"
#include <math.h>

// Constructors
C_Point::C_Point(){
	x = 0;
	y = 0;
}

C_Point::C_Point(double inputx, double inputy){
	x = inputx;
	y = inputy;
}

// Returns the Cartesian distance between p1 and p2
double C_distance(C_Point p1, C_Point p2){
	// Use distance formula
	return sqrt( pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2) );
}

std::ostream &operator<<(std::ostream &output, const C_Point p){
	output << "(" << p.x << "," << p.y << ")";
	return output;
}

C_Point operator+(const C_Point& p1, const C_Vector& v1){
	return C_Point(p1.x+v1.x,p1.y+v1.y);
}

C_Point operator-(const C_Point& p1, const C_Point& p2){
	return C_Point(p1.x-p2.x,p1.y-p2.y);
}