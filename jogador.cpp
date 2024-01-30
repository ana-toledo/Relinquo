#include "jogador.hpp"

Player* cria_jogador() {
	Player* p = NULL;
	p = (Player*)malloc(sizeof(Player));
	if (p == NULL) return NULL;
	p->dia = 1;
	for (int i = 0; i < 3; i++) {
		for(int j = 0; j < 5; j++)
			p->reply_mail[i][j] = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++)
			p->has_replied[i][j] = false;
	}
	p->hook = false;
	p->medkit = false;
	p->laser = false;
	p->combustivel = false;
	p->peca = false;
	p->read_info = false;
	p->new_message = false;
	p->dinheiro = 100;
	return p;
}

void passa_dia(Player* p) {
	p->dia++;
}


void resp_jogador(Player* p, int dia, int pos, int esc) {
	p->reply_mail[dia][pos] = esc;
}

void replied(Player* p, int dia, int pos) {
	p->has_replied[dia][pos] = true;
}

void bought_mask(Player* p) {
	if (p->dinheiro >= 40)
	p->dinheiro -= 40;
}

void bought_laser(Player* p) {
	if (p->dinheiro >= 80) {
		p->laser = true;
		p->dinheiro -= 80;
	}
}

void bought_medkit(Player* p) {
	if (p->dinheiro >= 20) {
		p->medkit = true;
		p->dinheiro -= 20;
	}
}

void bought_hook(Player* p) {
	if (p->dinheiro >= 60) {
		p->hook = true;
		p->dinheiro -= 60;
	}
}

void mata_jogador(Player* p) {
	free(p);
}

void update_read_info(Player* p) {
	p->read_info = true;
}