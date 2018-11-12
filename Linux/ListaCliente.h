#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "Cliente.h"


typedef struct nolista {
	Cliente info;
	struct nolista* prox;	
} NoLista;

NoLista* criar();

int vazia(NoLista*);

void removerCliente(NoLista**, char*);

void libera(NoLista**);

int tamanho(NoLista*);

NoLista* ultimo(NoLista*);

void insereOrdenado(NoLista**, Cliente);


void imprime(NoLista*);

NoLista* buscaElemento(NoLista*, char*);

#endif
