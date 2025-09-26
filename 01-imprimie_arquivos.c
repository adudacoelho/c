#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#define MAX_PRODUTOS 40 //troca onde tem MAX_PRODUTOS por 40

typedef struct {
    int id;
    char nome[64];
    char fab[64];
    char cat[64];
    char unidade[64];
    float preco;
    int quantidade;
} t_produto;

//typedef {
    //chat fabricante;
    //int vetordeTabela
//} t

typedef t_produto tabela[MAX_PRODUTOS]; 

t_produto criaProduto(char line[]){

    t_produto aux;
    char *token;

    line[strlen(line)-1] = '\0';

    token = strtok(line, ",");
    aux.id = atoi(token);

    token = strtok(NULL, ",");
    strcpy(aux.nome, token);

    token = strtok(NULL, ",");
    strcpy(aux.fab, token);

    token = strtok(NULL, ",");
    strcpy(aux.cat, token);

    token = strtok(NULL, ",");
    strcpy(aux.unidade, token);
    
    token = strtok(NULL, ",");
    aux.preco = atof(token);

    token = strtok(NULL, ",");
    aux.quantidade = atoi(token);

    return aux;
}

int carregarProdutos(char filename[], tabela produtos){  
    FILE *arq = fopen(filename, "rt");
    int tam = 0;
    char linha[256];
    t_produto produto;

    if(arq == NULL){
        printf("Problemas na abertura do arquivo!\n");
        exit(-1);
    }

    fgets(linha, sizeof(linha), arq);

    while (fgets(linha, sizeof(linha), arq)) {
        produto = criaProduto(linha);
        produtos[tam++] = produto;
    }

    fclose(arq);
    return tam;
}


void imprimirProdutos(tabela tab, int tam){
    printf("\n id           nome             fabricante           categoria    unidade    preco    quantidade\n");
        for (int i=0; i < tam; i++){
            printf("%2d%20s%20s%20s%10s%10.2f%10d\n", tab[i].id, tab[i].nome, tab[i].fab, tab[i].cat, tab[i].unidade, tab[i].preco, tab[i].quantidade );
        }
}

