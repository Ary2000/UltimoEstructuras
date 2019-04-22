#pragma once
#include "Simple_window.h" 
#include "Graph.h"
#include <string>
#include <vector>

using namespace Graph_lib;
typedef Graph_lib::Line * PLinea;

class Procesar {
	Simple_window * pWin;
	vector<PLinea> v;
public:
	Procesar() {
	};

	void ejecutar(string titulo) {
		pWin = new Simple_window{ Point(100,100),650,400,titulo };
		Graph_lib::Rectangle r(Point(10, 10), 630, 380);
		r.set_color(Color::white);
		r.set_fill_color(Color::white);
		pWin->attach(r);
		v.push_back(new Graph_lib::Line{ Point(20,110), Point(630, 110) });
		v.push_back(new Graph_lib::Line{ Point(20, 210), Point(630, 210) });
		v.push_back(new Graph_lib::Line{ Point(20, 300), Point(630, 300) });
		v.push_back(new Graph_lib::Line{ Point(20, 20), Point(630, 20) });
		v.push_back(new Graph_lib::Line{ Point(20, 20), Point(20, 380) });
		v.push_back(new Graph_lib::Line{ Point(107, 20), Point(107, 380) });
		v.push_back(new Graph_lib::Line{ Point(194, 20), Point(194, 380) });
		v.push_back(new Graph_lib::Line{ Point(281, 20), Point(281, 380) });
		v.push_back(new Graph_lib::Line{ Point(368, 20), Point(368, 380) });
		v.push_back(new Graph_lib::Line{ Point(455, 20), Point(455, 380) });
		v.push_back(new Graph_lib::Line{ Point(542, 20), Point(542, 380) });
		v.push_back(new Graph_lib::Line{ Point(630, 20), Point(630, 380) });
		v.push_back(new Graph_lib::Line{ Point(20,380), Point(630, 380) });
		for (int i = 0; i < v.size(); i++) {
			pWin->attach(*v[i]);
		}
		pWin->wait_for_button();
	}
	~Procesar() {
		delete pWin;
		for (int i = 0; i < v.size(); i++) {
			delete v[i];
		}
	}
};
