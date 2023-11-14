#include <iostream>
#include <windows.h>
#include "Model/m_test.h"
#include "Model/m_tablero.h"
#include "Model/m_partida.h"
using namespace std;

#define color SetConsoleTextAttribute

int main(int argc, char const* argv[])
{
	/*
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 1; i < 243; i++) {
		color(hConsole, i);
		cout << i << " - Hola Mundo!!" << endl;
	}
	

	m_partida partida = m_partida();

	partida.Jugar();

	bool winner = false;
	*/

	testJaque();

}
