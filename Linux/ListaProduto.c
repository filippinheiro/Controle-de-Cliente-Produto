#include <stdlib.h>
#include <stdio.h>
#include "Produto.h"
##include "Estoque.h"

//TODO: criar função de registrar venda. DONE

typedef struct no {
	struct no* prox;
	Produto info;
} No;

typedef struct descritor {
	No* prim;
	No* ult;
	int n;
} Descritor;

Descritor criarLista() {
	Descritor d;
	d.n = 0;
	d.prim = NULL;
	d.ult = NULL;
	return d;
}



int estaVazia(Descritor* d) {
	return(d->n==0);
}


Produto* buscaPorId(Descritor* d, int id) {
    if(!estaVazia(d)) {
        No* p;
        for(p=d->prim; p != NULL && p->info.id != id; p=p->prox);
        if(p!=NULL)
            return (&p->info);
    }
    return NULL;
}


void insereProduto(Descritor* d, Produto produto, Estoque* e) {
	No* novo = (No*)malloc(sizeof(No));
	if(novo!=NULL) {
		novo->info = produto;
		novo->prox = NULL;
		if(!estaVazia(d))
			d->ult->prox = novo;
		else
			d->prim = novo;
		d->ult = novo;
		d->n++;
		setTamanho(e, (d->n+produto->qtd));
	system("echo salvo com sucesso; read b");
	} else {
		printf("Erro de memória!\n");
		exit(1);
	}
}

void remover(Descritor* d, int id) {
	No *p, *ant = NULL;
	for(p=d->prim; p!=NULL&&p->info.id!=id;p=p->prox)
		ant = p;
	if(p==NULL) {
		printf("Elemento não encontrado\n");
        system("read b");
    }
	else {
		if(ant==NULL) {
			d->prim = p->prox;
			if(d->prim==NULL)
				d->ult = NULL;
		} else {
			ant->prox = p->prox;
			if(p->prox==NULL)
				d->ult = ant;
		}
		free(p);
		d->n--;
	}
}

/*
void libera(Descritor* d){
	//Função de liberação da Lista
}

*/

void vender(Descritor* d, Produto* produto, int id) {
    if(produto != NULL) {
        produto->qtd--;
        if(produto->qtd == 0) {
            remover(d, id);
						if(buscaPorId(d,id)!=NULL) {
							printf("ERRO AO REMOVER ITEM\n");
							exit(1);
						}
				}
			printf("Venda registrada com sucesso!\n");
			system("read b");
    } else {
        printf("Elemento não encontrado\n");
        system("read b");
    }
}

void imprimeTudo(Descritor* d) {
	if(!estaVazia(d)) {
		No* n;
		for(n=d->prim; n!=NULL; n=n->prox)
			imprimirProduto(&n->info);
		printf("\n");
	} else
		printf("Lista Vazia!\n");
}
