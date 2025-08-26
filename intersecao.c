#include <stdio.h>

void print_conjunto(int conj[30], int tam) {
    for(int i = 0; i < tam - 1; i++)
        printf("%d, ", conj[i]);
    if (tam > 0) 
        printf("%d\n", conj[tam - 1]);
    else 
        printf("{}\n");
}

void intersecao(int conj1[], int tam1, 
                int conj2[], int tam2, 
                int conj3[], int *tam3) {
    int k = 0;
    for(int i = 0; i < tam1; i++) {
        for(int j = 0; j < tam2; j++) {
            if(conj1[i] == conj2[j]) {
                conj3[k++] = conj1[i];
                break;  // evita repetir se já achou o elemento
            }
        }
    }
    *tam3 = k;
}

int main () {
    int conjuntoA[30] = {12, 3, 27, 4, 88};
    int tamA = 5;
    int conjuntoB[30] = {3, 7, 12, 45, 71, 27, 25};
    int tamB = 7;
    int intersec[30];
    int tamI = 0;

    intersecao(conjuntoA, tamA, conjuntoB, tamB, intersec, &tamI);

    printf("Conjunto A: ");
    print_conjunto(conjuntoA, tamA);

    printf("Conjunto B: ");
    print_conjunto(conjuntoB, tamB);

    printf("Intersecao: ");
    print_conjunto(intersec, tamI);

    return 0;
}
