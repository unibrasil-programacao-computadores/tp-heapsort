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
// Heap Sort in C

  // Function to swap the the position of two elements
  //funcao de swap/alternancia entre as posicoes de dois elementos
  void swap(int *pos_a, int *pos_b) {
    int temp = *pos_a;
    *pos_a = *pos_b;
    *pos_b = temp;
  }

  void heapify(double* arr, long arr_size) {
    // Find largest among root, left child and right child
    int i;//
    int maior = i;
    int filho_esq = 2 * i + 1;
    int filho_dir = 2 * i + 2;

    if (filho_esq < arr_size && arr[filho_esq] > arr[maior])
      maior = filho_esq;

    if (filho_dir < arr_size && arr[filho_dir] > arr[maior])
      maior = filho_dir;

    // Swap and continue heapifying if root is not largest
    if (maior != i) {
      swap(&arr[i], &arr[maior]);
      heapify(arr, arr_size, maior);
    }
  }

  // Main function to do heap sort
  void heapsort(double* arr, long arr_size) {
    // Build max heap
    for (int i = arr_size / 2 - 1; i >= 0; i--)
      heapify(arr, arr_size, i);

    // Heap sort
    for (int i = arr_size - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

  // Print an array
  void printArray(double* arr, long arr_size) {
    for (int i = 0; i < arr_size; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }

  // Driver code
  int main() {
    //int arr[] = {1, 12, 9, 5, 6, 10};
    long int tamanho_array = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, tamanho_array);

    printf("Sorted array is \n");
    printArray(arr, tamanho_array);
  }
