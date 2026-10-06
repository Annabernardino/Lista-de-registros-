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

int main() {

    Ponto A;
    Ponto B;

    printf("Digite a coordenada X do ponto A: ");
    scanf("%f", &A.x);

    printf("Digite a coordenada Y do ponto A: ");
    scanf("%f", &A.y);

    printf("\nDigite a coordenada X do ponto B: ");
    scanf("%f", &B.x);

    printf("Digite a coordenada Y do ponto B: ");
    scanf("%f", &B.y);

    printf("\nDistancia entre A e B: %.2f\n",
           distancia(A, B));

    return 0;
}