#include "m_tablero.h";
#include <iostream>
using namespace std;

void testCanMoveTorre() {

    cout << "---------------------------" << endl
         << "  TEST CanMove DE LA TORRE" << endl
         << "---------------------------" << endl;

    m_torre* t1 = new m_torre(3, 3, 1, "TB");
    vector<m_pieza*> v = { t1 };
    m_tablero tab(v);
    tab.printaTablero(false);

    // test a realizar
    vector<string> moves = { "" };

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true };

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


void testCanMovePeon() {

    cout << "-------------------------" << endl
        << "  TEST CanMove DEL PEON" << endl
        << "-------------------------" << endl;

    m_peon* p1 = new m_peon(1, 2, 1, "PB");
    vector<m_pieza*> v = { p1 };
    m_tablero tab(v);
    tab.printaTablero(false);

    // test a realizar
    vector<string> moves = { "c2 c3", "c2 c4", "c2 c5", "c2 d2", "c2 b2", "c2 c1", "c2 d3", "c2 b3" };

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true };

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

void testAll() {
    
    testCanMovePeon();

}
