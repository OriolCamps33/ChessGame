#include <iostream>
#include "Model/m_tablero.h"
using namespace std;

void testCanMove() {
    m_tablero tab;
    tab.printaTablero();

    // test a realizar
    vector<string> moves = { "c2 c3", "c2 c4", "c2 c5", "c2 d2", "c2 b2", "c2 c1", "c2 d3", "c2 b3"};

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true};

    bool pass = true;

    for (int i = 0; i < moves.size(); i++) {
        cout << endl;
        cout << "Test " << i << ": " << moves[i] << endl;

        bool res = tab.comprobarMove(moves[i]);

        if (res != resultados[i]) {
            pass = false;
            cout << "Incorrecto: " << endl;
        }
        else
        {
            cout << "Correcto " << endl;
        }
    }

    if (pass)
        cout << endl << "Test de movimientos passado correctamente" << endl;
}


void testMove() {
    m_tablero tab;
    tab.printaTablero();

    // test a realizar
    vector<string> moves = { "a1 a3", "b1 b2", "a3 b3", "c1 c3", "d1 d4", "f1 f3", "a5 a1", "a3 a5", "a3 a4",  "z6 x5"};

    // resultados de los test
    vector<bool> resultados = { true, true, false, true, false, false, false, false, true, false };

    bool pass = true;
    cout << endl;

    for (int i = 0; i < moves.size(); i++) {
        cout << "Test " << i << ": " << moves[i] << endl;

        bool res = tab.comprobarMove(moves[i]);
        
        if (res != resultados[i]) {
            pass = false;
            cout << "Incorrecto: " << endl;
        }
        else
        {
            cout << "Correcto " << endl;
        }
    }

    if (pass)
        cout << endl << "Test de movimientos passado correctamente" << endl;
}

int main(int argc, char const* argv[])
{
    testCanMove();
}
