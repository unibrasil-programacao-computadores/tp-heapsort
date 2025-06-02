#include <stdio.h>

// cód com ajuda do video abaixo 
// referencia: https://www.youtube.com/watch?v=zSYOMJ1E52A 

// função para subistituir o "a" e "b"
void substitua(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// função para por o rebaixamento 
void rebaixamento(int vetor[], int n, int i) {
    int mais_velho = i;
    int filho_esq = 2 * i + 1;
    int filho_dir = 2 * i + 2;

    if (filho_esq < n && vetor[filho_esq] > vetor[mais_velho])
        mais_velho = filho_esq;

    if (filho_dir < n && vetor[filho_dir] > vetor[mais_velho])
        mais_velho = filho_dir;

    if (mais_velho != i) {
        substitua(&vetor[i], &vetor[mais_velho]);
        rebaixamento(vetor, n, mais_velho);
    }
}

// função principal  
void heapSort(int vetor[], int n) {
    // construi e organizar a familia
    for (int i = n / 2 - 1; i >= 0; i--)
        rebaixamento(vetor, n, i);

    // um por um remove 
    for (int i = n - 1; i >= 0; i--) {
        substitua(&vetor[0], &vetor[i]);
        rebaixamento(vetor, i, 0);
        
    
    }
}

// função para imprimir
void imprimirFamilia(int vetor[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", vetor[i]);
    printf("\n");
}

// função principal
int main() {
    int vetor[] = {14, 91, 85, 83, 4, 8, 1, 7, 16, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Familia original:\n");
    imprimirFamilia(vetor, tamanho);

    heapSort(vetor, tamanho);

    printf("Familia ordenado:\n");
    imprimirFamilia(vetor, tamanho);

    return 0;
}
