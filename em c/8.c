#include <stdio.h>
#include <string.h>

#define MAX_COOPERADOS 1230
#define PREMIADOS 10

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

void cadastrarCooperados(
    Cooperado cooperados[],
    int n) {

    for (int i = 0; i < n; i++) {

        printf("\n========================================\n");
        printf("COOPERADO %d\n", i + 1);
        printf("========================================\n");

        cooperados[i].id = i + 1;

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

        printf("Total em reais da producao entregue: ");
        scanf("%f", &cooperados[i].totalReais);

        printf("Data de associacao:\n");

        printf("Dia: ");
        scanf("%d", &cooperados[i].dataAssociacao.dia);

        printf("Mes: ");
        scanf("%d", &cooperados[i].dataAssociacao.mes);

        printf("Ano: ");
        scanf("%d", &cooperados[i].dataAssociacao.ano);
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

float percentualPremio(int posicao) {

    return 20.0 - (posicao * 2.0);
}

void imprimirCooperado(
    Cooperado c,
    float percentual,
    float bonus) {

    printf("\n----------------------------------------\n");

    printf("Nome: %s\n", c.nome);
    printf("Telefone: %s\n", c.telefone);
    printf("CPF: %s\n", c.cpf);
    printf("Endereco: %s\n", c.endereco);
    printf("Quantidade entregue: %.2f\n",
           c.quantidade);
    printf("Total produzido: R$ %.2f\n",
           c.totalReais);

    printf("Data de associacao: %02d/%02d/%d\n",
           c.dataAssociacao.dia,
           c.dataAssociacao.mes,
           c.dataAssociacao.ano);

    printf("Percentual do premio: %.2f%%\n",
           percentual);

    printf("Acrescimo: R$ %.2f\n",
           bonus);
}

void premiarCooperados(
    Cooperado cooperados[],
    int n) {

    ordenarPorQuantidade(
        cooperados,
        n
    );

    float totalDesembolso = 0.0;

    printf("\n");
    printf("========================================\n");
    printf("       COOPERADOS BENEFICIADOS\n");
    printf("========================================\n");

    for (int i = 0; i < PREMIADOS; i++) {

        float percentual =
            percentualPremio(i);

        float bonus =
            cooperados[i].totalReais *
            percentual / 100.0;

        totalDesembolso += bonus;

        printf("\n%dº COLOCADO\n", i + 1);

        imprimirCooperado(
            cooperados[i],
            percentual,
            bonus
        );
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

    if (n < 10) {

        printf("\nE necessario cadastrar pelo menos 10 cooperados.\n");

        return 0;
    }

    if (n > MAX_COOPERADOS)
        n = MAX_COOPERADOS;

    cadastrarCooperados(
        cooperados,
        n
    );

    premiarCooperados(
        cooperados,
        n
    );

    return 0;
}