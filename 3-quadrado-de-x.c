#include <stdio.h>

int square (int x) {
    printf("O quadrado eh %d", (x * x));
    return(0);

}
  
int main(){
    int num;
    printf("Entre com um numero qualquer:");
    scanf("%d", &num);
    printf( "\n \n");
    square(num);
    return(0);

}