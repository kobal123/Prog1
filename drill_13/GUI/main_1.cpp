#include "Simple_window.h"
#include "Graph.h"

/*
	    g++ main_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

int main(){

using namespace Graph_lib;


constexpr int rect_num=8;
constexpr int size=100;


Point tl{0,0};

Simple_window win{tl,800,1000,"Canvas"};


for(int i=0;i<rect_num;i++){
	for(int k=0;k<rect_num;k++){

		Point *p=new Point(i*size,k*size);

		Rectangle *r = new Rectangle(*p,size,size);

		//ha az átlóhoz érünk legyen piros a négyzet
		if(i==k)r->set_fill_color(Color::red);

		win.attach(*r);
	}

}

 


Image i1{Point{0,200},"droid.jpg"};
win.attach(i1);

Image i2{Point{0,400},"droid.jpg"};
win.attach(i2);

Image i3{Point{0,600},"droid.jpg"};
win.attach(i3);



/*

Image *sq = new Image(Point{0,0},"sq.jpg");


sq->set_mask(Point{0,0},size,size);
win.attach(*sq);

*/


Image sq{Point{0,0},"sq.jpg"};
sq.set_mask(Point{0,0},100,100);
win.attach(sq);

//win.wait_for_button();

//sq.move(100,100);

win.wait_for_button();

while(true){

	for(int i=0;i<rect_num;i++){
		for(int k=0;k<rect_num;k++){
			 
			win.wait_for_button();
			sq.move(100,0);
		}
		sq.move(-800,100);
	}
	sq.move(0,-800);
}


win.wait_for_button();



	
}