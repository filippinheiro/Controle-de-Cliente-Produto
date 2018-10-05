typedef struct Estoque {
  int tamanho;
} Estoque;

int getTamanho (Estoque* e) {
    return e->tamanho;
}

Estoque stageEstoque() {
  Estoque e;
  e.tamanho = 0;
  return e;
}

int setTamanho (Estoque* e,int v) {
  e->tamanho += v;
}
