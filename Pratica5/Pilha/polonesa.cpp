/*
 * pratica04.cpp
 *
 *  Created on: 28 de set de 2017
 *      Author: ramide

 código para testar notação polonesa
 */
#include <iostream>
#include "pilha.h"
#include "pilha_array.h"
#include "pilha_ligada.h"

using namespace std;

int ehOperador(char token) {
	switch(token) {
	case '+':
	case '-':
	case '*':
	case '/': return 1;
	default: return 0;
	}
}

int avalia(char token, int valorEsq, int valorDir) {
	switch(token) {
	case '+': return valorEsq + valorDir;
	case '-': return valorEsq - valorDir;
	case '*': return valorEsq * valorDir;
	case '/': return valorEsq / valorDir;
	default: return 0;
	}
}

int polonesa(const char * exp) {
	Pilha<int>* pilha = new PilhaArray<int>(10);
  
  //Pilha<int>* pilha = new PilhaLigada<int>(10);
  //Pilha<int> pilha(10);
	while (*exp) {
		char token = *exp;
		if (ehOperador(token)) {
      //indireção
			int valorDir = pilha->desempilha();
			int valorEsq = pilha->desempilha();
			int resultado = avalia(token, valorEsq, valorDir);
			pilha->empilha(resultado);
		} else {
			int valor = (int)(token - '0');
			pilha->empilha(valor);
		}
		exp++;
	}
	return pilha->desempilha();
  //liberar espaço na memória
   delete pilha;
}


int main5() {
	cout << polonesa("23+31-*") << endl;
	cout << polonesa("93*42/-") << endl;

	return 0;
}