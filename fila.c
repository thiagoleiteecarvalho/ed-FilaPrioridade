/*
 * fila.c
 * Classe de implemantação da ED Fila de Prioridade.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* iniciar() {

	Fila *f = malloc(sizeof(Fila));
	f->cabeca = NULL;
	f->fim = NULL;
	f->tamanho = 0;

	return f;
}

void enqueue(Fila *f, char caractere, int prioridade) {

	Elemento *e = malloc(sizeof(Elemento));
	e->valor = caractere;
	e->prioridade = prioridade;
	e->proximo = NULL;

	if (f->cabeca == NULL) {

		f->cabeca = e;
		f->fim = e;

		f->tamanho = f->tamanho + 1;
	} else {

		if (e->prioridade > f->fim->prioridade) {

			f->fim->proximo = e;
			f->fim = e;

			f->tamanho = f->tamanho + 1;

			return;
		}

		if (e->prioridade < f->cabeca->prioridade) {

			e->proximo = f->cabeca;
			f->cabeca = e;

			f->tamanho = f->tamanho + 1;

			return;
		}

		Elemento *controle = f->cabeca;
		Elemento *anterior;

		while (controle->proximo != NULL) {

			if (e->prioridade < controle->prioridade) {

				e->proximo = controle;
				anterior->proximo = e;

				f->tamanho = f->tamanho + 1;

				return;
			} else {
				anterior = controle;
				controle = controle->proximo;
			}
		}

		 free(anterior);
		 free(controle);
		 anterior = NULL;
		 controle = NULL;
	}
}

int size(Fila *f) {
	return f->tamanho;
}

char head(Fila *f) {

	if (!empty(f)) {
		return f->cabeca->valor;
	}

	return '\0';
}

char dequeue(Fila *f) {

	Elemento *e;
	char caracter;

	if (!empty(f)) {

		e = f->cabeca;
		caracter = e->valor;

		f->cabeca = e->proximo;

		if (empty(f)) {
			f->fim = NULL;
		}

		f->tamanho = f->tamanho - 1;
		free(e);

		return caracter;
	} else {
		printf("Fila vazia.\n");
		return '\0';
	}
}

int empty(Fila *f) {
	return f->tamanho == 0;
}

void exibir(Fila *f) {

	if (empty(f)) {

		printf("Fila vazia!\n");
		return;
	}

	Elemento *e;
	e = f->cabeca;
	printf("Fila:\n");

	while (e != NULL) {

		printf(" %c[%d]", e->valor, e->prioridade);
		e = e->proximo;
	}

	printf("\n");
}
