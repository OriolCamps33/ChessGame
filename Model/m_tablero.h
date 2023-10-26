#pragma once
#include <vector>
#include <string>
#include "../Model/m_pieza.h"
using namespace std;

#define numRow 8
#define numCol 8

class m_tablero
{
private:
    m_pieza*** tablero;

public:
    m_tablero();
    m_tablero(vector<m_pieza*> piezas);
    ~m_tablero() {};

    void mover(string move);
    bool comprobarMove(string move, int jugador);
    void printaTablero(bool clean);
};


