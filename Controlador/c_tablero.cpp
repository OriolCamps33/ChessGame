#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

m_tablero::m_tablero(){
    // Creamos el espacio necessario para el tablero
    tablero = new m_pieza**[numRow];

    for (int i = 0; i < numRow; i++) {
        tablero[i] = new m_pieza*[numCol];
    }

    for (int i = 0; i < numRow; i++)
    {
        for (int j = 0; j < numCol; j++) {
            tablero[i][j] = new m_pieza;
        }
    }

    // inicializamos todas las piezas
    m_peon* peon1 = new m_peon(0, 0, 1, "PB");
    m_peon* peon2 = new m_peon(0, 1, 1, "PB");
    m_peon* peon3 = new m_peon(0, 2, 1, "PB");
    m_peon* peon4 = new m_peon(1, 0, 1, "PB");

    tablero[peon1->getRow()][peon1->getCol()] = peon1;
    tablero[peon2->getRow()][peon2->getCol()] = peon2;
    tablero[peon3->getRow()][peon3->getCol()] = peon3;
    tablero[peon4->getRow()][peon4->getCol()] = peon4;
}

vector<vector<int>> getMove(string move) {  // combierte el movimiento de string a vector de posiciones
    // Parametros para passar de str a int
    int letras = 97;
    int nums = 49;

    // separacion del movimiento origen y posterior guardado en vector
    string origen;
    origen.assign(move, 0, 2);
    vector<int> org;
    org.push_back(int(origen[1]) - nums);
    org.push_back(int(origen[0]) - letras);
                                   
    // Busqueda de separador       
    int pDest = move.find(" ");

    // separacion del movimiento destino y posterior guardado en vector
    string destino;
    destino.assign(move, pDest + 1, 2);
    vector<int> dst;
    dst.push_back(int(destino[1]) - nums);
    dst.push_back(int(destino[0]) - letras);

    // return del vector final
    vector<vector<int>> mov;
    mov.push_back(org);
    mov.push_back(dst);
    return mov;
}

bool m_tablero::mover(string move) { // funcion que permite mover las fichas segun un string
    // passamos coordenadas de string a ints
    vector<vector<int>> mov = getMove(move);
    int orgX = mov[0][0];
    int orgY = mov[0][1];
    int dstX = mov[1][0];
    int dstY = mov[1][1];

    m_pieza* pieza = tablero[orgX][orgY];

    if (pieza->getIcono() == "-1") {
        cout << "No hay ninguna pieza en la casilla de origen" << endl;
        return false;
    }
    
    if (pieza->canMove(dstX, dstY)) {
        pieza->setCol(dstY);
        pieza->setRow(dstX);
        tablero[dstX][dstY] = pieza;
        tablero[orgX][orgY] = new m_pieza();
    }
    else {
        cout << "Movimiento no valido" << endl;
    }
}


