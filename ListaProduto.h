#ifndef LISTAPRODUTO_H
#define LISTAPRODUTO_H

#include "Produto.h"

typedef struct no {
	struct no* prox;
	Produto info;
} No;

typedef struct descritor {
	No* prim;
	No* ult;
	int n;
} Descritor; 

Descritor criarLista();


int estaVazia(Descritor*);

void insereProduto(Descritor*,Produto);

void remover(Descritor*,int);


//void libera(Descritor*);



void imprimeTudo(Descritor*);


#endif
