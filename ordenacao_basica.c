#include <stdio.h>

void imprimirVetor(int *V, int n) {
    printf("\nVetor: ");
    for (int i = 0; i < n; i++) printf(" %d |", V[i]);
    printf("\n");
}

void bubbleSort(int v[], int n) {
    int i, j, temp;
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                trocou = 1;
            }
        }

        if (trocou == 0) break;
    }
}

void selectionSort(int V[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (V[j] < V[menor]) menor = j;
        }
        if (i != menor) {
            int temp = V[i];
            V[i] = V[menor];
            V[menor] = temp;
        }
    }
}

void insertionSort(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int main(void) {
    int origem[6] = {23, 5, 68, -5, 33, 80};
    int a[6], b[6], c[6];
    for (int i = 0; i < 6; i++) a[i] = b[i] = c[i] = origem[i];

    printf("Original: ");
    imprimirVetor(origem, 6);

    selectionSort(a, 6);
    printf("Selection:");
    imprimirVetor(a, 6);

    bubbleSort(b, 6);
    printf("Bubble:   ");
    imprimirVetor(b, 6);

    insertionSort(c, 6);
    printf("Insertion:");
    imprimirVetor(c, 6);

    return 0;
}
