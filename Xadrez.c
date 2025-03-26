#include <stdio.h>

// Função recursiva para a movimentação da Torre (5 casas para a direita)
void moverTorre(int movimentos_torre) {
    if (movimentos_torre == 0) {
        return; // Caso base: se não houver mais movimentos, parar
    }
    printf("Direita\n");
    moverTorre(movimentos_torre - 1); // Chamada recursiva
}

// Função recursiva para a movimentação do Bispo (com loops aninhados)
void moverBispo(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) {
        return; // Caso base: se não houver mais movimentos, parar
    }
    printf("Cima, Direita\n");
    moverBispo(vertical - 1, horizontal - 1); // Chamada recursiva para diagonal
}

// Função recursiva para a movimentação da Rainha (8 casas para a esquerda)
void moverRainha(int movimentos_rainha) {
    if (movimentos_rainha == 0) {
        return; // Caso base: se não houver mais movimentos, parar
    }
    printf("Esquerda\n");
    moverRainha(movimentos_rainha - 1); // Chamada recursiva
}

// Função para o movimento complexo do Cavalo (2 casas para cima, 1 para a direita)
void moverCavalo() {
    printf("Movimento do Cavalo (2 casas para cima e 1 casa para a direita):\n");
    
    for (int i = 0; i < 2; i++) { // Loop para movimentar 2 casas para cima
        printf("Cima\n");
    }
    
    // Loop aninhado para mover 1 casa para a direita
    for (int j = 0; j < 1; j++) {
        if (j == 1) {
            break; // Exemplo de uso de break (não será alcançado)
        }
        printf("Direita\n");
    }
}

int main() {
    // Movimentação da Torre
    printf("Movimento da Torre (5 casas para a direita):\n");
    moverTorre(5); // Chamada da função recursiva da Torre

    // Movimentação do Bispo (com recursividade e loops aninhados)
    printf("\nMovimento do Bispo (5 casas para cima e à direita):\n");
    moverBispo(5, 5); // Chamada da função recursiva do Bispo

    // Movimentação da Rainha
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");
    moverRainha(8); // Chamada da função recursiva da Rainha

    // Movimentação do Cavalo (com loops complexos)
    printf("\n");
    moverCavalo(); // Chamada da função do Cavalo

    return 0;
}
