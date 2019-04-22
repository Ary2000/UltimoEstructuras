
#include "Tokenizador.h"
#include <vector>
#include <iostream>
#include <string>


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

class Procesar {
	Simple_window * pWin;
	string s;
public:
	Procesar() {
		global = s;
	};

	void ejecutar(string titulo) {
		pWin = new Simple_window{ Point(100,100),600,400,titulo };
		Button boton(Point(300, 10), 130, 20, "Realizar instruccion", leerTexto());
		Button botonPaso(Point(300, 40), 135, 20, "Realizar paso a paso", pasoPaso());
		pWin->attach(boton);
		pWin->attach(inbox);
		pWin->attach(botonPaso);
		pWin->wait_for_button();
		delete pWin;
	}
};



int main() {
	while (true) {
		Procesar ventana = Procesar();
		ventana.ejecutar("Jerki");
		
	}
		
}
