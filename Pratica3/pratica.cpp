/*
 * pratica.cpp
 *
 *  Created on: 1 de abr. de 2023
 *      Author: agued
 */
#include <iostream>
#include "funcoes.h"
#include "arranjo.h"
#include "aluno.h"
using namespace funcoes;
using namespace std;

int main() {
	 int x = 5, y = 10, z = 30;

	 cout << "Antes: x = " << x << " y = " << y << endl;
	 trocar(x, y);
	 cout << "Depois: x = " << x << " y = " << y << endl;
	 cout << "Minimo entre " << x << " e " << y << ": " << minimo(x, y) << endl;
	 cout << "Maximo entre " << y << " e " << z << ": " << maximo(y, z) << endl;


	 using namespace funcoes;
	 cout << "Minimo de \"strA\" e \"strB\": " << minimo("strA", "strB") << endl;
	 cout << "Maximo de \"strA\" e \"strB\": " << maximo("strA", "strB") << endl;



	 Arranjo<int> arr(10);
	 arr.set(4, 5);
	 arr.set(7, 15);
	 arr.set(8, 22);
	 arr.exibir();



	 Arranjo<float>cole(5);
	 cole.set(0,0.25);
	 cole.set(1,0.50);
	 cole.set(2,1.00);
	 cole.set(3,1.50);
	 cole.set(4,2.00);
	 cole.exibir();

	 try {
	 float valor = cole.get(11); //acesso fora do array
	 std::cout << "Valor: " << valor << std::endl;
	 }
	 catch (IndiceInvalido& e) {
	 std::cerr << "Erro: " << e.what() << std::endl;
	 }

	Arranjo<Aluno> turma(3);
	turma.set(0, Aluno("Joao", "1234"));
	turma.set(1, Aluno("Maria", "5235"));
	turma.set(2, Aluno("Jose", "2412"));
	turma.exibir();

	return 0;
}
