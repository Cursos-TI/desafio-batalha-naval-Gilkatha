#include <stdio.h>

#define TAM 10
#define NAVIO 'N'
#define AGUA '~'

void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavios(char tabuleiro[TAM][TAM]) {
    // Navio 1 (horizontal)
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;
    tabuleiro[1][4] = NAVIO;

    // Navio 2 (vertical)
    tabuleiro[4][6] = NAVIO;
    tabuleiro[5][6] = NAVIO;
    tabuleiro[6][6] = NAVIO;

    // Navio 3 (horizontal)
    tabuleiro[8][0] = NAVIO;
    tabuleiro[8][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;
}

void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    printf("=== TABULEIRO DE BATALHA NAVAL (10x10) ===\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
