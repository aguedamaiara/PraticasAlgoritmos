/*
 * fila.h
 *
 *  Created on: 15 de abr. de 2023
 *      Author: agued
 */

#ifndef FILA_H_
#define FILA_H_

template<class T>
class Fila {
	// array de itens, capacidade, tamanho, posição inicial, etc.
private:
	T *itens;
	int capacidade;
	int inicio;
	int tamanhoAtual;

public:
	// inicializar array de items, capacidade, tamanho, posição inicial
	Fila(int cap) {
		itens = new T[cap];
		capacidade = cap;
		inicio = 0;
		tamanhoAtual = 0;
	}

	// destruir array de itens
	~Fila() {
		delete[] itens;
	}
	// adiciona um item ao final da fila; lança “Fila cheia” caso cheia
	void enfileira(const T &item) {
		if (cheia()) {
			throw "Fila cheia";
		}
		int fim = (inicio + tamanhoAtual) % capacidade;
		itens[fim] = item;
		tamanhoAtual++;
	}

	// remove um item do inicio da fila; lança “Fila vazia” caso vazia
	T desenfileira() {
		if (vazia()) {
			throw "Fila vazia";
		}
		T item = itens[inicio];
		inicio = (inicio + 1) % capacidade;
		tamanhoAtual--;
		return item;
	}

	// retorna 1 se cheia, 0 caso contrário
	int cheia() {
		return tamanhoAtual == capacidade;
	}

	// retorna 1 se vazia, 0 caso contrário
	int vazia() {
		return tamanhoAtual == 0;
	}

	// retorna a quantidade de itens atualmente na fila
	int tamanho() {
		return tamanhoAtual;
	}
};

#endif /* FILA_H_ */