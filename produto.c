#include <stdio.h>

/* Define um struct com campos: id, nome, fabricante, preco, qtd_estocada.
Dá a este tipo o nome tipo_produto.
Observação: o nome do tipo aqui é tipo_produto. Esse nome é diferente de t_produto que aparece depois. */

typedef struct {
    int id;
    char nome[32]; 
    char fab[32];
    float preco; 
    int qtd;
} t_produto;

typedef t_produto t_tabprods[40];

int ler_tabproducts(t_tabprods tab) {
    return 0;
}

void print_tab_produtos(t_tabprods tab, int tam){
    printf("id,	nome, fab,	preco,	qtd estocada\n");
    float i;
    for (i=0; i < tam; i++):{
        printf("%4d%40s%8.2f%8d\n", tab[i].id, tab[i].nome, tab[i].fab,
                                    tab[i].preco , tab[i].qtd); }
}

t_produto acha_prod_mais_caro(t_tabprods tab, int tam){
    float a; 
    float i;
    for (i=0; i < tam ; i++;){
        a = tab[i].preco; {
            if (a > i) {
                prod_mais_caro = a;
            else:
                prod_mais_caro = i++;}
        }
    }
    return t_produto;
}

t_produto acha_maior_est(t_tabprods tab){
    float b;
    for (i=0; i < tab; i++;){
        b = tab[i].qtd; {
            if (b > i) {
                prod_maior_est = b;
            else:
                prod_maior_est = i;}
    }
    return t_produto;
}

void print_produto(t_tabprods tab, int tam){

    printf("produto\n");
    int i;
    for (i=0; i < tam; i ++){
        printf("%40s\n", tab[i].nome);
    }
    
}


int main(){

    t_tabprods produtos;
    int tam_tab_prods = 0;
    t_produto prod_mais_caro, prod_maior_est;

    tam_tab_prods = ler_tabproducts(produtos);
    print_tab_produtos(produtos);

    prod_mais_caro = acha_prod_mais_caro(produtos);
    prod_maior_est = acha_prod_maior_est(produtos);

    print_produto(prod_mais_caro);
    print_produto(prod_maior_est);

    return 0;
}
