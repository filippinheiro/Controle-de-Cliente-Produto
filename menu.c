#include <stdio.h>
#include <stdlib.h>
#include "ListaCliente.h"
#include "Cliente.h"
#include "Produto.h"
#include "ListaProduto.h"

#define true 1
#define false 0

//TODO: Acertar a busca por id dos produtos. DONE

int menu(int opc, NoLista** l, Descritor* d, FILE* f1, FILE* f2) {
    int id;
    char nome[30];
	switch(opc) {
        case 1 : opc1(l);
            return true;
        case 2 : printf("Digite o nome completo do cliente >> ");
            setbuf(stdin, NULL);
            scanf("%30[^\n]", nome);
            removerCliente(l, nome);
            return true;
        case 3 : imprime(*l);
            system("read b");
            return true;
        case 4 : opcao1(d);
            return true;
        case 5 : printf("Digite o id do produto a ser removido >> ");
            setbuf(stdin, NULL);
            scanf("%d", &id);
            remover(d, id);
            return true;
        case 6 : imprimeTudo(d);
            system("read b");
            return true;
        case 7 : printf("Digite o id do produto >> ");
             setbuf(stdin, NULL);
             scanf("%d", &id);
             editarProduto(buscaPorId(d, id));
            return true;
        case 8 : printf("Digite o id do produto >> ");
            setbuf(stdin, NULL);
            scanf("%d", &id);
            vender(d, buscaPorId(d, id), id);
            return true;
        case 9 : salvaTudoC(f1, l);
            salvaTudoP(f2, d);
            return false;
        } 
}
