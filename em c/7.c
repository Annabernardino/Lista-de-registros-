#include <stdio.h>

#define MAX 100

typedef struct {
    int numeroPedido;
    int numeroProduto;
    int quantidade;
} Venda;

typedef struct {
    int numeroProduto;
    float precoUnitario;
} Preco;

void cadastrarVendas(
    Venda vendas[],
    int *n) {

    *n = 0;

    printf("\n===== CADASTRO DE VENDAS =====\n");

    while (*n < MAX) {

        printf("\nNumero do pedido (-1 para terminar): ");
        scanf("%d", &vendas[*n].numeroPedido);

        if (vendas[*n].numeroPedido == -1)
            break;

        printf("Numero do produto: ");
        scanf("%d", &vendas[*n].numeroProduto);

        printf("Quantidade vendida: ");
        scanf("%d", &vendas[*n].quantidade);

        (*n)++;
    }
}

void cadastrarPrecos(
    Preco precos[],
    int *n) {

    *n = 0;

    printf("\n===== TABELA DE PRECOS =====\n");

    while (*n < MAX) {

        printf("\nNumero do produto (-1 para terminar): ");
        scanf("%d", &precos[*n].numeroProduto);

        if (precos[*n].numeroProduto == -1)
            break;

        printf("Preco unitario: ");
        scanf("%f", &precos[*n].precoUnitario);

        (*n)++;
    }
}

int buscarPreco(
    Preco precos[],
    int n,
    int numeroProduto,
    float *preco) {

    for (int i = 0; i < n; i++) {

        if (precos[i].numeroProduto == numeroProduto) {

            *preco = precos[i].precoUnitario;

            return 1;
        }
    }

    return 0;
}

void ordenarVendas(
    Venda vendas[],
    int n) {

    Venda temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (vendas[i].numeroPedido >
                vendas[j].numeroPedido) {

                temp = vendas[i];

                vendas[i] = vendas[j];

                vendas[j] = temp;
            }
        }
    }
}

void imprimirRelatorio(
    Venda vendas[],
    int n,
    Preco precos[],
    int nPrecos) {

    printf("\n");
    printf("==============================================================\n");
    printf("                       RELATORIO\n");
    printf("==============================================================\n");

    printf("%-12s %-12s %-12s %-18s %-15s\n",
           "PEDIDO",
           "PRODUTO",
           "QUANTIDADE",
           "PRECO UNITARIO",
           "TOTAL");

    printf("--------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {

        float preco;
        float total;

        printf("%-12d %-12d %-12d ",
               vendas[i].numeroPedido,
               vendas[i].numeroProduto,
               vendas[i].quantidade);

        if (buscarPreco(
                precos,
                nPrecos,
                vendas[i].numeroProduto,
                &preco)) {

            total =
                preco * vendas[i].quantidade;

            printf("R$ %-15.2f R$ %.2f\n",
                   preco,
                   total);

        } else {

            printf("%-18s %-15s\n",
                   "PRODUTO INEXISTENTE",
                   "PRODUTO INEXISTENTE");
        }
    }
}

int main() {

    Venda vendas[MAX];

    Preco precos[MAX];

    int nVendas;
    int nPrecos;

    cadastrarVendas(
        vendas,
        &nVendas
    );

    cadastrarPrecos(
        precos,
        &nPrecos
    );

    ordenarVendas(
        vendas,
        nVendas
    );

    imprimirRelatorio(
        vendas,
        nVendas,
        precos,
        nPrecos
    );

    return 0;
}