#include <stdio.h>

     struct pessoa {
        char nome[50];
        int idade;
        float altura;
    };

int main()
{
    struct pessoa pessoas[3] = { {"Ana", 20, 1.65}, {"Joao", 24, 1.75}, {"Maria", 30, 1.55}};
    struct pessoa *p = pessoas;
    
    for(int i = 0; i < 3;i++) {
        printf("PESSOA %i - Nome: %s / Idade: %i / Altura: %.2f\n", i, p->nome, p->idade, p->altura);
        p++;
    }
    
    p = pessoas;
    (p + 1)->idade = 26;
    printf("%s agora tem %d anos\n", pessoas[1].nome, pessoas[1].idade);
    
    return 0;
}