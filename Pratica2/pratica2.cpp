/*
 * pratica2.cpp
 *
 *  Created on: 30 de mar. de 2023
 *      Author: agued
 */

#include<iostream>
#include <string>
using namespace std;
#include "veiculo.h"

int main() {

	/*
	 Veiculo * v1 = new Veiculo("carro");
	 ((Veiculo *)v1)->mover() ;

	 Veiculo * a1 = new Aquatico("aquatico");
	 ((Aquatico *)a1)->mover() ;


	 Veiculo * terr;
	 terr = new Terrestre("terr");
	 terr->mover();

	 cout << endl;
	 Veiculo * aqua;
	 aqua = new Aquatico("barco");
	 aqua->mover();

	 delete terr;
	 delete aqua;
	 */

	/*
	 Veiculo *terr = new Terrestre("carro");
	 terr->getNome();

	 delete terr;

	 Veiculo *aqua = new Aquatico("barco");
	 aqua->mover();

	 delete aqua;

	 Veiculo *aereo = new Aereo("aviao");
	 aereo->getNome();

	 delete aereo;
	 */

	/*
	 Veiculo *terr = new Terrestre("VT1");
	 ((Terrestre*) terr)->setCapPass(45);

	 Veiculo *aqua = new Aquatico("VQ1");
	 ((Aquatico*) aqua)->getCargaMax(12.5);

	 Veiculo *aereo = new Aereo("VA1");
	 ((Aereo*) aereo)->setVelMax(1040.5);
	 */


	 // Criando uma instância de Anfibio usando new
	 Veiculo *anfi = new Anfibio("Sapo");
	 anfi-> mover();
	 delete anfi;


	Veiculo *terr = new Terrestre("VT1");
	dynamic_cast<Terrestre*>(terr)->setCapPass(45);
	terr->mover();

	Veiculo *aqua = new Aquatico("VQ1");
	dynamic_cast<Aquatico*>(aqua)->setCargaMax(12.5);
	aqua->mover();

	Veiculo *aereo = new Aereo("VA1");
	dynamic_cast<Aereo*>(aereo)->setVelMax(1040.5);
	aereo->mover();


	delete terr;
	delete aqua;
	delete aereo;


	return 0;

}
