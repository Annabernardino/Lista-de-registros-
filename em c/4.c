#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto;

float distancia(Ponto A, Ponto B) {

    float dx = B.x - A.x;
    float dy = B.y - A.y;

    return sqrt(dx * dx + dy * dy);
}

float somaDistanciasTresPontos(Ponto A, Ponto B, Ponto C) {

    float dAB = distancia(A, B);
    float dBC = distancia(B, C);
    float dCA = distancia(C, A);

    return dAB + dBC + dCA;
}

int main() {

    Ponto A;
    Ponto B;
    Ponto C;

    printf("Digite X do ponto A: ");
    scanf("%f", &A.x);

    printf("Digite Y do ponto A: ");
    scanf("%f", &A.y);

    printf("\nDigite X do ponto B: ");
    scanf("%f", &B.x);

    printf("Digite Y do ponto B: ");
    scanf("%f", &B.y);

    printf("\nDigite X do ponto C: ");
    scanf("%f", &C.x);

    printf("Digite Y do ponto C: ");
    scanf("%f", &C.y);

    printf("\nDistancia AB: %.2f\n",
           distancia(A, B));

    printf("Distancia BC: %.2f\n",
           distancia(B, C));

    printf("Distancia CA: %.2f\n",
           distancia(C, A));

    printf("\nSoma das distancias: %.2f\n",
           somaDistanciasTresPontos(A, B, C));

    return 0;
}