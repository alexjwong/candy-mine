#include "View.h"
#include "math.h"

// Public member functions
View::View(){
	size = 11;
	scale = 2;
	origin = C_Point();
}

void View::clear(){	// Reset the board to default pattern
	for (int i=0;i<view_maxsize;i++){
		for (int j=0;j<view_maxsize;j++){
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(Game_Object * ptr){	// Plot an object on the board
	int ix, iy;
	if (get_subscripts(ix,iy,(*ptr).get_location())){
		if (grid[ix][iy][0] != '.'){
			grid[ix][iy][0] = '*';
			grid[ix][iy][1] = ' ';
		}
		else {
			(*ptr).drawself(grid[ix][iy]);
		}
	}

}

void View::draw(){	// Crazy For loops to make sure board looks proper
	for (int i=size-1;i>=0;i--){
		if (i%2 == 0){
			std::cout << scale*(i);
			if ((scale*i)<10){	// Add left side scale
				std::cout << ' ';
			}
			for (int j=0;j<size;j++){
				for (int k=0;k<2;k++){
					std::cout << grid[j][i][k];
				}
			}
			std::cout << std::endl;
		}
		else {
			std::cout << ' ' << ' ';
			for (int j=0;j<size;j++){
				for (int k=0;k<2;k++){
					std::cout << grid[j][i][k];
				}
			}
			std::cout << std::endl;
		}
	}
	// Add bottom scale
	std::cout << ' ' << ' ';
	for (int l=0;l<size;l++){
		if (l%2 == 0){
			std::cout << scale*l << ' ' << ' ';
			if (scale*l < 10){
				std::cout << ' ';
			}
		}
	}
	std::cout << std::endl;
	/*
	// ***To print just the board
	for (int i=size-1;i>=0;i--){
		for (int j=0;j<size;j++){
			for (int k=0;k<2;k++){
				std::cout << grid[j][i][k];
			}
		}
		std::cout << std::endl;
	}
	*/

}

// Private member functions

bool View::get_subscripts(int &ix, int &iy, C_Point location){
	ix = floor((location.x-origin.x)/scale);
	iy = floor((location.y-origin.y)/scale);
	if (ix <= 20 && iy <= 20){
		return true;
	}
	else {
		std::cout << "An object is outside the display" << std::endl;
		return false;
	}
}