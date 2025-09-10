
#include <stdio.h>

struct pessoa {
    char nome[50];
    int idade;
};

void imprime(struct pessoa p) {
    printf("Nome: %s, idade: %i\n", p.nome, p.idade);
}

void aniversario(struct pessoa *p) {
    p->idade++;
    printf("Nome: %s, idade: %i\n", p->nome, p->idade);
}

int main()
{
    struct pessoa p = {"Ana", 20};
    
    imprime(p);
    aniversario(&p);

    return 0;
}
