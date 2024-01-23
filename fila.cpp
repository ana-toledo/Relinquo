#include "fila.hpp"

Fila* cria_fila() {
	/*alocação do ponteiro li para controlar a lista*/
	Fila* fi = (Fila*)malloc(sizeof(Fila));
	if (fi != NULL) {
		/*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
		fi->fim = NULL;
		fi->inicio = NULL;
	}
	return fi;
}

void insere_elemento(Fila* fi, int n) {
	/*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
	Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
	novo->num = n;
	novo->prox = NULL;
	/*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
	if (fi->inicio == NULL) {
		fi->inicio = novo;
		fi->fim = novo;
		/*caso a fila ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila*/
	}
	else {
		fi->fim->prox = novo;
		fi->fim = novo;
	}
}

bool consulta_fila(Fila* fi) {
	Elemento* aux;
	if (fi->inicio == NULL) {
		return true;
	}
	else {
		aux = fi->inicio;
		while (aux != NULL) {
			std::cout << aux->num << " ";
			aux = aux->prox;
		}
		return false;
	}
}

void remove_elemento_fila(Fila* fi) {
	Elemento* aux;
	if (fi->inicio == NULL) {
		std::cout << "\nFila Vazia!!";
	}
	else {
		aux = fi->inicio;
		fi->inicio = fi->inicio->prox;
		free(aux);
	}
}

/*a fila será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_fila(Fila* fi) {
	Elemento* aux;
	if (fi->inicio == NULL) {
		std::cout << "\nFila Vazia!!";
	}
	else {
		aux = fi->inicio;
		do {
			fi->inicio = fi->inicio->prox;
			free(aux);
			aux = fi->inicio;
		} while (aux != NULL);
		printf("\nFila Esvaziada!!");
	}
}