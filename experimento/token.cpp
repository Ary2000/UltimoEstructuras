
#include "Tokenizador.h"
#include <vector>
#include <iostream>
#include <string>
#include "TablaNodos.h"
using namespace std;
using namespace Graph_lib;

string global;
Graph_lib::In_box inbox(Point(130, 10), 150, 20, "Escribir instrucción");



void le() {
Tokenizador tt(inbox.get_string());
tt.demeToken();
}

Callback leerTexto() {
	return Callback(le);
}

void paso() {
	Tokenizador tt(inbox.get_string());
	tt.paso = true;
	tt.demeToken();
}

Callback pasoPaso() {
	return Callback(paso);
}

void memoriaHeap() {
	TablaNodos p = TablaNodos();
	vector<int>numero;
	//numero.push_back(1);
	//numero.push_back(2);
	//numero.push_back(12);
	//numero.push_back(18);
	//numero.push_back(24);

	vector<string>valor;
	//valor.push_back("4");
	//valor.push_back("8");
	//valor.push_back("91");
	//valor.push_back("14");
	//valor.push_back("15");

	for (int pos = 0; pos < nodospDibujar.size(); pos++) {
		if (nodospDibujar[pos].v != "0") {
			numero.push_back(pos);
			valor.push_back(nodospDibujar[pos].v);
		}
	}

	p.ejecutar("Ventana", numero, valor);
}

Callback verMemoriaHeap() {
	return Callback(memoriaHeap);
}

class Procesar {
	Simple_window * pWin;
	string s;
public:
	Procesar() {
		global = s;
	};

	void ejecutar(string titulo) {
		pWin = new Simple_window{ Point(100,100),600,150,titulo };
		Button boton(Point(300, 10), 130, 20, "Realizar instruccion", leerTexto());
		Button botonPaso(Point(300, 40), 140, 20, "Realizar paso a paso", pasoPaso());
		Button botonVentana(Point(300, 70), 135, 20, "Memoria heap", verMemoriaHeap());
		pWin->attach(boton);
		pWin->attach(inbox);
		pWin->attach(botonPaso);
		pWin->attach(botonVentana);
		pWin->wait_for_button();
		delete pWin;
	}
};



int main() {
	Procesar ventana = Procesar();
	ventana.ejecutar("Jerki");
}
