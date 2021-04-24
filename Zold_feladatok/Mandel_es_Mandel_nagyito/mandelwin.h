#include "GUI.h"
#include <vector>

using namespace Graph_lib;
using namespace std;

struct Mandel_window : Graph_lib::Window {
	Mandel_window(Point xy, int w, int h, const string& title );


	 int handle(int event);


 

private:
	int iteraciosHatar=1000;
	
	

	double a,b,c,d;

	double aa,bb,cc,dd;
	int mx,my;


	Rectangle* rect;

	Box* box;

	double w_dx,w_dy;


	



	void draw_mandel(double,double,double,double);

	void area();
 
	int x_start;
	int y_start;




	void quit();
	

};
