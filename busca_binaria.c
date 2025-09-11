
#include <stdio.h>

int buscaBinaria(int *V, int chave, int inicio, int fim) {
    while(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if(V[meio] == chave) 
            return meio;
        else if(V[meio] < chave) 
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
    
}

int main()
{
    int array[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int busca, resultado;
    printf("Insira o numero para buscar: ");
    scanf("%i", &busca);
    
    resultado = buscaBinaria(array, busca, 0, 9);
    if (resultado == -1) {
        printf("Numero nao encontrado\n");
    }
    else {
        printf("Numero %i encontrado na posicao %i", busca, resultado);
    }
    return 0;
}
