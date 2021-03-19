// g++ ch12drill.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
#include "Simple_window.h"
#include "Graph.h"
int main()
{
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win {tl,600,400,"My window"};
	win.wait_for_button();

Axis xa {Axis::x, Point{20,375}, 300, 10, "x tengely"};
 xa.set_color(Color::blue);
 xa.label.set_color(Color::blue);
 win.attach(xa);
 win.set_label("My window #2");
 win.wait_for_button();

 Axis ya {Axis::y, Point{20,375}, 300, 10, "y tengely"};
 ya.set_color(Color::blue);
 ya.label.set_color(Color::blue);
 win.attach(ya);
 win.set_label("My window #3");
 win.wait_for_button();

 Function sine {sin,0,100,Point{20,300},1000,50,50};
 win.attach(sine);
 win.set_label("My window #4");
 win.wait_for_button();
 sine.set_color(Color::black);
	
 Polygon poly;
 poly.add(Point{50,350});
 poly.add(Point{100,250});
 poly.add(Point{150,350});
 poly.set_color(Color::red);
 poly.set_style(Line_style::dash);
 win.attach(poly);
 win.set_label("My window #5");
 win.wait_for_button();

 Closed_polyline poly_rect;
 poly_rect.add(Point{50,200});
 poly_rect.add(Point{150,200});
 poly_rect.add(Point{150,250});
 poly_rect.add(Point{50,250});
 poly_rect.set_fill_color(Color::green);
 win.attach(poly_rect);
 
	
 Rectangle r {Point{50,150}, 100, 50};
 win.attach(r);
 win.set_label("My window #6");
 win.wait_for_button();
 r.set_fill_color(Color::yellow);
 win.set_label("My window #7");
 win.wait_for_button();

 Text t {Point{10,25}, "Hello, graphical world!"};
 t.set_color(Color::red);
 t.set_font(Font::times_bold);
 t.set_font_size(20);
 win.attach(t);
 win.set_label("My window #8");
 win.wait_for_button();


 Image ii {Point{100,50},"image.jpg"};
 win.attach(ii);
 win.set_label("My window #9");
 win.wait_for_button();


 Circle c {Point{100,200},50};
 c.set_fill_color(Color::green);
 win.attach(c);
 win.set_label("My window #10");
 win.wait_for_button();
 
 
 Ellipse e {Point{100,200},75, 25};
 Mark m {Point{100,205},'x'};
 e.set_fill_color(Color::green);
 win.attach(e);
 win.attach(m);
 win.wait_for_button();
	
 ii.move(10,20);
	
 win.wait_for_button();
 
}
