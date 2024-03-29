#include "../Model/m_tablero.h"
#include "../Model/m_pieza.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

m_tablero::m_tablero() {
    // Creamos el espacio necessario para el tablero
    tablero = new m_pieza * *[numRow];

    for (int i = 0; i < numRow; i++) {
        tablero[i] = new m_pieza * [numCol];
    }

    for (int i = 0; i < numRow; i++)
    {
        for (int j = 0; j < numCol; j++) {
            tablero[i][j] = new m_pieza;
        }
    }

    // inicializamos todas las piezas

    //BLANCAS
    m_peon* peon0 = new m_peon(1, 0, 1, "PB");
    m_peon* peon1 = new m_peon(1, 1, 1, "PB");
    m_peon* peon2 = new m_peon(1, 2, 1, "PB");
    m_peon* peon3 = new m_peon(1, 3, 1, "PB");
    m_peon* peon4 = new m_peon(1, 4, 1, "PB");
    m_peon* peon5 = new m_peon(1, 5, 1, "PB");
    m_peon* peon6 = new m_peon(1, 6, 1, "PB");
    m_peon* peon7 = new m_peon(1, 7, 1, "PB");

    m_torre* torre1 = new m_torre(0, 0, 1, "TB");
    m_torre* torre2 = new m_torre(0, 7, 1, "TB");

    m_alfil* alfil1 = new m_alfil(0, 2, 1, "AB");
    m_alfil* alfil2 = new m_alfil(0, 5, 1, "AB");

    m_caballo* caballo1 = new m_caballo(0, 1, 1, "CB");
    m_caballo* caballo2 = new m_caballo(0, 6, 1, "CB");

    m_rey* rey1 = new m_rey(0, 3, 1, "RB");
    reyBlanco = rey1;

    tablero[peon0->getRow()][peon0->getCol()] = peon0;
    tablero[peon1->getRow()][peon1->getCol()] = peon1;
    tablero[peon2->getRow()][peon2->getCol()] = peon2;
    tablero[peon3->getRow()][peon3->getCol()] = peon3;
    tablero[peon4->getRow()][peon4->getCol()] = peon4;
    tablero[peon5->getRow()][peon5->getCol()] = peon5;
    tablero[peon6->getRow()][peon6->getCol()] = peon6;
    tablero[peon7->getRow()][peon7->getCol()] = peon7;

    tablero[torre1->getRow()][torre1->getCol()] = torre1;
    tablero[torre2->getRow()][torre2->getCol()] = torre2;

    tablero[alfil1->getRow()][alfil1->getCol()] = alfil1;
    tablero[alfil2->getRow()][alfil2->getCol()] = alfil2;

    tablero[caballo1->getRow()][caballo1->getCol()] = caballo1;
    tablero[caballo2->getRow()][caballo2->getCol()] = caballo2;

    tablero[rey1->getRow()][rey1->getCol()] = rey1;

    //NEGRAS
    m_peon* peon8 = new m_peon(6, 0, 2, "PN");
    m_peon* peon9 = new m_peon(6, 1, 2, "PN");
    m_peon* peon10 = new m_peon(6, 2, 2, "PN");
    m_peon* peon11 = new m_peon(6, 3, 2, "PN");
    m_peon* peon12 = new m_peon(6, 4, 2, "PN");
    m_peon* peon13 = new m_peon(6, 5, 2, "PN");
    m_peon* peon14 = new m_peon(6, 6, 2, "PN");
    m_peon* peon15 = new m_peon(6, 7, 2, "PN");

    m_torre* torre3 = new m_torre(7, 0, 2, "TN");
    m_torre* torre4 = new m_torre(7, 7, 2, "TN");

    m_alfil* alfil3 = new m_alfil(7, 2, 2, "AN");
    m_alfil* alfil4 = new m_alfil(7, 5, 2, "AN");

    m_caballo* caballo3 = new m_caballo(7, 1, 2, "CN");
    m_caballo* caballo4 = new m_caballo(7, 6, 2, "CN");

    m_rey* rey2 = new m_rey(7, 3, 2, "RN");
    reyNegro = rey2;

    tablero[peon8->getRow()][peon8->getCol()] = peon8;
    tablero[peon9->getRow()][peon9->getCol()] = peon9;
    tablero[peon10->getRow()][peon10->getCol()] = peon10;
    tablero[peon11->getRow()][peon11->getCol()] = peon11;
    tablero[peon12->getRow()][peon12->getCol()] = peon12;
    tablero[peon13->getRow()][peon13->getCol()] = peon13;
    tablero[peon14->getRow()][peon14->getCol()] = peon14;
    tablero[peon15->getRow()][peon15->getCol()] = peon15;

    tablero[torre3->getRow()][torre3->getCol()] = torre3;
    tablero[torre4->getRow()][torre4->getCol()] = torre4;

    tablero[alfil3->getRow()][alfil3->getCol()] = alfil3;
    tablero[alfil4->getRow()][alfil4->getCol()] = alfil4;

    tablero[caballo3->getRow()][caballo3->getCol()] = caballo3;
    tablero[caballo4->getRow()][caballo4->getCol()] = caballo4;

    tablero[rey2->getRow()][rey2->getCol()] = rey2;
}


