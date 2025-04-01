#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Não cabe no tabuleiro
    }
    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; // Posição já ocupada
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Não cabe no tabuleiro
    }
    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; // Posição já ocupada
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonalmente (direção crescente - esquerda para direita)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Não cabe no tabuleiro
    }
    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) {
            return 0; // Posição já ocupada
        }
    }
    // Posiciona o navio diagonalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1;
}

// Função para posicionar navio diagonalmente (direção decrescente - direita para esquerda)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        return 0; // Não cabe no tabuleiro
    }
    // Verifica se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) {
            return 0; // Posição já ocupada
        }
    }
    // Posiciona o navio diagonalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
    return 1;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas para os navios
    int linhaNavioHorizontal = 1, colunaNavioHorizontal = 3;
    int linhaNavioVertical = 4, colunaNavioVertical = 7;
    int linhaNavioDiagonalCrescente = 0, colunaNavioDiagonalCrescente = 0;
    int linhaNavioDiagonalDecrescente = 5, colunaNavioDiagonalDecrescente = 9;

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Erro ao posicionar o navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Erro ao posicionar o navio vertical!\n");
    }
    if (!posicionarNavioDiagonalCrescente(tabuleiro, linhaNavioDiagonalCrescente, colunaNavioDiagonalCrescente)) {
        printf("Erro ao posicionar o navio diagonal crescente!\n");
    }
    if (!posicionarNavioDiagonalDecrescente(tabuleiro, linhaNavioDiagonalDecrescente, colunaNavioDiagonalDecrescente)) {
        printf("Erro ao posicionar o navio diagonal decrescente!\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
