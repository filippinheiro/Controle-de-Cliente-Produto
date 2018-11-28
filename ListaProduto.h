#ifndef LISTAPRODUTO_H
#define LISTAPRODUTO_H

#include "Produto.h"
#include <stdio.h>

typedef struct no {
	struct no* prox;
	Produto info;
} No;

typedef struct descritor {
	No* prim;
	No* ult;
	int n;
} Descritor;

void criarLista(Descritor*);

void opcao1(Descritor*);

Produto* buscaPorId(Descritor*, int);

void vender(Descritor*, Produto*, int);

int estaVazia(Descritor*);

void insereProduto(Descritor*,Produto, int);

void remover(Descritor*,int);


//void libera(Descritor*);

void salvaTudoP(FILE*, Descritor*);

void lerArquivoP(FILE*, Descritor*);

void imprimeTudo(Descritor*);


#endif
