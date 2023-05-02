/*
 * veiculo.cpp
 *
 *			IMPLEMENTAÇÕES
 */

#include<iostream>
#include <string>
#include "veiculo.h"
using namespace std;

//Construtor e Destrutor Veiculo
Veiculo::Veiculo(const char *nome) {
	this->nome = std::string(nome);
	std::cout << "Novo objeto chamado " << this->nome << " foi construído."
			<< endl;
}

/*
 Veiculo::~Veiculo(){
 std::cout<< "Veiculo " <<getNome()<< " foi destruido " <<  endl;
 };
 */

//Destrutor virtual
Veiculo::~Veiculo() {
	//std::cout<< "Veiculo " <<getNome()<< " foi destruido " <<  endl;
}

//Metodo para pegar o nome
string Veiculo::getNome() const {
	return nome;
}

/*

 //Implementação do metodo mover Veiculo
 void Veiculo::mover(){
 std::cout << "Veiculo  " << this->nome << " foi movido." << endl;
 }

 */

//Construtor e Destrutor Aquatico
Aquatico::Aquatico(const char *nome) :
		Veiculo(nome) {
	this->carga_max = 10;
}

Aquatico::~Aquatico() {
	cout << "O veiculo aquatico foi destruido" << endl;

}

//Mover - Aquatico
void Aquatico::mover() {
	std::cout << "Veiculo aquatico " << this->nome << " foi movido." << endl;

}

//Construtor e Destrutor Terrestre
Terrestre::Terrestre(const char *nome) :
		Veiculo(nome) {
	this->cap_pass = 5;
}

Terrestre::~Terrestre() {
	cout << "O veiculo terrestre foi destruido" << endl;
}

//Mover - Terrestre
void Terrestre::mover() {
	std::cout << "Veiculo terrestre " << this->nome << " foi movido." << endl;

}

//Construtor e Destrutor Aereo
Aereo::Aereo(const char *nome) :
		Veiculo(nome) {
	this->vel_max = 100;
}

Aereo::~Aereo() {
	cout << "O veiculo aereo foi destruido" << endl;
}

//Mover - Aereo
void Aereo::mover() {
	std::cout << "Veiculo aereo " << this->nome << " foi movido." << endl;

}

//Metodos get e set
//Aquatico
float Aquatico::getCargaMax() const {
	return carga_max;
}

void Aquatico::setCargaMax(float cargaMax) {
	carga_max = cargaMax;
}

//Terrestre

int Terrestre::getCapPass() const {
	return cap_pass;
}

void Terrestre::setCapPass(int capPass) {
	cap_pass = capPass;
}

//Aereo

float Aereo::getVelMax() const {
	return vel_max;
}

void Aereo::setVelMax(float velMax) {
	vel_max = velMax;
}

//construtores sem parametro
Aquatico::Aquatico() :
		Veiculo(0) {
	this->carga_max = 10;
}

Terrestre::Terrestre() :
		Veiculo(0) {
	this->cap_pass = 5;
}
