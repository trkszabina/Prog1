// g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	int max_width = 800;
	int max_height = 1000;
	Simple_window win{Point{100,100},max_width,max_height,"Chapter 13 Drill"};
	
    
    int x_size = 100;
    int y_size = 100; 
    Lines grid;
	
    for (int x = 100; x<max_width; x+=100) 
    {
        grid.add(Point{x,0},Point(x,max_height-200));
    }
    for(int y=100;y<max_height;y+=100)
	{
	grid.add(Point{0,y},Point(win_x,y));
	}
    win.attach(grid);

	Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i<8; ++i) {
        vr.push_back(new Rectangle(Point{i*100,i*100},100,100));
        vr[i].set_fill_color(Color::red);
        win.attach(vr[i]);
    }
	
    win.wait_for_button();

    Image kep1(Point{600,0},"seal.jpeg");
    win.attach(kep1);
    Image kep2(Point{500,200},"mario.jpeg");
    win.attach(kep2);
    Image kep3(Point{0,600},"dog.jpeg");
    win.attach(kep3);
    win.wait_for_button();

    Image kep4(Point(0,0),"logo.jpeg");
    win.attach(kep4);
    win.wait_for_button();
	
int k=0;
	while(true)
	{
		for(int i=0;i<7;i++)
		{
			kep4.move(100,0);
			win.wait_for_button();
		}
		if(k==7)
		{
			k=0;
			kep4.move(-700,-700);
		}
		else
		{
			kep.move(-700,100);
			k++;
		}
		win.wait_for_button();
	}
	

}
