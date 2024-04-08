/*
 * pilha_teste.cpp
 *
 *  Created on: 10 de mar de 2020
 *      Author: IFPE

 ARQUIVO PARA TESTAR A CLASSE PILHA
 */

#include <iostream>
#include "pilha.h"
#include "pilha_array.h"
#include "pilha_ligada.h"



#define MAX 100

using namespace std;

int main() {
  Pilha<int>* pilha = new PilhaLigada<int>(MAX);

	try {
		cerr << "Testando empilha() [normal]: ";
		for (int i = 0; i < MAX; i++) {
      //indireção
			pilha->empilha(i);
		}
		cerr << "OK" << endl;
	} catch (...) {
		cerr << "FALHOU!" << endl;
		exit(1);
	}

	cerr << "Testando tamanho() [cheia]: ";
  //indireção
	if (pilha->tamanho() != MAX) {
   //indireção 
		cerr << "FALHOU (tam = " << pilha->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando empilha() [overflow]: ";
    //indireção
		pilha->empilha(MAX + 1);
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

	cerr << "Testando desempilha() [normal]: ";
	for (int i = (MAX - 1); i >= 0; i--) {
    //indireção
		if (pilha->desempilha() != i) {
			cerr << "FALHOU em " << i << endl;
			exit(1);
		}
	}
	cerr << "OK" << endl;

	cerr << "Testando tamanho() [vazia]: ";
  //indireção
	if (pilha->tamanho() != 0) {
    //indireção
		cerr << "FALHOU (tam = " << pilha->tamanho() << ")" << endl;
		exit(1);
	}
	cerr << "OK" << endl;

	try {
		cerr << "Testando desempilha() [underflow]: ";
    //indireção
		pilha->desempilha();
		cerr << "FALHOU!" << endl;
		exit(1);
	} catch (const char * ex) {
		cerr << "OK (" << ex << ")" << endl;
	}

  delete pilha;
	return 0;
}