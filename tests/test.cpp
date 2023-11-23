#include "pch.h"
#include "../Model/m_partida.h"
#include "../Model/m_pieza.h"
#include "../Model/m_tablero.h"
#include "../Controlador/c_tablero.cpp"
#include "../controlador/c_pieza.cpp"
#include <gtest/gtest.h>

TEST(ValidMove, Peon) {
	m_peon* p = new m_peon(1, 2, 1, "PB");

	// test a realizar
	vector<vector<int>> moves_true = { {2, 2}, {3, 2}, {2, 3}, {2, 1} };
	vector<vector<int>> moves_false = { {4, 2}, {1, 1}, {1, 3}, {0, 2}, {1, 2} };

	
	for (int i = 0; i < moves_true.size(); i++) {
		int dstX = moves_true[i][0];
		int dstY = moves_true[i][1];

		EXPECT_TRUE(p->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}
	
	for (int i = 0; i < moves_false.size(); i++) {
		int dstX = moves_false[i][0];
		int dstY = moves_false[i][1];

		EXPECT_FALSE(p->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}
	

}


TEST(ValidMove, Torre) {

	m_torre* t = new m_torre(3, 3, 1, "TB");

	// test a realizar
	vector<vector<int>> moves_true = { {0, 3}, {4, 3}, {3, 1}, {3, 4} };
	vector<vector<int>> moves_false = { {4, 2} , {0, 0} , {1, 2} , {2, 4} };

	for (int i = 0; i < moves_true.size(); i++) {
		int dstX = moves_true[i][0];
		int dstY = moves_true[i][1];

		EXPECT_TRUE(t->validMove(dstX, dstY)) << "Error en el move " << dstX << ", " << dstY;
	}

	for (int i = 0; i < moves_false.size(); i++) {
		int dstX = moves_false[i][0];
		int dstY = moves_false[i][1];

		EXPECT_FALSE(t->validMove(dstX, dstY)) << "Error en el move " << dstX << ", " << dstY;
	}
}

TEST(ValidMove, Alfil) {
	m_alfil* a = new m_alfil(2, 2, 1, "AB");

	// test a realizar
	vector<vector<int>> moves_true = { {0, 0}, {1, 3}, {4, 4}, {1, 3} };
	vector<vector<int>> moves_false = { {2, 1}, {1, 0}, {0, 3}, {4, 1} };


	for (int i = 0; i < moves_true.size(); i++) {
		int dstX = moves_true[i][0];
		int dstY = moves_true[i][1];

		EXPECT_TRUE(a->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}

	for (int i = 0; i < moves_false.size(); i++) {
		int dstX = moves_false[i][0];
		int dstY = moves_false[i][1];

		EXPECT_FALSE(a->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}
}

TEST(ValidMove, Caballo) {
	m_caballo* c = new m_caballo(2, 2, 1, "CB");

	//test a realizar
	vector<vector<int>> moves_true = { {3, 4}, {1, 4}, {0, 3}, {4, 1} };
	vector<vector<int>> moves_false = { {1, 1} , {4, 2} , {2, 3} , {0, 4} };


	for (int i = 0; i < moves_true.size(); i++) {
		int dstX = moves_true[i][0];
		int dstY = moves_true[i][1];

		EXPECT_TRUE(c->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}

	for (int i = 0; i < moves_false.size(); i++) {
		int dstX = moves_false[i][0];
		int dstY = moves_false[i][1];

		EXPECT_FALSE(c->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}
}

TEST(Jaque, rey){

	m_alfil* a1 = new m_alfil(4, 1, 1, "AB");
	m_alfil* a2 = new m_alfil(5, 1, 1, "AB");
	m_alfil* a3 = new m_alfil(4, 6, 1, "AB");
	m_torre* t1 = new m_torre(5, 4, 1, "TB");
	m_torre* t2 = new m_torre(6, 3, 1, "TB");
	m_torre* t3 = new m_torre(5, 3, 1, "TB");
	m_peon* p1 = new m_peon(6, 5, 1, "PB");
	m_peon* p2 = new m_peon(6, 4, 1, "PB");
	m_peon* p3 = new m_peon(7, 3, 1, "PB");
	m_caballo* c1 = new m_caballo(5, 5, 1, "CB");
	m_caballo* c2 = new m_caballo(6, 5, 1, "CB");
	m_caballo* c3 = new m_caballo(5, 4, 1, "CB");
	m_rey* r1 = new m_rey(7, 4, 2, "RN");

	// test a realizar
	vector<vector<m_pieza*>> pzs_true = { {r1, a1}, {r1, t1}, {r1, p1}, {r1, c1} };
	vector<vector<m_pieza*>> pzs_false = { {r1, a2}, {r1, a3}, {r1, t2}, {r1, t3}, {r1, p2}, {r1, p3}, {r1, c2}, {r1, c3} };


	for (int i = 0; i < pzs_true.size(); i++) {

		m_tablero t(pzs_true[i]);
		int orgX = pzs_true[i][0]->getRow();
		int orgY = pzs_true[i][0]->getCol();
		int dstX = pzs_true[i][0]->getRow();
		int dstY = pzs_true[i][0]->getCol();
		EXPECT_TRUE(t.isJaque(2, orgX, orgY, dstX, dstY));
	}

	for (int i = 0; i < pzs_false.size(); i++) {

		m_tablero t(pzs_false[i]);
		int orgX = pzs_false[i][0]->getRow();
		int orgY = pzs_false[i][0]->getCol();
		int dstX = pzs_false[i][0]->getRow();
		int dstY = pzs_false[i][0]->getCol();
		EXPECT_FALSE(t.isJaque(2, orgX, orgY, dstX, dstY));
	}
}


int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}