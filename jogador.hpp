#ifndef __JOGADOR_HPP__
#define __JOGADOR_HPP__

#include <stdlib.h>

// Estrutura do jogador
typedef struct {
	int vida; // come�a em 100 e diminui com o tempo
	int amzd; // come�a com 50 e pode diminuir ou aumentar
	int atk;
	int def;
	int escolhas[10]; // decisoes que podem impactar o final, valor exemplo
} Player;

// Fun��o que cria o objeto do jogador
Player* cria_jogador();

// Fun��o que diminui ou cura a vida de B4 
// se for curado, ent�o o valor no par�metro deve ser negativo
void dano_jogador(Player *p, int pontos);

// Fun��o que altera o nivel de amizade entre os agentes
// se a intera��o for positiva, ele ganha pontos
void amizade_jogador(Player *p, int pontos);

// Fun��o que guarda as decis�es importantes do jogador
void decisao_jogador(Player *p, int esc, int pos);

// Fun��o que faz o free da estrutura
void mata_jogador(Player *p);

#endif