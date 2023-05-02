/*
 * veiculo.h
 *
 *  Created on: 18 de mar. de 2023
 *      Author: agued
 *		DECLARAÇÕES
 */

#ifndef VEICULO_H_
#define VEICULO_H_

#include<iostream>
#include <string>
using namespace std;

//Classe Roda
class Roda {
public:
	Roda(); // Construtor padrão
	~Roda(); // Destrutor padrão
};

//Classe Veiculo
class Veiculo {

private:
	string nome;
	int num_rodas;
	Roda *rodas; // Ponteiro para array dinâmico de rodas

public:
	//Construtor
	Veiculo(const char *nome);

	//Destrutor
	~Veiculo();

	//Metodo para pegar o nome
	string getNome() const;

	//Pt.4 -Declaração da assinatura do método para obter o numero de rodas
	int getNumRodas();

	//Pt.4 Declaração da assinatura do metodo para setar o numero de rodas
	void setNumRodas(int numero);
};

#endif /* VEICULO_H_ */
