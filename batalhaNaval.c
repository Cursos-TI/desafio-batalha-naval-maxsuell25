#include <stdio.h>

int main(){

    char tabuleiro [10][10];
    int i, j;

    for (i = 0; i < 10; i++);
        for (j = 0; j < 10; j++);
            tabuleiro[i][j] = 0;

    
    int navioHorizontal = {3,3,3};
    int navioVertical = {3,3,3};

    int linha_h = 2; 
    int coluna_h = 4;
        for (j = 0; j < 3; j++){
            tabuleiro[linha_h][coluna_h + j] = navioHorizontal;
        }
        int colunaV = 7;
        int linha = 5;
            for (i = 0; i < 3; i++){
                tabuleiro[linha + i][colunaV]= navioVertical;
            }
                printf(".....TABULEIRO DE BATALHA NAVAL.....\n");

                for(j = 0; j < 3; j++){
                    printf("%d", j);
                }
                    printf("\n");

                    printf("------------------\n");

                    for(i = 0; i < 3; i++){
                        printf("%d\n", i);
                        for(j = 0; j < 3; j++){
                            printf("%d", tabuleiro[i][j]);
                        }
                        printf("\n");

                    }


    return 0;
}
