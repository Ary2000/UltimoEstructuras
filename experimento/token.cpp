
#include "Tokenizador.h"
#include <vector>
#include <iostream>
#include <string>
#include "TablaNodos.h"
using namespace std;
int main() {
	TablaNodos p = TablaNodos();
	vector<int>numero;
	//numero.push_back(1);
	//numero.push_back(2);
	numero.push_back(12);
	//numero.push_back(18);
	//numero.push_back(24);

	vector<string>valor;
	//valor.push_back("4");
	//valor.push_back("8");
	valor.push_back("91");
	//valor.push_back("14");
	//valor.push_back("15");
	p.ejecutar("Ventana",numero,valor);
	while(true){
		cout << "Escriba la instruccion: ";
		string s;
		cin >> s;
		Tokenizador tt = Tokenizador(s);
		tt.demeToken();
	}
};