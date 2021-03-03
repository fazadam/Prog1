/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
 

 int main() {

    using namespace Graph_lib;
 	
 	Point tl {100,100};

 	Simple_window win{tl, 600,400, " My window"};

 	Axis xa{Axis::x, Point{20,300},280,10,"x axis"};
 	xa.set_color(Color::dark_green);
 	Axis ya{Axis::y, Point{20,300},280,10,"y axis"};
 	ya.set_color(Color::blue);

 	ya.set_color(Color::cyan);
 	ya.label.set_color(Color::dark_red);


 	Function sine {sin,00,100, Point {200,300},1000,50,50};
 	sine.set_color(Color::blue);

 	

 	Polygon poly;
 	poly.add(Point{500,300});
 	poly.add(Point{600,400});
 	poly.add(Point{400,400});

 	poly.set_color(Color::black);
 	poly.set_style(Line_style(Line_style::dash,4));
 	poly.set_fill_color(Color::red);


 	Rectangle r{Point{300,300},100,50};
 	r.set_color(Color::green);
 	r.set_style(Line_style::solid);
 	r.set_fill_color(Color::black);

 	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	poly_rect.add(Point{50,30});


	poly.set_style(Line_style(Line_style::dash,8));
	poly_rect.set_style(Line_style(Line_style::dash,5));
	poly_rect.set_fill_color(Color::green);


	Text t {Point{300,100},"hello, graphical world!"};
	t.set_font(Font::times_italic);
	t.set_font_size(30);
	
	Image ii{Point{300,150},"world.jpeg"};
	//ii.move (10,10); --> szegmentacios hiba

	win.attach(ii);
	win.attach(t);
	win.attach(poly_rect);
 	win.attach(r);
 	win.attach(poly);
 	win.attach(sine);
 	win.attach(xa);
 	win.attach(ya);
    win.wait_for_button();
}
