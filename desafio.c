#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define AGUA 0
#define NAVIO_MARCA 3

// Função para verificar se uma posição está dentro do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO;
}

// Verifica se é possível posicionar o navio sem sobreposição
int podeColocarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        int novaLinha = linha + i * dx;
        int novaColuna = coluna + i * dy;

        if (!dentroDosLimites(novaLinha, novaColuna) || tabuleiro[novaLinha][novaColuna] != AGUA)
            return 0; // Fora dos limites ou já ocupado
    }
    return 1;
}

// Coloca o navio no tabuleiro
void colocarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        int novaLinha = linha + i * dx;
        int novaColuna = coluna + i * dy;
        tabuleiro[novaLinha][novaColuna] = NAVIO_MARCA;
    }
}

// Imprime o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa com água (0)

    // 1º Navio: Horizontal (linha 2, coluna 1 → direita)
    if (podeColocarNavio(tabuleiro, 2, 1, 0, 1))
        colocarNavio(tabuleiro, 2, 1, 0, 1);

    // 2º Navio: Vertical (linha 5, coluna 5 → para baixo)
    if (podeColocarNavio(tabuleiro, 5, 5, 1, 0))
        colocarNavio(tabuleiro, 5, 5, 1, 0);

    // 3º Navio: Diagonal ↘ (linha 0, coluna 0)
    if (podeColocarNavio(tabuleiro, 0, 0, 1, 1))
        colocarNavio(tabuleiro, 0, 0, 1, 1);

    // 4º Navio: Diagonal ↙ (linha 2, coluna 8)
    if (podeColocarNavio(tabuleiro, 2, 8, 1, -1))
        colocarNavio(tabuleiro, 2, 8, 1, -1);

    // Exibir o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
