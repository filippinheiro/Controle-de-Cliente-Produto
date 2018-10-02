#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cliente.h"
typedef struct nolista {
	Cliente info;
	struct nolista* prox;	
} NoLista;

NoLista* criar() {
	return NULL;
}

int vazia(NoLista* l){
	return (l == NULL);
} 

void insereOrdenado(NoLista** l, Cliente cliente) {
	NoLista *p, *tmp = NULL;
	for(p=*l; p!=NULL && strcmp(p->info.nome, cliente.nome) < 0; p=p->prox)
		tmp = p;
	NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
	if(novo!=NULL) {
		if(tmp == NULL) {
			novo->info = cliente;
			novo->prox = p;
			*l = novo;
		} else	{
			novo->info = cliente;
			novo->prox = p;
			tmp->prox = novo;
		}
	} else {
		printf("Falha de Memória!\n");
		exit(1);
	}
}


NoLista* buscaElemento(NoLista* l, char* nome){
	for(l; l != NULL && l->info.nome!=nome; l=l->prox);
	return l;
} 

void removerCliente(NoLista** l, char* nome) {
	NoLista *p, *ant = NULL;
	for(p=*l; p != NULL && strcmp(p->info.nome,nome) != 0; p=p->prox)
		ant = p;
	if(p==NULL) { 		
		printf("Elemento não encontrado\n");
        system("read b");
    }
	else {
		if (ant == NULL) 
			*l = p->prox;
		else
			ant->prox = p->prox;
		free(p);
	} 
}	

void liberaLista(NoLista** l) {
	NoLista *p, *tmp;
	for(p=*l; p!=NULL; p=tmp) { 
		tmp=p->prox;
		free(p);
	} 
	*l = criar();
}  

NoLista* ultimo(NoLista* l) {
	NoLista *p;
	for(p=l; p->prox != NULL; p=p->prox);
	return p;
} 

int tamanho(NoLista* l) {
	int i = 0;
	NoLista* p;
	for (p=l; p!=NULL; p=p->prox)
		i++;
	return i;
}

void imprime(NoLista *l){
	if(!vazia(l)) {
		NoLista* p;
		int i = 1;
		for(p=l; p!=NULL; p=p->prox) {
			imprimeCliente(&p->info);
			i++;
		} 
	} else {
		printf("Lista Vazia!\n");
	}	
} 
