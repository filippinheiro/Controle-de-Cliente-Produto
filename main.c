#include "ListaProduto.h"
#include "ListaCliente.h"
#include "Cliente.h"
#include "menu.h"
#include "Produto.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

void showMenu();
	
int main() {
    int a = true;
    NoLista* l = criar();
    Descritor d = criarLista();
    while(a) {
        showMenu();
        int opc;
        scanf(" %d", &opc);
        a = menu(opc, &l, &d);
        system("clear");
    }
    
        
} 



void showMenu() {
    printf("----------------MENU------------------\n");
    printf("1 - Cadastrar novo cliente\n");
    printf("2 - Remover cliente\n");
    printf("3 - Imprimir Clientes\n");
    printf("4 - Cadastrar novo produto\n");
    printf("5 - Remover produto\n");
    printf("6 - Imprimir produtos\n");
    printf("7 - Editar descrição de produtos\n");
    printf("8 - Registrar venda de produto\n");
    printf("9 - Sair\n");
    printf("Escolha uma opção:\n");
    printf("-------------------------------------------\n");
}

