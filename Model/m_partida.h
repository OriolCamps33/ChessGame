#pragma once
#include "m_tablero.h"
using namespace std;


class m_partida
{
public:
	m_partida(){};
	~m_partida(){};

	void Jugar();
	

private:
	m_tablero tablero;
	
};

