#include <stdio.h>
#include <string.h>

#define MAX 500

typedef struct {
    int matricula;
    char nome[100];
    char endereco[150];
} Funcionario;

typedef struct {
    int matricula;
    int dependentes;
} Dependente;

typedef struct {
    int matricula;
    char nome[100];
    int dependentes;
} Resultado;

void cadastrarFuncionarios(
    Funcionario funcionarios[],
    int n) {

    for (int i = 0; i < n; i++) {

        printf("\n===== FUNCIONARIO %d =====\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &funcionarios[i].matricula);

        printf("Nome: ");
        scanf(" %99[^\n]", funcionarios[i].nome);

        printf("Endereco: ");
        scanf(" %149[^\n]", funcionarios[i].endereco);
    }
}

void cadastrarDependentes(
    Dependente dependentes[],
    int n) {

    for (int i = 0; i < n; i++) {

        printf("\n===== DEPENDENTES %d =====\n", i + 1);

        printf("Matricula: ");
        scanf("%d", &dependentes[i].matricula);

        printf("Numero de dependentes: ");
        scanf("%d", &dependentes[i].dependentes);
    }
}

void ordenarFuncionarios(
    Funcionario funcionarios[],
    int n) {

    Funcionario temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (funcionarios[i].matricula >
                funcionarios[j].matricula) {

                temp = funcionarios[i];

                funcionarios[i] = funcionarios[j];

                funcionarios[j] = temp;
            }
        }
    }
}

void ordenarDependentes(
    Dependente dependentes[],
    int n) {

    Dependente temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (dependentes[i].matricula >
                dependentes[j].matricula) {

                temp = dependentes[i];

                dependentes[i] = dependentes[j];

                dependentes[j] = temp;
            }
        }
    }
}

int buscarDependentes(
    Dependente dependentes[],
    int n,
    int matricula) {

    for (int i = 0; i < n; i++) {

        if (dependentes[i].matricula == matricula) {
            return dependentes[i].dependentes;
        }
    }

    return 0;
}

void gerarResultado(
    Funcionario funcionarios[],
    Dependente dependentes[],
    Resultado resultado[],
    int n) {

    for (int i = 0; i < n; i++) {

        resultado[i].matricula =
            funcionarios[i].matricula;

        strcpy(
            resultado[i].nome,
            funcionarios[i].nome
        );

        resultado[i].dependentes =
            buscarDependentes(
                dependentes,
                n,
                funcionarios[i].matricula
            );
    }
}

void ordenarResultado(
    Resultado resultado[],
    int n) {

    Resultado temp;

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (resultado[i].dependentes <
                resultado[j].dependentes) {

                temp = resultado[i];

                resultado[i] = resultado[j];

                resultado[j] = temp;
            }
        }
    }
}

void imprimirResultado(
    Resultado resultado[],
    int n) {

    printf("\n========================================\n");
    printf("         RESULTADO FINAL\n");
    printf("========================================\n");

    for (int i = 0; i < n; i++) {

        printf("\nMatricula: %d\n",
               resultado[i].matricula);

        printf("Nome: %s\n",
               resultado[i].nome);

        printf("Dependentes: %d\n",
               resultado[i].dependentes);
    }
}

int main() {

    Funcionario funcionarios[MAX];

    Dependente dependentes[MAX];

    Resultado resultado[MAX];

    int n;

    printf("Quantidade de funcionarios (maximo 500): ");
    scanf("%d", &n);

    if (n < 1)
        n = 1;

    if (n > MAX)
        n = MAX;

    cadastrarFuncionarios(funcionarios, n);

    cadastrarDependentes(dependentes, n);

    ordenarFuncionarios(funcionarios, n);

    ordenarDependentes(dependentes, n);

    gerarResultado(
        funcionarios,
        dependentes,
        resultado,
        n
    );

    ordenarResultado(resultado, n);

    imprimirResultado(resultado, n);

    return 0;
}