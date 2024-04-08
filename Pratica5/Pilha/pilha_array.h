#ifndef _PILHAARRAY_
#define _PILHAARRAY_
#include <iostream>
using namespace std;
#include "pilha.h"

template <class T> class PilhaArray: public Pilha<T> {
private:
  // Atributos para array de items, capacidade e topo da pilha
  int capacidade;
  int topo;
  T *itens;

public:
  PilhaArray(int capacidade) {
    // instancia array de items, inicializa capacidade e topo
    this->capacidade = capacidade;
    this->itens = new T[capacidade];
    this->topo = -1; //inicializa o topo como -1 para que a posição 0 seja preenchida
  }
  ~PilhaArray() {
    delete[] itens;
    // destroy array de items
  }
  void empilha(T item) override {
    // empilha um item no topo da pilha; lança “Estouro da pilha” se cheia

    if (topo < capacidade -1) {
      topo++;
      this->itens[topo] = item;
    } else {
      throw "Estouro da pilha";
    }
  }
  T desempilha()override {
    // remove um item do topo da pilha; lança “Pilha vazia” se vazia
    if(topo==-1){
      throw "Pilha vazia";
    }
    else{
     T itemRetirado = this->itens[topo];
      topo--;
      return itemRetirado;
    }
  }
  int tamanho()override {
    // retorna o número de elementos na pilha.
    return topo+1;
  }
};

#endif