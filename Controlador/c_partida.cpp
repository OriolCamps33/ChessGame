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
		tablero.printaTablero(false);

		cout << endl << "Turno del jugador: " << jugador << endl;
		// input movimiento
		string m1;
		string m2;

		string move;

		while (movValido == false) //bucle para que pida movimientos hasta hacer uno valido
		{
			cin >> m1 >> m2;
			move = m1 + " " + m2;

			movValido = tablero.comprobarMove(move, jugador); //comprovamos si el movimiento es valido				
		}

		tablero.mover(move); //movemos

		if (tablero.isJaque(jugador)) {
			isJaque = true;
		}

		//si no puede mover: fin

		//actualizar tablero
		 
		//cambiar jugador
		jugador = (jugador % 2) + 1;

		movValido = false;
	}

}