#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <vector>
#include <string>
using namespace std;

bool m_peon::canMove(int dstX, int dstY)
{
    int actRow = getRow();
    int actCol = getCol();

    if (getColor() == 1) {
        if (actCol == dstY && actRow < dstX) {
            if((actRow + 1) == dstX)
                return true;
            else if ((actRow+ 2) == dstX && firstMove)
                return true;        
        }
        return false;
    }
    else {
        if (actCol == dstY && actRow > dstX) {
            if ((actRow - 1) == dstX)
                return true;
            else if ((actRow - 2) == dstX && firstMove)
                return true;
        }
        return false;
    }
}