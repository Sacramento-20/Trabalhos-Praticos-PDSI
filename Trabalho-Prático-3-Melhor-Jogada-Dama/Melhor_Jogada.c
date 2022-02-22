#include <stdio.h>
#include <stdlib.h>
#define TMAX 20   // Tamanho fixo para facilitar o trabalho com o tabuleiro
# include <math.h>


// Função que imprime o tabuleiro
void print_tabuleiro(char tabuleiro[][TMAX], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        putchar('\n');
    }
}


// Essa função irá inicialmente varrer o tabuleiro e retornar todas as posições pertencentes as peças que serão aplicadas na recursão
// O retorno será feito em duas partes:
// Será feito dois vetores com realloc que será aumentado conforme for encontrando as peças
// Depois disso passará tudo para uma matriz com o tamanho do número de peças encontradas para ser retornada e aplicada na recursão 
int **varre_matriz(char tabuleiro[][TMAX], int tamanho)
{
    int branca = 0;                                     // Variavel respectiva ao numero de peças no tabuleiro
    int *vetor_coord_x, *vetor_coord_y;                 // Coodenadas da coluna 1 e coluna 2
    int **matriz_coord;                                 // Matriz das coordenadas que será retornada


    vetor_coord_x = (int *) calloc(0, sizeof (int));    // Coluna 1 das coordenadas 
    vetor_coord_y = (int *) calloc(0, sizeof (int));    // Coluna 2 das coordenadas
    

    for (int i = 0; i < tamanho; i++)                   // FOR que percorrerá as linhas do tabuleiro
    {
        if(i%2 == 0)                                    // Percorre da esquerda para a direita
        {
            for (int j = 0; j < tamanho; j++)
            {
                if(tabuleiro[i][j] == 'b')
                {    
                    branca += 1;                        // Acresce um valor na peça branca
                    
                    vetor_coord_x =  realloc(vetor_coord_x,branca*sizeof(int));         // Aloca dinamicamente o indice  do vetor coluna 1
                    vetor_coord_y =  realloc(vetor_coord_y,branca*sizeof(int));         // Aloca dinamicamente o indice  do vetor coluna 2

                    vetor_coord_x[branca-1] = i;                                        // Coluna 1 recebe eixo x
                    vetor_coord_y[branca-1] = j;                                        // Coluna 2 recebe eixo y
                }
            }
        }
        if(i%2 != 0)                                    // Percorre da direita para a esquerda
        {
            for (int j = tamanho-1; j >= 0; j--)
            {
                if(tabuleiro[i][j] == 'b')
                {

                    branca += 1;                        // Acresce um valor na peça branca
                    
                    vetor_coord_x = realloc(vetor_coord_x,branca*sizeof(int));          // Aloca dinamicamente o indice  do vetor coluna 1
                    vetor_coord_y = realloc(vetor_coord_y,branca*sizeof(int));          // Aloca dinamicamente o indice  do vetor coluna 2

                    vetor_coord_x[branca-1] = i;                                        // Coluna 1 recebe eixo x
                    vetor_coord_y[branca-1] = j;                                        // Coluna 2 recebe eixo y
                }
            }
        }
    }

    matriz_coord = (int **) malloc(branca*sizeof(int*));        // Criando uma matriz baseada no numero de peças que já foi pego

    for (int i = 0; i <= branca; i++)
    {
        if(i == 0)
        {
            matriz_coord[i] = malloc(2*sizeof(int));                // Alocando linhas da matriz
            matriz_coord[0][0] = branca;                  // Passando elementos da coluna 1 para a matriz
            matriz_coord[0][1] = branca;
        }
        else
        {
        matriz_coord[i] = malloc(2*sizeof(int));                    // Alocando linhas da matriz 
        matriz_coord[i][0] = vetor_coord_x[i-1];                    // Passando elementos da coluna 1 para a matriz
        matriz_coord[i][1] = vetor_coord_y[i-1];                    // Passando elementos da coluna 2 para a matriz
        }                  
    }

    return matriz_coord;
    
    // Liberando os vetores.    
    free(vetor_coord_x);
    free(vetor_coord_y);
}


