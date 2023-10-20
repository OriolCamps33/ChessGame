#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <vector>
#include <string>
using namespace std;

m_tablero::m_tablero(){
    m_peon peon = m_peon(); 
    tablero[0] = peon;    
};

vector<vector<int>> getMove(string move){  // combierte el movimiento de string a vector de posiciones
    char aux[2];
    move.copy(aux, 0, 2);
    string origen = aux; 

    int pDest = move.find(" ");
    move.copy(aux, pDest+1, 2);
    string destino = aux;
}


void m_tablero::mover(string move){ // funcion que permite mover las fichas segun un string
    
}
