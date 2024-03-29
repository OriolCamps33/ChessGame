#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../Model/m_partida.h"
#include "../Model/m_tablero.h"
#include "../Model/m_partida.h"
using namespace std;

string m_partida::Jugar() {

	//variables que utilizaremos
	string ganador;
	bool movValido = false;
	int jugador = 1;

	m_tablero tablero = m_tablero(); //crear tablero + a�adir fichas

	//bucle principal
	while (true) {
		//couts tablero + nombre del jugador actual
		tablero.printaTablero(true);

		cout << endl << " " << player1 << " vs " << player2 << ": " << puntos1 << "-" << puntos2 << endl;

		if (jugador == 1)
			cout << endl << " Turno de " << player1 << endl;
		else
			cout << endl << " Turno de " << player2 << endl;

		// input movimiento
		string m1;
		string m2;

		string move;

		while (movValido == false) //bucle para que pida movimientos hasta hacer uno valido
		{
			cout << " Movimiento: ";
			cin >> m1 >> m2;
			move = m1 + " " + m2;

			//si el movimiento es -1 -1 se acaba el game (jaque mate)
			if (move == "-1 -1") {
				if ((jugador % 2) + 1 == 1) {
					ganador = player1;
				}
				else {
					ganador = player2;
				}
				goto fin;
			}

			//comprobamos que el movimiento no da error
			movValido = tablero.comprobarMove(move, jugador); //comprovamos si el movimiento es valido
		}

		//una vez fuera del bucle es que el movimiento es correcto, asi que se hace el movimiento actualizando las fichas
		tablero.mover(move); //movemos

		//cambiar jugador
		jugador = (jugador % 2) + 1;

		movValido = false;
	}
fin:
	cout << " El ganador es " << ganador << "!!!" << endl;
	return ganador;

}

void m_partida::CrearPlayers() {

	//preguntamos nombre jugadores
	cout << "Nombre jugador 1: ";
	cin >> player1;
	cout << "Nombre jugador 2: ";
	cin >> player2;

	string combinacion1 = player1 + " vs " + player2;
	string combinacion2 = player2 + " vs " + player1;

	//abrimos archivo y comprovamos que existe
	ifstream archivo("registro.txt");

	if (!archivo) {
		ofstream aux("registro.txt");
		cout << "Se ha creado el registro de partidas\n";
		aux.close();
		ifstream archivo("registro.txt");
	}

	//buscamos si los nombres ya estan en el txt
	string lineaArchivo;
	bool encontrado1 = false;
	bool encontrado2 = false;

	while (getline(archivo, lineaArchivo)) {

		if (lineaArchivo.find(combinacion1) != string::npos) {
			encontrado1 = true;
		}
		if (lineaArchivo.find(combinacion2) != string::npos) {
			encontrado2 = true;
		}
	}
	archivo.close();

	ofstream archivo2("registro.txt", ios::app);

	//si los nombres no estan los a�adimos
	if (!encontrado1 && !encontrado2) {
		archivo2 << combinacion1 + " 0 - 0" << endl;
		puntos1 = "0";
		puntos2 = "0";
	}

	if (encontrado1) {
		vector<string> puntos = getPuntuacions(combinacion1);
		puntos1 = puntos[0];
		puntos2 = puntos[1];
	}
	else if(encontrado2)
	{
		vector<string> puntos = getPuntuacions(combinacion2);
		puntos1 = puntos[0];
		puntos2 = puntos[1];

	}

	archivo2.close();

}

vector<string> m_partida::getPuntuacions(string combinacion)
{
	string lineaArchivo;
	ifstream archivoIn("registro.txt");

	if (!archivoIn) {
		cout << "Error al abrir el registro.txt\n";
		exit(EXIT_FAILURE);
	}
	
	vector<string> punts;

	while (getline(archivoIn, lineaArchivo)) {
		if (lineaArchivo.find(combinacion) != string::npos) {
			int longitud = combinacion.length() + 1; //sacamos longitud y sumamos 1 para eliminar el espacio en blanco
			string puntos = lineaArchivo.erase(0, longitud);

			size_t posicion = puntos.find('-'); //buscamos la posicion del guion
			string primerNum = puntos.substr(0, posicion); //sacamos el primer numero y despues el segundo
			string segundoNum = puntos.substr(posicion + 1);
			punts.push_back(primerNum);
			punts.push_back(segundoNum);
		}
	}
	return punts;
}


void m_partida::ActualizaPuntuacion(string winner) {

	//miramos que jugador ha ganado
	int ganador;
	if (winner == player1)
		ganador = 1;
	else
		ganador = 2;

	string combinacion1 = player1 + " vs " + player2;
	string combinacion2 = player2 + " vs " + player1;

	//abrimos archivo y comprovamos que existe
	ifstream archivoIn("registro.txt");

	if (!archivoIn) {
		cout << "Error al abrir el registro.txt\n";
		exit(EXIT_FAILURE);
	}

	ofstream archivoOut("copiaRegistro.txt");

	if (!archivoOut) {
		cout << "Error al abrir el registro.txt\n";
		exit(EXIT_FAILURE);
	}


	//buscamos los nombres en el txt
	string lineaArchivo;
	string nuevaLinea;

	while (getline(archivoIn, lineaArchivo)) {

		//si es la linea
		if (lineaArchivo.find(combinacion1) != string::npos) {

			int longitud = combinacion1.length() + 1; //sacamos longitud y sumamos 1 para eliminar el espacio en blanco
			string puntos = lineaArchivo.erase(0, longitud);

			size_t posicion = puntos.find('-'); //buscamos la posicion del guion
			string primerNum = puntos.substr(0, posicion); //sacamos el primer numero y despues el segundo
			string segundoNum = puntos.substr(posicion + 1);

			int numero1, numero2;

			istringstream(primerNum) >> numero1; //pasamos los numero a int
			istringstream(segundoNum) >> numero2;

			//augmentamos el que queremos
			if (ganador == 1)
				numero1 += 1;
			else
				numero2 += 1;

			//montamos el string
			string puntosFinales = " " + to_string(numero1) + " - " + to_string(numero2);

			nuevaLinea = combinacion1 + puntosFinales;
			archivoOut << nuevaLinea << endl;
		}
		else if (lineaArchivo.find(combinacion2) != string::npos) {

			int longitud = combinacion1.length() + 1; //sacamos longitud y sumamos 1 para eliminar el espacio en blanco
			string puntos = lineaArchivo.erase(0, longitud);

			size_t posicion = puntos.find('-'); //buscamos la posicion del guion
			string primerNum = puntos.substr(0, posicion); //sacamos el primer numero y despues el segundo
			string segundoNum = puntos.substr(posicion + 1);

			int numero1, numero2;

			istringstream(primerNum) >> numero1; //pasamos los numero a int
			istringstream(segundoNum) >> numero2;

			//augmentamos el que queremos
			if (ganador == 1)
				numero2 += 1;
			else
				numero1 += 1;

			//montamos el string
			string puntosFinales = " " + to_string(numero1) + " - " + to_string(numero2);

			nuevaLinea = combinacion2 + puntosFinales;
			archivoOut << nuevaLinea << endl;
		}
		else
		{
			archivoOut << lineaArchivo << endl;
		}

	}
	archivoIn.close();
	archivoOut.close();


	remove("registro.txt");

	rename("copiaRegistro.txt", "registro.txt");

}
