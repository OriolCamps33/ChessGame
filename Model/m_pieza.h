#pragma once
#include <vector>
#include <string>
using namespace std;

class m_pieza
{
    private:
        vector <int> posicion;
        int color;
        bool vivo;

    public:
        m_pieza(/* args */);
        ~m_pieza();

        //getters
        int getColor() { return color; }

        bool getVivo() { return vivo; }

        vector <int> getPosicion() { return posicion; }

        //setters
        void setColor(int Color) { color = Color; }

        void setVivo(bool Vivo) { vivo = Vivo; }

        void setPosicion( vector<int> pos) { posicion = pos; }
};


class m_peon : public m_pieza{
    private:
        bool isMate;
    public:
        bool getMate(){ return isMate; }
        void setMate(bool m) { isMate = m; }
        bool canMove(vector<int> pos); // comprobar si el movimiento es valido
};

