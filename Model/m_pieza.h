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

    virtual bool getFM() { return false; }

    //setters
    void setColor(int Color) { color = Color; }

    void setVivo(bool Vivo) { vivo = Vivo; }

    void setRow(int pX) { row = pX; }

    void setCol(int pY) { col = pY; }

    void setIcono(string ic) { icono = ic; }

    void setMate(bool m) { isJaque = m; }

    virtual void setFM(bool fm) {}

    virtual bool validMove(int dstX, int dstY) { return true; }


    virtual bool isPeon() { return false; }
    virtual bool isTorre() { return false; }
    virtual bool isAlfil() { return false; }
    virtual bool isCaballo() { return false; }
    virtual bool isRey() { return false; }

};


class m_peon : public m_pieza {
private:
    bool firstMove;
public:
    m_peon() { firstMove = true; }
    m_peon(int row, int col, int colr, string ico) : m_pieza(row, col, colr, ico) { firstMove = true; }
    bool getFM() override { return firstMove; }
    void setFM(bool fm) override { firstMove = fm; }
    bool validMove(int dstX, int dstY) override; // comprobar si el movimiento es valido
    bool isPeon() override { return true; }
};

class m_torre : public m_pieza {
private:
public:
    m_torre() {}
    m_torre(int x, int y, int col, string ico) : m_pieza(x, y, col, ico) {}
    bool validMove(int dstX, int dstY) override; // comprobar si el movimiento es valido
    bool isTorre() override { return true; }
};

class m_alfil : public m_pieza {
private:
public:
    m_alfil() {}
    m_alfil(int x, int y, int col, string ico) : m_pieza(x, y, col, ico) {}
    bool validMove(int dstX, int dstY) override;
    bool isAlfil() override { return true; }
};


class m_caballo : public m_pieza {
private:
public:
    m_caballo() {}
    m_caballo(int x, int y, int col, string ico) : m_pieza(x, y, col, ico) {}
    bool validMove(int dstX, int dstY) override;
    bool isCaballo() override { return true; }
};


class m_rey : public m_pieza {
private:
public:
    m_rey() {}
    m_rey(int x, int y, int col, string ico) : m_pieza(x, y, col, ico) {}
    bool validMove(int dstX, int dstY) override;
    bool isRey() override { return true; }
};
