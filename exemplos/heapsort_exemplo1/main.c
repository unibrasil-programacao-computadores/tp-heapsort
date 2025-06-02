#include <stdio.h>
#include <stdlib.h>

//Exemplo do Livro: Estruturas de dados usando C
//Adaptado por Marcelo Henrique.
//Referencias:
//TENENBAUM, A. M.; LANGSAM, Y.; AUGENSTEIN, M. J. Estruturas de dados usando C. [s.l: s.n.].

void pqinsert(int dpq[], int k, int elt)
{
    int s = k;
    int f = (s - 1) / 2;
    while (s > 0 && dpq[f] < elt)
    {
        dpq[s] = dpq[f];
        s = f;
        f = (s - 1) / 2;
    }
    dpq[s] = elt;
}

int largeson(int x[], int p, int m)
{
    int s = 2 * p + 1;
    if (s + 1 <= m && x[s] < x[s + 1])
    {
        s = s + 1;
    }
    if (s > m)
    {
        return -1;
    }
    else
    {
        return s;
    }
}

void adjustheap(int dpq[], int root, int k)
{
    int f = root;
    int kvalue = dpq[k];
    int s = largeson(dpq, f, k - 1);
    while (s >= 0 && kvalue < dpq[s])
    {
        dpq[f] = dpq[s];
        f = s;
        s = largeson(dpq, f, k - 1);
    }
    dpq[f] = kvalue;
}

int pqmaxdelete(int dpq[], int k)
{
    int p = dpq[0];
    dpq[0] = dpq[k - 1];
    adjustheap(dpq, 0, k - 1);
    return p;
}

void heapsort(int x[], int n)
{
    int i;

    for (i = 1; i < n; i++)
    {
        pqinsert(x, i, x[i]);
    }

    for (i = n - 1; i > 0; i--)
    {
        x[i] = pqmaxdelete(x, i + 1);
    }
}

void printArray(int x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

int main()
{
    int x[] = {14, 91, 85, 83, 4, 8, 1, 7, 16, 5, 10, 9, 11, 2, 34};
    int n = sizeof(x) / sizeof(x[0]);

    printf("Array original:\n");
    printArray(x, n);

    heapsort(x, n);

    printf("Array ordenado:\n");
    printArray(x, n);

    return 0;
}
