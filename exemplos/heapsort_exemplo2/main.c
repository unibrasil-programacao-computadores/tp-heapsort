#include <stdio.h>
#include <stdlib.h>

//Exemplo dos Reis
//Adaptado por Marcelo Henrique.
//Referencias:
//PROGRAMIZ. Heap Sort Algorithm. Disponível em: <https://www.programiz.com/dsa/heap-sort>.

// funcao para alternar entre o rei e o seu afilhado(substituicao)
void substituicao(double *a, double *b)
{
    //temp eh uma variavel para armazenar um valor temporario
    //*a eh um apontador que representa uma posicao
    //*b eh um apontador que representa uma outra posicao

    //o valor de *a ficara em temp
    double temp = *a;

    //os ponteiros *a e *b trocara dois elementos
    //*a sera igual o valor de *b, ja *b vai sera igual temp(onde o valor estara armazenado)
    *a = *b;
    *b = temp;
}

// funcao da filtragem(rebaixamento)
void rebaixamento(int familia[], int n, int i)
{
    // familia eh o array
    // i eh o integrante da familia
    // n eh o tamanho da familia

    // encontrando o mais velho entre o trono(rei), filho_esq e filho_dir
    int mais_velho = i;
    int filho_esq = 2 * i + 1;
    int filho_dir = 2 * i + 2;

    if (filho_esq < n && familia[filho_esq] > familia[mais_velho])
        mais_velho = filho_esq;

    if (filho_dir < n && familia[filho_dir] > familia[mais_velho])
        mais_velho = filho_dir;

    // prosseguir com alternancia e filtragem se o trono nao for o mais_velho(valor_maximo)
    if (mais_velho != i)
    {
        substituicao(&familia[i], &familia[mais_velho]);
        rebaixamento(familia, n, mais_velho);
    }
}

//procedimento heap sort
void heapSort(int familia[], int n)
{
    //construindo max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        rebaixamento(familia, n, i);

    //realizando o heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        //substituindo o trono com
        substituicao(&familia[0], &familia[i]);

        //aplicando rebaixamento no trono para que o mais_velho volte para o trono.
        rebaixamento(familia, i, 0);
    }
}

// imprimir familia
void imprimeFamilia(int familia[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", familia[i]);
    printf("\n");
}

int main()
{
    int familia[] = {14, 91, 85, 83, 4, 8, 1, 7, 16, 5};
    int n = sizeof(familia) / sizeof(familia[0]);

    printf("Original familiaay is \n");
    imprimeFamilia(familia, n);

    heapSort(familia, n);

    printf("Sorted familiaay is \n");
    imprimeFamilia(familia, n);
}
