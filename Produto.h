#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct produto {
	int id, qtd;
	char nome[30], desc[80];
} Produto;

Produto* criarProduto(int);
Produto* fcriarProduto(int, int, char*, char*);
void editarProduto(Produto*);

void imprimirProduto(Produto*);

#endif
