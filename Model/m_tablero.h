#pragma once
#include <vector>
#include <string>
#include "../Model/m_pieza.h"
using namespace std;

#define numRow 5
#define numCol 5

class m_tablero
{
private:
    m_pieza*** tablero;

public:
    m_tablero();
    ~m_tablero() {};

    void mover(string move);
    bool comprobarMove(string move);
    void printaTablero();
};


