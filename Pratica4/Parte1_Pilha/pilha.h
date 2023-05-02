/*
 * pilha.h
 *
 *  Created on: 15 de abr. de 2023
 *      Author: agued
 */

#ifndef PILHA_H_
#define PILHA_H_

template<class T>
class Pilha {
private:
	// Atributos para array de items, capacidade e topo da pilha
	T *items;
	int capacidade;
	int topo;

public:
	// instancia array de items, inicializa capacidade e topo
	Pilha(int capacidade) {
		this->capacidade = capacidade;
		this->items = new T[capacidade];
		this->topo = -1;
	}

	// destroy array de items
	~Pilha() {
		delete[] this->items;
	}

	// empilha um item no topo da pilha; lança “Estouro da pilha” se cheia
	void empilha(T item) {
		if (this->topo == this->capacidade - 1) {
			throw "Estouro da pilha";
		}
		this->topo++;
		this->items[this->topo] = item;

	}

	// remove um item do topo da pilha; lança “Pilha vazia” se vazia
	T desempilha() {
		if (this->topo == -1) {
			throw "Pilha vazia";
		}
		T item = this->items[this->topo];
		this->topo--;
		return item;

	}

	// retorna o número de elementos na pilha.
	int tamanho() {
		return this->topo + 1;

	}
};

#endif /* PILHA_H_ */