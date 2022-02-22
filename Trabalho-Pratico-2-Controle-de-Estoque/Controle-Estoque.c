#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// struct
struct produto{
    int codigo;
    char nome[100];
    int qtd;
    float preco;
    char estado[5];
};

// vetor de struct - esse valor estrapolado pq nao sei das intenções do professor
struct produto produtos[2500];


// FUNÇÃO 1 - Gerar relatório de estoque.
void f1_ordena_produtos(int j, char *parametro3){
    int x, y, r;
    //
    char aux_nome[80];
    char aux_estado[5];
    int aux_codigo;
    int aux_qtd, contador;
    float aux_preco;


    // FOR responsavel por ordenar os produtos por ordem alfabetica
    for(x = 0; x <= j; x++){
        for(y = x+1; y <= j; y++){
            r = strcmp(produtos[x].nome, produtos[y].nome);
            
            if(r > 0){
                // NOME
                strcpy(aux_nome, produtos[x].nome);
                strcpy(produtos[x].nome, produtos[y].nome);
                strcpy(produtos[y].nome, aux_nome);
                // CODIGO
                aux_codigo = produtos[x].codigo;
                produtos[x].codigo = produtos[y].codigo;
                produtos[y].codigo = aux_codigo;
                // QTD
                aux_qtd = produtos[x].qtd;
                produtos[x].qtd = produtos[y].qtd;
                produtos[y].qtd = aux_qtd;
                // PRECO
                aux_preco = produtos[x].preco;
                produtos[x].preco = produtos[y].preco;
                produtos[y].preco = aux_preco;
                // ESTADO
                strcpy(aux_estado, produtos[x].estado);
                strcpy(produtos[x].estado, produtos[y].estado);
                strcpy(produtos[y].estado, aux_estado);

                
            }
        }
    }
    
    /** foi identificado que os arquivos com mesmo nome estavam na ordem invertida, então decidi fazer outro FOR
        para mudar todos os iguais de posição, já que o primeiro colocou a ordem dos repetidos errada.
        talvez possa aumentar o tempo de execução do aplicativo, mas foi a unica solução que encontrei para resolver o problema.**/ 
    for(x = 0; x <= j; x++){
        for(y = x+1; y <= j; y++){
            r = strcmp(produtos[x].nome, produtos[y].nome);
            
            if(r == 0){
                // NOME
                strcpy(aux_nome, produtos[x].nome);
                strcpy(produtos[x].nome, produtos[y].nome);
                strcpy(produtos[y].nome, aux_nome);
                // CODIGO
                aux_codigo = produtos[x].codigo;
                produtos[x].codigo = produtos[y].codigo;
                produtos[y].codigo = aux_codigo;
                // QTD
                aux_qtd = produtos[x].qtd;
                produtos[x].qtd = produtos[y].qtd;
                produtos[y].qtd = aux_qtd;
                // PRECO
                aux_preco = produtos[x].preco;
                produtos[x].preco = produtos[y].preco;
                produtos[y].preco = aux_preco;
                // ESTADO
                strcpy(aux_estado, produtos[x].estado);
                strcpy(produtos[x].estado, produtos[y].estado);
                strcpy(produtos[y].estado, aux_estado);

                
            }
        }
    }
    
    FILE *arquivo;
    arquivo = fopen(parametro3, "w");

        for (int i = 1; i <= j; i++){
            
                // printf("Produto: %d\n", i+1);
                fprintf(arquivo,"%d\n", produtos[i].codigo);
                fprintf(arquivo,"%s\n", produtos[i].nome);
                fprintf(arquivo,"%d\n", produtos[i].qtd);
                fprintf(arquivo,"%.2f\n", produtos[i].preco);
                fprintf(arquivo,"%s\n", produtos[i].estado); 
            
        }
    fclose(arquivo);

}

// FUNÇÃO 2 - Pesquisar por produto pelo código.
void f2_pesquisa_codigo(int j, int codigo){
    for (int i = 0; i < j; i++){
        if(codigo == produtos[i+1].codigo){
            printf("%d\n", produtos[i+1].codigo);
            printf("%s\n", produtos[i+1].nome);
            printf("%d\n", produtos[i+1].qtd);
            printf("%.2f\n", produtos[i+1].preco);
            printf("%s\n", produtos[i+1].estado);  
        }

    }
}

