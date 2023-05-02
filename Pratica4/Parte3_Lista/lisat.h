#include <stdexcept>
#include <iostream>

template <class T>
class Lista {
private:
    T* itens; // Ponteiro para array de itens da lista
    int capacidade; // Capacidade máxima da lista
    int tamanho; // Tamanho atual da lista

public:
    Lista(int capacidade) {
        this->capacidade = capacidade;
        this->tamanho = 0;
        this->itens = new T[capacidade];
    }

    ~Lista() {
        delete[] this->itens;
    }

    void adiciona(const T& item) {
        if (this->tamanho == this->capacidade) {
            throw ("Lista cheia");
        }
        this->itens[this->tamanho++] = item;
    }

    T pega(int idx) {
        if (idx < 1 || idx > this->tamanho) {
            throw "Item inválido";
        }
        return this->itens[idx - 1];
    }

    void insere(int idx, const T& item) {
        if (this->tamanho == this->capacidade) {
            throw std::overflow_error ("Lista cheia");
        }
        if (idx < 1 || idx > this->tamanho + 1) {
            throw ( "Item inválido");
        }
        for (int i = this->tamanho; i >= idx; i--) {
            this->itens[i] = this->itens[i - 1];
        }
        this->itens[idx - 1] = item;
        this->tamanho++;
    }

    void remove(int idx) {
        if (idx < 1 || idx > this->tamanho) {
           throw "Item inválido";
        }
        for (int i = idx - 1; i < this->tamanho - 1; i++) {
            this->itens[i] = this->itens[i + 1];
        }
        this->tamanho--;
    }

    void exibe() {
        for (int i = 0; i < this->tamanho; i++) {
            std::cout << this->itens[i] << " ";
        }
        std::cout << std::endl;
    }

    int getTamanho() {
        return this->tamanho;
    }
};