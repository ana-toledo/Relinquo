#ifndef __JOGADOR_HPP__
#define __JOGADOR_HPP__

#include <stdlib.h>

// Estrutura do jogador
typedef struct {
	int dia;
	bool medkit;
	bool hook;
	bool laser;
	bool combustivel;
	bool peca;
	bool manual;
	bool read_info;
	int dinheiro;
	bool has_replied[3][5];
	int reply_mail[3][5]; // 3 dias, 5 respostas max por dia
	bool new_message;
} Player;

// Fun��o que cria o objeto do jogador
Player* cria_jogador();


void passa_dia(Player* p);

// Fun��o que guarda as decis�es importantes do jogador
void resp_jogador(Player *p, int dia, int pos, int esc);

// Fun��o que salva se respondeu
void replied(Player* p, int dia, int pos);


// Fun��es de compra
void bought_mask(Player* p);
void bought_laser(Player* p);
void bought_medkit(Player* p);
void bought_hook(Player* p);


// Fun��o que faz o free da estrutura
void mata_jogador(Player *p);

void update_read_info(Player* p);

#endif