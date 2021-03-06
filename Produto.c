#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
	int id;
	int qtd;
	char nome[30];
	char desc[80];
} Produto;

Produto* criarProduto(int id) {
	Produto* novo = (Produto*)malloc(sizeof(Produto));
	if(novo!=NULL) {
		setbuf(stdin, NULL);
		printf("Digite o nome do novo produto >> ");
		scanf("%30[^\n]", novo->nome);
		setbuf(stdin, NULL);
		printf("Digite a descrição do produto >> ");
		scanf("%80[^\n]", novo->desc);
		setbuf(stdin, NULL);
		printf("Digite a quantidade em estoque >> ");
		scanf("%d", &novo->qtd);
		novo->id = id;
	}
	setbuf(stdin, NULL);
	return novo;
}

Produto* fcriarProduto(int id, int qtd, char* nome, char* desc){
	Produto* novo = (Produto*)malloc(sizeof(Produto));
	if(novo!=NULL){
		novo->id = id;
		novo->qtd = qtd;
		strcpy(novo->nome, nome);
		strcpy(novo->desc, desc);
	} 
	return novo;
}

void editarProduto(Produto* produto) {
	if(produto != NULL) {
        printf("Digite o novo nome do produto >> ");
        setbuf(stdin, NULL);
        scanf("%30[^\n]", produto->nome);
		printf("Digite a nova descrição do produto >> ");
        setbuf(stdin, NULL);
		scanf("%80[^\n]", produto->desc);
	} else {
		printf("Produto inexistente!\n");
        system("read b");
    }
} 

void imprimirProduto(Produto* produto) {
	if(produto!=NULL) 
		printf("%d: %s - %s Qtde: %d\n", produto->id, produto->nome, produto->desc, produto->qtd);
	else
		printf("Produto inexistente!\n");
} 
