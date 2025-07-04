
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 50 // tamanho do vetor

// Função para preencher o vetor com números aleatórios de 1 a 100
void preencherVetor(int vetor[TAM]) {
    srand(time(NULL)); // inicializa gerador aleatório
    for (int i = 0; i < TAM; i++) {
        vetor[i] = (rand() % 100) + 1; // números entre 1 e 100
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[TAM]) {
    printf("Vetor:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%3d ", vetor[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n"); // quebra de linha a cada 10 números
        }
    }
}

// Função recursiva para encontrar o maior elemento do vetor
int encontrarMaior(int vetor[TAM], int indice, int maiorAtual) {
    // Caso base: percorreu todos os elementos
    if (indice == TAM) {
        return maiorAtual;
    }

    // Atualiza o maior valor se necessário
    if (vetor[indice] > maiorAtual) {
        maiorAtual = vetor[indice];
    }

    // Chamada recursiva para o próximo elemento
    return encontrarMaior(vetor, indice + 1, maiorAtual);
}

int main() {
    int vetor[TAM];

    // Preencher vetor aleatoriamente
    preencherVetor(vetor);

    // Imprimir vetor
    imprimirVetor(vetor);

    // Encontrar o maior valor usando recursão
    int maior = encontrarMaior(vetor, 0, vetor[0]);

    // Imprimir o maior valor encontrado
    printf("\nMaior valor do vetor: %d\n", maior);

    return 0;
}
