#include "sort.h"

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
}
//implementar insertionsort que não use sentinela comitar
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
