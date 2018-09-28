all: compila
compila: main.o ListaCliente.o ListaProduto.o Produto.o Cliente.o
	gcc main.o ListaCliente.o ListaProduto.o Produto.o Cliente.o -o prog
main.o: main.c
	gcc -c main.c
ListaCliente.o: ListaCliente.c
	gcc -c ListaCliente.c
ListaProduto.o:ListaProduto.c
	gcc -c ListaProduto.c
Produto.o: Produto.c
	gcc -c Produto.c
Cliente.o: Cliente.c
	gcc -c Cliente.c
clean:
	rm ListaCliente.o main.o ListaProduto.o Produto.o Cliente.o prog
