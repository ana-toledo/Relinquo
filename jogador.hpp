#ifndef __JOGADOR_HPP__
#define __JOGADOR_HPP__

#include <stdlib.h>

// Estrutura do jogador
typedef struct {
	int vida; // começa em 100 e diminui com o tempo
	int amzd; // começa com 50 e pode diminuir ou aumentar
	int atk;
	int def;
	int escolhas[10]; // decisoes que podem impactar o final, valor exemplo
} Player;

// Função que cria o objeto do jogador
Player* cria_jogador();

// Função que diminui ou cura a vida de B4 
// se for curado, então o valor no parâmetro deve ser negativo
void dano_jogador(Player *p, int pontos);

// Função que altera o nivel de amizade entre os agentes
// se a interação for positiva, ele ganha pontos
void amizade_jogador(Player *p, int pontos);

// Função que guarda as decisões importantes do jogador
void decisao_jogador(Player *p, int esc, int pos);

// Função que faz o free da estrutura
void mata_jogador(Player *p);

#endif