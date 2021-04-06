#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x){return x*x;}
double cos_slope(double x){return  slope(x)+cos(x);}
double cos (double x) {return cos(x);}

int main()
{
	int win_h=600;
	int win_w=600;
	Point origo{win_w/2,win_h/2};

	Simple_window win (Point{100,100},win_w,win_h,"Function graphs");

	int n=20;

	Axis x_sis (Axis::x, Point{100,300},400,n,"1==20 pixels");
	x_sis.set_color(Color::red);
	win.attach(x_sis);
	Axis y_sis (Axis::y, Point{300,500},400,n,"1==20 pixels");
	y_sis.set_color(Color::red);
	win.attach(y_sis);

	int range_min=-10, range_max=11;
	int points=400;
	int x_scaling=20, y_scaling=20;

	Function s1(one,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(s1);
	
	Function s2(slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(s2);
	
	Text ts2 {Point {500,190}, "x/2"};
	win.attach(ts2);
	
	Function s3(square,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(s3);
	
	Function s4(cos, range_min, range_max, origo, points, x_scaling, y_scaling);
	cosinus.set_color(Color::blue);
	win.attach(s4);
	
	Function s5(cos_slope,range_min,range_max,origo,points,x_scaling,y_scaling);
	win.attach(s5);

	win.wait_for_button();
}
