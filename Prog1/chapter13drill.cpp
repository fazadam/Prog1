/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main() {

	int max_width = 800;
	int max_height = 1000;

	Simple_window win{Point{920,50}, max_width,max_height,"Chapter 13 drill"};

	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for(int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for(int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{0,y},Point{x_size,y});



	Vector_ref<Rectangle> rects;
	for(int i = 0; i < 8; ++i){
		rects.push_back(new Rectangle{Point{i*100,i*100}, 100,100});
        rects[i].set_fill_color(Color::red);
        win.attach(rects[i]);
    }

 	Image panda1 {Point{0,300},"panda.jpg"};
 	Image panda2 {Point{300,0},"panda.jpg"};
 	Image panda3 {Point{500,100,},"panda.jpg"};

 	panda1.set_mask(Point{150,150}, 200,200);
 	panda2.set_mask(Point{200,200}, 200,200);
 	panda3.set_mask(Point{150,200}, 200,200);

 	win.attach(panda1);
 	win.attach(panda2);
 	win.attach(panda3);
	win.attach(grid);

	win.wait_for_button();


Image mozgokep{Point{0,0}, "world.jpeg" };
mozgokep.set_mask(Point{50,50}, 100, 100);
win.attach(mozgokep);

for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(j == 0){
				win.wait_for_button();
			} else {
			mozgokep.move(100,0);
			win.wait_for_button();
			}
		}
		mozgokep.move(-700,100);
		win.wait_for_button();
	}
}