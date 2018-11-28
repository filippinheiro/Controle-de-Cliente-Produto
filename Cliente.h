#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
	int id;
	char nome[30];
} Cliente;

Cliente* criarCliente(int);
Cliente* fcriarCliente(int, char*);
void editarCliente(Cliente*);

void imprimeCliente(Cliente*);


#endif
