#pragma once
#include <vector>
#include <string>
#include "../Model/m_pieza.h"
using namespace std;

#define MIDA_TAB 3

class m_tablero
{
private:
    vector <m_pieza> tablero;

public:
    m_tablero();
    ~m_tablero();
    void mover(string move); 
};
