#include <stdio.h>



int main() {
    char *nomes[] = {"Ana", "Joao", "Carlos"};
    
    char **p = nomes;
    
    for(int i = 0; i < 3; i++) {
        printf("Nome %i: %s\n", i + 1, *p);
        p++;
    }
    
    p = nomes;
    *(p + 1) = "Pedro";
    printf("Novo nome: %s\n", *(p + 1));
}