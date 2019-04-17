
#include "Tokenizador.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main() {
	while(true){
		cout << "Escriba la instruccion: ";
		string s;
		cin >> s;
		Tokenizador tt = Tokenizador(s);
		tt.demeToken();
	}
}