m_tablero::m_tablero(vector<m_pieza*> piezas)
{

    // Creamos el espacio necessario para el tablero
    tablero = new m_pieza * *[numRow];

    for (int i = 0; i < numRow; i++) {
        tablero[i] = new m_pieza * [numCol];
    }

    for (int i = 0; i < numRow; i++)
    {
        for (int j = 0; j < numCol; j++) {
            tablero[i][j] = new m_pieza;
        }
    }

    //a�adimos las piezas al tablero
    for (int i = 0; i < piezas.size(); i++) {
        m_pieza* p = piezas[i];
        if (p->isRey()) {
            if (p->getColor() == 1) {
                reyBlanco = p;
            }
            else {
                reyNegro = p;
            }
        }
        tablero[p->getRow()][p->getCol()] = p;
    }
}

vector<vector<int>> m_tablero::getMove(string move, bool &result) {  // combierte el movimiento de string a vector de posiciones
    //formato correcto
    if (move.size() > 5) {
        cout << " No se reconoce el formato" << endl;
        result = false;
    }

    // Parametros para passar de str a int
    int letras = 97;
    int nums = 49;

    // separacion del movimiento origen y posterior guardado en vector
    string origen;
    origen.assign(move, 0, 2);
    int orgX = int(origen[1]) - nums;
    int orgY = int(origen[0]) - letras;
    vector<int> org = { orgX, orgY };

    // Busqueda de separador       
    int pDest = move.find(" ");

    // separacion del movimiento destino y posterior guardado en vector
    string destino;
    destino.assign(move, pDest + 1, 2);
    int dstX = int(destino[1]) - nums;
    int dstY = int(destino[0]) - letras;

    vector<int> dst = { dstX, dstY };

    // return del vector final
    vector<vector<int>> mov;
    mov.push_back(org);
    mov.push_back(dst);
    //posicion fuera tablero
    if (orgX >= numRow || orgX < 0 || orgY >= numRow || orgY < 0 || dstX >= numRow || dstX < 0 || dstY >= numRow || dstY < 0) {
        cout << " Movimiento invalido, posicion fuera del tablero" << endl;
        result = false;
    }

    return mov;
}

bool m_tablero::comprobarMove(string move, int jugador) {
    // passamos coordenadas de string a ints
    bool result = true;
    vector<vector<int>> mov = getMove(move, result);

    if (!result) {
        return result;
    }
  
    int orgX = mov[0][0];
    int orgY = mov[0][1];
    int dstX = mov[1][0];
    int dstY = mov[1][1];

    m_pieza* pieza = tablero[orgX][orgY];

    //casilla seleccionada no hay nada
    if (pieza->getIcono() == "-1") {
        cout << " Movimiento invalido, no hay ninguna pieza en la casilla de origen" << endl;
        return false;
    }

    //casilla destino ocupada por ficha aliada
    if (tablero[dstX][dstY]->getIcono() != "-1" && tablero[dstX][dstY]->getColor() == tablero[orgX][orgY]->getColor())
    {
        cout << " Movimiento invalido, casilla ocupada por ficha aliada" << endl;
        return false;
    }

    //jugador moviendo ficha del enemigo
    if (tablero[orgX][orgY]->getColor() != jugador) {
        cout << " Movimiento invalido, ficha del oponente seleccionada" << endl;
        return false;
    }


    // si el movimiento de la ficha no es correcto
    if (!pieza->validMove(dstX, dstY)) {
        cout << " Movimiento de la ficha invalido" << endl;
        return false;
    }

    //cosas especiales de peon
    if (pieza->isPeon() && !excepcionesPeon(dstX, dstY, orgX, orgY, pieza)) {
        return false;
    }
    //cosas especiales de torre
    else if (pieza->isTorre() && !excepcionesTorre(dstX, dstY, orgX, orgY, pieza)) {
        return false;
    }
    //cosas especiales de alfil
    else if (pieza->isAlfil() && !excepcionesAlfil(dstX, dstY, orgX, orgY, pieza)) {
        return false;
    }

    //mi movimiento no ha generado jaque contra mi
    if (isJaque(jugador, orgX, orgY, dstX, dstY)) {
        cout << " Movimiento incorrecto, estas en jaque" << endl;
        return false;
    }
}

