#include "m_tablero.h";
#include <iostream>
using namespace std;


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

        bool res = tab.comprobarMove(moves[i], 1);

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

void testCanMoveTorre() {

    cout << "---------------------------" << endl
        << "  TEST CanMove DE LA TORRE" << endl
        << "---------------------------" << endl;

    m_torre* t1 = new m_torre(3, 3, 1, "TB");
    vector<m_pieza*> v = { t1 };
    m_tablero tab(v);
    tab.printaTablero(false);

    // test a realizar
    vector<string> moves = { "d4 d1", "d4 d5", "d4 e3", "d4 a1", "d4 b3", "d4 c5", "d4 b4", "d4 e4" };

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true };

    bool pass = true;

    for (int i = 0; i < moves.size(); i++) {
        cout << endl;
        cout << "Test " << i << ": " << moves[i] << endl;

        bool res = tab.comprobarMove(moves[i], 1);

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



void testCanMoveAlfil() {

    cout << "---------------------------" << endl
        << "  TEST CanMove DEL ALFIL" << endl
        << "---------------------------" << endl;

    m_alfil* t1 = new m_alfil(2, 2, 1, "AB");
    vector<m_pieza*> v = { t1 };
    m_tablero tab(v);
    tab.printaTablero(false);

    // test a realizar
    vector<string> moves = { "c3 a1", "c3 b4", "c3 b3", "c3 a2", "c3 d1", "c3 b5", "c3 e5", "c3 d2" };

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true };

    bool pass = true;

    for (int i = 0; i < moves.size(); i++) {
        cout << endl;
        cout << "Test " << i << ": " << moves[i] << endl;

        bool res = tab.comprobarMove(moves[i], 1);

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


void testCanMoveCaballo() {

    cout << "---------------------------" << endl
        << "  TEST CanMove DEL CABALLO" << endl
        << "---------------------------" << endl;

    m_caballo* t1 = new m_caballo(2, 2, 1, "CB");
    vector<m_pieza*> v = { t1 };
    m_tablero tab(v);
    tab.printaTablero(false);

    // test a realizar
    vector<string> moves = { "c3 d5", "c3 b5", "c3 b2", "c3 e3", "c3 c4", "c3 a5", "c3 a4", "c3 e2" };

    // resultados de los test
    vector<bool> resultados = { true, true, false, false, false, false, true, true };

    bool pass = true;

    for (int i = 0; i < moves.size(); i++) {
        cout << endl;
        cout << "Test " << i << ": " << moves[i] << endl;

        bool res = tab.comprobarMove(moves[i], 1);

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

    testCanMoveTorre();
    testCanMoveAlfil();
    testCanMoveCaballo();

}
