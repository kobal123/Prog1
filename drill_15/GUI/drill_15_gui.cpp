#include "Simple_window.h"
#include "Graph.h"

/*
	    g++ drill_15_gui.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/


double one(double x){ return x;}

double slope(double x){return x/2;}

double square(double x){return x*x;}

double sloping_cos(double x){return cos(x)+slope(x);}

int main(){

using namespace Graph_lib;

constexpr int size=600;


Point tl{100,100};

Simple_window win{tl,size ,size ,"Function graphs"};


//300,300-ban metszés
Axis x{Axis::x,Point{100,300},400,20,"x-axis"};
Axis y{Axis::y,Point{300,500},400,20,"y-axis"};
x.set_color(Color::red);
y.set_color(Color::red);


Function f1{one,-10.0,11.0,Point{size/2,size/2},400,20,20};

Function f2{slope,-10.0,11.0,Point{size/2,size/2},400,20,20};

Function f3{square,-10.0,11.0,Point{size/2,size/2},400,20,20};

Function f4{sloping_cos,-10.0,11.0,Point{size/2,size/2},400,20,20};

Function f5{cos,-10.0,11.0,Point{size/2,size/2},400,20,20};

f5.set_color(Color::blue);





Text t{Point{f2.point(0).x,f2.point(0).y -5},"x/2"};

win.attach(t);

 
win.attach(x);
win.attach(y);

win.attach(f1);
win.attach(f2);
win.attach(f3);
win.attach(f4);
win.attach(f5);
win.wait_for_button();



	
}