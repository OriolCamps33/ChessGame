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
    m_pieza* reyBlanco;
    m_pieza* reyNegro;
public:
    m_tablero();
    m_tablero(vector<m_pieza*> piezas);
    ~m_tablero() {};

    void mover(string move);
    vector<vector<int>> getMove(string move, bool &result);
    bool comprobarMove(string move, int jugador);
    bool isJaque(int player, int orgX, int orgY, int dstX, int dstY);
    void printaTablero(bool clean);
    bool excepcionesPeon(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza);
    bool excepcionesAlfil(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza);
    bool excepcionesTorre(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza);
};
