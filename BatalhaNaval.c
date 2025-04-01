#include <stdio.h>

// Fixando o tamanho do tabuleiro como 10x10
#define TAMANHO_TABULEIRO 10

// Fixando o tamanho dos navios como 3
#define TAMANHO_NAVIO 3

//Função onde declaramos que todo o tabuleiro receberá o número zero, que de acordo com o enunciado representa a água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

//Validamos de acordo com o tamanho do navio se este cabe na regra de tamanho 3 e cabe no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;  //Neste caso não cabe e retorna um erro
    }

    // Verificamos se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0;  // Quando tem sobreposição retorna erro
        }
    }

    // Posicionamos o navio horizontalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1;  // Tudo certo
}

int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verificamos se o navio cabe no tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0;  // Não cabe, apresenta erro
    }

    // Verificamos se as posições estão livres
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0;  //Há sobreposiçãoe e apresenta erro
        }
    }

    // Posicionamos o navio verticalmente
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1;  // Tudo certo
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Exibimos o tabuleiro no terminal
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

    // Inicializmosa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas para os navios ja definidas
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 4;
    int linhaNavioVertical = 5, colunaNavioVertical = 1;

    // Posicionamos os navios no tabuleiro
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Erro ao posicionar o navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Erro ao posicionar o navio vertical!\n");
    }

    // Exibimos o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}