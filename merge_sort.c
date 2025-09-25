#include <stdlib.h> 
#include <stdio.h>

void merge(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(v, inicio, meio);

        mergeSort(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

void imprimirVetor(int v[], int n) {
    printf("\nVetor: ");
    for (int i = 0; i < n; i++)
        printf("%d | ", v[i]);
    printf("\n");
}

int main() {
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Original: ");
    imprimirVetor(v, n);

    mergeSort(v, 0, n - 1);

    printf("Ordenado: ");
    imprimirVetor(v, n);

    return 0;
}