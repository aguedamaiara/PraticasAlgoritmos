/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

#include "util.h"

using namespace std;

/* funções força bruta -----------------*/

void reset(int * array, int len) {
	for (int i = 0; i < len; i++) array[i] = 0;
}

int sum(const int * array, const int * subset, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
		if (subset[i])
			sum += array[i];
	return sum;
}

int finished(const int * subset, int len) {
	for (int i = 0; i < len; i++) if(!subset[i]) return 0;
	return 1;
}

void next(int * subset, int len) {
	for (int i = 0; i < len; i++) {
		if (subset[i]) {
			subset[i] = 0;
		} else {
			subset[i] = 1;
			break;
		}
	}
}

int subsetSumBF(int * array, int len, int value, int * subset, long & count) {
	int tmp = 0;
	reset(subset, len);
	while(!((tmp = sum(array, subset, len)) == value) && !finished(subset, len)) {
		next(subset, len);
		count++;
	}
	return tmp == value;
}

/* ---------------- PRÃ�TICA 11 ----------------------------- */
/* funções Backtracking V1 ----------------- */

int __subseqSumBT(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	// Sucesso!
	if (sum == value) return 1;

	if (pos >= len) return 0;
	count++;

		// Adicionando número na posição atual ao conjunto
	subset[pos] = 1;
	if (__subseqSumBT(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	// Desfazendo (Backtracking) porque não deu certo e tentando de novo
	subset[pos] = 0;
	if (__subseqSumBT(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBT(int * array, int len, int value, int * subset, long & count) {
	return __subseqSumBT(array, len, value, subset, 0, 0, count);
}

/* funções Backtracking V2 ----------------- */

// TODO Prática 11

int __subsetSumBTv2(int * array, int len, int value, int * subset, int pos, int sum, long & count) {
	// Sucesso!
	if (sum == value) return 1;

  // Chegou ao final do array sem solução? retorne (backtrack).
	if (pos >= len) return 0;

	if (sum > value) return 0;

	count++;

	// Adicionando numero na posição atual ao conjunto
	subset[pos] = 1;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum + array[pos], count)) return 1;

	// Desfazendo (Backtracking) porque não deu certo e tentando de novo
	subset[pos] = 0;
	if (__subsetSumBTv2(array, len, value, subset, pos + 1, sum, count)) return 1;

	return 0;
}

int subsetSumBTv2(int * array, int len, int value, int * subset, long & count) {
// TODO Prática 11
    int sum = 0;
    for (int i = 0; i < len; i++) {
		sum += array[i];
    }

    if (value < sum) return __subsetSumBTv2(array, len, value, subset, 0, 0, count);

    return 0;
}


int __subsetSumBTv3(int *array,
		int len, int value,
		int *subset, int pos,
		int sum, long &count) {

	// É a soma que queremos: sucesso, retorne 1!
	if (sum == value)  return 1;

	// Estrapolou o limite do array, backtrack (não deve acontacer, mas...)
	if (pos >= len)    return 0;

	// Incrementar contador de chamadas
	count++;

	// Fazer pruning para evitar caminhos desnecessários
	// Para todas as posições p = pos + 1 até len - 1; faça:
	for (int p = pos + 1; p < len; p++) {
		// Chamada recursiva passando posição p e nova soma (sum + array[p])
		// Lembrar de passar count também
		if (__subsetSumBTv3(array, len, value, subset, p, sum + array[p], count)) {
			// Se retorno com sucesso (!= 0), então:
			// Adicione a posição p à solução (subset)
			// Retorne sucesso (1)
			subset[p] = 1;
			return 1;
		}
	}

	// Falhou, retornar 0 (backtrack)
	return 0;
}

int subsetSumBTv3(int *array, int len, int value, int *subset, long &count) {

	int sum = 0;

	// Calcular a soma total dos elementos do array
	for (int i = 0; i < len; i++) {
		sum += array[i];
	}

	// Se o valor desejado for menor que a soma total, chame a função __subsetSumBTv3
	if (value < sum) {
		// Atenção que pos = -1 na chamada inicial, difere de antes!
		return __subsetSumBTv3(array, len, value, subset, -1, 0, count);
	}

	// Caso contrário, retorne 0 (não há solução)
	return 0;
}

/* ---------------- PRÁTICA 12 ----------------------------- */

int subsetSumGreedy(int * array, int len, int value, int * subset, long & count) {
	// TODO PrÃ¡tica 12

	return -100;
}

/* -------------------------------------- */

void runSubsetSum(const char * name,	int func(int *, int, int, int *, long &), int * array, int len, int value) {
	long count = 0;
	int * subset = new int[len];
	reset(subset, len);

	auto start = std::chrono::high_resolution_clock::now();

	int found = func(array, len, value, subset, count);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << (found?"YES ":" NO ");
	if (found) {
		cout << "[ ";
		for (int i = 0; i < len; i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << "[time: "<< elapsed << "us] ";
	cout << "[count: "<< count << "]" << endl;


	delete [] subset;
}

int main_SUBSETSUM() {
// int main() {
	int size = 20;

	int * array = new int[size];

		srand(333);
//	srand(12345);


	for (int i = 0; i < size; i++) {
		cout << (array[i] = rand() % (size * 2)) << " ";
	}
	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		 value += (rand() % (size * 3));
		cout << i << ": Trying " << value << " ..." << endl;

		runSubsetSum("Bruteforce     ", subsetSumBF, array, size, value);
		runSubsetSum("Backtracking   ", subsetSumBT, array, size, value);
		runSubsetSum("Backtracking V2", subsetSumBTv2, array, size, value);
		runSubsetSum("Backtracking V3", subsetSumBTv3, array, size, value);
	}

	delete [] array;

	return 0;
}
