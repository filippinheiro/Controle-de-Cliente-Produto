#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct Estoque {
  int tamanho;
} Estoque;

int getTamanho (Estoque*);

Estoque stageEstoque();

int setTamanho (Estoque*,int);
#endif
