// ESSE É PROMISSOR

#include <stdio.h>
#define TMAX 20
#include <stdlib.h>

int main() {

    int tamanho;
    char entrada[TMAX]; 
    // printf("Informe o tamanho do tabuleiro: ");
    
    fgets(entrada, TMAX, stdin);  // vai solicitar a entrada ao usuário.
    sscanf(entrada, "%d", &tamanho);    // vai armazenar a entrada na variavel tamanho. 4
    
    char tabuleiro[TMAX][TMAX];  // matriz de valores char == letras

    // capturar o tabuleiro
    // printf("Informe o tabuleiro: \n");
    for (int i = 0; i < tamanho; i++) {
        fgets(tabuleiro[i], TMAX, stdin);
    }



    // Exibe  o tabuleiro primeira vez
    // for (int i = 0; i < tamanho; i++) {
    //     for (int j = 0; j < tamanho; j++) {
    //         printf("%c ", tabuleiro[i][j]);

    //     }
    //     printf("\n");
    // }
// -----------------------------------------------------------------------------------------------
//  NÃO MEXER DAQUI PARA CIMA, POR FAVOR !!!!
    for(int j=0; j <= tamanho-1; j++ ){
        if (tabuleiro[0][j] == 'b'){
            tabuleiro[0][j] = 'B';
        }
    }

    for(int j=0; j <= tamanho-1; j++ ){
        if (tabuleiro[tamanho-1][j] == 'p'){
            tabuleiro[tamanho-1][j] = 'P';
        }
    }

    // inicio 1 e 2 serão as variaveis que amazenarei as entradas do tabuleiro. ex: (2,3) (4,6)
    // final 1 e 2 serão as variaveis que armazenarei os destinos das peças. ex: (5,6) (4,2)
    // somatorio é a variavel que criei para a seguinte finalidade
        // o codigo tem que parar quando as entradas são: 0,0,0,0. então se a soma das entradas e das saidas forem 0, o codigo para,
        // estava enfrentando problemas ao usar operadores logicos e isso me ajudou.
    int inicio1, inicio2, final1, final2, somatorio = 1;
    char vazio = 'o', DamaB = 'B', DamaP = 'P';
    int pretas = 0, brancas = 0;
       
    //loop que irá fazer as peças se mexerem.
    // e responsaveis por todas as regras.
    while(somatorio != 0) {
        
        // printf("----------------------------------\n");
        // printf("Informe as jogadas: ");
        scanf("%d %d %d %d", &inicio1, &inicio2, &final1, &final2);
        
        somatorio = inicio1 + inicio2 + final1 + final2;
        if (inicio1 == 0 && inicio2 == 0 && final1 == 0 && final2 == 0){
            break;
        }

        // Loop responsavel por fazer as peças pretas não voltarem para tras.
        if (tabuleiro[inicio1][inicio2] == 'p') {
           
            if(final1 < inicio1 ) {                 // como as peças pretas começam de cima para baixo ou 0 ate o final, uma linha menor que 3
                                                    // por exemplo, se torna uma linha invalida
                continue;
            }
        }

        // Condição para não voltar peça branca
        if (tabuleiro[inicio1][inicio2] == 'b') {
            if(final1 > inicio1 ) {                 // como as peças brancas começam de baixo para cima ou de tamanho ate 0, uma linha maior que 
                                                    // (tamanho - 3) por exemplo, se torna uma linha invalida
                continue;
            }
        }

        // Condição para não se mover para casas vazias
        if (tabuleiro[inicio1][inicio2] == 'b' || 'p'){     // Esse vale tanto para as casas pretas, como brancas, se o movimento encontrar
            if(tabuleiro[final1][final2] == ' ') {          // uma casa vazia, sem o 'o', ele vai da como movimento inválido
                
                continue;
            }
        }
        // Condição de que não deve sair do tabuleiro
        if (tabuleiro[inicio1][inicio2] == 'b' || 'p' || ' ' || 'o'|| 'P' || 'B'){
            if(inicio1 < 0 || inicio1 > tamanho - 1|| inicio2 > tamanho -1 || inicio2 < 0 || final1 < 0 || final1 > tamanho -1 || final2 < 0 || final2 > tamanho - 1) {        // se o valor for excedente ao da matriz, o codigo irá invalidar

                continue;

            }

        }


        if (tabuleiro[inicio1][inicio2] == 'p'){

            if (tabuleiro[final1][final2] == 'o'){
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];
            tabuleiro[final1][final2] ^= tabuleiro[inicio1][inicio2];
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];

                if(inicio1+1 == final1-1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1+1][inicio2+1] == 'b' || tabuleiro[inicio1+1][inicio2+1] == 'B'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1+1][inicio2+1] = vazio;
                        pretas += 1;
                    }
                }
            
                else if(inicio1+1 == final1-1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1+1][inicio2-1] == 'b' || tabuleiro[inicio1+1][inicio2-1] == 'B') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1+1][inicio2-1] = vazio;
                        pretas += 1;
                    }  

                }
                // Dama
                if(final1 == tamanho-1){
                    tabuleiro[final1][final2] = 'P';
                    pretas += 1;
                }
            }            

        }


        // Funcionalidades da dama Preta
        if (tabuleiro[inicio1][inicio2] == 'P'){

            if (tabuleiro[final1][final2] == 'o'){
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];
            tabuleiro[final1][final2] ^= tabuleiro[inicio1][inicio2];
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];

                if(inicio1+1 == final1-1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1+1][inicio2+1] == 'b' || tabuleiro[inicio1+1][inicio2+1] == 'B'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1+1][inicio2+1] = vazio;
                        pretas += 1;
                    }
                }
            
                else if(inicio1+1 == final1-1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1+1][inicio2-1] == 'b' || tabuleiro[inicio1+1][inicio2-1] == 'B') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1+1][inicio2-1] = vazio;
                        pretas += 1;
                    }  

                }

                // mover como branca
                else if(inicio1-1 == final1+1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1-1][inicio2+1] == 'b' || tabuleiro[inicio1-1][inicio2+1] == 'B'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1-1][inicio2+1] = vazio;
                        pretas += 1;
                    }
                }

                else if(inicio1-1 == final1+1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1-1][inicio2-1] == 'b' || tabuleiro[inicio1-1][inicio2-1] == 'B') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1-1][inicio2-1] = vazio;
                        pretas += 1;
                    }  

                }
            }

        }
        //Funcionalidades Dama Branca
        if (tabuleiro[inicio1][inicio2] == 'B'){

            if (tabuleiro[final1][final2] == 'o'){
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];
            tabuleiro[final1][final2] ^= tabuleiro[inicio1][inicio2];
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];

                // movendo como Preta
                if(inicio1+1 == final1-1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1+1][inicio2+1] == 'p' || tabuleiro[inicio1+1][inicio2+1] == 'P'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1+1][inicio2+1] = vazio;
                        brancas += 1;
                    }
                }

                else if(inicio1+1 == final1-1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1+1][inicio2-1] == 'p' || tabuleiro[inicio1+1][inicio2-1] == 'P') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1+1][inicio2-1] = vazio;
                        brancas += 1;
                    }  

                }

                else if(inicio1-1 == final1+1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1-1][inicio2+1] == 'p' || tabuleiro[inicio1-1][inicio2+1] == 'P'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1-1][inicio2+1] = vazio;
                        brancas += 1;
                    }
                }

                else if(inicio1-1 == final1+1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1-1][inicio2-1] == 'p' || tabuleiro[inicio1-1][inicio2-1] == 'P') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1-1][inicio2-1] = vazio;
                        brancas += 1;
                    }  

                }

            }
        }

        if (tabuleiro[inicio1][inicio2] == 'b'){

            if (tabuleiro[final1][final2] == 'o'){
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];
            tabuleiro[final1][final2] ^= tabuleiro[inicio1][inicio2];
            tabuleiro[inicio1][inicio2] ^= tabuleiro[final1][final2];

                if(inicio1-1 == final1+1 && inicio2+1 == final2-1){
                    if(tabuleiro[inicio1-1][inicio2+1] == 'p' || tabuleiro[inicio1-1][inicio2+1] == 'P'){
                        // printf("Deve se mover para a direita.\n");
                        tabuleiro[inicio1-1][inicio2+1] = vazio;
                        brancas += 1;
                    }
                }

                else if(inicio1-1 == final1+1 && inicio2-1 == final2+1){
                    if(tabuleiro[inicio1-1][inicio2-1] == 'p' || tabuleiro[inicio1-1][inicio2-1] == 'P') {
                        // printf("Deve se mover para a esquerda.\n");
                        tabuleiro[inicio1-1][inicio2-1] = vazio;
                        brancas += 1;
                    }  

                }
                // Dama
                if(final1 == 0){
                    tabuleiro[final1][final2] = DamaB;
                    brancas += 1;
                }

            }
        
        }

        
    }

    printf("PRETAS %d", pretas);
    printf("\n");
    printf("BRANCAS %d", brancas);
    printf("\n");
    if (pretas == brancas){
        printf("EMPATE\n");
    }
    else if(pretas > brancas){
        printf("PRETAS VENCERAM\n");
    }
    else{
        printf("BRANCAS VENCERAM\n");
    }

    return 0;
}