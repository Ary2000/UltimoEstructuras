#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Simple_window.h" 
#include "Graph.h"

using namespace std;


enum Tipo {variable, operador, numero, nulo};

typedef struct Nodo* enlace;
struct Nodo {
	int v;
	enlace sig;
	Nodo(int v) : v{ v }, sig{ nullptr } {}
	Nodo(int v, enlace sig) : v{ v }, sig{ sig } {}
};

enlace a;
enlace b;
enlace c;
enlace d;
enlace e;
enlace f;
enlace g;
enlace h;
enlace i;
enlace j;
enlace k;
enlace l;
enlace m;
enlace n;
enlace o;
enlace p;
enlace q;
enlace r;
enlace s;
enlace t;
enlace u;
enlace v;
enlace w;
enlace x;
enlace y;
enlace z;

int heapback = 0;

class nodoDibujo {
public:
	string instruccion;
	string v;
	bool heapback;
	nodoDibujo(string s, string valor, bool heap) {
		instruccion = s;
		v = valor;
		heap = heapback;
	}
};

vector<nodoDibujo> nodospDibujar;

class win2 {
	Simple_window * pWin;
	string s;

public:
	win2() {
	};

	void ejecutar(string instruccionActual) {
		Simple_window pWin( Point(100,100),600,200, "Instrucciones paso a paso" );
		Text te(Point(10, 20), "La instrucción que se esta haciendo es: ");
		Text t(Point(260, 20), instruccionActual);
		pWin.attach(t);
		pWin.attach(te);
		pWin.wait_for_button();
	}
	~win2() {
		delete pWin;
	}
};

struct Token {
	Tipo tipo;
	string tokenS;
	int num;
	char tokenC;

	Token(string st) { tipo = variable; tokenS = st; }
	Token(char s) { tipo = operador; tokenC = s; }
	Token(int n) { tipo = numero; num = n ; }
	Token() : tipo{ nulo } { }
	Tipo demeTipo() { return tipo; }
	friend ostream& operator<<(ostream &os, Token & t);
	~Token() {};
};


ostream& operator <<(ostream &os, Token & t) {
	switch (t.tipo) 	{
	case variable : {
		os << "[" << t.tokenS << "]" << "<var>\n";
		break;
	}
	case operador:
		os << "[" << t.tokenC << "]" << "<opr>\n";
		break;
	case numero :
		os << "[" << t.num << "]" << "<num>\n";
		break;
	case nulo:
		os << "[ ]" << "<nul>\n";
		break;
	}
	return os;
}

class Tokenizador {
private :
	int pos;
	string tira;
	bool uve = false;
	win2 ventanita;
public:
	bool paso = false;
	bool wh = false;
	bool repeat = false;
	Tokenizador(string entrada);
	void demeToken();
	void demeTokenAux(string x);
	void realizarInstruccion(string instruccion);
	enlace& revisarVariable(string var);
	enlace& realizarSigs(enlace& variable, string instruccion, int x);
};

enlace& Tokenizador::realizarSigs(enlace& variable, string instruccion, int x) {
	while (x < instruccion.length()) {
		if (instruccion[x] == 's') { return realizarSigs(variable->sig, instruccion, ++x); }
		if (instruccion[x] == 'v') { uve = true; }
		x++;
	}
	return variable;
}

enlace& Tokenizador::revisarVariable(string var) {
	while (true) {
		if (var[0] == 'a') {
			return a;
		}
		else if (var[0] == 'b') {
			return b;
		}
		else if (var[0] == 'c') {
			return c;
		}
		else if (var[0] == 'd') {
			return d;
		}
		else if (var[0] == 'e') {
			return e;
		}
		else if (var[0] == 'f') {
			return f;
		}
		else if (var[0] == 'g') {
			return g;
		}
		else if (var[0] == 'h') {
			return h;
		}
		else if (var[0] == 'i') {
			return i;
		}
		else if (var[0] == 'j') {
			return j;
		}
		else if (var[0] == 'k') {
			return k;
		}
		else if (var[0] == 'l') {
			return l;
		}
		else if (var[0] == 'm') {
			return m;
		}
		else if (var[0] == 'n') {
			return n;
		}
		else if (var[0] == 'o') {
			return o;
		}
		else if (var[0] == 'p') {
			return p;
		}
		else if (var[0] == 'q') {
			return q;
		}
		else if (var[0] == 'r') {
			return r;
		}
		else if (var[0] == 's') {
			return s;
		}
		else if (var[0] == 't') {
			return t;
		}
		else if (var[0] == 'u') {
			return u;
		}
		else if (var[0] == 'v') {
			return v;
		}
		else if (var[0] == 'w') {
			return w;
		}
		else if (var[0] == 'x') {
			return x;
		}
		else if (var[0] == 'y') {
			return y;
		}
		else if (var[0] == 'temp') {
			int x;
		}
	}
}

Tokenizador::Tokenizador(string entrada) {
	tira = entrada;
	pos = 0;
}

