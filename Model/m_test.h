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
    vector<bool> resultados = { true, true, false, true, false, false, true, true };

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

void testJaque() {
    /*
    cout << "---------------------------" << endl
        << "         TEST Jaque         " << endl
        << "----------------------------" << endl;

    m_alfil* a1 = new m_alfil(4, 1, 1, "AB");
    m_alfil* a2 = new m_alfil(5, 1, 1, "AB");
    m_alfil* a3 = new m_alfil(4, 6, 1, "AB");
    m_torre* t1 = new m_torre(5, 4, 1, "TB");
    m_torre* t2 = new m_torre(6, 3, 1, "TB");
    m_torre* t3 = new m_torre(5, 3, 1, "TB");
    m_peon* p1 = new m_peon(6, 5, 1, "PB");
    m_peon* p2 = new m_peon(6, 4, 1, "PB");
    m_peon* p3 = new m_peon(7, 3, 1, "PB");
    m_rey* r1 = new m_rey(7, 4, 2, "RN");

    // test a realizar
    vector<vector<m_pieza*>> pzs = { {r1, a1}, {r1, a2}, {r1, a3}, {r1, t1}, {r1, t2}, {r1, t3}, {r1, p1}, {r1, p2}, {r1, p3} };

    // resultados de los test
    vector<bool> resultados = { true, false, false, true, false, false, true, false, false };
    vector<string> tests = { "Test Alfil", "Test Torre", "Test Peon" };

    bool pass = true;
    int x = 0;
    for (int i = 0; i < pzs.size(); i++) {
        if (i % 3 == 0) {
            string test = tests[x];
            cout << endl << "-------" << endl << test << endl << "-------" << endl;
            x++;
        }

        m_tablero t(pzs[i]);
        t.printaTablero(false);
        int orgX = pzs[i][0]->getRow();
        int orgY = pzs[i][0]->getCol();
        int dstX = pzs[i][0]->getRow();
        int dstY = pzs[i][0]->getCol();

        bool res = t.isJaque(2, orgX, orgY, dstX, dstY);

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
        cout << endl << "Test de Jaque passado Correctamente" << endl;
    else
        cout << endl << "Test de Jaque passado Incorrectamente" << endl;
        */
}

void testAll() {

    testCanMovePeon();
    testCanMoveTorre();
    testCanMoveAlfil();
    testCanMoveCaballo();
    //testJaque();
}
