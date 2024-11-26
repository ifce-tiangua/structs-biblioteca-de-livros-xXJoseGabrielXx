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

void limpar_input() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

void preencher_livros(pLivro livros, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Livro %d:\n", i + 1);

        printf("Nome: ");
        fgets(livros[i].titulo, TAM_MAX, stdin);
        livros[i].titulo[strcspn(livros[i].titulo, "\n")] = '\0';

        printf("ISBN: ");
        fgets(livros[i].codigoISBN, TAM_MAX, stdin);
        livros[i].codigoISBN[strcspn(livros[i].codigoISBN, "\n")] = '\0';

        printf("Preço: ");
        scanf("%f", &livros[i].valor);

        printf("Score: ");
        scanf("%d", &livros[i].avaliacao);
        limpar_input();

        printf("Editora: ");
        fgets(livros[i].publicadora, TAM_MAX, stdin);
        livros[i].publicadora[strcspn(livros[i].publicadora, "\n")] = '\0';
    }
}

void mostrar_livros(pLivro livros, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].titulo);
        printf("ISBN: %s\n", livros[i].codigoISBN);
        printf("Preço: R$ %.2f\n", livros[i].valor);
        printf("Score: %d\n", livros[i].avaliacao);
        printf("Editora: %s\n", livros[i].publicadora);
        if (i < quantidade - 1) {
            printf("\n");
        }
    }
}

void liberar_livros(pLivro livros) {
    free(livros);
}

int main() {
    int quantidade;

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &quantidade);
    limpar_input();

    if (quantidade <= 0) {
        printf("Nenhum livro cadastrado.\n");
    } else {
        pLivro livros = alocar_livros(quantidade);

        preencher_livros(livros, quantidade);
        mostrar_livros(livros, quantidade);
        liberar_livros(livros);
    }

    return 0;
}
