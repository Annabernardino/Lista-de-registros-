#include <stdio.h>
#include <string.h>

#define MAX 500

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char rua[100];
    int numero;
    char bairro[100];
} Endereco;

typedef struct {
    int codigo;
    char nome[100];
    Endereco endereco;
    float salario;
    Data dataContratacao;
} Funcionario;

void cadastrarFuncionarios(Funcionario funcionarios[], int *n) {

    printf("Quantidade de funcionarios (maximo 500): ");
    scanf("%d", n);

    if (*n > MAX)
        *n = MAX;

    for (int i = 0; i < *n; i++) {

        printf("\n--- Funcionario %d ---\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &funcionarios[i].codigo);

        printf("Nome: ");
        scanf(" %99[^\n]", funcionarios[i].nome);

        printf("Nome da rua: ");
        scanf(" %99[^\n]", funcionarios[i].endereco.rua);

        printf("Numero: ");
        scanf("%d", &funcionarios[i].endereco.numero);

        printf("Bairro: ");
        scanf(" %99[^\n]", funcionarios[i].endereco.bairro);

        printf("Salario: ");
        scanf("%f", &funcionarios[i].salario);

        printf("Data de contratacao:\n");

        printf("Dia: ");
        scanf("%d", &funcionarios[i].dataContratacao.dia);

        printf("Mes: ");
        scanf("%d", &funcionarios[i].dataContratacao.mes);

        printf("Ano: ");
        scanf("%d", &funcionarios[i].dataContratacao.ano);
    }
}

void imprimirFuncionario(Funcionario f) {

    printf("\nCodigo: %d", f.codigo);
    printf("\nNome: %s", f.nome);
    printf("\nRua: %s", f.endereco.rua);
    printf("\nNumero: %d", f.endereco.numero);
    printf("\nBairro: %s", f.endereco.bairro);
    printf("\nSalario: R$ %.2f", f.salario);
    printf("\nData de contratacao: %02d/%02d/%d\n",
           f.dataContratacao.dia,
           f.dataContratacao.mes,
           f.dataContratacao.ano);
}

/* Letra A */
void salarios(Funcionario funcionarios[], int n, float salarioMinimo) {

    printf("\n========================================");
    printf("\nFUNCIONARIOS ACIMA DE 5 SALARIOS MINIMOS");
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {

        if (funcionarios[i].salario > 5 * salarioMinimo) {
            imprimirFuncionario(funcionarios[i]);
        }
    }

    printf("\n========================================");
    printf("\nFUNCIONARIOS ABAIXO DE 2 SALARIOS MINIMOS");
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {

        if (funcionarios[i].salario < 2 * salarioMinimo) {
            imprimirFuncionario(funcionarios[i]);
        }
    }
}

/* Letra B */
void funcionariosDoMes(Funcionario funcionarios[], int n, int mes) {

    printf("\n========================================");
    printf("\nFUNCIONARIOS CONTRATADOS NO MES %d", mes);
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {

        if (funcionarios[i].dataContratacao.mes == mes) {
            imprimirFuncionario(funcionarios[i]);
        }
    }
}

/* Letra C */
void ordenarPorNome(Funcionario funcionarios[], int n) {

    Funcionario temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (strcmp(funcionarios[i].nome,
                       funcionarios[j].nome) > 0) {

                temp = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = temp;
            }
        }
    }

    printf("\n========================================");
    printf("\nFUNCIONARIOS EM ORDEM CRESCENTE DE NOME");
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {
        imprimirFuncionario(funcionarios[i]);
    }
}

/* Letra D */
void ordenarPorSalario(Funcionario funcionarios[], int n) {

    Funcionario temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (funcionarios[i].salario <
                funcionarios[j].salario) {

                temp = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = temp;
            }
        }
    }

    printf("\n========================================");
    printf("\nFUNCIONARIOS EM ORDEM DECRESCENTE DE SALARIO");
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {
        imprimirFuncionario(funcionarios[i]);
    }
}

/* Letra E */
void ordenarPorBairroRua(Funcionario funcionarios[], int n) {

    Funcionario temp;
    int comparacao;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            comparacao = strcmp(
                funcionarios[i].endereco.bairro,
                funcionarios[j].endereco.bairro
            );

            if (comparacao > 0 ||
                (comparacao == 0 &&
                 strcmp(funcionarios[i].endereco.rua,
                        funcionarios[j].endereco.rua) > 0)) {

                temp = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = temp;
            }
        }
    }

    printf("\n========================================");
    printf("\nFUNCIONARIOS POR BAIRRO E RUA");
    printf("\n========================================\n");

    for (int i = 0; i < n; i++) {
        imprimirFuncionario(funcionarios[i]);
    }
}

/* Letra F */
void funcionarioMaisAntigo(Funcionario funcionarios[], int n) {

    int posicao = 0;

    for (int i = 1; i < n; i++) {

        if (funcionarios[i].dataContratacao.ano <
            funcionarios[posicao].dataContratacao.ano) {

            posicao = i;
        }
        else if (
            funcionarios[i].dataContratacao.ano ==
            funcionarios[posicao].dataContratacao.ano &&
            funcionarios[i].dataContratacao.mes <
            funcionarios[posicao].dataContratacao.mes) {

            posicao = i;
        }
        else if (
            funcionarios[i].dataContratacao.ano ==
            funcionarios[posicao].dataContratacao.ano &&
            funcionarios[i].dataContratacao.mes ==
            funcionarios[posicao].dataContratacao.mes &&
            funcionarios[i].dataContratacao.dia <
            funcionarios[posicao].dataContratacao.dia) {

            posicao = i;
        }
    }

    printf("\n========================================");
    printf("\nFUNCIONARIO COM CONTRATACAO MAIS ANTIGA");
    printf("\n========================================\n");

    imprimirFuncionario(funcionarios[posicao]);
}

int main() {

    Funcionario funcionarios[MAX];

    int n;
    float salarioMinimo;
    int mes;

    cadastrarFuncionarios(funcionarios, &n);

    printf("\nDigite o valor do salario minimo: ");
    scanf("%f", &salarioMinimo);

    salarios(funcionarios, n, salarioMinimo);

    printf("\nDigite o mes para consulta: ");
    scanf("%d", &mes);

    funcionariosDoMes(funcionarios, n, mes);

    ordenarPorNome(funcionarios, n);

    ordenarPorSalario(funcionarios, n);

    ordenarPorBairroRua(funcionarios, n);

    funcionarioMaisAntigo(funcionarios, n);

    return 0;
}