bool m_tablero::excepcionesPeon(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza) {

    // comprobar que no hay piezas en el destino cuando se mueve en vertical
    if (dstY == orgY && tablero[dstX][dstY]->getIcono() != "-1") {
        cout << " Hay fichas en mitad del camino" << endl;
        return false;
    } // lo mismo pero cuando se mueve 2
    else if (dstY == orgY && abs(dstX - orgX) == 2) {
        if (pieza->getColor() == 1 && tablero[dstX - 1][dstY]->getIcono() != "-1") {
            cout << " Hay fichas en mitad del camino" << endl;
            return false;
        }
        else if (pieza->getColor() == 2 && tablero[dstX + 1][dstY]->getIcono() != "-1") {
            cout << " Hay fichas en mitad del camino" << endl;
            return false;
        }
    } // Comprobar que solo se mueve en diagonal para matar una ficha
    else if (dstY != orgY && tablero[dstX][dstY]->getIcono() == "-1") {
        cout << " Solo se puede mover en diagonal para matar" << endl;
        return false;
    }
    return true;
}


bool m_tablero::excepcionesAlfil(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza) {
    // comprobacion de piezas intermedias en el movimiento
    if (orgY == min(orgY, dstY)) {
        int positivo = 1;
        if (orgX > dstX) {
            positivo = -1;
        }

        for (int i = 1; i < (dstY - orgY); i++) {
            m_pieza* p = tablero[orgX + positivo * i][orgY + i];
            if (p->getIcono() != "-1") { //miramos si hay una ficha
                cout << " Hay fichas en mitad del camino" << endl;
                return false;
            }
        }
    }
    else {
        int positivo = 1;
        if (orgX < dstX) {
            positivo = -1;
        }

        for (int i = 0; i < (orgY - dstY); i++) {
            m_pieza* p = tablero[dstX + (positivo * i)][dstY + i];
            if (p->getIcono() != "-1") { //miramos si hay una ficha
                cout << " Hay fichas en mitad del camino" << endl;
                return false;
            }
        }
    }
    return true;
}

bool m_tablero::excepcionesTorre(int dstX, int dstY, int orgX, int orgY, m_pieza* pieza) {
    // comprobacion de piezas intermedias en el movimiento
    if (orgX == dstX) {
        for (int i = min(orgY, dstY) + 1; i < max(dstY, orgY) - 1; i++) {
            m_pieza* p = tablero[orgX][i];
            if (p->getIcono() != "-1") { //miramos si hay una ficha
                cout << " Hay fichas en mitad del camino" << endl;
                return false;
            }
        }
    }
    else {
        for (int i = min(orgX, dstX) + 1; i < max(dstX, orgX) - 1; i++) {
            m_pieza* p = tablero[i][orgY];
            if (p->getIcono() != "-1") { //miramos si hay una ficha
                cout << " Hay fichas en mitad del camino" << endl;
                return false;
            }
        }
    }
    return true;
}


void m_tablero::mover(string move) { // funcion que permite mover las fichas segun un string

    // passamos coordenadas de string a ints
    bool result;
    vector<vector<int>> mov = getMove(move, result);
    int orgX = mov[0][0];
    int orgY = mov[0][1];
    int dstX = mov[1][0];
    int dstY = mov[1][1];

    m_pieza* pieza = tablero[orgX][orgY];
    pieza->setCol(dstY);
    pieza->setRow(dstX);
    tablero[dstX][dstY] = pieza;
    tablero[orgX][orgY] = new m_pieza();
}


