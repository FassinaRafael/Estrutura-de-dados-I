#include <stdio.h>
#include <string.h>  

int palindromo(char str[], int inicio, int fim) {
    if (inicio >= fim)  
        return 1;
    if (str[inicio] != str[fim])  
        return 0;
    return palindromo(str, inicio + 1, fim - 1);
}

int main() {
    char palavra[] = "radar";  
    int resultado = palindromo(palavra, 0, strlen(palavra) - 1);

    if (resultado == 1)
        printf("'%s' É palíndromo!\n", palavra);
    else
        printf("'%s' NÃO é palíndromo!\n", palavra);

    return 0;
}
