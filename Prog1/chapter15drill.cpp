/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double slope_cosinus(double x) {return slope(x) + cos(x);}

int main() {

	int max_width = 600;
	int max_height = 600;
	Point origo{max_height/2,max_width/2};

	Simple_window win{Point{920,50}, max_width,max_height,"Chapter 15 drill"};

	int notch = 20;

	Axis x { Axis:: x, Point {100,300}, 400, notch, " 20 pix. = 1notch"};
	Axis y { Axis:: y, Point {300,500}, 400, notch, " 20 pix. = 1notch"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);


	int rmin = -10;
	int rmax = 11;
	double xscale = 20;
	double yscale = 20;
	int points = 400;

	Function fun_one(one, rmin,rmax,origo,points,xscale,yscale);
	Function fun_slope(slope, rmin,rmax,origo,points,xscale,yscale);
	Function fun_square(square, rmin,rmax,origo,points,xscale,yscale);
	Function fun_cosinus(cos,rmin,rmax,origo,points,xscale,yscale);
	Function fun_slopecosi(slope_cosinus,rmin,rmax,origo,points,xscale,yscale);
	
	Text label {Point {100,380}, "x/2"};

	fun_cosinus.set_color(Color::blue);



	win.attach(fun_slopecosi);
	win.attach(fun_cosinus);
	win.attach(fun_one);
	win.attach(fun_slope);
	win.attach(fun_square);
	win.attach(label);


	win.wait_for_button();

}