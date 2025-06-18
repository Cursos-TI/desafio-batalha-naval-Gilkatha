#include <stdio.h>

#include <stdbool.h>
 
#define TAM 10

#define NAVIO 'N'

#define AGUA '~'

#define TAM_NAVIO 3
 
typedef struct {

    int linha;

    int coluna;

    char direcao; // 'H' = horizontal, 'V' = vertical, 'D' = diagonal desc., 'U' = diagonal asc.

} Navio;
 
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {

    for (int i = 0; i < TAM; i++)

        for (int j = 0; j < TAM; j++)

            tabuleiro[i][j] = AGUA;

}
 
bool podeColocarNavio(char tabuleiro[TAM][TAM], Navio navio) {

    for (int i = 0; i < TAM_NAVIO; i++) {

        int lin = navio.linha;

        int col = navio.coluna;
 
        switch (navio.direcao) {

            case 'H': col += i; break;

            case 'V': lin += i; break;

            case 'D': lin += i; col += i; break;

            case 'U': lin -= i; col += i; break;

            default: return false;

        }
 
        // Verifica limites do tabuleiro

        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM) return false;

        // Verifica sobreposição

        if (tabuleiro[lin][col] == NAVIO) return false;

    }

    return true;

}
 
void posicionarNavio(char tabuleiro[TAM][TAM], Navio navio) {

    for (int i = 0; i < TAM_NAVIO; i++) {

        int lin = navio.linha;

        int col = navio.coluna;
 
        switch (navio.direcao) {

            case 'H': col += i; break;

            case 'V': lin += i; break;

            case 'D': lin += i; col += i; break;

            case 'U': lin -= i; col += i; break;

        }
 
        tabuleiro[lin][col] = NAVIO;

    }

}
 
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {

    printf("   ");

    for (int i = 0; i < TAM; i++)

        printf("%2d ", i);

    printf("\n");
 
    for (int i = 0; i < TAM; i++) {

        printf("%2d|", i);

        for (int j = 0; j < TAM; j++) {

            printf(" %c ", tabuleiro[i][j]);

        }

        printf("\n");

    }

}
 
int main() {

    char tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);
 
    Navio navios[4] = {

        {0, 0, 'H'}, // horizontal

        {3, 6, 'V'}, // vertical

        {7, 0, 'D'}, // diagonal descendente

        {2, 2, 'U'}  // diagonal ascendente

    };
 
    for (int i = 0; i < 4; i++) {

        if (podeColocarNavio(tabuleiro, navios[i])) {

            posicionarNavio(tabuleiro, navios[i]);

        } else {

            printf("Erro ao posicionar navio %d na posição (%d, %d) direção '%c'\n", 

                   i + 1, navios[i].linha, navios[i].coluna, navios[i].direcao);

        }

    }
 
    printf("\n=== TABULEIRO DE BATALHA NAVAL (10x10) ===\n");

    imprimirTabuleiro(tabuleiro);
 
    return 0;

}

 