bool m_tablero::isJaque(int player, int orgX, int orgY, int dstX, int dstY) {

    int i;
    int j;
    bool inJaque = false;

    m_pieza* rey;
    if (player == 1) {
        rey = reyBlanco;
    }
    else {
        rey = reyNegro;
    }

    //simulamos movimiento
    m_pieza* copiaSeguridadOrg = tablero[orgX][orgY];
    m_pieza* copiaSeguridadDst = tablero[dstX][dstY];

    m_pieza* pieza = tablero[orgX][orgY];
    pieza->setCol(dstY);
    pieza->setRow(dstX);
    tablero[dstX][dstY] = pieza;
    tablero[orgX][orgY] = new m_pieza();



    //jaque por torre
    //comprobar vertical
    for (int i = rey->getRow() + 1; i < numRow; i++) {
        m_pieza* p = tablero[i][rey->getCol()];
        if (p->getIcono() != "-1") { //miramos si hay una ficha

            if (p->getColor() != rey->getColor() && p->isTorre() == true) {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }
    }

    for (int i = rey->getRow() - 1; i > 0; i--) {
        m_pieza* p = tablero[i][rey->getCol()];
        if (p->getIcono() != "-1") { //miramos si hay una ficha

            if (p->getColor() != rey->getColor() && p->isTorre()) {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }
    }

    // comprobar horizontal
    for (int i = rey->getCol() + 1; i < numCol; i++) {
        m_pieza* p = tablero[rey->getRow()][i];
        if (p->getIcono() != "-1") { //miramos si hay una ficha

            if (p->getColor() != rey->getColor() && p->isTorre() == true) {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }
    }

    for (int i = rey->getCol() - 1; i > 0; i--) {
        m_pieza* p = tablero[rey->getRow()][i];
        if (p->getIcono() != "-1") { //miramos si hay una ficha

            if (p->getColor() != rey->getColor() && p->isTorre())
            {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }
    }

    //jaque por alfil
    // diagonal superior derecha
    i = rey->getRow() + 1;
    j = rey->getCol() + 1;
    while (i < numRow && j < numCol) {
        m_pieza* p = tablero[i][j];

        if (p->getIcono() != "-1") {
            if (p->getColor() != rey->getColor()) {
                if (p->isAlfil())
                {
                    inJaque = true;
                    goto deshacerMove;
                }
                else if (abs(j - rey->getCol()) == 1 && abs(i - rey->getRow()) == 1 && p->isPeon())
                {

                    inJaque = true;
                    goto deshacerMove;
                }
                else
                    break;
            }
            else
                break;
        }

        i++;
        j++;
    }

    //diagonal superior izquierda
    i = rey->getRow() + 1;
    j = rey->getCol() - 1;
    while (i < numRow && j > 0) {
        m_pieza* p = tablero[i][j];

        if (p->getIcono() != "-1") {
            if (p->getColor() != rey->getColor()) {
                if (p->isAlfil())
                {
                    inJaque = true;
                    goto deshacerMove;
                }
                else if (abs(j - rey->getCol()) == 1 && abs(i - rey->getRow() == 1 && p->isPeon()))
                {
                    inJaque = true;
                    goto deshacerMove;
                }
                else
                    break;
            }
            else
                break;
        }

        i++;
        j--;
    }

    //diagonal inferior derecha
    i = rey->getRow() - 1;
    j = rey->getCol() + 1;
    while (i > 0 && j < numCol) {
        m_pieza* p = tablero[i][j];

        if (p->getIcono() != "-1") {

            if (p->getColor() != rey->getColor() && p->isAlfil())
            {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }

        i--;
        j++;
    }

    //diagonal inferior izquierda
    i = rey->getRow() - 1;
    j = rey->getCol() - 1;
    while (i > 0 && j > 0) {
        m_pieza* p = tablero[i][j];

        if (p->getIcono() != "-1") {

            if (p->getColor() != rey->getColor() && p->isAlfil())
            {
                inJaque = true;
                goto deshacerMove;
            }
            else
                break;
        }

        i--;
        j--;
    }

    // jaque caballos
    i = rey->getRow();
    j = rey->getCol();

    // +2 +1
    if (i + 2 < numRow && j + 1 < numCol)
    {
        if (tablero[i + 2][j + 1]->getIcono() != "-1" &&
            tablero[i + 2][j + 1]->isCaballo() &&
            tablero[i + 2][j + 1]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //+1 +2
    if (i + 1 < numRow && j + 2 < numCol)
    {
        if (tablero[i + 1][j + 2]->getIcono() != "-1" &&
            tablero[i + 1][j + 2]->isCaballo() &&
            tablero[i + 1][j + 2]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //-1 +2
    if (i - 1 > 0 && j + 2 < numCol)
    {
        if (tablero[i - 1][j + 2]->getIcono() != "-1" &&
            tablero[i - 1][j + 2]->isCaballo() &&
            tablero[i - 1][j + 2]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //-2 +1
    if (i - 2 > 0 && j + 1 < numCol)
    {
        if (tablero[i - 2][j + 1]->getIcono() != "-1" &&
            tablero[i - 2][j + 1]->isCaballo() &&
            tablero[i - 2][j + 1]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //-2 -1
    if (i - 2 > 0 && j - 1 > 0)
    {
        if (tablero[i - 2][j - 1]->getIcono() != "-1" &&
            tablero[i - 2][j - 1]->isCaballo() &&
            tablero[i - 2][j - 1]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //-1 -2
    if (i - 1 > 0 && j - 2 > 0)
    {
        if (tablero[i - 1][j - 2]->getIcono() != "-1" &&
            tablero[i - 1][j - 2]->isCaballo() &&
            tablero[i - 1][j - 2]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //+1 -2
    if (i + 1 < numRow && j - 2 < numCol)
    {
        if (tablero[i + 1][j - 2]->getIcono() != "-1" &&
            tablero[i + 1][j - 2]->isCaballo() &&
            tablero[i + 1][j - 2]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }

    //+2 -1
    if (i + 2 < numRow && j - 1 < numCol)
    {
        if (tablero[i + 2][j - 1]->getIcono() != "-1" &&
            tablero[i + 2][j - 1]->isCaballo() &&
            tablero[i + 2][j - 1]->getColor() != rey->getColor())
        {
            inJaque = true;
            goto deshacerMove;
        }
    }


    //jaque por peon
    i = rey->getRow();
    j = rey->getCol();
    if (player == 1) {
        if (j + 1 < numCol && i + 1 < numRow && j - 1 >= 0) {
            if (tablero[i + 1][j + 1]->getIcono() != "-1" &&
                tablero[i + 1][j + 1]->isPeon() &&
                tablero[i + 1][j + 1]->getColor() != rey->getColor())
            {
                inJaque = true;
                goto deshacerMove;
            }
            else if (tablero[i + 1][j - 1]->getIcono() != "-1" &&
                tablero[i + 1][j - 1]->isPeon() &&
                tablero[i + 1][j - 1]->getColor() != rey->getColor())
            {
                inJaque = true;
                goto deshacerMove;
            }
        }
    }
    else {
        if (j + 1 < numCol && i - 1 >= 0 && j - 1 >= 0) {
            if (tablero[i - 1][j + 1]->getIcono() != "-1" &&
                tablero[i - 1][j + 1]->isPeon() &&
                tablero[i - 1][j + 1]->getColor() != rey->getColor())
            {
                inJaque = true;
                goto deshacerMove;
            }
            else if (tablero[i - 1][j - 1]->getIcono() != "-1" &&
                tablero[i - 1][j - 1]->isPeon() &&
                tablero[i - 1][j - 1]->getColor() != rey->getColor())
            {
                inJaque = true;
                goto deshacerMove;
            }
        }
    }
    
    
    //jaque por rey
    i = rey->getRow();
    j = rey->getCol();

    //miramos que el rey no este pegado al otro rey
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < numRow && y >= 0 && y < numCol) //miramos que este dentro de tablero
            {
                if (tablero[x][y]->isRey() && tablero[x][y]->getColor() != rey->getColor())
                {
                    inJaque = true;
                    goto deshacerMove;
                }
            }
        }
    }
    

    //deshacer movimiento
deshacerMove:

    copiaSeguridadOrg->setCol(orgY);
    copiaSeguridadOrg->setRow(orgX);

    tablero[orgX][orgY] = copiaSeguridadOrg;

    tablero[dstX][dstY] = copiaSeguridadDst;

    if (inJaque == true)
        return true;
    else
        return false;
}
