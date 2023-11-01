#pragma once
#include <vector>
#include <string>
#include "../Model/m_pieza.h"
using namespace std;

#define numRow 8
#define numCol 7

class m_tablero
{
private:
    m_pieza*** tablero;
    m_pieza* reyBlanco;
    m_pieza* reyNegro;
public:
    m_tablero();
    m_tablero(vector<m_pieza*> piezas);
    ~m_tablero() {};

    void mover(string move);
    bool comprobarMove(string move, int jugador);
    bool isJaque(int player, int orgX, int orgY, int dstX, int dstY);
    void printaTablero(bool clean);
};
