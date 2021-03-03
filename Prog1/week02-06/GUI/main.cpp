/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) {return 1;}

double square(double x) {return x*x;}

int main()
{
    using namespace Graph_lib;

    Point tl {100,100};

    int xmax = 1280;
    int ymax = 720;

    int x_origo = xmax/2;
    int y_origo = ymax/2;

    int rmin = -11;
    int rmax = 11;

    int n_points = 400;



    Simple_window win{Point{100,100}, 1280,720, "canvas"};

    Polygon poly;
    poly.add(Point{300,200});
    poly.add(Point{350,100});
    poly.add(Point{400,200});

    Point origo {x_origo,y_origo};

    int xlength = xmax - 10;
    int ylength = ymax - 10;

    int xscale = 30;
    int yscale = 30;

    Function s (one, rmin, rmax, origo, n_points,xscale,yscale);
    Function sq (square, rmin, rmax, origo, n_points,xscale,yscale);

    Axis x {Axis::x, Point{20,y_origo},xlength,xlength/xscale,"x axis"};
    Axis y {Axis::y, Point{x_origo, ylength +20},ylength,ylength/yscale,"y axis"};

    Rectangle r {Point{200,200},100,50};

   r.set_fill_color(Color::yellow);
   r.set_style(Line_style(Line_style::dash, 4));

   Text t {Point{100,200},"hello Graph"};
   t.set_style(Font::times_bold);
   t.set_font_size(20);

   Image ii {Point{100,100}, "badge.jpg"};

   Circle c {Point{400,400},50};


   win.attach(ii);
   	win.attach(t);
	win.attach(r);
    win.attach(sq);
    win.attach(s);
    win.attach(y);
    win.attach(x);
    win.attach(poly);
	win.attach(c);

    win.wait_for_button();

}
