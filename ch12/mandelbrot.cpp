// https://medium.com/farouk-ounanes-home-on-the-internet/mandelbrot-set-in-c-from-scratch-c7ad6a1bf2d9

#include <iostream>
#include <fstream>
#include <complex>

using namespace std;
using namespace png;

constexpr int width = 600;
constexpr int height = 600;

int value (int x, int y)
{
	constexpr double x_eltolas = 0.8;
	constexpr double y_eltolas = 0.5;
	constexpr double scale = 2.5;
	constexpr double intensity = 25; //minél kisebb annál intenzívebb
  
  complex<double> point(((double)x/width-x_eltolas)*scale, ((double)y/height-y_eltolas)*scale); //azért kell osztani, hogy a szám [0, 1] intervallumban legyen
	
  complex<double> z(0, 0);
	
  int nb_iter = 0; //ez azt jelenti hogy hányszor/mennyire nézi meg ezt
	
  while (abs(z) < 2 && nb_iter <= 50)
  { //akkor lép ki a while-ból ha az adott komplex szám kilép a 2 sugarú körből, vagy miután megnézte mind az 50 iterációt
			z = z * z + point;
			nb_iter++;
	}
  
		if (nb_iter < 50) return (255*nb_iter)/intensity; // szín visszatérítése
		else return 0; //minél később lép ki az iterációból annál sötétebb
		// minél kisebb az iteráció, akkor mivel annyival kevesebbet néz meg, ezért több rész lesz fekete(feketes piros) színű
}

int main()
{
    image<rgb_pixel> image(width, height); //kep inicializalasa

    for (int x = 0; x < image.get_width(); ++x) //vegig megy a kepernyo osszes pixelen/koordinatajan
    	for (int y = 0; y < image.get_height(); ++y) //vegig megy a kepernyo osszes pixelen/koordinatajan
    	{
    		int val = value(x, y); //szinertek kiszmaolasa
    		image[y][x] = rgb_pixel(val, 0, 0); //itt azert van megforditva az x es az y hogy horizontalis legyen a megjelenites
    	}

    image.write("mandelbrot_render.png"); //kep ,,kiirasa,,
    
    return 0;

}
