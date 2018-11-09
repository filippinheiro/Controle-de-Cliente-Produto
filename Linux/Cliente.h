#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
	int id;
	char nome[30];
} Cliente;

Cliente* criarCliente();

void editarCliente(Cliente*);

void imprimeCliente(Cliente*);


#endif