float mediaPrecoPorFabricante(tabela tab, int tam, char fabricante[]){
    float soma = 0.0;
    int cont = 0;

    for (int i = 0; i < tam; i++) {
        if (strcmp(tab[i].fab, fabricante) == 0) {
            soma += tab[i].preco;
            cont++;
        }
    }

    if (cont == 0) {
        printf("Fabricante '%s' não encontrado!\n", fabricante);
        return 0.0;
    } else {
        float media = soma / cont;
        printf("Media de precos do fabricante '%s' = %.2f\n", fabricante, media);
        return media;
    }
}

       
void listarPorCategoria(tabela tab, int tam, char categoria[]) {
    int encontrados = 0;
    printf("\nProdutos da categoria '%s':\n", categoria);
    printf(" id           nome             fabricante       unidade     preco  quantidade\n");

    for (int i = 0; i < tam; i++) {
        if (strcmp(tab[i].cat, categoria) == 0) {
            printf("%2d%20s%20s%10s%10.2f%10d\n",
                   tab[i].id, tab[i].nome, tab[i].fab,
                   tab[i].unidade, tab[i].preco, tab[i].quantidade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto encontrado na categoria '%s'.\n", categoria);
    }
}

void imprimirProdutoMaisCaro(tabela tab, int tam) {
    if (tam == 0) {
        printf("Nenhum produto disponivel.\n");
        return;
    }

    t_produto maisCaro = tab[0]; // Começa assumindo que o primeiro é o mais caro

    for (int i = 1; i < tam; i++) {
        if (tab[i].preco > maisCaro.preco) {
            maisCaro = tab[i];
        }
    }
    printf("\nProduto mais caro\n");
    printf("Nome e preco: %s - R$ %.2f\n", maisCaro.nome, maisCaro.preco);

}

void listarPorFaixaDePreco(tabela tab, int tam, float min, float max) {
    int encontrados = 0;
    printf("\nProdutos com preço entre R$ %.2f e R$ %.2f:\n", min, max);
    printf(" id           nome             fabricante       preco  quantidade\n");

    for (int i = 0; i < tam; i++) {
        if (tab[i].preco >= min && tab[i].preco <= max) {
            printf("%2d%20s%20s%10.2f%10d\n",
                   tab[i].id, tab[i].nome, tab[i].fab,
                   tab[i].preco, tab[i].quantidade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto encontrado nessa faixa de preço.\n");
    }
}

float calcularValorTotalEstoque(tabela tab, int tam) {
    float total = 0.0;

    for (int i = 0; i < tam; i++) {
        total += tab[i].preco * tab[i].quantidade;
    }

    printf("\nValor total em estoque: R$ %.2f\n", total);
    return total;
}

void buscarProdutoPorNome(tabela tab, int tam, char nome[]) {
    int encontrados = 0;
    printf("\nBuscando produto com nome '%s':\n", nome);

    for (int i = 0; i < tam; i++) {
        if (strcmp(tab[i].nome, nome) == 0) {
            printf("ID: %d\n", tab[i].id);
            printf("Fabricante: %s\n", tab[i].fab);
            printf("Categoria: %s\n", tab[i].cat);
            printf("Unidade: %s\n", tab[i].unidade);
            printf("Preco: R$ %.2f\n", tab[i].preco);
            printf("Quantidade: %d\n", tab[i].quantidade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Produto '%s' nao encontrado.\n", nome);
    }
}

void listarEstoqueBaixo(tabela tab, int tam, int limite) {
    int encontrados = 0;
    printf("\nProdutos com estoque abaixo de %d unidades:\n", limite);
    printf(" id           nome             fabricante       quantidade\n");

    for (int i = 0; i < tam; i++) {
        if (tab[i].quantidade < limite) {
            printf("%2d%20s%20s%10d\n",
                   tab[i].id, tab[i].nome, tab[i].fab, tab[i].quantidade);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto com estoque baixo.\n");
    }
}

void relatriodeProdutosPorFabricante(tabela tab, int tam){
    int vetorIdsProduto[tam];
    int tamVetorIdsProduto = 0;
    int repetiu = 0;

    for (int i = 0; i < tam; i++) {
        for (int k = 0; k < tamVetorIdsProduto; k++){
            if(tab[i].id == vetorIdsProduto[k]){
                repetiu = 1;
                break;
            }
        }

        if (repetiu){
            repetiu = 0;
            continue;
        }

        vetorIdsProduto[tamVetorIdsProduto++] = tab[i].id;

        printf("\n%s: %s ", tab[i].fab, tab[i].nome);
        for (int j = i+1; j < tam; j++){
            if(strcmp(tab[i].fab, tab[j].fab) == 0){
                printf("%s ", tab[j].nome);
                vetorIdsProduto[tamVetorIdsProduto++] = tab[j].id;
            }
        }
    }
}

void relatriodeProdutosPorCategoria(tabela tab, int tam){
    int vetorIdsProduto[tam];
    int tamVetorIdsProduto = 0;
    int repetiu = 0;

    for (int i = 0; i < tam; i++) {
        for (int k = 0; k < tamVetorIdsProduto; k++){
            if(tab[i].id == vetorIdsProduto[k]){
                repetiu = 1;
                break;
            }
        }

        if (repetiu){
            repetiu = 0;
            continue;
        }

        vetorIdsProduto[tamVetorIdsProduto++] = tab[i].id;

        printf("\n%s: %s ", tab[i].cat, tab[i].nome);
        for (int j = i+1; j < tam; j++){
            if(strcmp(tab[i].cat, tab[j].cat) == 0){
                printf("%s ", tab[j].nome);
                vetorIdsProduto[tamVetorIdsProduto++] = tab[j].id;
            }
        }
    }
}


int main(){
    tabela tab_produtos;
    int tamanho = carregarProdutos("tabela-produtos.txt", tab_produtos);
    imprimirProdutos(tab_produtos, tamanho);

    // char fabricante[64];
    // printf("\nDigite o nome de um fabricante: ");
    // fgets(fabricante, sizeof(fabricante), stdin);
    // fabricante[strcspn(fabricante, "\n")] = '\0'; 

    // mediaPrecoPorFabricante(tab_produtos, tamanho, fabricante);

    // char categoria[64];
    // printf("\nDigite o nome de uma categoria: ");
    // fgets(categoria, sizeof(categoria), stdin);
    // categoria[strcspn(categoria, "\n")] = '\0'; // remove o \n

    // listarPorCategoria(tab_produtos, tamanho, categoria);
   
    // imprimirProdutoMaisCaro(tab_produtos, tamanho);

    // // Faixa de preço
    // float min, max;
    // printf("\nDigite o preco minimo: ");
    // scanf("%f", &min);
    // printf("Digite o preco maximo: ");
    // scanf("%f", &max);
    // listarPorFaixaDePreco(tab_produtos, tamanho, min, max);
    // getchar(); // limpa o buffer

    // // Valor total em estoque
    // calcularValorTotalEstoque(tab_produtos, tamanho);

    // // Buscar por nome
    // char nomeBusca[64];
    // printf("\nDigite o nome do produto para buscar: ");
    // fgets(nomeBusca, sizeof(nomeBusca), stdin);
    // nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
    // buscarProdutoPorNome(tab_produtos, tamanho, nomeBusca);

    // // Estoque baixo
    // int limite;
    // printf("\nDigite o limite de estoque: ");
    // scanf("%d", &limite);
    // listarEstoqueBaixo(tab_produtos, tamanho, limite);

    // Relatorio por fabricante
    printf("\n\nRelatorio de Produto por Fabricante");
    relatriodeProdutosPorFabricante(tab_produtos, tamanho);
    printf("\n\nRelatorio de Produto por Categoria");
    relatriodeProdutosPorCategoria(tab_produtos, tamanho);

    return 0;
}


//gerar relatorio de produtos por fabricante e sub categoria de produtos