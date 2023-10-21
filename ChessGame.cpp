#include <iostream>
#include "Model/m_tablero.h"
using namespace std;



int main(int argc, char const* argv[])
{
    m_tablero tab;
    tab.printaTablero();
    bool res = tab.mover("a1 a3");
    tab.printaTablero();
}

bool testMove() {
    return true;
}   