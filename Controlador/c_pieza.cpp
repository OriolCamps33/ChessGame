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

    int actRow = getRow();
    int actCol = getCol();


    if (getColor() == 1) {
        //movimiento recto + movimiento doble inicial + diagonal (para matar)
        if (dstX - actRow == 1 && (dstY == actCol || abs(dstY - actCol) == 1))
            return true;
        else if (dstX - actRow == 2 && actRow == 1 && dstY == actCol)
            return true;
    }
    else {
        if (dstX - actRow == -1 && (dstY == actCol || abs(dstY - actCol) == 1))
            return true;
        else if (dstX - actRow == -2 && actRow == numRow - 2 && dstY == actCol)
            return true;
    }

    return false;
}


//TORRE
bool m_torre::validMove(int dstX, int dstY)
{
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

 //REY
bool m_rey::validMove(int dstX, int dstY)
{
    int actRow = getRow();
    int actCol = getCol();

    //comprovamos solo quiere moverse una casilla
    if ( (abs(actRow - dstX) == 1 && abs(actCol - dstY) == 1) || //MOVIEMIENTO EN DIAGONAL
        (abs(actRow - dstX) == 1 && abs(actCol - dstY) == 0) ||  //MOVIMIENTO EN VERTICAL
        (abs(actRow - dstX) == 0 && abs(actCol - dstY) == 1) ) //MOVIMIENTO HORIZONTAL
        return true;
    else
        return false;
}
