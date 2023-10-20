#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <vector>
#include <string>
using namespace std;

bool m_peon::canMove(vector<int> posDesti)
{
    vector<int> posActual = getPosicion();
    if (getColor() == 1) {
        if (posActual[1] == posDesti[1] && posActual[0] < posDesti[0]) {
            if((posActual[0] + 1) == posDesti[0])
                return true;
            else if ((posActual[0] + 2) == posDesti[0] && posActual[0] == 1)
                return true;        
        }
        return false;
    }
    else {
        if (posActual[1] == posDesti[1] && posActual[0] > posDesti[0]) {
            if((posActual[0] - 1) == posDesti[0])
                return true;
            else if ((posActual[0] - 2) == posDesti[0] && posActual[0] == (MIDA_TAB - 1))
                return true;        
        }
        return false;
    }
}
