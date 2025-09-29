#include <stdio.h>

/* =========================================================
   MateCheck — Níveis: Novato, Aventureiro e Mestre
   - Valores definidos via variáveis no código (sem scanf)
   - Saída apenas com as direções: Cima, Baixo, Esquerda, Direita
   ========================================================= */

/* ======================== NÍVEL NOVATO ======================== */
/* Bispo: 5 casas na diagonal superior direita (Cima + Direita)
   Torre: 5 casas para a Direita
   Rainha: 8 casas para a Esquerda
   (Usando apenas estruturas de repetição simples) */

void novato_bispo(int passos) {           /* while */
    printf("=== Nivel Novato — Bispo (diagonal superior direita, %d passos) ===\n", passos);
    int i = 0;
    while (i < passos) {
        printf("Cima\n");
        printf("Direita\n");
        i++;
    }
    printf("---\n");
}

void novato_torre(int passos) {           /* for */
    printf("=== Nivel Novato — Torre (direita, %d passos) ===\n", passos);
    for (int j = 0; j < passos; j++) {
        printf("Direita\n");
    }
    printf("---\n");
}

void novato_rainha(int passos) {          /* do...while */
    printf("=== Nivel Novato — Rainha (esquerda, %d passos) ===\n", passos);
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < passos);
    printf("---\n");
}

/* ====================== NÍVEL AVENTUREIRO ====================== */
/* Cavalo: mover em L para BAIXO e ESQUERDA
   - Obrigatório: loops ANINHADOS (um for + um while) */

void aventureiro_cavalo_baixo_esquerda(void) {
    /* L válido para baixo+esquerda:
       variação A: 2x Baixo + 1x Esquerda
       variação B: 1x Baixo + 2x Esquerda
       Vamos mostrar as DUAS variações, cada uma com loops aninhados. */

    printf("=== Nivel Aventureiro — Cavalo (L para baixo e esquerda) ===\n");

    /* Variação A: 2 Baixo + 1 Esquerda (for externo controla componente; while interno repete) */
    printf("[Variacao A] L = 2x Baixo + 1x Esquerda\n");
    for (int comp = 0; comp < 2; comp++) {    /* 0 = vertical, 1 = horizontal */
        int count = (comp == 0 ? 2 : 1);
        int t = 0;
        while (t < count) {
            if (comp == 0) printf("Baixo\n");
            else           printf("Esquerda\n");
            t++;
        }
    }
    printf("---\n");

    /* Variação B: 1 Baixo + 2 Esquerda (mesma ideia) */
    printf("[Variacao B] L = 1x Baixo + 2x Esquerda\n");
    for (int comp = 0; comp < 2; comp++) {
        int count = (comp == 0 ? 1 : 2);
        int t = 0;
        while (t < count) {
            if (comp == 0) printf("Baixo\n");
            else           printf("Esquerda\n");
            t++;
        }
    }
    printf("---\n");
}

/* ======================== NÍVEL MESTRE ======================== */
/* Trocar loops simples por FUNÇÕES RECURSIVAS.
   Exigências:
   - Bispo: recursivo + loops ANINHADOS dentro da movimentação.
   - Torre: recursivo (Direita N vezes)
   - Rainha: recursivo (Esquerda N vezes)
   - Cavalo: 1 salto em L para CIMA à DIREITA usando loop(s) com
             variáveis/condições múltiplas e uso de continue/break. */

/* Bispo recursivo: a cada passo imprime "Cima" e "Direita".
   (loops aninhados DENTRO da recursão para a movimentação do passo) */
void mestre_bispo_rec(int passos_restantes) {
    if (passos_restantes <= 0) return;

    /* loops aninhados (propósito didático): percorre as duas direções do passo */
    for (int outer = 0; outer < 1; outer++) {
        for (int d = 0; d < 2; d++) {
            if (d == 0) printf("Cima\n");
            else        printf("Direita\n");
        }
    }
    mestre_bispo_rec(passos_restantes - 1);
}

void mestre_torre_rec(int passos_restantes) {
    if (passos_restantes <= 0) return;
    printf("Direita\n");
    mestre_torre_rec(passos_restantes - 1);
}

void mestre_rainha_rec(int passos_restantes) {
    if (passos_restantes <= 0) return;
    printf("Esquerda\n");
    mestre_rainha_rec(passos_restantes - 1);
}

/* Cavalo: 1 L para CIMA à DIREITA
   - Ex.: 2x Cima + 1x Direita (poderia ser 1x Cima + 2x Direita)
   - Loop com variáveis/condições múltiplas e uso de continue/break */
void mestre_cavalo_cima_direita(void) {
    printf("=== Nivel Mestre — Cavalo (1 salto em L para cima e direita) ===\n");

    int cima = 0, direita = 0;       /* contadores realizados */
    int alvo_cima = 2, alvo_dir = 1; /* queremos Cima,Cima,Direita (exemplo) */

    /* condição composta: continua enquanto faltar qualquer parte do L */
    for (int passo = 1; (cima < alvo_cima) || (direita < alvo_dir); passo++) {

        /* se já completei Cima e falta Direita, priorize Direita */
        if (cima >= alvo_cima && direita < alvo_dir) {
            printf("Direita\n");
            direita++;
            continue; /* volta ao topo do for para reavaliar condições */
        }

        /* se já completei Direita e falta Cima, priorize Cima */
        if (direita >= alvo_dir && cima < alvo_cima) {
            printf("Cima\n");
            cima++;
            continue;
        }

        /* caso geral: primeiro complete Cima, depois Direita */
        if (cima < alvo_cima) {
            printf("Cima\n");
            cima++;
            continue;
        }

        if (direita < alvo_dir) {
            printf("Direita\n");
            direita++;
            continue;
        }

        /* segurança: se atingirmos os dois alvos, encerramos */
        break;
    }
    printf("---\n");
}

int main(void) {
    /* ========= valores (inseridos manualmente no código) ========= */
    int passos_bispo_novato  = 5;  /* diagonal cima+direita */
    int passos_torre_novato  = 5;  /* direita */
    int passos_rainha_novato = 8;  /* esquerda */

    int passos_bispo_mestre  = 5;  /* recursivo: diagonal cima+direita */
    int passos_torre_mestre  = 5;  /* recursivo: direita */
    int passos_rainha_mestre = 8;  /* recursivo: esquerda */

    /* ===================== NÍVEL NOVATO ===================== */
    novato_bispo(passos_bispo_novato);
    novato_torre(passos_torre_novato);
    novato_rainha(passos_rainha_novato);

    /* =================== NÍVEL AVENTUREIRO ================== */
    aventureiro_cavalo_baixo_esquerda();

    /* ====================== NÍVEL MESTRE ==================== */
    printf("=== Nivel Mestre — Bispo (diagonal cima+direita, %d passos, recursivo + loops aninhados) ===\n",
           passos_bispo_mestre);
    mestre_bispo_rec(passos_bispo_mestre);
    printf("---\n");

    printf("=== Nivel Mestre — Torre (direita, %d passos, recursivo) ===\n", passos_torre_mestre);
    mestre_torre_rec(passos_torre_mestre);
    printf("---\n");

    printf("=== Nivel Mestre — Rainha (esquerda, %d passos, recursivo) ===\n", passos_rainha_mestre);
    mestre_rainha_rec(passos_rainha_mestre);
    printf("---\n");

    mestre_cavalo_cima_direita();

    printf("=== Fim do programa ===\n");
    return 0;
}