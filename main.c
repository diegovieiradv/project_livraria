#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_ACERVO 20

// Estrutura que representa um livro no acervo
struct Livro {
    int codigo;
    char titulo[50];
    char autor[50];
    char area[30];
    int ano;
    char editora[30];
};

// Ordena o acervo por ano crescente Bubble sort
void bubbleSort(struct Livro acervo[], int totalLivros) {
    for (int i = 0; i < totalLivros - 1; i++) {
        for (int j = 0; j < totalLivros - i - 1; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                struct Livro temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    // Acervo com limite fixo de 20 livros
    struct Livro acervo[TAMANHO_ACERVO];
    int Menu;
    int totalLivros = 0;

    // Loop principal do menu
    do {
        printf("------------------------- Menu ------------------------------\n\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por código\n");
        printf("4 - Ordenar livros por ano de publicação\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opção:  ");
        scanf("%d", &Menu);
        getchar(); // Consome o '\n' deixado pelo scanf

        // Tratamento das opções do menu
        switch (Menu) {

            case 1:
                // Cadastro de um novo livro no acervo
                if (totalLivros < TAMANHO_ACERVO) {
                    printf("Cadastro do livro %d\n", totalLivros + 1);

                    printf("Código: ");
                    scanf("%d", &acervo[totalLivros].codigo);
                    getchar();

                    // Uso de fgets para evitar problemas de buffer do printf
                    printf("Título: ");
                    fgets(acervo[totalLivros].titulo, 50, stdin);
                    acervo[totalLivros].titulo[strcspn(acervo[totalLivros].titulo, "\n")] = '\0';

                    printf("Autor: ");
                    fgets(acervo[totalLivros].autor, 50, stdin);
                    acervo[totalLivros].autor[strcspn(acervo[totalLivros].autor, "\n")] = '\0';

                    printf("Área: ");
                    fgets(acervo[totalLivros].area, 30, stdin);
                    acervo[totalLivros].area[strcspn(acervo[totalLivros].area, "\n")] = '\0';

                    printf("Ano de publicação: ");
                    scanf("%d", &acervo[totalLivros].ano);
                    getchar();

                    printf("Editora: ");
                    fgets(acervo[totalLivros].editora, 30, stdin);
                    acervo[totalLivros].editora[strcspn(acervo[totalLivros].editora, "\n")] = '\0';

                    totalLivros++;
                    printf("Livro cadastrado com sucesso!\n\n");
                } else {
                    printf("Acervo sem espaço! Não é possível cadastrar mais livros.\n\n");
                }

                // Mostra os livros ja cadastrados
                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado.\n\n");
                } else {
                    printf("Lista de livros:\n");
                    for (int i = 0; i < totalLivros; i++) {
                        printf("\nCódigo: %d\nTítulo: %s\nAutor: %s\nÁrea: %s\nAno: %d\nEditora: %s\n",
                               acervo[i].codigo, acervo[i].titulo, acervo[i].autor,
                               acervo[i].area, acervo[i].ano, acervo[i].editora);
                    }
                    printf("\n");
                }
                break;

            case 2:
                // Listagem completa de todos os livros no acervo
                printf("Imprimir todos os livros\n\n");
                printf("--- Dados dos livros ---\n");
                for (int i = 0; i < totalLivros; i++) {
                    printf("Livro %d:\n", i + 1);
                    printf("  Codigo: %d\n", acervo[i].codigo);
                    printf("  Título: %s\n", acervo[i].titulo);
                    printf("  Autor: %s\n", acervo[i].autor);
                    printf("  Area: %s\n", acervo[i].area);
                    printf("  Ano: %d\n", acervo[i].ano);
                    printf("  Editora: %s\n", acervo[i].editora);
                    printf("-----------------------\n");
                }
                break;

            case 3:
                // Busca de um livro por um código
                printf("Pesquisar livro por código\n\n");

                // Permite varias pesquisas ate o usuario digitar 5
                while (1) {
                    int codigoPesquisa;
                    int encontrado = 0;

                    printf("Digite o código do livro (ou 5 para sair): ");
                    scanf("%d", &codigoPesquisa);
                    getchar();

                    if (codigoPesquisa == 5) {
                        break;
                    }

                    for (int i = 0; i < totalLivros; i++) {
                        if (acervo[i].codigo == codigoPesquisa) {
                            printf("Livro encontrado:\n");
                            printf("Código: %d\n", acervo[i].codigo);
                            printf("Título: %s\n", acervo[i].titulo);
                            printf("Autor: %s\n", acervo[i].autor);
                            printf("Área: %s\n", acervo[i].area);
                            printf("Ano: %d\n", acervo[i].ano);
                            printf("Editora: %s\n\n", acervo[i].editora);
                            encontrado = 1;
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Livro %d não encontrado.\n\n", codigoPesquisa);
                    }
                }
                break;

            case 4:
                // Ordena o acervo e depois imprime os livros já ordenados por ano de lançamento
                printf("Ordenando livros por ano de publicação\n\n");
                bubbleSort(acervo, totalLivros);

                for (int i = 0; i < totalLivros; i++) {
                    printf("Livro %d:\n", i + 1);
                    printf("  Codigo: %d\n", acervo[i].codigo);
                    printf("  Título: %s\n", acervo[i].titulo);
                    printf("  Autor: %s\n", acervo[i].autor);
                    printf("  Area: %s\n", acervo[i].area);
                    printf("  Ano: %d\n", acervo[i].ano);
                    printf("  Editora: %s\n", acervo[i].editora);
                    printf("-----------------------\n");
                    printf("\n");
                }
                break;

            case 5:
                // Encerramento do programa
                printf("Sair do programa...\n");
                printf("Te esperamos novamente!\n");
                exit(0);
                break;

            default:
                // Opção inválida digitada pelo usuário
                printf("Opção inválida\n\n");
        }

    } while (Menu != 5);

    return 0;
}

