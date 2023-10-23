#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <assert.h>
#define NDEBUG 
#include <vector>
#include <string>
using namespace std;

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