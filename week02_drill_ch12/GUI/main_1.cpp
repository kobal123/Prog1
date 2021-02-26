#include "Simple_window.h"
#include "Graph.h"

/*
    g++ main_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

int main(){

using namespace Graph_lib;


Point tl{100,100};

Simple_window win{tl,600,400,"Canvas"};

Polygon poly;

poly.add(Point{300,200});
poly.add(Point{350,100});
poly.add(Point{400,200});
poly.set_fill_color(Color::yellow);
poly.set_style(Line_style(Line_style::dash,4));
poly.set_color(Color::red);
win.attach(poly);


Axis xa {Axis::x,Point{20,300},280,10,"x axis"};
xa.set_color(Color::red);


win.attach(xa);


Axis ya {Axis::y,Point{20,300},280,10,"y axis"};
ya.set_color(Color::blue);
ya.label.set_color(Color::dark_red);
win.attach(ya);



Function sine (sin,0,100,Point{20,150},1000,50,50);
win.attach(sine);

/*
sin(), (0:100),  (20:150) kooridnátánál, 1000 ponttal, 50*x és 50*y
*/

Rectangle rect {Point{300,200},100,100};
win.attach(rect);





Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
poly_rect.add(Point{50,75});

poly_rect.set_fill_color(Color::dark_red);
poly_rect.set_style(Line_style(Line_style::dash,2));
win.attach(poly_rect);


Text t{Point{300,250},"Hello, world?!"};
t.set_font_size(15);
win.attach(t);


Mark m{Point{100,210},'x'};
//Ellipse e{Point{100,200},80,25};
Circle c{Point{100,200},50};

win.attach(m);
//win.attach(e);
win.attach(c);












win.wait_for_button();



	
}