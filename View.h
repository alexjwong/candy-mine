#ifndef VIEW_H
#define VIEW_H

#include <iostream>

#include "Game_Object.h"

const int view_maxsize = 20;

class View {
	public:
		View();

		void clear();
		void plot(Game_Object * ptr);
		void draw();

	private:
		int size;
		double scale;
		C_Point origin;
		char grid[view_maxsize][view_maxsize][2];

		bool get_subscripts(int &ix, int &iy, C_Point location);

};

#endif