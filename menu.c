#include <stdio.h>
#include "ListaCliente.h"
#include "Cliente.h"
#include "Produto.h"
#include "ListaProduto.h"

#define true 1
#define false 0

//TODO: Acertar a busca por id dos produtos.

int menu(int opc, NoLista** l, Descritor* d) {
    int id, id2;
	switch(opc) {
        case 1 : insereOrdenado(l, *criarCliente());
            return true;
        case 2 : printf("Digite o nome completo do cliente >> ");
            char nome[30];
            setbuf(stdin, NULL);
            scanf("%30[^\n]", nome);
            removerCliente(l, "Filipe");
            return true;
        case 3 : imprime(*l);
            return true;
        case 4 : insereProduto(d, *criarProduto());
            return true;
        case 5 : printf("Digite o id do produto a ser removido >> ");
            setbuf(stdin, NULL);
            scanf(" &d", &id);
            remover(d, id);
            return true;
        case 6 : imprimeTudo(d);
            return true;
        case 7 : printf("Digite o id do produto >> ");
             setbuf(stdin, NULL);
             scanf(" &d", &id2);
             editarProduto(buscaPorId(d, id2));
            return true;
        case 8 : 
            return false;
        case 9 : 
            return false;
        }
}