void Tokenizador::realizarInstruccion(string instruccion) {
	if (paso) {
		ventanita.ejecutar(instruccion);
	}
	string instruccion1;
	string instruccion2;
	int x = 0;
	while (x < instruccion.length()) {
		if (instruccion[x] == '=') {
			break;
		}
		instruccion1.push_back(instruccion[x++]);
	}
	x++;
	while (x < instruccion.length()) {
		instruccion2.push_back(instruccion[x++]);
	}
	enlace& variable = revisarVariable(instruccion1);
	enlace& varSigs = realizarSigs(variable, instruccion1, 0);
	if (instruccion2[0] == '0') {
		varSigs->v = 0;
		varSigs->sig == nullptr;
		for (int pos = 0; pos < nodospDibujar.size(); pos++) {
			if (nodospDibujar[pos].instruccion == instruccion1) {
				nodospDibujar[pos].v = "0";
				break;
			}
		}
	}
	else if (instruccion2[0] == '1' || instruccion2[0] == '2' || instruccion2[0] == '3' || instruccion2[0] == '4' || instruccion2[0] == '5' || instruccion2[0] == '6' || instruccion2[0] == '7' || instruccion2[0] == '8' || instruccion2[0] == '9') {
		if (uve == true) {
			int valor = stoi(instruccion2);
			varSigs->v = valor;
			for (int pos = 0; pos < nodospDibujar.size(); pos++) {
				if (nodospDibujar[pos].instruccion == instruccion1) {
					nodospDibujar[pos].v == to_string(valor);
					break;
				}
			}
			for (int pos = 0; pos < nodospDibujar.size(); pos++) {
				if (nodospDibujar[pos].instruccion == instruccion1) {
					nodospDibujar[pos].v = instruccion2;
					break;
				}
			}

			
		}
	}
	else if (instruccion2[0] == '_') {
		int valor = rand() % 99 + 1;
		varSigs->v = valor;
		for (int pos = 0; pos < nodospDibujar.size(); pos++) {
			if (nodospDibujar[pos].instruccion == instruccion1) {
				nodospDibujar[pos].v == to_string(valor);
				break;
			}
		}
	}
	else if (instruccion2[0] == 'n') {
		if (instruccion2[1] == 'e') {
			int valor;
			if (instruccion2[8] == '1' || instruccion2[8] == '2' || instruccion2[8] == '3' || instruccion2[8] == '4' || instruccion2[8] == '5' || instruccion2[8] == '6' || instruccion2[8] == '7' || instruccion2[8] == '8' || instruccion2[8] == '9') {
				string numeros;
				int posicion = 8;
				while (instruccion2[posicion] != ')') {
					numeros.push_back(instruccion2[posicion]);
					posicion++;
					break;
				}
				valor = stoi(numeros);
				varSigs = new Nodo(valor);
			}
			else if(instruccion2[8] == '_') {
				valor = rand() % 99 + 1;
				varSigs = new Nodo(rand() % 99 + 1);
			}
			if (heapback) {
				nodoDibujo p = nodoDibujo(instruccion1, to_string(valor), true);
				nodospDibujar.push_back(p);
			}
			else {

				nodoDibujo p = nodoDibujo(instruccion1, to_string(valor), false);
				nodospDibujar.push_back(p);
			}
		}
	}
	else if(instruccion2.length()) {
		enlace& variable2 = revisarVariable(instruccion2);
		enlace& varSigs2 = realizarSigs(variable2, instruccion2, 0);
		if (uve) {
			varSigs->v = varSigs2->v;
		}
		else {
			varSigs = varSigs2;
		}
	}

	
}

void Tokenizador::demeToken(){
	demeTokenAux(tira);
}

void Tokenizador::demeTokenAux(string instruccion){
	string instruccion1;
	string instruccion2;
	repeat = false;
	wh = false;
	int x = 0;
	while (x < instruccion.length()) {
		if (instruccion[x] == ';') {
			int y = 0;
			while (y < x) {
				instruccion1.push_back(instruccion[y++]);
			}
			y++;
			while (y < instruccion.length()) {
				instruccion2.push_back(instruccion[y++]);
			}
			break;
		}
		x++;
	}
	if (instruccion1.length() == 0) { instruccion1 = instruccion; }
	if (instruccion1[0] == 'w') {
		if (instruccion1[1] == 'h') {
			wh = true;
		}
	}
	else if (instruccion1[0] == 'r') {
		if (instruccion1[1] == 'e') {
			repeat = true;
		}
	}
	else if (wh) {
		string variableWh;
		variableWh.push_back(instruccion1[6]);
		enlace& variable = revisarVariable(variableWh);
		variableWh.pop_back();
		while (instruccion1[pos] != ')') { variableWh.push_back(instruccion1[pos++]); }
		variableWh.push_back(instruccion1[pos++]);
		enlace& variSigs = realizarSigs(variable, instruccion1, 0);
		while (variSigs->v) {
			demeTokenAux(instruccion2);
		}

	}
	else if (repeat) {
		string cantidad;
		int pos = 7;
		while (instruccion1[pos] != ')') { cantidad.push_back(instruccion1[pos++]); }
		cantidad.push_back(instruccion1[pos++]);
		int cantidadVeces = stoi(cantidad);
		for (int vara = 0; vara < cantidadVeces; vara++) {
			demeTokenAux(instruccion2);
		}
	}
	else {
		realizarInstruccion(instruccion1);
		if (instruccion2.length()) {
			demeTokenAux(instruccion2);
		}
	}

}



