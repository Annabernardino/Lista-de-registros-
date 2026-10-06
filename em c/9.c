#include <stdio.h>
#include <string.h>

#define MAX_COOPERADOS 1230
#define PREMIADOS_PRODUCAO 10
#define PREMIADOS_ANTIGUIDADE 15

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[100];
    char telefone[30];
    char cpf[20];
    char endereco[150];
    float quantidade;
    float totalReais;
    Data dataAssociacao;
} Cooperado;

int ehMaisAntigo(
    Data d1,
    Data d2) {

    if (d1.ano != d2.ano)
        return d1.ano < d2.ano;

    if (d1.mes != d2.mes)
        return d1.mes < d2.mes;

    return d1.dia < d2.dia;
}

void cadastrarCooperados(
    Cooperado cooperados[],
    int n) {

    for (int i = 0; i < n; i++) {

        cooperados[i].id = i + 1;

        printf("\n========================================\n");
        printf("COOPERADO %d\n", i + 1);
        printf("========================================\n");

        printf("Nome: ");
        scanf(" %99[^\n]", cooperados[i].nome);

        printf("Telefone: ");
        scanf(" %29[^\n]", cooperados[i].telefone);

        printf("CPF: ");
        scanf(" %19[^\n]", cooperados[i].cpf);

        printf("Endereco: ");
        scanf(" %149[^\n]", cooperados[i].endereco);

        printf("Quantidade entregue: ");
        scanf("%f", &cooperados[i].quantidade);

        printf("Total em reais: ");
        scanf("%f", &cooperados[i].totalReais);

        printf("Dia da associacao: ");
        scanf("%d",
              &cooperados[i].dataAssociacao.dia);

        printf("Mes da associacao: ");
        scanf("%d",
              &cooperados[i].dataAssociacao.mes);

        printf("Ano da associacao: ");
        scanf("%d",
              &cooperados[i].dataAssociacao.ano);
    }
}

void ordenarPorQuantidade(
    Cooperado cooperados[],
    int n) {

    Cooperado temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (cooperados[i].quantidade <
                cooperados[j].quantidade) {

                temp = cooperados[i];

                cooperados[i] = cooperados[j];

                cooperados[j] = temp;
            }
        }
    }
}

void ordenarPorAntiguidade(
    Cooperado cooperados[],
    int n) {

    Cooperado temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (ehMaisAntigo(
                    cooperados[j].dataAssociacao,
                    cooperados[i].dataAssociacao)) {

                temp = cooperados[i];

                cooperados[i] = cooperados[j];

                cooperados[j] = temp;
            }
        }
    }
}

int foiPremiado(
    int id,
    int premiados[]) {

    for (int i = 0; i < PREMIADOS_PRODUCAO; i++) {

        if (premiados[i] == id)
            return 1;
    }

    return 0;
}

void imprimirCooperado(
    Cooperado c,
    float bonus) {

    printf("\n----------------------------------------\n");

    printf("Nome: %s\n", c.nome);
    printf("Telefone: %s\n", c.telefone);
    printf("CPF: %s\n", c.cpf);
    printf("Endereco: %s\n", c.endereco);
    printf("Quantidade entregue: %.2f\n",
           c.quantidade);
    printf("Total em reais: R$ %.2f\n",
           c.totalReais);

    printf("Data de associacao: %02d/%02d/%d\n",
           c.dataAssociacao.dia,
           c.dataAssociacao.mes,
           c.dataAssociacao.ano);

    printf("Bonus de antiguidade: R$ %.2f\n",
           bonus);
}

void executarExercicio9(
    Cooperado cooperados[],
    int n) {

    Cooperado porQuantidade[MAX_COOPERADOS];

    Cooperado porAntiguidade[MAX_COOPERADOS];

    int premiados[PREMIADOS_PRODUCAO];

    for (int i = 0; i < n; i++) {

        porQuantidade[i] = cooperados[i];

        porAntiguidade[i] = cooperados[i];
    }

    /* Encontrar os 10 maiores produtores */

    ordenarPorQuantidade(
        porQuantidade,
        n
    );

    for (int i = 0;
         i < PREMIADOS_PRODUCAO;
         i++) {

        premiados[i] =
            porQuantidade[i].id;
    }

    /* Ordenar todos por antiguidade */

    ordenarPorAntiguidade(
        porAntiguidade,
        n
    );

    float totalDesembolso = 0.0;

    int contemplados = 0;

    printf("\n");
    printf("========================================\n");
    printf(" BENEFICIADOS POR TEMPO DE ASSOCIACAO\n");
    printf("========================================\n");

    for (int i = 0;
         i < n &&
         contemplados < PREMIADOS_ANTIGUIDADE;
         i++) {

        if (!foiPremiado(
                porAntiguidade[i].id,
                premiados)) {

            contemplados++;

            float bonus =
                porAntiguidade[i].totalReais *
                0.14;

            totalDesembolso += bonus;

            printf("\n%dº BENEFICIADO\n",
                   contemplados);

            imprimirCooperado(
                porAntiguidade[i],
                bonus
            );
        }
    }

    printf("\n========================================\n");
    printf("TOTAL DESEMBOLSADO: R$ %.2f\n",
           totalDesembolso);
    printf("========================================\n");
}

int main() {

    Cooperado cooperados[MAX_COOPERADOS];

    int n;

    printf("Quantidade de cooperados (maximo 1230): ");
    scanf("%d", &n);

    if (n < 25) {

        printf(
            "\nE necessario cadastrar pelo menos "
            "25 cooperados para realizar a selecao.\n"
        );

        return 0;
    }

    if (n > MAX_COOPERADOS)
        n = MAX_COOPERADOS;

    cadastrarCooperados(
        cooperados,
        n
    );

    executarExercicio9(
        cooperados,
        n
    );

    return 0;
}