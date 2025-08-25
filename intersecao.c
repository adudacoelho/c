#include <stdio.h>

void print_conjunto (int conj[30], tam) {
    for(int i=0; i < tam-1; i++)
        printf("%d,", conj[i]);
    printf("%d\n", conj[tam - 1]);


}

void intersecao(int conj1[], int tam1, 
                int conj2[], int tam2, 
                int conj3[], int *tam3)
                int k = 0;
    for( int=0; i < tam1; i++){
        for(int k=0; k < tam2; j++;){
            if(conj1[i] == conj2[j]){
                conj3[k++] = conj1[i];
                /*k = k + 1;*/
                break;
            }
        }

        *tam3 = k;
    }

int main (){
    int conjuntoA[30] = {12, 3, 27, 4, 88};
    int tamA = 5;
    int conjuntoB[30] = {3, 7, 12, 45, 71, 27, 25};
    int tamB = 7;
    int intersec[30];
    int tamI = 0;

   intersecao(conjuntoA, tamA, conjuntoB, tamB, intersec, &tamI)



    print_conjunto(conjuntoA, tamA);
    print_conjunto(conjuntoB, tamB);
    print_conjunto(intersec, tamI);

    return 0;
}