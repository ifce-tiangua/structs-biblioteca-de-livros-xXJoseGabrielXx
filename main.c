#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 200

typedef struct {
    char titulo[TAM_MAX];
    char codigoISBN[TAM_MAX];
    float valor;
    int avaliacao;
    char publicadora[TAM_MAX];
} Livro, *pLivro;

pLivro alocar_livros(int quantidade) {
    return (pLivro)malloc(quantidade * sizeof(Livro));
}

void limpar_buffer() {
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF) {}
}

void preencher_livros(pLivro livros, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        scanf("%[^\n]s", livros[i].titulo);
        limpar_buffer();
        scanf("%[^\n]s", livros[i].codigoISBN);
        limpar_buffer();
        scanf("%f", &livros[i].valor);
        scanf("%d", &livros[i].avaliacao);
        limpar_buffer();
        scanf("%[^\n]s", livros[i].publicadora);
        limpar_buffer();
    }
}

void exibir_livros(pLivro livros, int quantidade) {
    for (int indice = 0; indice < quantidade; indice++) {
        printf("Livro %d:\n", indice + 1);
        printf("Nome: %s\n", livros[indice].titulo);
        printf("ISBN: %s\n", livros[indice].codigoISBN);
        printf("Preço: R$ %.2f\n", livros[indice].valor);
        printf("Score: %d\n", livros[indice].avaliacao);
        printf("Editora: %s\n", livros[indice].publicadora);
        if (indice < quantidade - 1) {
            printf("\n");
        }
    }
}

void liberar_livros(pLivro livros) {
    free(livros);
}

int main() {
    int quantidade;

    scanf("%d", &quantidade);
    limpar_buffer();

    if (quantidade == 0) {
        printf("Sem livros\n");
    } else {
        pLivro livros = alocar_livros(quantidade);

        preencher_livros(livros, quantidade);
        exibir_livros(livros, quantidade);
        liberar_livros(livros);
    }

    return 0;
}

