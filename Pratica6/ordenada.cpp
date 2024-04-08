#include <iostream>

using namespace std;

class ListaOrdenada {
private:
	int * items;
	int tamanho, capacidade;
public:
	ListaOrdenada(int cap) {
		this->capacidade = cap;
		this->tamanho = 0;
		items = new int[cap];
	}

	~ListaOrdenada() {
		delete [] items;
	}

	void insere(int item) {
		 int pos = tamanho;

    while (pos > 0 && items[pos-1] > item) {
        items[pos] = items[pos-1];
        pos--;
    }
    items[pos] = item;
    tamanho++;
	}

	void remove(int item) {
		 int pos = buscaBinaria(item);
    if (pos == -1) {
        throw "Elemento não encontrado.";
    }
    for (int i = pos; i < tamanho-1; i++) {
        items[i] = items[i+1];
    }
    tamanho--;
	}

	int buscaSequencial(int key)  {
    for (int i = 0; i < tamanho; i++) {
        if (items[i] == key) {
            return i;
        } else if (items[i] > key) {
            break;
        }
    }
    return -1;
}

	int buscaBinaria(int item) {
		return buscaBinaria(0, tamanho - 1, item);
	}

	int valida() {
		for (int i = 0; i < tamanho - 1; i++) {
			if (items[i] > items[i + 1]) return 0;
		}
		return 1;
	}

	void exibe() {
		for (int i = 0; i < tamanho; i++) {
			cout << i << ": " << items[i] << "; ";
		}
		cout << endl;
	}

	int getTamanho() {
		return tamanho;
	}

private:

	int buscaBinaria(int inicio, int final, int item) {
    if (final < inicio) {
        return -1;
    }
    int meio = (inicio + final) / 2;
    if (items[meio] == item) {
        return meio;
    } else if (items[meio] > item) {
        return buscaBinaria(inicio, meio-1, item);
    } else {
        return buscaBinaria(meio+1, final, item);
    }
}
};


int mainO() {

	ListaOrdenada lista(10);

	int elementos [] = {10, 5, 25, 1, 64, 13, 50, 99, 33, 12};

	cout << "Testando inserção ..." << endl;
	for (int i = 0; i < 10; i++) {
		lista.insere(elementos[i]);
	}

	cout << "Lista: ";
	lista.exibe();

	if (lista.getTamanho() == 10) {
		cout << "Tamanho OK." << endl;
	} else {
		cout << "ERRO: Tamanho errado (!= 10): " << lista.getTamanho() << endl;
		exit(1);
	}

	if (lista.valida()) {
		cout << "Lista está ordenada." << endl;
	} else {
		cout << "ERRO: Lista não está ordenada." << endl;
		exit(1);
	}

	cout << endl << "Testando remoção..." << endl;
	try {
		lista.remove(5);
		lista.remove(50);
		lista.remove(33);
		lista.remove(-100); // erro
		cout << "ERRO: Exceção não lançada na remoção. Abortando." << endl;
		exit(1);
	} catch (...) {
		cout << "Exceção lançada na remoção." << endl;
	}

	cout << "Lista: ";
	lista.exibe();

	if (lista.getTamanho() == 7) {
		cout << "Tamanho OK." << endl;
	} else {
		cout << "ERRO: Tamanho errado (!= 7): " << lista.getTamanho() << endl;
		exit(1);
	}

	if (lista.valida()) {
		cout << "Lista está ordenada." << endl;
	} else {
		cout << "ERRO: Lista não está ordenada." << endl;
		exit(1);
	}

	cout << endl << "Testando buscas..." << endl;

	cout << "- Itens presentes: ";

	int bs10 = lista.buscaSequencial(10);
	int bb10 = lista.buscaBinaria(10);

	int bs25 = lista.buscaSequencial(25);
	int bb25 = lista.buscaBinaria(25);

	if ((bs10 == 1) && (bb10 == 1) && (bs25 == 4) && (bb25 == 4)) {
		cout << "OK" << endl;
	} else {
		cout << "ERRO" << endl;
		exit (1);
	}

	cout << "- Itens ausentes: ";

	int bs20 = lista.buscaSequencial(20);
	int bb20 = lista.buscaBinaria(20);

	int bs77 = lista.buscaSequencial(77);
	int bb77 = lista.buscaBinaria(77);

	if ((bs20 == -1) && (bb20 == -1) && (bs77 == -1) && (bb77 == -1)) {
		cout << "OK" << endl;
	} else {
		cout << "ERRO" << endl;
		exit (1);
	}

	cout << "- Itens removidos: ";

	int bs5 = lista.buscaSequencial(5);
	int bb5 = lista.buscaBinaria(5);

	int bs33 = lista.buscaSequencial(33);
	int bb33 = lista.buscaBinaria(33);

	if ((bs5 == -1) && (bb5 == -1) && (bs33 == -1) && (bb33 == -1)) {
		cout << "OK" << endl;
	} else {
		cout << "ERRO" << endl;
		exit (1);
	}

	return 0;
}