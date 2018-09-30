#include <stdlib.h>
#include <stdio.h>

typedef struct cliente {
	int id;
	char nome[30];
} Cliente;

int idTrackC = 1;

Cliente* criarCliente() {
	Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
	if(novo!=NULL) {
		setbuf(stdin, NULL);
		printf("Digite o nome do novo cliente >> ");
		scanf("%30[^\n]", novo->nome);	
		novo->id = idTrackC;
		idTrackC++;
	}
	setbuf(stdin, NULL);
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
