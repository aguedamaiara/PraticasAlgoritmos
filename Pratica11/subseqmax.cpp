/*
 * subseqmax.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */

/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <chrono>
#include <iostream>
#include <stdlib.h>

#include "util.h"

using namespace std;

/* ---------------- PRÃ�TICA 11 ----------------------------- */

/* funções força bruta -----------------*/

int subseqMaxBF(int *array, int len, int &ini, int &end, long &count) {
  int max = -9999, sum;
  ini = end = -1;
  for (int i = 0; i < len; i++) {
    sum = 0;
    for (int j = i; j < len; j++) {
      count++;

      sum += array[j];
      if (sum > max) {
        max = sum;
        ini = i;
        end = j;
      }
    }
  }
  return max;
}

/* funções Dividir e Conquistar ----------------- */

int subseqMaxMiddle(int *array, int start, int middle, int finish, int &ini,
                    int &end, long &count) {
  int maxL = 0, maxR = 0;
  int sumL = 0, sumR = 0;

  ini = end = middle;

  for (int i = middle - 1; i >= start; i--) {
    count++;
    sumL += array[i];
    if (sumL > maxL) {
      maxL = sumL;
      ini = i;
    }
  }

  for (int i = middle + 1; i <= finish; i++) {
    count++;
    sumR += array[i];
    if (sumR > maxR) {
      maxR = sumR;
      end = i;
    }
  }

  return maxL + maxR + array[middle];
}

// TODO PrÃ¡tica 11
// array:	o array sendo processado
// start:	posição a ser considerada início do array
// finish:	posição a ser considerada final do array
// ini:		(Resultado) deve conter ao final a posição de início da
// subsequência máxima
// end: 	(Resultado)	deve contar ao final a posição de final da
// subsequência máxima RETORNO:	soma da subsequência máxima
int __subseqMaxDC(int *array, int start, int finish, int &ini, int &end,
                  long &count) {
  if (start > finish)
    return -9999; // caso de retorno
  int iniPT1 = 0, fimPT1 = 0;
  int iniPT2 = 0, fimPT2 = 0;

  int iniMEIO = 0, endMEIO = 0;

  // count = 0;

  // Calcule a posiÃ§Ã£o central (middle)
  // O meio estÃ¡ entre start e finish
  int meio = (start + finish) / 2;

  // Chame a função recursivamente para as duas metades:
  // 	Lado esquerdo (start até middle -1) e Lado direito (middle + 1 até
  // finish)
  //  Para cada metade, devem ser retornados a soma da subseqmax, os os inicios
  //  (ini) e finais (end)
  //     Salve esses valores em variáveis temporárias adequadas para cada metade
  int subseqmaxPT1 =
      __subseqMaxDC(array, start, meio - 1, iniPT1, fimPT1, count);
  int subseqmaxPT2 =
      __subseqMaxDC(array, meio + 1, finish, iniPT2, fimPT2, count);

  // Use subseqMaxMiddle() para achar a sequência com soma máxima que passa no
  // meio do array (middle)
  int subseqmaxMeio =
      subseqMaxMiddle(array, start, meio, finish, iniMEIO, endMEIO, count);

  // 	Lembre de salvar o retorno (soma máxima) e limites da sequência (ini e end) em variáveis próprias
	// Identifique qual dos três cenários (esquerda, direita, meio) gerou a maior soma:
	// 	Esse valor será o retornado pelo função e vai determinar
	// 	quais limites serão salvo nos parâmetros ini e end da chamada atual
  int maxSum = subseqmaxMeio;
  if (subseqmaxPT1 > maxSum) {
    maxSum = subseqmaxPT1;
    ini = iniPT1;
    end = fimPT1;
  } else if (subseqmaxPT2 > maxSum) {
    maxSum = subseqmaxPT2;
    ini = iniPT2;
    end = fimPT2;
  } else if (subseqmaxMeio >= maxSum) {
    maxSum = subseqmaxMeio;
    ini = iniMEIO;
    end = endMEIO;
  }

  return maxSum; // corrigir com o retorno certo
}

int subseqMaxDC(int *array, int len, int &ini, int &end, long &count) {
  return __subseqMaxDC(array, 0, len - 1, ini, end, count);
}

/* ---------------- PRÃ�TICA 12 ----------------------------- */

/* funÃ§Ãµes versÃ£o Rercusiva ----------------- */

int seqMax(int *array, int pos, int &ini, long &count) {
  if (pos < 0)
    return 0;
  int sum, iniPrev;

  count++;
  int x = array[pos];
  int sumPrev = x + seqMax(array, pos - 1, iniPrev, count);

  if (x >= sumPrev) { // comeÃ§a nova sequencia
    sum = array[pos];
    ini = pos;
  } else { // continua sequencia anterior
    sum = sumPrev;
    ini = iniPrev;
  }

  return sum;
}

int subseqMaxRec(int *array, int len, int &ini, int &end, long &count) {
  int sum = -9999;
  ini = end = -1;

  for (int i = 0; i < len; i++) {
    int _ini, _sum;
    _sum = seqMax(array, i, _ini, count);

    if (_sum > sum) {
      sum = _sum;
      ini = _ini;
      end = i;
    }
  }

  return sum;
}

/* funÃ§Ãµes Memoization (Top-Down) ----------------- */

int seqMaxMemo(int *array, int pos, int &ini, int *SUM, int *INI, long &count) {
  // TODO PrÃ¡tica 12

  return 0;
}

int subseqMaxMemo(int *array, int len, int &ini, int &end, long &count) {
  // TODO PrÃ¡tica 12

  return 0;
}

/* funÃ§Ãµes ProgramaÃ§Ã£o DinÃ¢mica (Bottom-Up)---------- */

int subseqMaxPD(int *array, int len, int &ini, int &end, long &count) {
  // TODO PrÃ¡tica 12

  return 0;
}

/* -------------------------------------- */

void runSubseqMax(const char *name, int func(int *, int, int &, int &, long &),
                  int *array, int len, int printSeq) {
  long count = 0;

  int ini = 0, end = 0;

  auto start = std::chrono::high_resolution_clock::now();

  int max = func(array, len, ini, end, count);

  auto finish = std::chrono::high_resolution_clock::now();
  long elapsed =
      std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start)
          .count() /
      1000;

  cout << name << ": " << max << " ";

  if (printSeq) {
    cout << "[ ";
    print(array, ini, end);
    cout << "] ";
  }

  cout << "[time: " << elapsed << "us] ";
  cout << "[count: " << count << "]" << endl;
}

// int main_SUBSEQMAX() {
int main() {

  int printSeq = 1;
  int size = 38; // altera tamanho

  srand(12345);

  int *array = new int[size];

  for (int i = 0; i < 10; i++) {

    for (int i = 0; i < size; i++) {
      array[i] = (rand() % (2 * size)) - size;
    }
    cout << i << ": " << endl;
    print(array, size);

    runSubseqMax("Bruteforce     ", subseqMaxBF, array, size, printSeq);
    runSubseqMax("Divide&Conquer ", subseqMaxDC, array, size, printSeq);
    runSubseqMax("Recursive      ", subseqMaxRec, array, size, printSeq);
    runSubseqMax("Memoization    ", subseqMaxMemo, array, size, printSeq);
    runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, size, printSeq);
  }

  delete[] array;

  return 0;
}
