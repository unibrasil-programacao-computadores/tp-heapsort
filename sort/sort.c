#include "sort.h"
#include <stdio.h>

int compare(const void* a, const void* b)
{
    double diff =  *(double*)a - *(double*)b;
    return diff > 0 ? 1 : diff < 0 ? -1 : 0;
}

void quicksort(double* arr, long arr_size)
{
    qsort(arr, arr_size, sizeof(double), compare);
}

void selectionsort(double* arr, long arr_size)
{
    int i, j, min;
    double x;
    for(i = 0; i < arr_size; i++) {
        min = i;

        for(j = i + 1; j < arr_size; j++) {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        x = arr[min]; arr[min] = arr[i];  arr[i] = x;
        }

        x = arr[min];
        arr[min] = arr[i];
        arr[i] = x;
    }
}//implementar insertionsort que não use sentinela comitar

void insertionsort(double* arr, long arr_size)
{
    int i, j;
    double sent;
    for(i = 2; i < arr_size; i++) {
        sent = 2;
        while(j >=0 && sent < arr[j]) {
            j--;
        }
        j=sent;
    }
}

//funcao para alternar a posicao de dois elementos(swap)
void swap(double *a, double *b)
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

//funcao da filtragem(heapify)
void heapify(double* arr, long n, long i)
{
    //arr eh o array
    //i eh a posicao
    //n eh a enesima posicao(tamanho do array/qntde de elementos no array)

    //encontrando o maior valor(valor_maximo) entre a raiz, posicao_esq e posicao_dir
    double temp;
    long valor_maximo, posicao_esq, posicao_dir;

    valor_maximo = i;
    posicao_esq = 2 * i + 1;
    posicao_dir = 2 * i + 2;

    //se o valor da posicao_esq existir/for menor que o tamanho do array(enesima posicao)
    //e for maior que a raiz do array
    if (posicao_esq < n && arr[posicao_esq] > arr[valor_maximo])

        //a raiz da arvore sera atualizada pelo valor da posicao_esq
        valor_maximo = posicao_esq;

    //se o valor da posicao_dir existir/for menor que enesima posicao/o tamanho do array
    //e for maior que a raiz do array
    if (posicao_dir < n && arr[posicao_dir] > arr[valor_maximo])

        //a raiz da arvore sera atualizada pelo valor da posicao_dir
        valor_maximo = posicao_dir;

    //se a raiz nao for o maior elemento(valor_maximo), prosseguir com swap(alternancia) e heapify(filtragem).
    if (valor_maximo != i) {

        //temp valera uma determinada posicao do array
        temp = arr[i];

        //alternara essa determinada posicao do array com a raiz
        swap(&arr[i], &arr[valor_maximo]);

        //e passara o array, o seu tamanho e raiz para filtrar
        heapify(arr, n, valor_maximo);
    }
}

//procedimento heap sort
void heapsort(double* arr, long arr_size)
{
    //construindo max heap
    for (int i = arr_size / 2 - 1; i >= 0; i--) {
        heapify(arr, arr_size, i);
    }

    //realizando o heap sort
    for (int i = arr_size - 1; i >= 0; i--) {

        //alternando a raiz com uma determinada posicao do array
        swap(&arr[0], &arr[i]);

        //aplicando heapify na raiz para que o maior elemento volte para a raiz.
        heapify(arr, i, 0);
    }
}
