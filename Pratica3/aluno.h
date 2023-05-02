/*
 * aluno.h
 *
 *  Created on: 1 de abr. de 2023
 *      Author: agued
 */

#ifndef ALUNO_H_
#define ALUNO_H_

#include <iostream>
#include <string>
#include "arranjo.h"

using namespace std;

class Aluno {
private:
	string nome;
	string mat;

public:
	Aluno() {
	}
	Aluno(const char *nome, const char *mat) :
			nome(nome), mat(mat) {
	}
	friend class Arranjo<Aluno> ;

};

template<>
void Arranjo<Aluno>::set(int idx, const Aluno &aluno) {
	items[idx].mat = aluno.mat;
	items[idx].nome = aluno.nome;
}

template<>
void Arranjo<Aluno>::exibir() {
	for (int i = 0; i < tamanho; i++) {
		cout << i << ": " << items[i].mat << " = " << items[i].nome << endl;
	}
}

#endif /* ALUNO_H_ */
