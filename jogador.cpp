#include "jogador.hpp"

Player* cria_jogador() {
	Player* p = NULL;
	p = (Player*)malloc(sizeof(Player));
	if (p == NULL) return NULL;
	p->vida = 100;
	p->amzd = 50;
	for (int i = 0; i < 10; i++) {
		p->escolhas[i] = 0;
	}
	return p;
}

void dano_jogador(Player* p, int pontos) {
	p->vida -= pontos;
}

void amizade_jogador(Player* p, int pontos) {
	p->amzd += pontos;
}

void decisao_jogador(Player* p, int esc, int pos) {
	p->escolhas[pos] = esc;
}

void mata_jogador(Player* p) {
	free(p);
}