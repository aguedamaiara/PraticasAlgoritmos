/*
 * veiculo.cpp
 *
 *  Created on: 18 de mar. de 2023
 *      Author: agued
 *
 *			IMPLEMENTAÇÕES
 */

#include<iostream>
#include <string>
#include "veiculo.h"
using namespace std;

// Implementação do construtor da classe Roda
Roda::Roda() {
	std::cout << "Uma nova roda foi construída!" << std::endl;
}

// Implementação do destrutor da classe Roda
Roda::~Roda() {
	std::cout << "Uma roda foi destruída!" << std::endl;
}

//Construtor
Veiculo::Veiculo(const char *nome) {
	this->nome = std::string(nome);
	std::cout << "Novo objeto chamado " << this->nome << " foi construído."
			<< endl;
	this->num_rodas = 0;
	this->rodas = NULL;
}

//Destrutor
Veiculo::~Veiculo() {
	std::cout << "Veiculo " << getNome() << " foi destruido " << endl;
	delete[] this->rodas;
}
;

//Metodo para pegar o nome
string Veiculo::getNome() const {
	return nome;
}

//Pt.4 -Implementação do Metodo para obter o numero de rodas FORA DA CLASSE
int Veiculo::getNumRodas() {
	return num_rodas;
}

//Pt.4 -Implementação do Metodo para setar o numero de rodas FORA DA CLASSE
void Veiculo::setNumRodas(int numero) {
	this->num_rodas = numero;
	delete[] rodas; // Libera a memória alocada anteriormente
	rodas = new Roda[num_rodas]; // Aloca um novo array dinâmico
}
