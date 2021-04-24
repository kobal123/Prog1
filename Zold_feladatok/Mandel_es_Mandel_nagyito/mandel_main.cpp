/*
    g++ mandel_main.cpp Graph.cpp Window.cpp GUI.cpp mandelwin.cpp -o Mandelbrot_set `fltk-config --ldflags --use-images`
*/
#include "mandelwin.h"
#include "Graph.h"
#include <vector>


using namespace std;
int main()
{
    Mandel_window win {Point{0,0},800, 800, "Mandelbrot set zoom"};

	



	

    return gui_main();
}
