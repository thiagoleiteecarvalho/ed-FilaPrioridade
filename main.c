/*
 * main.c
 * Classe principal de execução da Fila de Prioridade.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void) {

	Fila *fila = iniciar();

	if (!fila) {

		printf("Sem memoria disponivel!\n");
		exit(1);
	} else {

		int opcao;
		char valor;
		int prioridade;
		int tamanho;

		do {

			printf("\n");
			printf("Escolha a opcao\n");
			printf("FILA DE PRIORIDADE\n");
			printf("0. Sair\n");
			printf("1. ENQUEUE\n");
			printf("2. HEAD\n");
			printf("3. DEQUEUE\n");
			printf("4. SIZE\n");
			printf("5. Exibir fila\n");
			printf("Digite uma opção:");
			scanf("%d", &opcao);

			switch (opcao) {
			case 0:
				exit(1);
				break;

			case 1:
				printf("Digite um valor a ser enfileirado:");
				scanf(" %c", &valor);
				printf("Digite a prioridade(maior que 0):");
				scanf(" %d", &prioridade);
				enqueue(fila, valor, prioridade);
				break;

			case 2:
				valor = head(fila);
				if (valor)
					printf("Cabeça da fila: %c\n\n", valor);
				else
					printf("Fila vazia.\n");
				break;

			case 3:
				valor = dequeue(fila);
				if (valor)
					printf("Elemento desenfileirado: %c\n\n", valor);
				break;

			case 4:
				tamanho = size(fila);
				printf("Quantidade de elementos da fila: %d\n\n", tamanho);
				break;

			case 5:
				exibir(fila);
				break;

			default:
				printf("Comando invalido\n\n");
				break;
			}

		} while (opcao);

		free(fila);
		return 0;
	}
}
