#include <iostream>
#include <windows.h>
#include "Model/m_test.h"
#include "Model/m_tablero.h"
#include "Model/m_partida.h"
using namespace std;

#define color SetConsoleTextAttribute


int main(int argc, char const* argv[])
{
	m_partida partida = m_partida();

	partida.CrearPlayers();

	string ganador = partida.Jugar();

	partida.ActualizaPuntuacion(ganador);

	//testAll();

}
