#include <iostream>
#include "Model/m_test.h"
#include "Model/m_tablero.h"
#include "Model/m_partida.h"
using namespace std;


int main(int argc, char const* argv[])
{
	m_tablero tab;
	tab.printaTablero(true);


	m_partida partida = m_partida();

	// partida.Jugar();

	bool winner = false;

	//testAll();
}
