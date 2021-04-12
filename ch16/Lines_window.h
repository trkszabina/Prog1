#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window
{

	Lines_window(Point xy, int w, int h, const string& title);

	Open_polyline lines;
	
	Menu color_menu;
	Menu line_menu;

	Button color_button;
	Button linestyle_button;

 	bool wait_for_button();
	
	static void cb_red(Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}
	static void cb_dark_red(Address, Address pw){reference_to<Lines_window>(pw).dark_red_pressed();}
	static void cb_blue(Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}
	static void cb_dark_blue(Address, Address pw) {reference_to<Lines_window>(pw).dark_blue_pressed();}
	static void cb_black(Address, Address pw){reference_to<Lines_window>(pw).black_pressed();}
	static void cb_white(Address, Address pw){reference_to<Lines_window>(pw).white_pressed();}
	static void cb_color_menu(Address, Address pw){reference_to<Lines_window>(pw).color_pressed();}

	static void cb_line_menu(Address, Address pw){reference_to<Lines_window>(pw).line_pressed();}
	static void cb_solid(Address, Address pw){reference_to<Lines_window>(pw).solid_pressed();}
	static void cb_dash(Address, Address pw){reference_to<Lines_window>(pw).dash_pressed();}
	static void cb_dot(Address, Address pw){reference_to<Lines_window>(pw).dot_pressed();}
	static void cb_dashdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dot_pressed();}
	static void cb_dashdotdot(Address, Address pw){reference_to<Lines_window>(pw).dash_dot_dot_pressed();}

  
  private:
	Button next_button;
	Button quit_button;

	In_box next_x;
	In_box next_y;

	Out_box xy_out;

	void next();
	void quit();
};
