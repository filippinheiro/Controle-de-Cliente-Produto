#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
	int id;
	int qtd;
	char nome[30];
	char desc[80];
} Produto;



int idTrackP = 1;

Produto* criarProduto() {
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
		novo->id = idTrackP;
		idTrackP++;
	}
	setbuf(stdin, NULL);
	return novo;
}

void editarProduto(Produto* produto) {
	if(produto != NULL) {
		int a = 0;
		char resp;
		do {
		printf("Deseja alterar o nome do produto também? [s/n] >> ");
		setbuf(stdin, NULL);
		scanf("%c", resp);
		switch (resp) {
			case 's' : break;
			case 'n' : break;
			default: a = 1;
		}
	} while(a);
	if(resp == 's') {
  	printf("Digite o novo nome do produto >> ");
  	setbuf(stdin, NULL);
  	scanf("%30[^\n]", produto->nome);
	}
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
