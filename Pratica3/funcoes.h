/*
 * funcoes.h
 *
 *  Created on: 1 de abr. de 2023
 *      Author: agued
 */

#ifndef FUNCOES_H_
#define FUNCOES_H_
#include <cstring>

namespace funcoes {

template<class T>
void trocar(T &a, T &b) {
	/* troca valores de a e b entre si */
	T temp = a;
	a = b;
	b = temp;

}

template<class T>
T maximo(const T a, const T b) {
	/* retorna maior entre a e b */
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}

template<class T>
T minimo(const T a, const T b) {
	/* retorna menor entre a e b */
	if (a <= b) {
		return a;
	} else {
		return b;
	}

}

template<>
const char* minimo<const char*>(const char *a, const char *b) {
	return (std::strcmp(a, b) < 0) ? a : b;
}

template<>
const char* maximo<const char*>(const char *a, const char *b) {
	return (std::strcmp(a, b) > 0) ? a : b;
}

}

#endif /* FUNCOES_H_ */
