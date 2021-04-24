#include "Simple_window.h"
#include "Graph.h"

/*
	    g++ main_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

int main(){

using namespace Graph_lib;
int w_width=1000;
int w_height=1000;

Point tl{100,100};

Simple_window win{tl,w_width,w_height,"Canvas"};



int size=100;


//rectangle, polygon

Rectangle rect{Point{100,100},size,size};
rect.set_color(Color::blue);


Polygon poly;


poly.add(Point{100,200});
poly.add(Point{200,200});
poly.add(Point{200,300});
poly.add(Point{100,300});
poly.set_color(Color::red);




//howdy rectangle

Rectangle howdy{Point{ w_width/2,w_height/2 },100,30};
Text t{Point{w_width/2 + 15,w_height/2 +15},"howdy?"};
t.set_font(20);



//initials

Line k1{Point{100,550},Point{100,700}};
Line k2{Point{175,550},Point{100,625}};
Line k3{Point{175,700},Point{100,625}};

win.attach(k1);
win.attach(k2);
win.attach(k3);




Line b1{Point{200,550},Point{200,700}};
Line b2{Point{200,700},Point{270,655}};
Line b3{Point{270,655},Point{200,630}};

Line b4{Point{200,630},Point{250,600}};

Line b5{Point{250,600},Point{200,550}};




win.attach(b1);
win.attach(b2);
win.attach(b3);
win.attach(b4);
win.attach(b5);


//tic-tac-toe

Vector_ref<Rectangle> v;

bool isred=true;
for(int i=0;i<3;i++)
{
	for(int k=0;k<3;k++)
	{
		//bal alsó sarokba lesz
		v.push_back(new Rectangle(Point{i*100,700+ k*100},100,100));

		if(isred)
		{
			v[i*3 +k].set_fill_color(Color::red);
			isred=!isred;
		}
		else
		{
			v[i*3 +k].set_fill_color(Color::white);
			isred=!isred;
		}

		win.attach(v[i*3 +k]);
	}
}



//big rectangle

Rectangle rectangle{Point{0,0},w_width/4 * 3,w_height/3 * 2};
rectangle.set_color(Color::red);
rectangle.set_style(Line_style(Line_style::solid,15));
win.attach(rectangle);



//big window, shape
/*
Simple_window big_win{tl,10000,10000,"big window"};
Rectangle big{Point{9000,9000},1005,1005};
big_win.attach(big);

big_win.wait_for_button();
*/



//2d house		600-1000

Rectangle h_rect{Point{700,700},300,300};
win.attach(h_rect);

Polygon triangle;
triangle.add(Point{700,700});
triangle.add(Point{1000,700});
triangle.add(Point{850,600});
win.attach(triangle);


Rectangle door(Point{900,800},100,200);
win.attach(door);




Rectangle window1{Point{725,800},50,50};

Line l1{Point{725,825},Point{775,825}};
Line l2{Point{750,800},Point{750,850}};
win.attach(l1);
win.attach(l2);
win.attach(window1);



Rectangle window2{Point{825,800},50,50};
Line l3{Point{825,825},Point{875,825}};
Line l4{Point{850,800},Point{850,850}};
win.attach(l3);
win.attach(l4);
win.attach(window2);


Line ch(Point{780,650},Point{780,600});
Line ch2(Point{780,600},Point{800,600});
Line ch3(Point{800,600},Point{800,630});

win.attach(ch);
win.attach(ch2);
win.attach(ch3);

//olympic ring

int radius =50;

Circle c1{Point{400,200},radius};
c1.set_color(Color::blue);

Circle c2{Point{515,200},radius};


Circle c3{Point{630,200},radius};
c3.set_color(Color::red);
Circle c4{Point{460,260},radius};
c4.set_color(Color::yellow);
Circle c5{Point{570,260},radius};
c5.set_color(Color::green);

win.attach(c1);
win.attach(c2);
win.attach(c3);
win.attach(c4);
win.attach(c5);
//image


Image moon{Point{500,800},"Moon.jpg"};
moon.set_mask(Point{0,0},200,200);
Text m_text{Point{500,780},"Moon"};
m_text.set_font(20);


win.attach(m_text);
win.attach(moon);



win.attach(t);
win.attach(howdy);
win.attach(poly);
win.attach(rect);

win.set_label("Moon");

win.wait_for_button();



	
}