// FUNÇÃO 3 - Listar dados do produto com menor quantidade em estoque
void f3_listar_menor_qtd(int j){
    int menor;

    menor = produtos[0].qtd;

    for (int i = 1; i < j; i++){
        if(produtos[i].qtd < menor){
            menor = produtos[i].qtd;
        }
    }


    for (int i = 0; i <= j; i++){
        if(produtos[i].qtd == menor){
            printf("%d\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].qtd);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);  
        }
    }

}

// FUNÇÃO 4 - Listar produtos por estado.
int f4_ordena_estado(int j, char estado[]){
    int x, y, r;
    //
    char aux_nome[80];
    char aux_estado[5];
    int aux_codigo, contador;
    int aux_qtd;
    float aux_preco;

    for (contador = 1; contador <= j; contador++) {
        for (int i = 0; i <= j - 1; i++) {
            if (strcmp(produtos[i].nome, produtos[i+1].nome) > 0) {
                // NOME
                strcpy(aux_nome, produtos[i].nome);
                strcpy(produtos[i].nome, produtos[i+1].nome);
                strcpy(produtos[i+1].nome, aux_nome);
                // CODIGO
                aux_codigo = produtos[i].codigo;
                produtos[i].codigo = produtos[i+1].codigo;
                produtos[i+1].codigo = aux_codigo;
                // QTD
                aux_qtd = produtos[i].qtd;
                produtos[i].qtd = produtos[i+1].qtd;
                produtos[i+1].qtd = aux_qtd;
                // PRECO
                aux_preco = produtos[i].preco;
                produtos[i].preco = produtos[i+1].preco;
                produtos[i+1].preco = aux_preco;
                // ESTADO
                strcpy(aux_estado, produtos[i].estado);
                strcpy(produtos[i].estado, produtos[i+1].estado);
                strcpy(produtos[i+1].estado, aux_estado);
                
            }
        }
    }
    
    for (int i = 0; i < j; i++){
        if(strcmp(estado, produtos[i].estado) == 0){
            printf("%d\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].qtd);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado); 
        }
    }
    

}

// FUNÇÃO 5 - Encontrar produto com menor quantidade em estoque do estado.
void f5_lista_menor_estado(int j, char estado[]){
    int menor = 10000000;

    for (int i = 0; i < j; i++){
        if(strcmp(estado, produtos[i].estado) == 0){
            if(produtos[i].qtd < menor){
                menor = produtos[i].qtd;
            }
        }

    }
    for (int i = 0; i <= j; i++){
        if(produtos[i].qtd == menor){
            printf("%d\n", produtos[i].codigo);
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].qtd);
            printf("%.2f\n", produtos[i].preco);
            printf("%s\n", produtos[i].estado);  
        }
    }

}

// FUNÇÃO 6 - Calcular a quantidade total de itens no estoque.
void f6_somatorio(int j){
    int somatorio = 0;
    for (int i = 0; i < j; i++){
        somatorio += produtos[i].qtd;    
    }
    printf("%d \n", somatorio);
    
}


// MAIN
int main(int argc, char *argv[]){
    
    // Coloquei a lib para localizar o codigo em português para evitar alguma incompatibilidade.
    setlocale(LC_ALL,"Portuguese");

    
    char parametro3[50];
    int funcao;
    int j;

    // For que vai iterar os valores que foram passados como argumentos
    for(int i = 1; i < argc; i++){
        
        // condição para o Arquivo
        if(i == 1){
            
            FILE *file;
            file = fopen(argv[1], "r");

            char linha[1000];
            int i = 0; 
            
            // Usei o fgets, pois achei mais facil para pegar uma linha inteira, isso antes de assistir as aulas sobre arquivos
            while(fgets(linha, 1000, file) != NULL){
                
                // Aqui o arquivo recebe a quantidade de produtos, que acabou que não foi usada no TP.
                // Apenas ignorei ele porque não teve utiliadde (pelo menos não encontrei).
                // Na verdade ele me economizaria a variavel J que eu acabei criando para contar os arquivos na função.
                if (i == 0){
                    i++;
                    continue;
                }
                
                /** A maneira mais facil que encontrei foi estavelecer esse i que reseta a cada numero de caracteristicas dos
                produtos armazenadas**/
                if(i == 1){
                    produtos[j].codigo = atoi(linha);
                }
                if(i == 2){
                    strcpy(produtos[j].nome, linha);
                    produtos[j].nome[strlen(produtos[j].nome)-1] = '\0';
                }
                if(i == 3){
                    produtos[j].qtd = atoi(linha);
                }
                if(i == 4){
                    produtos[j].preco = atof(linha);
                }
                if(i == 5){
                    strcpy(produtos[j].estado, linha);
                    produtos[j].estado[strlen(produtos[j].estado)-1] = '\0';
                }

                i++;
                
                // aqui o i volta ao valor 1 e acrescento 1 ao J para a qunatidade, que poderia ser o valor em i == 0
                if(i==6){ 
                    i = 1;
                    j ++;
                }

            }

            fclose(file);
        }
        
        // FUNÇÃO
        funcao = atoi(argv[2]);
        if(i==2){
            
            if(funcao == 1){                
                char nome_arquivo[50];
                strcpy(nome_arquivo, argv[3]);
                f1_ordena_produtos(j, nome_arquivo);            
            }
            
            if(funcao == 2){                
                strcpy(parametro3, argv[3]);
                int codigo;
                codigo = atoi(argv[3]);
                f2_pesquisa_codigo(j, codigo);
            }
            
            if(funcao == 3){                
                f3_listar_menor_qtd(j);
            }
            
            if(funcao == 4){
                f4_ordena_estado(j, argv[3]);
            }
            
            if(funcao == 5){
                f5_lista_menor_estado(j, argv[3]);
            }
            
            if(funcao == 6){
                f6_somatorio(j);
            }
        }
    }

    return 0;
}
