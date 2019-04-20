/*
#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib;

	Point tl(150, 150);
	Simple_window win(tl, 600, 400, "My window");
	win.wait_for_button();
}
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace std;

/*
void callback1(Fl_Widget*, void*) {
	cout << "lol" << endl;
}
*/

int main()
{
	//II get access to our window l ibrary
		//II get access to our graphics library fac i l it ies
		using namespace Graph_lib;// II our graphics faci l ities are in Graph_l ib
		Point tl(100, 100); // I to become top left corner of window
		int dimx = 600;
		int dimy = 400;
		Simple_window win(tl, dimx, dimy, "Canvas"); //II make a simple window
		Button boton(Point(123, 123), 50, 10, "Boton", callback1);
		Graph_lib::Polygon poly;

	//Figura de dos triángulos
	poly.add(Point(300, 200));
	poly.add(Point(350, 100));
	poly.add(Point(400, 200));
	poly.add(Point(450, 100));
	poly.set_color(Color:: red);
	win.attach(poly);

	//Eje x
	Axis xa(Axis::x, Point(20, dimy/2), 525, 10, "x axis");
	xa.set_color(Color::black);
	win.attach(xa);

	//Eje y
	Axis ya(Axis::y, Point(dimx/2, dimy - 20), 350, 10, "y axis");
	ya.set_color(Color::black);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);

	//Función seno
	Function sine(sin, 0, 12, Point(20, 200), 1000, 45, 45);
	sine.set_color(Color::blue);
	win.attach(sine);

	//Triángulo de lineas dash
	Graph_lib::Polygon pol;
	pol.add(Point(300, 200));
	pol.add(Point(350, 100));
	pol.add(Point(400, 200));
	pol.set_color(Color::red);
	pol.set_style(Line_style(Line_style::dash,4));
	win.attach(pol);


	//Rectángulo
	Graph_lib::Rectangle r(Point(200, 200), 100, 50);
	r.set_color(Color::black);
	r.set_fill_color(Color::yellow);
	win.attach(r);

	//Polígono rectángulo con un triángulo en un lado
	Closed_polyline poly_rect;
	poly_rect.add(Point(100, 50));
	poly_rect.add(Point(200, 50));
	poly_rect.add(Point(200, 100));
	poly_rect.add(Point(100, 100));
	poly_rect.add(Point(50, 75));
	poly_rect.set_color(Color::magenta);
	poly_rect.set_style(Line_style(Line_style::dash, 2));
	poly_rect.set_fill_color(Color::green);
	win.attach(poly_rect);

	//Texto
	Text t(Point(150, 150), "No se que estoy haciendo");
	t.set_color(Color::dark_green);
	t.set_font(Font::times_bold_italic);
	t.set_font_size(20);
	win.attach(t);

	//Imágenes
	Image ii(Point(250, 150), "image.jpg");
	win.attach(ii);

	//Círculo
	Circle c(Point(100, 200), 50);
	c.set_color(Color::black);
	win.attach(c);

	//Ellipse
	Graph_lib::Ellipse e(Point(100, 200), 75, 25);
	e.set_color(Color::dark_red);
	win.attach(e);

	//Mark
	Mark m(Point(100, 200), 'x');
	win.attach(m);

	//Tamaño de la ventana
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes(Point(100, 20), oss.str());
	sizes.set_color(Color::black);
	win.attach(sizes);

	//Gif
	Image cal(Point(225, 225), "tenor.gif");
	cal.set_mask(Point(40, 40), 200, 150);
	win.attach(cal);


	Fl_Button buton(50, 50, 100, 30, "Run");
	win.attach(buton);

	//Título y botón "Next"
	win.set_label("Ayuda");
	win.wait_for_button();

	//II make a shape(a polygonl
		//II add a point
		//II add another point
		//II add a third point
		//II adjust properties of poly
		//II connect poly to the window
		//II give mntrol ro the display engine
}