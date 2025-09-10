/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
