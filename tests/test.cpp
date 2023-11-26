#include "pch.h"
#include <fstream>
#include "../Model/m_partida.h"
#include "../Model/m_pieza.h"
#include "../Model/m_tablero.h"
#include "../Controlador/c_tablero.cpp"
#include "../controlador/c_pieza.cpp"
#include <gtest/gtest.h>


TEST(MockObject, validMovePeon) {
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
TEST(MockObject, validMoveTorre) {

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
TEST(MockObject, validMoveAlfil) {
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
TEST(MockObject, validMoveCaballo) {
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
TEST(MockObject, validMoveRey){
	m_rey* r = new m_rey(4, 4, 1, "RB");

	//test a realitzar
	vector<vector<int>> moves_true = { {5, 3}, {4, 3}, {3, 3}, {5, 4}, {3, 4}, {5, 5}, {4, 5}, {3, 5} };
	vector<vector<int>> moves_false = { {4, 6}, {4, 2}, {6, 6}, {2, 2}, {2, 4}, {6, 4} };


	for (int i = 0; i < moves_true.size(); i++) {
		int dstX = moves_true[i][0];
		int dstY = moves_true[i][1];

		EXPECT_TRUE(r->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}

	for (int i = 0; i < moves_false.size(); i++) {
		int dstX = moves_false[i][0];
		int dstY = moves_false[i][1];

		EXPECT_FALSE(r->validMove(dstX, dstY)) << "Error en el move" << dstX << dstY;
	}
}
TEST(MockObject, JaqueRey) {

	//creamos fichas que amenazan al rey
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

TEST(valorsLimit, comprobarMove) {

	m_tablero tab;

	//combinaciones de intentos de movimiento que pueden fallar, para comprobar que no se puede poner algo incorrecto o salirse del tablero
	vector<string> moves_false = { "a9 b1", "a0 b1", "i2 b1", "z3 b1", "a1 a9", "a1 a0", "a1 i2", "a1 z3", "b2a b3", "b22 a33", "2c 4c", "-- --", "<> <>" };
	for (int i = 0; i < moves_false.size(); i++) {
		EXPECT_FALSE(tab.comprobarMove(moves_false[i], 1));
	}
}

TEST(Registre, ActualitzaPuntuacions) {
	ofstream archTest("Registro-test.txt");

	archTest << "oriol vs marc 2 - 3" << endl;
	archTest << "a vs b 0 - 0" << endl;
	archTest << "z vs y 10 - 3" << endl;


}

TEST(DecisionPathStatement, comprobarMove) {
	
	//por la estructura del codigo, al hacer decisionCoverage también se hace pathCoverage y statementCoverage
	
	//decision coverage
	m_tablero tab;

	// if formato correcto
	EXPECT_FALSE(tab.comprobarMove("aaa aaa", 1));
	EXPECT_TRUE(tab.comprobarMove("a2 a3", 1));

	// if posicion fuera tablero
	EXPECT_FALSE(tab.comprobarMove("z9 a2", 1));
	EXPECT_TRUE(tab.comprobarMove("a2 a3", 1));

	// if casilla seleccionada no hay nada
	EXPECT_FALSE(tab.comprobarMove("c3 c4", 1));
	EXPECT_TRUE(tab.comprobarMove("c2 c4", 1));

	// if casilla destino ocupada por ficha aliada
	EXPECT_FALSE(tab.comprobarMove("a1 a2", 1));
	EXPECT_TRUE(tab.comprobarMove("a2 a3", 1));

	// if jugador moviendo ficha del enemigo
	EXPECT_FALSE(tab.comprobarMove("a7 a6", 1));
	EXPECT_TRUE(tab.comprobarMove("a2 a4", 1));

	// if si el movimiento de la ficha no es correcto
	EXPECT_FALSE(tab.comprobarMove("a2 a5", 1));
	EXPECT_TRUE(tab.comprobarMove("b2 b4", 1));
	tab.~m_tablero();

	//creamos nuevo tablero con fichas para comprovar las excepciones de algunas fichas
	m_peon* p1 = new m_peon(2, 1, 1, "PB");
	m_peon* p2 = new m_peon(3, 2, 2, "PN");
	m_torre* t = new m_torre(3, 1, 1, "TB");
	m_torre* t2 = new m_torre(1, 6, 2, "TN");
	m_alfil* a = new m_alfil(2, 2, 1, "AB");
	m_rey* r = new m_rey(7, 7, 1, "RB");

	m_tablero tab2({ p1, p2, t, t2, a, r});
	// if cosas especiales de peon, avanzar dos casillas al principio y comer en diagonal
	EXPECT_FALSE(tab2.comprobarMove("b3 a4", 1)) << "Peon False" << endl;
	EXPECT_TRUE(tab2.comprobarMove("b3 c4", 1)) << "Peon true" << endl;

	// if cosas especiales de torre, no atravesar otras piezas
	EXPECT_FALSE(tab2.comprobarMove("b4 h4", 1)) << "Torre False" << endl;
	EXPECT_TRUE(tab2.comprobarMove("b4 b7", 1)) << "Torre True" << endl;
	 
	// if cosas especiales de alfil, no atravesar otras piezas
	EXPECT_FALSE(tab2.comprobarMove("c3 a5", 1)) << "Alfil False" << endl;
	EXPECT_TRUE(tab2.comprobarMove("c3 e5", 1)) << "Alfil True" << endl;

	// if el movimiento nos genera jaque
	EXPECT_FALSE(tab2.comprobarMove("h8 g8", 1)) << "Rey FALSE" << endl;
	EXPECT_TRUE(tab2.comprobarMove("h8 h7", 1)) << "Rey TRUE" << endl;
}


int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
