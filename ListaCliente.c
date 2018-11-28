#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Cliente.h"

int idCount = 1;

typedef struct nolista {
	Cliente info;
	struct nolista* prox;
} NoLista;

void criar(NoLista** l) {
	*l = NULL;
}

int vazia(NoLista* l){
	return (l == NULL);
}

long tamanho(FILE* file) {
	long ponteiroAtual = ftell(file);
	fseek(file, 0, SEEK_END);
	long tamanho = ftell(file);
	fseek(file, ponteiroAtual, SEEK_SET);
	return tamanho;
}

void lerArquivoC(FILE* f, NoLista** l){
	if(f!=NULL){
		if(tamanho(f) > 0){
			criar(l);
			int idTracking = 1;
			while(!feof(f)){
				int id;
				char nome[30];
				fscanf(f, "%[^\t]%d\n", nome, &id);
				if(id > idTracking)
					idTracking = id;
				Cliente c = *fcriarCliente(id, nome);
				insereOrdenado(l, c, 1);
			} 
			idCount = idTracking;
			idCount++;
		} else
			criar(l);
	} else {
		printf("Erro no arquivo");
		exit(1);
	} 
}

void insereOrdenado(NoLista** l, Cliente cliente, int file) {
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
		if(!file) 
		system("echo Salvo com sucesso; read b");
	} else {
		printf("Falha de Memória!\n");
		exit(1);
	}
}

void opc1(NoLista** l){
	insereOrdenado(l, *criarCliente(idCount), 0);
	idCount++; 
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
		system("echo removido com sucesso; read b");
	}
}

NoLista* ultimo(NoLista* l) {
	NoLista *p;
	for(p=l; p->prox != NULL; p=p->prox);
	return p;
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

void salvaTudoC(FILE* file, NoLista** l) {
    if(file != NULL) {
		NoLista* cliente;
        for(cliente = *l; cliente != NULL; cliente = cliente->prox){
            fprintf(file,"%s\t%d\n", cliente->info.nome, cliente->info.id);
        }
	}
} 