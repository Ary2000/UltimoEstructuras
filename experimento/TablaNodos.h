#pragma once
#include "Simple_window.h" 
#include "Graph.h"
#include <string>
#include <vector>

using namespace Graph_lib;
typedef Graph_lib::Line * PLinea;
typedef Graph_lib::Text * numeros;
typedef Graph_lib::Rectangle * Pnodo;
typedef Graph_lib::Circle * Sig;

class TablaNodos {
	Simple_window * pWin;
	vector<PLinea> v;
	vector<numeros> intHeap;
	vector<Pnodo> nodos;
	vector<Pnodo> mNodos;
	vector<Sig> bola;
public:
	TablaNodos() {
	};

	void ejecutar(string titulo, vector<int> numero) {
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

		intHeap.push_back(new Graph_lib::Text(Point(25, 35), "1"));//1
		intHeap.push_back(new Graph_lib::Text(Point(112, 35), "2"));//1
		intHeap.push_back(new Graph_lib::Text(Point(199, 35), "3"));//1
		intHeap.push_back(new Graph_lib::Text(Point(286, 35), "4"));//1
		intHeap.push_back(new Graph_lib::Text(Point(373, 35), "5"));//1
		intHeap.push_back(new Graph_lib::Text(Point(460, 35), "6"));//1
		intHeap.push_back(new Graph_lib::Text(Point(547, 35), "7"));//1
		intHeap.push_back(new Graph_lib::Text(Point(25, 135), "8"));//1
		intHeap.push_back(new Graph_lib::Text(Point(112, 135), "9"));//1
		intHeap.push_back(new Graph_lib::Text(Point(199, 135), "10"));//1
		intHeap.push_back(new Graph_lib::Text(Point(286, 135), "11"));//1
		intHeap.push_back(new Graph_lib::Text(Point(373, 135), "12"));//1
		intHeap.push_back(new Graph_lib::Text(Point(460, 135), "13"));//1
		intHeap.push_back(new Graph_lib::Text(Point(547, 135), "14"));//1
		intHeap.push_back(new Graph_lib::Text(Point(25, 235), "15"));//1
		intHeap.push_back(new Graph_lib::Text(Point(112, 235), "16"));//1
		intHeap.push_back(new Graph_lib::Text(Point(199, 235), "17"));//1
		intHeap.push_back(new Graph_lib::Text(Point(286, 235), "18"));//1
		intHeap.push_back(new Graph_lib::Text(Point(373, 235), "19"));//1
		intHeap.push_back(new Graph_lib::Text(Point(460, 235), "20"));//1
		intHeap.push_back(new Graph_lib::Text(Point(547, 235), "21"));//1
		intHeap.push_back(new Graph_lib::Text(Point(25, 320), "22"));//1
		intHeap.push_back(new Graph_lib::Text(Point(112, 320), "23"));//1
		intHeap.push_back(new Graph_lib::Text(Point(199, 320), "24"));//1
		intHeap.push_back(new Graph_lib::Text(Point(286, 320), "25"));//1
		intHeap.push_back(new Graph_lib::Text(Point(373, 320), "26"));//1
		intHeap.push_back(new Graph_lib::Text(Point(460, 320), "27"));//1
		intHeap.push_back(new Graph_lib::Text(Point(547, 320), "28"));//1

		nodos.push_back(new Graph_lib::Rectangle(Point(35, 50), 55, 30));//1
		nodos.push_back(new Graph_lib::Rectangle(Point(122, 50), 55, 30));//2
		nodos.push_back(new Graph_lib::Rectangle(Point(209, 50), 55, 30));//3
		nodos.push_back(new Graph_lib::Rectangle(Point(296, 50), 55, 30));//4
		nodos.push_back(new Graph_lib::Rectangle(Point(383, 50), 55, 30));//5
		nodos.push_back(new Graph_lib::Rectangle(Point(470, 50), 55, 30));//6
		nodos.push_back(new Graph_lib::Rectangle(Point(557, 50), 55, 30));//7
		nodos.push_back(new Graph_lib::Rectangle(Point(35, 150), 55, 30));//1
		nodos.push_back(new Graph_lib::Rectangle(Point(122, 150), 55, 30));//2
		nodos.push_back(new Graph_lib::Rectangle(Point(209, 150), 55, 30));//3
		nodos.push_back(new Graph_lib::Rectangle(Point(296, 150), 55, 30));//4
		nodos.push_back(new Graph_lib::Rectangle(Point(383, 150), 55, 30));//5
		nodos.push_back(new Graph_lib::Rectangle(Point(470, 150), 55, 30));//6
		nodos.push_back(new Graph_lib::Rectangle(Point(557, 150), 55, 30));//7
		nodos.push_back(new Graph_lib::Rectangle(Point(35, 245), 55, 30));//1
		nodos.push_back(new Graph_lib::Rectangle(Point(122, 245), 55, 30));//2
		nodos.push_back(new Graph_lib::Rectangle(Point(209, 245), 55, 30));//3
		nodos.push_back(new Graph_lib::Rectangle(Point(296, 245), 55, 30));//4
		nodos.push_back(new Graph_lib::Rectangle(Point(383, 245), 55, 30));//5
		nodos.push_back(new Graph_lib::Rectangle(Point(470, 245), 55, 30));//6
		nodos.push_back(new Graph_lib::Rectangle(Point(557, 245), 55, 30));//7
		nodos.push_back(new Graph_lib::Rectangle(Point(35, 325), 55, 30));//1
		nodos.push_back(new Graph_lib::Rectangle(Point(122, 325), 55, 30));//2
		nodos.push_back(new Graph_lib::Rectangle(Point(209, 325), 55, 30));//3
		nodos.push_back(new Graph_lib::Rectangle(Point(296, 325), 55, 30));//4
		nodos.push_back(new Graph_lib::Rectangle(Point(383, 325), 55, 30));//5
		nodos.push_back(new Graph_lib::Rectangle(Point(470, 325), 55, 30));//6
		nodos.push_back(new Graph_lib::Rectangle(Point(557, 325), 55, 30));//7

		mNodos.push_back(new Graph_lib::Rectangle(Point(35, 50), 28, 30));//1
		mNodos.push_back(new Graph_lib::Rectangle(Point(122, 50), 28, 30));//2
		mNodos.push_back(new Graph_lib::Rectangle(Point(209, 50), 28, 30));//3
		mNodos.push_back(new Graph_lib::Rectangle(Point(296, 50), 28, 30));//4
		mNodos.push_back(new Graph_lib::Rectangle(Point(383, 50), 28, 30));//5
		mNodos.push_back(new Graph_lib::Rectangle(Point(470, 50), 28, 30));//6
		mNodos.push_back(new Graph_lib::Rectangle(Point(557, 50), 28, 30));//7
		mNodos.push_back(new Graph_lib::Rectangle(Point(35, 150), 28, 30));//1
		mNodos.push_back(new Graph_lib::Rectangle(Point(122, 150), 28, 30));//2
		mNodos.push_back(new Graph_lib::Rectangle(Point(209, 150), 28, 30));//3
		mNodos.push_back(new Graph_lib::Rectangle(Point(296, 150), 28, 30));//4
		mNodos.push_back(new Graph_lib::Rectangle(Point(383, 150), 28, 30));//5
		mNodos.push_back(new Graph_lib::Rectangle(Point(470, 150), 28, 30));//6
		mNodos.push_back(new Graph_lib::Rectangle(Point(557, 150), 28, 30));//7
		mNodos.push_back(new Graph_lib::Rectangle(Point(35, 245), 28, 30));//1
		mNodos.push_back(new Graph_lib::Rectangle(Point(122, 245), 28, 30));//2
		mNodos.push_back(new Graph_lib::Rectangle(Point(209, 245), 28, 30));//3
		mNodos.push_back(new Graph_lib::Rectangle(Point(296, 245), 28, 30));//4
		mNodos.push_back(new Graph_lib::Rectangle(Point(383, 245), 28, 30));//5
		mNodos.push_back(new Graph_lib::Rectangle(Point(470, 245), 28, 30));//6
		mNodos.push_back(new Graph_lib::Rectangle(Point(557, 245), 28, 30));//7
		mNodos.push_back(new Graph_lib::Rectangle(Point(35, 325), 28, 30));//1
		mNodos.push_back(new Graph_lib::Rectangle(Point(122, 325), 28, 30));//2
		mNodos.push_back(new Graph_lib::Rectangle(Point(209, 325), 28, 30));//3
		mNodos.push_back(new Graph_lib::Rectangle(Point(296, 325), 28, 30));//4
		mNodos.push_back(new Graph_lib::Rectangle(Point(383, 325), 28, 30));//5
		mNodos.push_back(new Graph_lib::Rectangle(Point(470, 325), 28, 30));//6
		mNodos.push_back(new Graph_lib::Rectangle(Point(557, 325), 28, 30));//7

		bola.push_back(new Graph_lib::Circle(Point(76, 65), 10));//1
		bola.push_back(new Graph_lib::Circle(Point(163, 65), 10));//2
		bola.push_back(new Graph_lib::Circle(Point(250, 65), 10));//3
		bola.push_back(new Graph_lib::Circle(Point(337, 65), 10));//4
		bola.push_back(new Graph_lib::Circle(Point(424, 65), 10));//5
		bola.push_back(new Graph_lib::Circle(Point(511, 65), 10));//6
		bola.push_back(new Graph_lib::Circle(Point(598, 65), 10));//7
		bola.push_back(new Graph_lib::Circle(Point(76, 165), 10));//1
		bola.push_back(new Graph_lib::Circle(Point(163, 165), 10));//2
		bola.push_back(new Graph_lib::Circle(Point(250, 165), 10));//3
		bola.push_back(new Graph_lib::Circle(Point(337, 165), 10));//4
		bola.push_back(new Graph_lib::Circle(Point(424, 165), 10));//5
		bola.push_back(new Graph_lib::Circle(Point(511, 165), 10));//6
		bola.push_back(new Graph_lib::Circle(Point(598, 165), 10));//7
		bola.push_back(new Graph_lib::Circle(Point(76, 260), 10));//1
		bola.push_back(new Graph_lib::Circle(Point(163, 260), 10));//2
		bola.push_back(new Graph_lib::Circle(Point(250, 260), 10));//3
		bola.push_back(new Graph_lib::Circle(Point(337, 260), 10));//4
		bola.push_back(new Graph_lib::Circle(Point(424, 260), 10));//5
		bola.push_back(new Graph_lib::Circle(Point(511, 260), 10));//6
		bola.push_back(new Graph_lib::Circle(Point(598, 260), 10));//7
		bola.push_back(new Graph_lib::Circle(Point(76, 340), 10));//1
		bola.push_back(new Graph_lib::Circle(Point(163, 340), 10));//2
		bola.push_back(new Graph_lib::Circle(Point(250, 340), 10));//3
		bola.push_back(new Graph_lib::Circle(Point(337, 340), 10));//4
		bola.push_back(new Graph_lib::Circle(Point(424, 340), 10));//5
		bola.push_back(new Graph_lib::Circle(Point(511, 340), 10));//6
		bola.push_back(new Graph_lib::Circle(Point(598, 340), 10));//7

		for (int i = 0; i < v.size(); i++) {
			pWin->attach(*v[i]);
		}
		for (int a = 0; a < intHeap.size(); a++) {
			pWin->attach(*intHeap[a]);
		}
		getNodo(numero);
		/*for (int j = 0; j < nodos.size(); j++) {
			Pnodo n;
			n = nodos[j];
			n->set_fill_color(Color::yellow);
			pWin->attach(*n);
		}
		for (int x = 0; x < mNodos.size(); x++) {
			Pnodo m;
			m = mNodos[x];
			m->set_fill_color(Color::dark_green);
			pWin->attach(*m);
			//pWin->attach(*mNodos[x]);
		}
		for (int y = 0; y < bola.size(); y++) {
			Sig c;
			c = bola[y];
			c->set_fill_color(Color::blue);
			pWin->attach(*c);
			//pWin->attach(*bola[y]);
		}*/
		pWin->wait_for_button();
	}
	/*Ppunto getPuntos(int x) {
		return puntos[x];
	}*/
	/*void generateNodo(int punto) {
		Ppunto pl;
		pl=getPuntos(punto);
		Graph_lib::Rectangle nodo(pl, 50, 380);
	}*/
	void getNodo(vector<int> numero) {
		for (int i = 0; i < numero.size(); i++) {
			Pnodo n;
			n = nodos[numero[i]];
			n->set_fill_color(Color::yellow);
			pWin->attach(*n);
			Pnodo m;
			m = mNodos[numero[i]];
			m->set_fill_color(Color::dark_green);
			pWin->attach(*m);
			Sig c;
			c = bola[numero[i]];
			c->set_fill_color(Color::blue);
			pWin->attach(*c);
		}
	}
	~TablaNodos() {
		delete pWin;
		for (int i = 0; i < v.size(); i++) {
			delete v[i];
		}
		for (int a = 0; a < intHeap.size(); a++) {
			delete intHeap[a];
		}
		for (int j = 0; j < nodos.size(); j++) {
			delete nodos[j];
		}
		for (int x = 0; x < mNodos.size(); x++) {
			delete mNodos[x];
		}
		for (int y = 0; y < nodos.size(); y++) {
			delete bola[y];
		}

	}
};