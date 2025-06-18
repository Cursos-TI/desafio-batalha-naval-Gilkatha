#include <stdio.h>

#include <stdlib.h>
 
#define TAM 10

#define NAVIO 3

#define H 5 // Tamanho das matrizes de habilidade
 
int tabuleiro[TAM][TAM] = {0};
 
// Função para verificar se a posição está dentro dos limites

int dentroLimite(int x, int y) {

    return x >= 0 && x < TAM && y >= 0 && y < TAM;

}
 
// Função para posicionar navios

int posicionarNavio(int x, int y, int dx, int dy) {

    for (int i = 0; i < 3; i++) {

        int nx = x + i * dx;

        int ny = y + i * dy;

        if (!dentroLimite(nx, ny) || tabuleiro[nx][ny] != 0)

            return 0; // posição inválida

    }
 
    for (int i = 0; i < 3; i++) {

        int nx = x + i * dx;

        int ny = y + i * dy;

        tabuleiro[nx][ny] = NAVIO;

    }

    return 1;

}
 
// Função para aplicar habilidades

void aplicarHabilidade(int origemX, int origemY, char tipo) {

    int meio = H / 2;

    for (int i = 0; i < H; i++) {

        for (int j = 0; j < H; j++) {

            int efeito = 0;
 
            if (tipo == 'C') { // Cone

                efeito = (i >= j - meio && i >= meio - j);

            } else if (tipo == '+') { // Cruz

                efeito = (i == meio || j == meio);

            } else if (tipo == 'O') { // Octaedro

                efeito = (abs(i - meio) + abs(j - meio) <= meio);

            }
 
            if (efeito) {

                int tx = origemX - meio + i;

                int ty = origemY - meio + j;

                if (dentroLimite(tx, ty) && tabuleiro[tx][ty] == 0) {

                    tabuleiro[tx][ty] = 5; // Marca área da habilidade

                }

            }

        }

    }

}
 
// Função para imprimir o tabuleiro

void imprimirTabuleiro() {

    printf("   ");

    for (int i = 0; i < TAM; i++) printf("%2d ", i);

    printf("\n");

    for (int i = 0; i < TAM; i++) {

        printf("%2d ", i);

        for (int j = 0; j < TAM; j++) {

            if (tabuleiro[i][j] == 0) printf(" ~ ");

            else if (tabuleiro[i][j] == NAVIO) printf(" N ");

            else if (tabuleiro[i][j] == 5) printf(" * ");

        }

        printf("\n");

    }

}
 
int main() {

    // Posicionamento de 4 navios (2 na diagonal)

    if (!posicionarNavio(0, 0, 1, 0)) printf("Erro ao posicionar navio 1\n");

    if (!posicionarNavio(2, 2, 0, 1)) printf("Erro ao posicionar navio 2\n");

    if (!posicionarNavio(5, 1, 1, 1)) printf("Erro ao posicionar navio 3\n"); // diagonal ↘

    if (!posicionarNavio(7, 5, -1, 1)) printf("Erro ao posicionar navio 4\n"); // diagonal ↗
 
    // Aplicar habilidades

    aplicarHabilidade(4, 4, 'C'); // Cone

    aplicarHabilidade(7, 2, '+'); // Cruz

    aplicarHabilidade(6, 6, 'O'); // Octaedro
 
    // Imprimir resultado

    imprimirTabuleiro();
 
    return 0;

}

 
