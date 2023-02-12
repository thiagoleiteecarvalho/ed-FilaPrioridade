/*
 * fila.h
 * Header de definição da ED Fila de Prioridade.
 * Author: Thiago Leite
 */

#pragma once

typedef struct elemento {
 char valor;
 int prioridade;
 struct elemento *proximo;
} Elemento;

typedef struct fila {
 Elemento *cabeca;
 Elemento *fim;
 int tamanho;
} Fila;

Fila* iniciar();
void enqueue(Fila *f, char caractere, int prioridade);
int size(Fila *f);
char head(Fila *f);
char dequeue(Fila *f);
int empty(Fila *f);
void exibir(Fila *f);
