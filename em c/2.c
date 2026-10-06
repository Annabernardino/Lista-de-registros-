#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 200
#define SEMANAS 4
#define DIAS 6

typedef struct {
    char nome[100];
    int codigo;
    float preco;
    int baixas[SEMANAS][DIAS];
} Produto;

void cadastrarProdutos(Produto produtos[], int *n) {

    printf("Quantidade de produtos (maximo 200): ");
    scanf("%d", n);

    if (*n > MAX_PRODUTOS)
        *n = MAX_PRODUTOS;

    for (int i = 0; i < *n; i++) {

        printf("\n===== PRODUTO %d =====\n", i + 1);

        printf("Nome: ");
        scanf(" %99[^\n]", produtos[i].nome);

        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("\nDigite as baixas do produto:\n");

        for (int semana = 0; semana < SEMANAS; semana++) {

            printf("\n--- %d Semana ---\n", semana + 1);

            for (int dia = 0; dia < DIAS; dia++) {

                printf("Dia %d: ", dia + 1);
                scanf("%d", &produtos[i].baixas[semana][dia]);
            }
        }
    }
}

int buscarProduto(Produto produtos[], int n, int codigo) {

    for (int i = 0; i < n; i++) {

        if (produtos[i].codigo == codigo)
            return i;
    }

    return -1;
}

/* Letra A */
void segundaSemana(Produto produtos[], int n) {

    int codigo;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("\n===== PRODUTO =====\n");
    printf("Nome: %s\n", produtos[posicao].nome);
    printf("Codigo: %d\n", produtos[posicao].codigo);
    printf("Preco: R$ %.2f\n", produtos[posicao].preco);

    printf("\nBaixas da segunda semana:\n");

    for (int dia = 0; dia < DIAS; dia++) {

        printf("Dia %d: %d\n",
               dia + 1,
               produtos[posicao].baixas[1][dia]);
    }
}

/* Letra B */
void totalPorDia(Produto produtos[], int n) {

    int codigo;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("\n===== TOTAL DE BAIXAS POR DIA =====\n");

    for (int dia = 0; dia < DIAS; dia++) {

        int total = 0;

        for (int semana = 0; semana < SEMANAS; semana++) {

            total += produtos[posicao].baixas[semana][dia];
        }

        printf("Dia %d: %d\n", dia + 1, total);
    }
}

/* Letra C */
void maiorBaixaDia(Produto produtos[], int n) {

    int codigo;
    int dia;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("Digite o dia da semana (1 a 6): ");
    scanf("%d", &dia);

    if (dia < 1 || dia > 6) {

        printf("\nDia invalido.\n");
        return;
    }

    dia--;

    int maior = produtos[posicao].baixas[0][dia];

    for (int semana = 1; semana < SEMANAS; semana++) {

        if (produtos[posicao].baixas[semana][dia] > maior) {

            maior = produtos[posicao].baixas[semana][dia];
        }
    }

    printf("\nMaior baixa no dia %d: %d\n", dia + 1, maior);
}

/* Letra D */
void diaMaiorBaixa(Produto produtos[], int n) {

    int codigo;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    int totais[DIAS];

    for (int dia = 0; dia < DIAS; dia++) {

        totais[dia] = 0;

        for (int semana = 0; semana < SEMANAS; semana++) {

            totais[dia] += produtos[posicao].baixas[semana][dia];
        }
    }

    int maiorDia = 0;

    for (int dia = 1; dia < DIAS; dia++) {

        if (totais[dia] > totais[maiorDia]) {

            maiorDia = dia;
        }
    }

    printf("\nDia com maior baixa: Dia %d\n", maiorDia + 1);
    printf("Total de baixas: %d\n", totais[maiorDia]);
}

/* Letra E */
void totalSemana(Produto produtos[], int n) {

    int codigo;
    int semana;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("Digite a semana (1 a 4): ");
    scanf("%d", &semana);

    if (semana < 1 || semana > 4) {

        printf("\nSemana invalida.\n");
        return;
    }

    semana--;

    int total = 0;

    for (int dia = 0; dia < DIAS; dia++) {

        total += produtos[posicao].baixas[semana][dia];
    }

    printf("\nTotal de movimentacao na semana %d: %d\n",
           semana + 1, total);
}

/* Letra F */
void totalCadaSemana(Produto produtos[], int n) {

    int codigo;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    printf("\n===== TOTAL POR SEMANA =====\n");

    for (int semana = 0; semana < SEMANAS; semana++) {

        int total = 0;

        for (int dia = 0; dia < DIAS; dia++) {

            total += produtos[posicao].baixas[semana][dia];
        }

        printf("Semana %d: %d\n", semana + 1, total);
    }
}

/* Letra G */
void totalTodasSemanas(Produto produtos[], int n) {

    int codigo;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigo);

    int posicao = buscarProduto(produtos, n, codigo);

    if (posicao == -1) {

        printf("\nProduto nao encontrado.\n");
        return;
    }

    int total = 0;

    for (int semana = 0; semana < SEMANAS; semana++) {

        for (int dia = 0; dia < DIAS; dia++) {

            total += produtos[posicao].baixas[semana][dia];
        }
    }

    printf("\nTotal de movimentacao de todas as semanas: %d\n",
           total);
}

/* Letra H */
void relatorioTodosProdutos(Produto produtos[], int n) {

    printf("\n========================================\n");
    printf("RELATORIO DE TODOS OS PRODUTOS\n");
    printf("========================================\n");

    for (int i = 0; i < n; i++) {

        int totalGeral = 0;

        printf("\nProduto: %s\n", produtos[i].nome);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Preco: R$ %.2f\n", produtos[i].preco);

        printf("\nTotais por semana:\n");

        for (int semana = 0; semana < SEMANAS; semana++) {

            int totalSemana = 0;

            for (int dia = 0; dia < DIAS; dia++) {

                totalSemana +=
                    produtos[i].baixas[semana][dia];
            }

            totalGeral += totalSemana;

            printf("Semana %d: %d\n",
                   semana + 1,
                   totalSemana);
        }

        printf("Total geral: %d\n", totalGeral);
    }
}

int main() {

    Produto produtos[MAX_PRODUTOS];

    int n;
    int opcao;

    cadastrarProdutos(produtos, &n);

    do {

        printf("\n\n========================================\n");
        printf("              MENU ESTOQUE\n");
        printf("========================================\n");
        printf("1 - Produto e baixas da segunda semana\n");
        printf("2 - Total de baixas por dia\n");
        printf("3 - Maior baixa de um dia\n");
        printf("4 - Dia com maior baixa\n");
        printf("5 - Total de uma semana\n");
        printf("6 - Total de cada semana\n");
        printf("7 - Total de todas as semanas\n");
        printf("8 - Relatorio de todos os produtos\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                segundaSemana(produtos, n);
                break;

            case 2:
                totalPorDia(produtos, n);
                break;

            case 3:
                maiorBaixaDia(produtos, n);
                break;

            case 4:
                diaMaiorBaixa(produtos, n);
                break;

            case 5:
                totalSemana(produtos, n);
                break;

            case 6:
                totalCadaSemana(produtos, n);
                break;

            case 7:
                totalTodasSemanas(produtos, n);
                break;

            case 8:
                relatorioTodosProdutos(produtos, n);
                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}