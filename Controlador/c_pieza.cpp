#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <assert.h>
#define NDEBUG 
#include <vector>
#include <string>
using namespace std;

//PEON
bool m_peon::validMove(int dstX, int dstY)
{
    // posiciones dentro del tablero
    assert(dstX < numRow && dstX >= 0);
    assert(dstY < numCol && dstY >= 0);

    int actRow = getRow();
    int actCol = getCol();

    // no hay cambio de columna
    assert(actCol == dstY);

    if (getColor() == 1) {
        if (actRow < dstX) {
            if((actRow + 1) == dstX)
                return true;
            else if ((actRow+ 2) == dstX && firstMove)
                return true;        
        }
        return false;
    }
    else {
        if (actRow > dstX) {
            if ((actRow - 1) == dstX)
                return true;
            else if ((actRow - 2) == dstX && firstMove)
                return true;
        }
        return false;
    }
}


//TORRE
bool m_torre::validMove(int dstX, int dstY)
{

    // posiciones dentro del tablero
    assert(dstX < numRow&& dstX >= 0);
    assert(dstY < numCol&& dstY >= 0);

    int actRow = getRow();
    int actCol = getCol();

    //si la fila y columna han cambiado es que no se ha movido ni horizontal ni verticalmente, sino una combinación
    if (actRow != dstX && actCol != dstY)
    {
        return false;
    }
    else
        return true;
}

//ALFIL
bool m_alfil::validMove(int dstX, int dstY)
{
    // posiciones dentro del tablero
    assert(dstX < numRow&& dstX >= 0);
    assert(dstY < numCol&& dstY >= 0);

    int actRow = getRow();
    int actCol = getCol();

    //si se cumple esto esta haciendo diagonal, se ve con un dibujito :)
    if (abs(actRow - dstX) == abs(actCol - dstY)) { 
        return true;
    }
    else
        return false;
}

//CABALLO
bool m_caballo::validMove(int dstX, int dstY)
{
    // posiciones dentro del tablero
    assert(dstX < numRow&& dstX >= 0);
    assert(dstY < numCol&& dstY >= 0);

    int actRow = getRow();
    int actCol = getCol();

    //si se cumple esto esta haciendo diagonal, se ve con un dibujito :)
    if (abs(actRow - dstX) == 1 && abs(actCol - dstY) == 2) {
        return true;
    }
    else if (abs(actCol - dstY) == 1 && abs(actRow - dstX) == 2) {
        return true;
    }
    else
        return false;
}


// REY
bool m_rey::validMove(int dstX, int dstY)
{
    // posiciones dentro del tablero
    assert(dstX < numRow && dstX >= 0);
    assert(dstY < numCol && dstY >= 0);

    int actRow = getRow();
    int actCol = getCol();

    //si se cumple esto esta haciendo diagonal, se ve con un dibujito :)
    if (abs(actRow - dstX) == 1 && abs(actCol - dstY) == 1) 
        return true;
    else
        return false;
}