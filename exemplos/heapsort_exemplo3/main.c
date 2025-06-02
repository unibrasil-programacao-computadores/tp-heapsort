#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Codigo baseado no video de Amit G. Maru
Referencias:
AMIT G. MARU. C Program For Heap Sort Algorithm. Disponível em: <https://www.youtube.com/watch?v=bnlxkQ_gA0U>. Acesso em: 30 mai. 2025.*/

void heap_sort(int[], int);
void build_max_heap(int[], int);
void max_heapify(int[], int, int);
int main()
{
    int i, r, heapsize, n;
    int a[50];
    printf("How many nodes are there in Tree?\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter value=");
        scanf("%d", &a[i]);
    }
    heapsize = n-1;
    heap_sort(a, heapsize);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    getch();
}

void heap_sort(int a[], int heapsize)
{
    int i, tmp;
    build_max_heap(a, heapsize);
    for (i = heapsize; i > 0; i--)
    {
        tmp = a[i];
        a[i] = a[0];
        a[0] = tmp;
        heapsize--;
        max_heapify(a, 0, heapsize);
    }
}
void build_max_heap(int a[], int heapsize)
{
    int i;
    for (i = heapsize/2; i >= 0; i--)
    {
        max_heapify(a, i, heapsize);
    }
}

void max_heapify(int a[], int i, int heapsize)
{
    int tmp, largest;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if ((l <= heapsize) && (a[l] > a[i]))
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if ((r <= heapsize) && (a[r] > a[largest]))
    {
        largest = r;
    }
    if (largest != i)
    {
        tmp = a[i];
        a[i] = a[largest];
        a[largest] = tmp;
        max_heapify(a, largest, heapsize);
    }
}
