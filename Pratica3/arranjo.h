#ifndef ARRANJO_H_
#define ARRANJO_H_

#include <iostream>
#include <stdexcept>

class IndiceInvalido: public std::exception {
public:
	virtual const char* what() const throw () {
		return "Indice fora do limite do arranjo!";
	}
};

template<class T>
class Arranjo {
private:
	int tamanho; // tamanho do arranjo
	T *items; //items do arranjo

public:
	Arranjo(int tam) {
		tamanho = tam;
		items = new T[tam]; // instanciar o array de items com new (pratica 1) e setar tamanho;
	}
	virtual ~Arranjo() {
		delete[] items; // destruir o array de items (prática 1);
	}

	virtual T get(int idx) {
		if (idx < 0 || idx >= tamanho) {
			throw IndiceInvalido();
		}
		return items[idx]; // retornar um item do array a partir do indice;
	}

	virtual void set(int idx, const T &item) {
		if (idx < 0 || idx >= tamanho) {
			throw IndiceInvalido();
		}
		items[idx] = item; // set o item do array apontado pelo indice usando =
	}

	virtual void exibir() {
		for (int i = 0; i < tamanho; i++) {
			std::cout << i << ": " << items[i] << std::endl; // exibir cada item numa linha da forma "<idx>: <item>"
		}
	}
};

#endif /* ARRANJO_H_ */
