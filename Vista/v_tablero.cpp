#include <iostream>
#include <iomanip>
#include "../Model/m_tablero.h"
using namespace std;

void m_tablero::printaTablero(){
    
    // creamos matriz
    string tablero2[numRow][numCol];
    //inicializamos con string vacios de momento
    for (int i = 0; i < numRow; i++){
        for (int j = 0; j < numCol; j++){
            string ico = tablero[i][j]->getIcono();
            if (ico == "-1") {
                tablero2[i][j] = "";
            }
            else
            {
                tablero2[i][j] = ico;
            }
        }
    }
               
    // limpiamos la pantalla antes de printar nada
    system("cls");


    //printar tablero
    for(int i = int(numRow)-1; i >= 0; i--){

        //lineas horizontales
        cout << endl << string(2, ' ');
        for(int j = 0; j < numCol; j++){
            cout << setfill('-') << setw(5) << left << '+';
        }
        cout << '+' << endl;

        //lineas verticales
        cout << setfill(' ') << setw(2) << left << i+1;
        for(int j = 0; j<numCol; j++){
            cout << setfill(' ') << setw(2) << left << '|';
            cout << setfill(' ') << setw(3) << left << tablero2[i][j];
        }
        cout << '|';
    }

    cout << endl << string(2,' ');
    for (int i = 0; i < numCol; i++){
        cout << setfill('-') << setw(5) << left << 'x';
    }
    cout << '+';

    //linea inferior posicion tablero
    cout << endl;
    cout << string(5, ' ');
    for (int i = 0; i < numCol; i++) {
        cout << setfill(' ') << setw(5) << left << char('A'+i);
    }
    cout << ' ' << endl;
}
