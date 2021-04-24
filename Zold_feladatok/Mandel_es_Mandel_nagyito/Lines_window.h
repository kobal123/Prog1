#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title );

	 

private:
	Open_polyline lines;

	Menu color_menu;
	Menu style_menu;
	Button color_menu_button;
	Button style_menu_button;


	bool wait_for_button();
	void hide_color_menu(){color_menu.hide(); color_menu_button.show();}
	void hide_style_menu(){style_menu.hide(); style_menu_button.show();}


	 






	void red_pressed(){change(Color::red);}
	void black_pressed(){change(Color::black);}
	void blue_pressed(){change(Color::blue);}

	void dash_pressed(){style(Line_style::dash);};
	void dashdot_pressed(){style(Line_style::dashdot);};
	void dot_pressed(){style(Line_style::dot);};
	void solid_pressed(){style(Line_style::solid);};


	void change(Color c){lines.set_color(c);}
	void style(Line_style s){ lines.set_style(s);} 
	void color_menu_pressed(){color_menu_button.hide();color_menu.show();}
	void style_menu_pressed(){style_menu_button.hide();style_menu.show();}



	static void cb_red(Address,Address);
	static void cb_blue(Address,Address);
	static void cb_black(Address,Address);
	static void cb_menu(Address,Address);

	static void cb_solid(Address,Address);
	static void cb_dash(Address,Address);
	static void cb_dashdot(Address,Address);
	static void cb_dot(Address,Address);


	static void cb_mouse_pos(Address,Address);

	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();
	

};
