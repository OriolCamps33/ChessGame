#include <iostream>
#include "../Model/m_partida.h"
#include "../Model/m_tablero.h"
#include "../Model/m_partida.h"
using namespace std;

void m_partida::Jugar() {

	bool winner = false;
	bool movValido = false;
	int jugador = 1;

	m_tablero tablero = m_tablero(); //crear tablero + añadir fichas

	while (winner == false) {

		cout << endl << "Turno del jugador: " << jugador << endl;

		tablero.printaTablero(false);

		// input movimiento
		string m1;
		string m2;

		while (movValido == false) //bucle para que pida movimientos hasta hacer uno valido
		{
			cin >> m1 >> m2;
			string move = m1 + " " + m2;

			movValido = tablero.comprobarMove(move, jugador); //comprovamos si el movimiento es valido

			if(movValido == true)
				tablero.mover(move); //movemos
		}

		// jugador mueve
			//comprueba movimiento
			//mueve fichas
			//comprueba jaque

		//si no puede mover: fin

		//actualizar tablero

		//cambiar jugador
		if (jugador == 1)
			jugador = 2;
		else
			jugador = 1;

		movValido = false;
	}

}