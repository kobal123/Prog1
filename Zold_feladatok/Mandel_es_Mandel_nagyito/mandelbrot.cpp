/*
    g++ mandelbrot.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o mandel `fltk-config --ldflags --use-images`

    g++ mandelbrot.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

*/
#include "Simple_window.h"
#include "Graph.h"
#include <vector>
#include <complex>



void mandel(Window& win)
{

	double a=-2.0;
	double b=0.7;
	double c=-1.35;
	double d=1.35;




 	double dx = (b-a)/x_max();
    double dy = (d-c)/y_max();

    //source https://github.com/rbesenczi/BHAXBook/blob/master/Mandelbrot/halmaz/mandel_mento/frakszal.cpp


    int iteracio;
    int iteraciosHatar=255;
    double reC, imC, reZ, imZ, ujreZ, ujimZ;

     for(int j=0; j<x_max(); ++j) {
        //sor = j;

        for(int k=0; k<y_max(); ++k) {
            // c = (reC, imC) a háló rácspontjainak
            // megfelelõ komplex szám
            reC = a+k*dx;
            imC = d-j*dy;
            // z_0 = 0 = (reZ, imZ)
            reZ = 0;
            imZ = 0;
            iteracio = 0;

            // z_{n+1} = z_n * z_n + c iterációk
            // számítása, amíg |z_n| < 2 vagy még
            // nem értük el a 255 iterációt, ha
            // viszont elértük, akkor úgy vesszük,
            // hogy a kiinduláci c komplex számra
            // az iteráció konvergens, azaz a c a
            // Mandelbrot halmaz eleme
            while(reZ*reZ + imZ*imZ < 4 && iteracio < iteraciosHatar) {
                // z_{n+1} = z_n * z_n + c

                ujreZ = reZ*reZ - imZ*imZ + reC;
                ujimZ = 2*reZ*imZ + imC;

                reZ = ujreZ;
                imZ = ujimZ;

                ++iteracio;

            }

            iteracio%=256;

            Pixel *r = new Pixel(Point{k,j},0,255-iteracio,0);
            //if(iteracio!=iteraciosHatar){
			//	r->set_color(Color(Color::red));
            //}
            win.attach(*r);
        }
    }
             
		win.redraw();


}
using namespace std;
int main()
{
	constexpr int MERET=600;

    Simple_window win {Point{0,0},MERET, MERET, "Mandelbrot set"};



    // számítás adatai
    float a = -2.0, b = .7, c = -1.35, d = 1.35;
    int szelesseg = MERET, magassag = MERET, iteraciosHatar = 2000;

    // a számítás
    float dx = (b - a) / szelesseg;
    float dy = (d - c) / magassag;
    float reC, imC, reZ, imZ, ujreZ, ujimZ;


    // Hány iterációt csináltunk?
    int iteracio = 0;
    // Végigzongorázzuk a szélesség x magasság rácsot:
    for (int j = 0; j < magassag; ++j)
    {
        //sor = j;
        for (int k = 0; k < szelesseg; ++k)
        {
            // c = (reC, imC) a rács csomópontjainak
            // megfelelő komplex szám
            reC = a + k * dx;
            imC = d - j * dy;
            std::complex<double> c(reC,imC);
             
            // z_0 = 0 = (reZ, imZ)
            reZ = 0;
            imZ = 0;

            std::complex<double> z=(reZ,imZ);
            iteracio = 0;
            // z_{n+1} = z_n * z_n + c iterációk
            // számítása, amíg |z_n| < 2 vagy még
            // nem értük el a 255 iterációt, ha
            // viszont elértük, akkor úgy vesszük,
            // hogy a kiinduláci c komplex számra
            // az iteráció konvergens, azaz a c a
            // Mandelbrot halmaz eleme
            while (std::abs(z)< 4 && iteracio < iteraciosHatar)
            {
                // z_{n+1} = z_n * z_n + c
              z=z*z+c;
/*
                ujreZ = reZ * reZ - imZ * imZ + reC;
                ujimZ = 2 * reZ * imZ + imC;
                reZ = ujreZ;
                imZ = ujimZ;

*/              ++iteracio;

            }

             Pixel *r = new Pixel(Point{k,j},0,255-iteracio,0);
            //if(iteracio!=iteraciosHatar){
			//	r->set_color(Color(Color::red));
           // }
            win.attach(*r);
        }
    }
	

    win.wait_for_button();
}
