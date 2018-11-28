#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cliente {
	int id;
	char nome[30];
} Cliente;

Cliente* criarCliente(int id) {
	Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
	if(novo!=NULL) {
		setbuf(stdin, NULL);
		printf("Digite o nome do novo cliente >> ");
		scanf("%30[^\n]", novo->nome);	
		novo->id = id;
	}
	setbuf(stdin, NULL);
	return novo;
}

Cliente* fcriarCliente(int id, char* nome) {
	Cliente* novo  =(Cliente*)malloc(sizeof(Cliente));
	if(novo!=NULL){
		novo->id = id;
		strcpy(novo->nome, nome);
	}
	return novo;
}

void editarCliente(Cliente* cliente){
	if(cliente!=NULL) {
		printf("Digite o novo nome do cliente >> ");
		scanf("%30[^\n]", cliente->nome);
		setbuf(stdin, NULL);
	} else 
		printf("Cliente inexistente!\n");	
}

void imprimeCliente(Cliente* cliente) {
	if(cliente!=NULL) 
		printf("%d: %s\n", cliente->id, cliente->nome);
	else
		printf("Cliente inexistente!\n");
} 
