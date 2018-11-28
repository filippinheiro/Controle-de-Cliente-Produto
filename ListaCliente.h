#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "Cliente.h"
#include <stdio.h>

typedef struct nolista {
	Cliente info;
	struct nolista* prox;	
} NoLista;

void criar(NoLista**);

long tamanho(FILE*);

void opc1(NoLista** l);

int vazia(NoLista*);

void removerCliente(NoLista**, char*);

void libera(NoLista**);

NoLista* ultimo(NoLista*);

void insereOrdenado(NoLista**, Cliente, int);


void imprime(NoLista*);

void lerArquivoC(FILE*, NoLista**);

void salvaTudoC(FILE*, NoLista**);

NoLista* buscaElemento(NoLista*, char*);

#endif