// Como a recursão funciona:
// Ela recebe o tabuleiro, as coordenadas(a partir da coluna 1 pq usei a linha zero para armazenar o numero de peças que me ajudará fazer o for no qual a recursão vai está contido, já que a função só retorna a matriz, dei um jeito de incluir esse valor nela para me facilitar)
// Dentro das condições do tabuleiro eu criei um tabuleiro provisorio que sera chamado recursivamente, para não afetar o tabuleiro inicial e causar erro
// Criei variaveis que armazena o numero de capturas e no final da função compara qual é o maior e retorna ela
int recursao(char tabuleiro[][TMAX], int x, int y,int tamanho)
{
    
    int diagonal_direita_baixo = 0,diagonal_esquerda_baixo = 0 ,diagonal_direita_cima = 0 ,diagonal_esquerda_cima = 0 ;

    if (tabuleiro[x][y] == 'b')
    {
            if(x+2 < tamanho && y+2 < tamanho)
            {
                if (tabuleiro[x+2][y+2] == 'o' && tabuleiro[x+1][y+1] == 'p') 
                {
                    char backup[TMAX][TMAX];

                        for (int i = 0; i < tamanho; i++)
                        {
                            for (int j = 0; j < tamanho; j++)
                            {
                                backup[i][j] = tabuleiro[i][j];
                            }    
                        }

                        backup[x][y] = 'o';
                        backup[x+2][y+2] = 'b';
                        backup[x+1][y+1] = 'o';

                        diagonal_direita_baixo = 1 + recursao(backup, x+2, y+2, tamanho);
                }
            }
            if(x+2 < tamanho && y-2 >= 0)
            {
                if (tabuleiro[x+2][y-2] == 'o' && tabuleiro[x+1][y-1] == 'p')
                {
                        char backup[TMAX][TMAX];

                        for (int i = 0; i < tamanho; i++)
                        {
                            for (int j = 0; j < tamanho; j++)
                            {
                                backup[i][j] = tabuleiro[i][j];
                            }    
                        }

                        backup[x][y] = 'o';
                        backup[x+2][y-2] = 'b';
                        backup[x+1][y-1] = 'o';
                    
                        diagonal_esquerda_baixo = 1 + recursao(backup, x+2, y-2, tamanho);
                }
            }
            if(x-2 >= 0 && y+2 < tamanho)
            {
                if (tabuleiro[x-2][y+2] == 'o' && tabuleiro[x-1][y+1] == 'p')
                {
                        char backup[TMAX][TMAX];

                        for (int i = 0; i < tamanho; i++)
                        {
                            for (int j = 0; j < tamanho; j++)
                            {
                                backup[i][j] = tabuleiro[i][j];
                            }    
                        }
                        
                        backup[x][y] = 'o';
                        backup[x-2][y+2] = 'b';
                        backup[x-1][y+1] = 'o';
                        
                        diagonal_direita_cima = 1 + recursao(backup, x-2, y+2, tamanho);
                }
            }
            if (x-2 >= 0 && y-2 >= 0)
            {
                if (tabuleiro[x-2][y-2] == 'o' && tabuleiro[x-1][y-1] == 'p')
                {
                        char backup[TMAX][TMAX];

                        for (int i = 0; i < tamanho; i++)
                        {
                            for (int j = 0; j < tamanho; j++)
                            {
                                backup[i][j] = tabuleiro[i][j];
                            }    
                        }
                        
                        backup[x][y] = 'o';
                        backup[x-2][y-2] = 'b';
                        backup[x-1][y-1] = 'o';
                        
                        diagonal_esquerda_cima = 1 + recursao(backup, x-2, y-2, tamanho);
                }
                
                
            }
        
        if(diagonal_esquerda_baixo > diagonal_esquerda_cima)
        {
            if(diagonal_direita_cima > diagonal_direita_baixo)
            {
                if(diagonal_esquerda_baixo > diagonal_direita_cima)
                {
                    return diagonal_esquerda_baixo;
                }
                else
                {
                    return diagonal_direita_cima;
                }
            }
            else
            {
                if(diagonal_esquerda_baixo > diagonal_direita_baixo)
                {
                    return diagonal_esquerda_baixo;
                }
            
                else
                {
                    return diagonal_direita_baixo;
                }
            }
        }
        else 
        {
            if(diagonal_direita_cima > diagonal_direita_baixo)
            {
                if(diagonal_esquerda_cima > diagonal_direita_cima)
                {
                    return diagonal_esquerda_cima;
                }
                else
                {
                    return diagonal_direita_cima;
                }
            }
            else
            {
                if(diagonal_esquerda_cima > diagonal_direita_baixo)
                {
                    return diagonal_esquerda_cima;
                }
                else
                {
                    return diagonal_direita_baixo;
                }
            }
        }
    }
    
}

// Main irá receber e coordenar todas as operações, inclusive percorrer um for com o i indo até o numero de peças que foram catalogadas e aplicando a recursão em cada uma delas
// Retornando apenas aquelas que possuem possibilidades de capturas e destacando a que tem a maior entre elas
int main(){

    int tamanho;
    char entrada[TMAX];
    
    fgets(entrada, TMAX, stdin);
    sscanf(entrada, "%d", &tamanho);

    int capturas = 0;

    char tabuleiro[TMAX][TMAX];
    
    for (int i = 0; i < tamanho; i++)
    {
        fgets(tabuleiro[i], 20, stdin);
    }

    int **matriz_coordenadas;
    matriz_coordenadas = varre_matriz(tabuleiro, tamanho); // As coordenadas será recebida por essa matriz

    int n_elementos = matriz_coordenadas[0][0];
    
    // Vetor com o numero de peças capturadas
    int pecas_capturadas[n_elementos];

    for (int i = 1; i <= n_elementos; i++)
    {
        // Passando a copia da matriz para colocar na função

        capturas = recursao(tabuleiro,matriz_coordenadas[i][0],matriz_coordenadas[i][1], tamanho);
        // Armazenando o numero de peças no vetor que tem o mesmo indice que as coordenadas
        pecas_capturadas[i] = capturas;

        
    }

    putchar('\n');

    
    // Pegar o maior
    int maior = pecas_capturadas[1];
    int indice = 1;

    for (int i = 2; i <= n_elementos; i++)
    {
        if(pecas_capturadas[i] > maior)
        {
            maior = pecas_capturadas[i];
            indice = i;
        }
            
    }
    
    // OUTPUT
    
    
    // Maior numero de capturas
    printf("%d %d %d\n", matriz_coordenadas[indice][0],matriz_coordenadas[indice][1],maior);

    // Peças com capturas acima de zero    
    for (int i = 1; i <= n_elementos; i++)
        {
            if(pecas_capturadas[i] > 0)
            {
                printf("%d %d %d\n", matriz_coordenadas[i][0],matriz_coordenadas[i][1],pecas_capturadas[i]);
            }
        }   

    free(matriz_coordenadas);
    
    return 0;
}