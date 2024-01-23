#ifndef __FILA_HPP__
#define __FILA_HPP__

#include <stdlib.h>
#include <iostream>

/*registro que reprensentará cada elemento da fila*/
typedef struct Elemento{
	int num;
	struct Elemento* prox;
} Elemento;

/*registro do tipo Fila contento dois ponteiros do tipo nó para controlar a fila*/
typedef struct {
	struct Elemento* inicio; /*aponta para o elemento do início da fila*/
	struct Elemento* fim; /*aponta para o elemento do fim da fila*/
} Fila;

Fila* cria_fila();
void insere_elemento(Fila* fi, int n);
bool consulta_fila(Fila* fi);
void remove_elemento_fila(Fila* fi);
void esvazia_fila(Fila* fi);

#endif