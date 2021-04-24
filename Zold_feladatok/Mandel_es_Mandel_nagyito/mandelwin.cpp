#include "mandelwin.h"
#include <complex>
#include <iostream>
#include "GUI.h"
#include <stdlib.h>
#include "fltk.h"

using namespace Graph_lib;

Mandel_window::Mandel_window(Point xy,int w, int h,const string& label)
:Window(xy,w,h,label)

{

a=-2.0;
b=0.7;
d=1.35;
c=-1.35;
x_start=y_start=mx=my=0;

rect = new Rectangle(Point{x_start,y_start},1,1);
attach(*rect);

draw_mandel(a,b,c,d); 

}







int Mandel_window::handle(int event)
{

	double aa;
	double bb;
	double cc;
	double dd;

	switch(event){

		case FL_PUSH:
				
				
				x_start=Fl::event_x();
				y_start=Fl::event_y();
				mx=0;
				my=0;
 				
 

				return 1;
		
		case FL_DRAG:
				


				mx=abs(Fl::event_x()-x_start);
				my=mx;	


				area();

 				
				
				return 1;

		case FL_RELEASE:

		


				w_dx = (b-a)/x_max();
    			w_dy = (d-c)/y_max();





     			aa = this->a+x_start*w_dx;
    			bb = this->a+x_start*w_dx+mx*w_dx;
    			cc = this->d-y_start*w_dy-my*w_dy;
    			dd = this->d-y_start*w_dy;

 
    			this->a=aa;
    			this->b=bb;
    			this->d=dd;
    			this->c=cc;

  
				

				draw_mandel(aa,bb,cc,dd);
		

				
				return 1;
		
		
		default:
				return Fl_Window::handle(event);
			};

	


}


void Mandel_window::area()
{
				


				detach(*rect);

				cout<<shapes_size()<<endl;
				
				delete rect;
				rect = new Rectangle(Point{x_start,y_start},abs(mx+1),abs(my+1));
				rect->set_color(Color::blue);
				attach(*rect);

				damage(1,x_start,y_start,abs(mx+1),abs(my+1));
 				

}


using namespace std;


void Mandel_window::draw_mandel(double a, double b, double c, double d)
{

 	if(shapes_size())
 	{	
 		

 		for(int i=0;i<shapes_size();i++){
 			delete shapes[i];
 		}
 		shapes.clear();

 		



 		
 	}


 	double dx = (b-a)/x_max();
    double dy = (d-c)/y_max();


   

    
     





    //source https://github.com/rbesenczi/BHAXBook/blob/master/Mandelbrot/halmaz/mandel_mento/frakszal.cpp


    int iteracio;
    double reC, imC, reZ, imZ, ujreZ, ujimZ;

     for(int j=0; j<x_max(); ++j) {
        //sor = j;

        for(int k=0; k<y_max(); ++k) {
            // c = (reC, imC) a háló rácspontjainak
            // megfelelõ komplex szám
            reC = a+k*dx;
            imC = d-j*dy;


            //complex<double> c(reC,imC);
            

            // z_0 = 0 = (reZ, imZ)
            reZ = 0;
            imZ = 0;

            //complex<double> z(reZ,imZ);
            iteracio = 0;

            // z_{n+1} = z_n * z_n + c iterációk
            // számítása, amíg |z_n| < 2 vagy még
            // nem értük el a 255 iterációt, ha
            // viszont elértük, akkor úgy vesszük,
            // hogy a kiinduláci c komplex számra
            // az iteráció konvergens, azaz a c a
            // Mandelbrot halmaz eleme


            	//abs(z), ha az std::complex -et használod
            while(reZ*reZ + imZ* imZ < 4 && iteracio < iteraciosHatar) {
                // z_{n+1} = z_n * z_n + c


            	//std::complex szam
            	//z=z*z+c;
            	


            	
                ujreZ = reZ*reZ - imZ*imZ + reC;
                ujimZ = 2*reZ*imZ + imC;

                reZ = ujreZ;
                imZ = ujimZ;
				
                ++iteracio;

            }

            iteracio%=256;

            Pixel *r = new Pixel(Point{k,j},0,255-iteracio,0);
           
            attach(*r);
        }
    }
             
		redraw();

}











void Mandel_window::quit()
{
    hide();
}