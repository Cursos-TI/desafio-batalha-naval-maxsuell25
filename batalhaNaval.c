#include <stdio.h>

// Função que valida se ja possui navio no local.
int verificaposicao(int linha,int coluna,int tamanho,int orientacao, int Tab[10][10]){
    if(orientacao == 0){
        for(int aux = coluna; aux < coluna+tamanho;aux++){
            if(Tab[linha][aux] != 0 ){
                return 0; 
            }
        }
    } else if(orientacao == 1){
        for (int aux = linha;aux < linha+tamanho;aux++){
            if(Tab[aux][coluna] != 0){
                return 0;
            }
        }
    } else if(orientacao == 2){ // Diagonal Principal
        for (int i = 0; i < tamanho; i++) {
            if (Tab[linha + i][coluna + i] != 0) {
                return 0;
            }
        }
    }  else if(orientacao == 3){ // Diagonal Secundaria
        for (int i = 0; i < tamanho; i++) {
            if (Tab[linha + i][coluna - i] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int centro_x, int centro_y) {
    int tamanho = 5;
    int offset = tamanho / 2; // 2 para matriz 5x5
    
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int tab_x = centro_x - offset + i;
            int tab_y = centro_y - offset + j;
            
            // Verifica se está dentro dos limites do tabuleiro
            if (tab_x >= 0 && tab_x < 10 && tab_y >= 0 && tab_y < 10) {
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (habilidade[i][j] == 1) {
                    // Preserva os navios existentes (valor 3)
                    if (tabuleiro[tab_x][tab_y] != 3) {
                        tabuleiro[tab_x][tab_y] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    // Variaveis de Agua, Navio, Tamanho Tabuleiro e Tabuleiro 10x10
    int Tamanho_Tabu = 10;
    int Tabuleiro[Tamanho_Tabu][Tamanho_Tabu];
    int Agua = 0;
    int Navio = 3;
    int Habilidade = 5; // Valor para área afetada por habilidade

    // Inicializa o Tabuleiro do jogo 10x10
    for (int linha = 0; linha < 10; linha++){
        for(int coluna = 0; coluna <10; coluna++){
            Tabuleiro[linha][coluna] = Agua;
        }
    }

    // Matriz Cone 5x5
    int TAMANHO_Cone = 5;
    int cone[TAMANHO_Cone][TAMANHO_Cone];
    int centro_cone = TAMANHO_Cone / 2;
    
    printf("Ataque Cone %dx%d:\n\n", TAMANHO_Cone, TAMANHO_Cone);
    
    for (int linha = 0; linha < TAMANHO_Cone; linha++) {
        int inicio = centro_cone - linha;
        int fim = centro_cone + linha;
        
        if (inicio < 0) inicio = 0;
        if (fim >= TAMANHO_Cone) fim = TAMANHO_Cone - 1;
        
        for (int coluna = 0; coluna < TAMANHO_Cone; coluna++) {
            if (coluna >= inicio && coluna <= fim) {
                cone[linha][coluna] = 1; // Área afetada
            } else {
                cone[linha][coluna] = 0;
            }
            printf("%d ", cone[linha][coluna]);
        }
        printf("\n");
    }

    // Matriz Cruz 5x5
    int Tamanho_Cruz = 5;
    int cruz[Tamanho_Cruz][Tamanho_Cruz];
    int centro_Cruz = Tamanho_Cruz / 2;
    
    printf("\nAtaque Cruz %dx%d:\n\n", Tamanho_Cruz, Tamanho_Cruz);
    
    for (int i = 0; i < Tamanho_Cruz; i++) {
        for (int j = 0; j < Tamanho_Cruz; j++) {
            if (i == centro_Cruz || j == centro_Cruz) {
                cruz[i][j] = 1; // Área afetada
            } else {
                cruz[i][j] = 0;
            }
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    // Matriz Octaedro 5x5
    int Tamanho_octaedro = 5;
    int octaedro[Tamanho_octaedro][Tamanho_octaedro];
    int centro_octo = Tamanho_octaedro / 2;
    
    printf("\nMatriz Octaedro %dx%d:\n\n", Tamanho_octaedro, Tamanho_octaedro);
    
    for (int linha = 0; linha < Tamanho_octaedro; linha++) {
        int distancia = (linha <= centro_octo) ? linha : Tamanho_octaedro - 1 - linha;
        
        for (int coluna = 0; coluna < Tamanho_octaedro; coluna++) {
            if (coluna >= centro_octo - distancia && coluna <= centro_octo + distancia) {
                octaedro[linha][coluna] = 1; // Área afetada
            } else {
                octaedro[linha][coluna] = 0;
            }
            printf("%d ", octaedro[linha][coluna]);
        }
        printf("\n");
    }

    // Posicionar navios no tabuleiro
    // [Código de posicionamento de navios permanece igual...]
    
    // Variaveis do Navio 1 (Horizontal) no Tabuleiro.
    int Tamanho_Navio1 = 4;
    int Linha_navio1 = 1;
    int Coluna_navio1 = 2;
    int Orientacao_Navio1 = 0;
    
    if(Tamanho_Navio1 + Coluna_navio1 > 10){
        printf("Navio 1 não foi posicionado!\n");
    } else { 
        if(!verificaposicao(Linha_navio1,Coluna_navio1,Tamanho_Navio1,Orientacao_Navio1,Tabuleiro)){
            printf("ERRO: Navio 1 não posicionado, pois ja possui um navio na posição desejada!\n");
            return 0;
        } else {
            for(int indice = Coluna_navio1 ;indice < Coluna_navio1+Tamanho_Navio1;indice++){
                Tabuleiro[Linha_navio1][indice] = Navio;
            }
        }
    }

    // Variaveis do Navio 2 (Vertical) no Tabuleiro.
    int Tamanho_Navio2 = 4;
    int Linha_navio2 = 2;
    int Coluna_navio2 = 8;
    int Orientacao_Navio2 = 1;
    
    if(Tamanho_Navio2 + Linha_navio2 > 10){
        printf("Navio 2 não foi posicionado!\n");
    } else {
        if(!verificaposicao(Linha_navio2,Coluna_navio2,Tamanho_Navio2,Orientacao_Navio2,Tabuleiro)){
            printf("ERRO: Navio 2 não posicionado, pois ja possui um navio na posição desejada!\n");
            return 0;
        } else {
            for(int indice = Linha_navio2 ;indice < Linha_navio2+Tamanho_Navio2;indice++){
                Tabuleiro[indice][Coluna_navio2] = Navio;
            }
        }
    }

    // Aplicar habilidades ao tabuleiro
    printf("\nAplicando habilidades ao tabuleiro...\n");
    
    // Aplicar Cone na posição (3, 3)
    aplicarHabilidade(Tabuleiro, cone, 3, 3);
    
    // Aplicar Cruz na posição (7, 7)
    aplicarHabilidade(Tabuleiro, cruz, 7, 7);
    
    // Aplicar Octaedro na posição (5, 5)
    aplicarHabilidade(Tabuleiro, octaedro, 5, 5);

    // Exibir o tabuleiro com as habilidades
    char Colunas[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int Linha[10] = {1,2,3,4,5,6,7,8,9,10};

    printf("\n-------Legandas Tabuleiro-------\n");
    printf("Água = 0\n");
    printf("Navio = 3\n");
    printf("Área afetada = 5\n");
    
    printf("\n-------Tabuleiro Batalha Naval-------\n");
    printf("   ");
    
    // Exibição dos Indices da Coluna
    for (int aux = 0; aux < 10; aux++){
        printf(" %c  ", Colunas[aux]);
    }
    printf("\n");

    // Exibe Tabuleiro 
    for (int linha = 0; linha < 10; linha++){  
        // Exibição dos Indices da Linha
        if(linha < 9){
            printf("%d   ", Linha[linha]);
        } else {
            printf("%d  ", Linha[linha]);
        }
        
        // Exibição do conteúdo do tabuleiro
        for(int coluna = 0; coluna < 10; coluna++){
            printf("%d | ", Tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    printf("------------------------------------------\n");
    return 0;
}
