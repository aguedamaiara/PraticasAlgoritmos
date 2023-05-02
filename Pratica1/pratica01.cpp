/*
 * pratica01.cpp
 *
 *  Created on: 15 de mar. de 2023
 *      Author: agued
 */

#include<iostream>
#include <string>
#include "veiculo.h"
using namespace std;

int main() {
	/*
	 //Codigo da Parte 1 - Preparação inicial
	 cout<< "Primeira aplicação C++" << endl;

	 */

	/*
	 //Continuação da parte 2 - Passo 5 adicionando o codigo com os escopos

	 {
	 Veiculo veiculo1("v1");


	 {
	 Veiculo veiculo2("v2");

	 {

	 Veiculo veiculo3("v3");


	 }
	 }
	 }

	 return 0;  */

	//Construtores

	//Objetos declarados como ponteiros e instanciados com o operador new
	Veiculo *obj1 = new Veiculo("v1");
	obj1->setNumRodas(4);
	obj1->setNumRodas(4);

	//Obtendo o número de rodas dos veículos
	std::cout << "Numero de rodas do " << obj1->getNome() << obj1->getNumRodas()
			<< endl;

	//Objeto destruido
	delete obj1;


	return 0;
}
