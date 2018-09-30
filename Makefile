all: compila
	./prog
compila: main.o ListaCliente.o ListaProduto.o Produto.o Cliente.o menu.o
	gcc main.o ListaCliente.o ListaProduto.o Produto.o Cliente.o menu.o -o prog
main.o: main.c
	gcc -c main.c
ListaCliente.o: ListaCliente.c
	gcc -c ListaCliente.c
ListaProduto.o:ListaProduto.c
	gcc -c ListaProduto.c
menu.o: menu.c
	gcc -c menu.c
Produto.o: Produto.c
	gcc -c Produto.c
Cliente.o: Cliente.c
	gcc -c Cliente.c
clean:
	rm ListaCliente.o main.o ListaProduto.o Produto.o Cliente.o prog
