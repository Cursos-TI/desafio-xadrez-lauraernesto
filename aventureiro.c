#include <stdio.h>

/*
  Desafio de Xadrez - MateCheck
  Nível Novato:
    - Bispo: 5 casas na diagonal superior direita (imprimir Cima e Direita por passo)
    - Torre: 5 casas para a Direita
    - Rainha: 8 casas para a Esquerda
    - Exigir loops e saída clara

  Nível Aventureiro:
    - Cavalo: movimentação em L para BAIXO e para a ESQUERDA
    - É OBRIGATÓRIO usar LOOPS ANINHADOS: 1 for + (while OU do...while)
    - Aqui usaremos for + while
*/

/* --- Constantes opcionais para facilitar manutenção --- */
const int PADRAO_PASSOS_BISPO  = 5;
const int PADRAO_PASSOS_TORRE  = 5;
const int PADRAO_PASSOS_RAINHA = 8;

/* -------------------- NÍVEL NOVATO -------------------- */

void mover_bispo_superior_direita(int passos) {
    /* while: repete "passos" vezes; para cada passo, imprime Cima e Direita */
    int i = 0;
    printf("Movimentacao do Bispo (diagonal superior direita, %d passos):\n", passos);
    while (i < passos) {
        printf("Cima\n");
        printf("Direita\n");
        i++;
    }
    printf("---\n");
}

void mover_torre_direita(int passos) {
    /* for: já sabemos quantas repetições */
    printf("Movimentacao da Torre (direita, %d passos):\n", passos);
    for (int j = 0; j < passos; j++) {
        printf("Direita\n");
    }
    printf("---\n");
}

void mover_rainha_esquerda(int passos) {
    /* do...while: executa pelo menos uma vez */
    int k = 0;
    printf("Movimentacao da Rainha (esquerda, %d passos):\n", passos);
    do {
        printf("Esquerda\n");
        k++;
    } while (k < passos);
    printf("---\n");
}

/* ------------------ NÍVEL AVENTUREIRO ------------------ */
/* Cavalo: L para BAIXO e ESQUERDA, usando LOOPS ANINHADOS (for + while).
   Variação 1: 2x Baixo + 1x Esquerda  (Δ = -1, -2)
   Variação 2: 1x Baixo + 2x Esquerda  (Δ = -2, -1)
   Obs: Não desenhamos tabuleiro nem posições; só imprimimos as direções.
*/

void cavalo_L_baixo_esquerda(int v_down, int h_left, const char *rotulo) {
    printf("Movimentacao do Cavalo %s (L: baixo + esquerda -> %dx Baixo, %dx Esquerda):\n",
           rotulo, v_down, h_left);

    /* for externo: 2 componentes do L (0 = vertical, 1 = horizontal) */
    for (int comp = 0; comp < 2; comp++) {
        int count = (comp == 0 ? v_down : h_left);

        /* while interno: conta quantas vezes imprimir cada componente */
        int t = 0;
        while (t < count) {
            if (comp == 0) {
                printf("Baixo\n");
            } else {
                printf("Esquerda\n");
            }
            t++;
        }
    }

    printf("---\n");
}

int main(void) {
    /* Valores inseridos manualmente em variáveis (sem scanf) */
    int passos_bispo  = PADRAO_PASSOS_BISPO;   // 5
    int passos_torre  = PADRAO_PASSOS_TORRE;   // 5
    int passos_rainha = PADRAO_PASSOS_RAINHA;  // 8

    /* ----- Nível Novato ----- */
    mover_bispo_superior_direita(passos_bispo);
    mover_torre_direita(passos_torre);
    mover_rainha_esquerda(passos_rainha);

    /* ----- Nível Aventureiro (obrigatório loops aninhados) ----- */
    /* Duas variações válidas do L para baixo+esquerda */
    cavalo_L_baixo_esquerda(2, 1, "(variacao 1: 2 Baixo + 1 Esquerda)");
    cavalo_L_baixo_esquerda(1, 2, "(variacao 2: 1 Baixo + 2 Esquerda)");

    return 0;
}