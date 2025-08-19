#include <stdio.h> #imprimir na tela, preciso utilizar stdio.

int main() {

    int Dias;
    float Anos;

    printf("Entre com o número de dias: ");

    /* Entrada de dados */
    scanf("%d", &Dias);

    Anos = Dias / 365.25; /*conversão dias para anos*/
    printf ("\n \n%d dias equivalem a %.3f anos. \n", Dias, Anos);

    return(0);

}
