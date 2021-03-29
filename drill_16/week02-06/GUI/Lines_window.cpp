#include "Lines_window.h"
#include <iostream>

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-300,0}, 150, 40, "Next point",
        [](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-150,0}, 150, 40, "Quit",
        [](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
    next_x{Point{300,0}, 50, 40, "next x:"},
    next_y{Point{450,0}, 50, 40, "next y:"},
    xy_out{Point{100,0}, 100, 40, "current (x,y):"},
    color_menu{Point{x_max()-110,40},70,20,Menu::vertical,"color"},
    color_menu_button{Point{x_max()-150,40},150,40,"color menu",[](Address,Address pw){reference_to<Lines_window>(pw).color_menu_pressed();}},
    style_menu{Point{x_max()-110,100},70,20,Menu::vertical,"style"},
    style_menu_button{Point{x_max()-150,100},150,40,"style menu",[](Address,Address pw){reference_to<Lines_window>(pw).style_menu_pressed();}}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    
    color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
    color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
    color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});

    style_menu.attach(new Button{Point{0,0},0,0,"dash",cb_dash});
    style_menu.attach(new Button{Point{0,0},0,0,"dashdot",cb_dashdot});
    style_menu.attach(new Button{Point{0,0},0,0,"dot",cb_dot});
    style_menu.attach(new Button{Point{0,0},0,0,"solid",cb_solid});

   // color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
   // color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
   // color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
    attach(style_menu);
    attach(color_menu);
    color_menu.hide();
    attach(color_menu_button);
    attach(style_menu_button);
    style_menu.hide();
}

void Lines_window::quit()
{
    hide();
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Point{x,y});

    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}




void Lines_window::cb_blue(Address,Address pw)
{
    reference_to<Lines_window>(pw).blue_pressed();
    reference_to<Lines_window>(pw).hide_color_menu();
}

void Lines_window::cb_red(Address,Address pw)
{
    reference_to<Lines_window>(pw).red_pressed();
    reference_to<Lines_window>(pw).hide_color_menu();
}

void Lines_window::cb_black(Address,Address pw)
{
    reference_to<Lines_window>(pw).black_pressed();
    reference_to<Lines_window>(pw).hide_color_menu();
}



void Lines_window::cb_dash(Address,Address pw)
{
    reference_to<Lines_window>(pw).dash_pressed();
    reference_to<Lines_window>(pw).hide_style_menu();
}

void Lines_window::cb_dashdot(Address,Address pw)
{
    reference_to<Lines_window>(pw).dashdot_pressed();
    reference_to<Lines_window>(pw).hide_style_menu();
}

void Lines_window::cb_dot(Address,Address pw)
{
    reference_to<Lines_window>(pw).dot_pressed();
    reference_to<Lines_window>(pw).hide_style_menu();
}

void Lines_window::cb_solid(Address,Address pw)
{
    reference_to<Lines_window>(pw).solid_pressed();
    reference_to<Lines_window>(pw).hide_style_menu();
}