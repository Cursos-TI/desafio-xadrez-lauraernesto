#include <stdio.h>

#define BOARD_W 8
#define BOARD_H 8

/* Desenha o tabuleiro (0,0) é canto inferior esquerdo) */
void desenhar_tabuleiro(int x, int y) {
    for (int yy = BOARD_H - 1; yy >= 0; yy--) {
        for (int xx = 0; xx < BOARD_W; xx++) {
            if (xx == x && yy == y) {
                printf("P ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Mantém (x,y) dentro do tabuleiro [0..7] */
void limitar_borda(int *x, int *y) {
    if (*x < 0) *x = 0;
    if (*x >= BOARD_W) *x = BOARD_W - 1;
    if (*y < 0) *y = 0;
    if (*y >= BOARD_H) *y = BOARD_H - 1;
}

int main(void) {
    // Variáveis inseridas manualmente (sem scanf)
    int passos_bispo  = 5;
    int passos_torre  = 5;
    int passos_rainha = 8;

    int x, y;

    printf("=== Desafio de Xadrez - MateCheck (Tabuleiro em texto) ===\n\n");

    /* BISPO -> WHILE */
    printf("BISPO: diagonal superior direita (%d passos)\n", passos_bispo);
    x = 2; y = 2;
    desenhar_tabuleiro(x, y);

    int i = 0;
    while (i < passos_bispo) {
        y++;  x++;  limitar_borda(&x, &y);
        printf("Passo %d: Cima + Direita -> Posicao (%d, %d)\n", i+1, x, y);
        desenhar_tabuleiro(x, y);
        i++;
    }
    printf("---\n\n");

    /* TORRE -> FOR */
    printf("TORRE: direita (%d passos)\n", passos_torre);
    x = 0; y = 0;
    desenhar_tabuleiro(x, y);

    for (int j = 0; j < passos_torre; j++) {
        x++;  limitar_borda(&x, &y);
        printf("Passo %d: Direita -> Posicao (%d, %d)\n", j+1, x, y);
        desenhar_tabuleiro(x, y);
    }
    printf("---\n\n");

    /* RAINHA -> DO...WHILE */
    printf("RAINHA: esquerda (%d passos)\n", passos_rainha);
    x = 7; y = 0;
    desenhar_tabuleiro(x, y);

    int k = 0;
    do {
        x--;  limitar_borda(&x, &y);
        printf("Passo %d: Esquerda -> Posicao (%d, %d)\n", k+1, x, y);
        desenhar_tabuleiro(x, y);
        k++;
    } while (k < passos_rainha);
    printf("---\n\n");

    printf("=== Fim ===\n");
    return 0;
}