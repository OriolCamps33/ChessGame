#pragma once
#include <vector>
#include <string>
using namespace std;

class m_pieza
{
    private:
        int col;
        int row;
        int color;
        bool vivo;
        bool isJaque;
        string icono;

    public:
        m_pieza() { vivo = true; isJaque = false; row = -1; col = -1; color = -1; icono = "-1"; }
        m_pieza(int pX, int pY, int colo, string ico) { row = pX, col = pY, color = colo, vivo = true, isJaque = false, icono = ico; }
        ~m_pieza() {}

        //getters
        int getColor() { return color; }

        bool getVivo() { return vivo; }

        int getRow() { return row; }

        int getCol() { return col; }

        string getIcono() { return icono; }

        bool getMate() { return isJaque; }
        //setters
        void setColor(int Color) { color = Color; }

        void setVivo(bool Vivo) { vivo = Vivo; }

        void setRow(int pX) { row = pX; }

        void setCol(int pY) { col = pY; }
        
        void setIcono(string ic) { icono = ic;  }

        void setMate(bool m) { isJaque = m; }

        virtual bool validMove(int dstX, int dstY) { return true; }
};


class m_peon : public m_pieza{
    private:
        bool firstMove;
    public:
        m_peon() { firstMove = true; }
        m_peon(int x, int y, int col, string ico) : m_pieza(x, y, col, ico) { firstMove = true; }
        bool getFM() { return firstMove; }
        bool validMove(int dstX, int dstY) override; // comprobar si el movimiento es valido
};

