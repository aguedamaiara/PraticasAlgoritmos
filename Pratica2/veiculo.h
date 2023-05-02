/*
 * veiculo.h
 *
 *
 * 			DECLARAÇÕES
 */

#ifndef VEICULO_H_
#define VEICULO_H_

#include<iostream>
#include <string>
using namespace std;

class Veiculo {

protected:
	string nome;

public:
	//Construtor
	Veiculo(const char *nome);

	/*//Destrutor
	 ~Veiculo();*/

	virtual ~Veiculo();

	//Metodo para pegar o nome
	string getNome() const;

	/*//Metodo mover
	 virtual void mover();
	 */
	virtual void mover() = 0;
};

class Aquatico: public virtual Veiculo {
public:
	Aquatico(const char *nome);
	~Aquatico();

	//Métodos  get() e set
	float getCargaMax() const;

	void setCargaMax(float cargaMax);

	//Metodo Mover
	void mover();

private:
	float carga_max;

protected:
	Aquatico();

};

class Terrestre: public virtual Veiculo {
public:
	Terrestre(const char *nome);
	~Terrestre();

	//Métodos  get() e set
	int getCapPass() const;

	void setCapPass(int capPass);

	void mover();

private:
	int cap_pass;

protected:
	Terrestre();

};

class Aereo: public Veiculo {
public:
	Aereo(const char *nome);
	~Aereo();

	//Métodos  get() e set
	float getVelMax() const;

	void setVelMax(float velMax);

	void mover();

private:
	float vel_max;
};

class Anfibio: public Terrestre, public Aquatico {
public:

	Anfibio(const char *nome) :
			Veiculo(nome), Terrestre(), Aquatico() {
	}

	void mover() override {
		Terrestre::mover();
		Aquatico::mover();
	}

};

#endif /* VEICULO_H_ */
