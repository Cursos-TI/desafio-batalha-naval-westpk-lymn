#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; 
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int podePosicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; 
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; 
        }
    }

    return 1; 
}


void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3; 
    }
}


int podePosicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; 
    }

    
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; 
        }
    }

    return 1; 
}


void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3; 
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];


    inicializarTabuleiro(tabuleiro);

    
    int linhaHorizontal = 2, colunaHorizontal = 3; 
    int linhaVertical = 5, colunaVertical = 6;     

    
    if (podePosicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal);
    } else {
        printf("Erro ao posicionar o navio horizontal!\n");
    }

    if (podePosicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical);
    } else {
        printf("Erro ao posicionar o navio vertical!\n");
    }

    
    printf("Tabuleiro de Batalha Naval:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
