
#include <stdio.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[30];
};

int buscaPorMatricula(struct aluno a[], int chaveMat, int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        if(a[i].matricula == chaveMat)
            return i;
    }
    return -1;
}

int buscaPorNome(struct aluno a[], char chaveNome[], int tamanho) {
    int i;
    for(i = 0; i < tamanho; i++) {
        if(strcmp(a[i].nome, chaveNome) == 0)
            return i;
    }
    return -1;
}

int main() {
    struct aluno alunos[5] = {
        {123, "Ana"},
        {456, "Carlos"},
        {789, "Maria"},
        {111, "Joao"},
        {222, "Walter"}
    };
    
    int mat, resultadoMat, resultadoNome;
    char nome[30];
    
    printf("Insira o numero de matricula: ");
    scanf("%i", &mat);
    
    resultadoMat = buscaPorMatricula(alunos, mat, 5);
    if (resultadoMat == -1) {
        printf("Matricula nao encontrada\n");
    } else {
        printf("Matricula %i encontrada: %s (posicao %i)\n",
               mat, alunos[resultadoMat].nome, resultadoMat);
    }
    
    printf("Insira o nome: ");
    scanf("%s", nome);
    
    resultadoNome = buscaPorNome(alunos, nome, 5);
    if (resultadoNome == -1) {
        printf("Nome nao encontrado\n");
    } else {
        printf("Nome %s encontrado: matricula %i (posicao %i)\n",
               alunos[resultadoNome].nome, alunos[resultadoNome].matricula, resultadoNome);
    }
    
    return 0;
}
