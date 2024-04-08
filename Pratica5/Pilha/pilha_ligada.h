#ifndef _PILHALIGADA_
#define _PILHALIGADA_
#include <iostream>
using namespace std;
#include "pilha.h"
template <class T> class PilhaLigada: public Pilha<T> {
private:
  class No {
  public:
   // T *item;
    T item;
    No *proximo;
  };
  No *topo;
  int capacidade;
  int quantidade_itens;
public:
  PilhaLigada(int capacidade) {
    topo = nullptr;
    this->capacidade = capacidade;
    this->quantidade_itens = 0;
  }
  ~PilhaLigada() {
    No *atual = topo;
    while (atual != nullptr) {
      No *proximo = atual->proximo;
      delete atual;
      atual = proximo;
    }
  }
  
  void empilha(T item) {
    if (this->quantidade_itens == capacidade) {
      throw "Pilha cheia";
    } else {
      No* criado = new No();
      criado->item = item;
      //criado->item = new T(item);
      criado->proximo = topo;
      topo = criado;
      quantidade_itens++;
    }
  }
  T desempilha() {
    if(topo==nullptr){
      throw "Lista vazia";
    }
    T item = topo->item;
    //T item = (*topo->item);
    No* topo_descartado = topo;
    topo=topo->proximo;
    delete topo_descartado;
    quantidade_itens--;
    return item;
    
  }
  int tamanho() { 
    return quantidade_itens; 
  }
};

#endif