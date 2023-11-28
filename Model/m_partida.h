#pragma once
#include "m_tablero.h"
using namespace std;


class m_partida
{
public:
	m_partida() {};
	~m_partida() {};

	string Jugar();
	void CrearPlayers();
	vector<string> getPuntuacions(string combinacion);
	void ActualizaPuntuacion(string ganador);


private:
	m_tablero tablero;
	string player1;
	string player2;
	string puntos1;
	string puntos2;
};
