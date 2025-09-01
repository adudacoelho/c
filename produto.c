#include <stdio.h>

typedef struct {
    int id;
    char nome[32]; 
    char fabricante[32];
    float preco; 
    int qtd_estocada;
} tipo_produto;

typedef t_produto t_tabprods[40];

int le_tab_prod(t_tabprodutos tab) {

}

void print_tab_produtos(t_tabprods tab, int tam){
    printf("id,	nome, fab,	preco,	qtd estocada\n");
    for (i=0; i < tam; i++):{}
        printf("%4d%40s%8.2f%8d\n", tab[i].id, tab[i].nome, tab[i].fab
                                    tab[i].preco , tab[i].qtd);
}

t_produto acha_prod_mais_caro(t_tabprods tab){

}

t_produto acha_maior_est(t_tabprods tab){

}

void print_produto(t_tabprods tab){

}



int main(){

    t_tabprodutos produtos;
    int tam_tab_prods = 0;
    t_produto prod_mais_caro, prod_maior_est;

    tam_tab_prods = ler_tabproducts(produtos);
    print_tab_produtos(produtos);

    prod_mais_caro = acha_prod_mais_caro(produtos);
    prod_mais-est = acha_prod_maior_est(produtos);

    print_produto(prod_mais_caro);
    print_produto(prod_maior_est);

    return 0;
}
