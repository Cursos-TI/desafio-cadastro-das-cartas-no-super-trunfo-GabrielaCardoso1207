#include <stdio.h>

// Tamanho do tabuleiro e das habilidades
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
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

// Função para posicionar navio horizontalmente (mesmo código do nível anterior)
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + 3 > TAMANHO_TABULEIRO) {
        return 0; // Não cabe no tabuleiro
    }
    // Verifica se as posições estão livres
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; // Posição já ocupada
        }
    }
    // Posiciona o navio
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Função para criar a matriz da habilidade Cone (5x5)
void criarHabilidadeCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            cone[i][j] = 0;
        }
    }

    // Define a forma de cone
    cone[0][2] = 1;
    cone[1][1] = 1; cone[1][2] = 1; cone[1][3] = 1;
    cone[2][0] = 1; cone[2][1] = 1; cone[2][2] = 1; cone[2][3] = 1; cone[2][4] = 1;
}

// Função para criar a matriz da habilidade Cruz (5x5)
void criarHabilidadeCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            cruz[i][j] = 0;
        }
    }

    // Define a forma de cruz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        cruz[2][i] = 1; // Linha central
        cruz[i][2] = 1; // Coluna central
    }
}

// Função para criar a matriz da habilidade Octaedro (5x5)
void criarHabilidadeOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Inicializa com 0
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            octaedro[i][j] = 0;
        }
    }

    // Define a forma de octaedro (losango)
    octaedro[0][2] = 1;
    octaedro[1][1] = 1; octaedro[1][3] = 1;
    octaedro[2][0] = 1; octaedro[2][2] = 1; octaedro[2][4] = 1;
    octaedro[3][1] = 1; octaedro[3][3] = 1;
    octaedro[4][2] = 1;
}

// Função para sobrepor uma habilidade ao tabuleiro
void aplicarHabilidadeNoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = linhaOrigem + i - TAMANHO_HABILIDADE / 2;
            int colunaTabuleiro = colunaOrigem + j - TAMANHO_HABILIDADE / 2;

            // Verifica se as coordenadas estão dentro dos limites do tabuleiro
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    // Marca a área afetada pela habilidade com 5
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {
                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Inicializa o tabuleiro e as habilidades
    inicializarTabuleiro(tabuleiro);
    criarHabilidadeCone(cone);
    criarHabilidadeCruz(cruz);
    criarHabilidadeOctaedro(octaedro);

    // Posiciona um navio para visualização
    posicionarNavioHorizontal(tabuleiro, 1, 3);

    // Aplica as habilidades no tabuleiro
    aplicarHabilidadeNoTabuleiro(tabuleiro, cone, 5, 5);       // Aplica cone no centro
    aplicarHabilidadeNoTabuleiro(tabuleiro, cruz, 7, 2);       // Aplica cruz em outra posição
    aplicarHabilidadeNoTabuleiro(tabuleiro, octaedro, 3, 8);   // Aplica octaedro no canto

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
