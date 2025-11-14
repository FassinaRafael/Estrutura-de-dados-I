#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int info;
	struct No *esq;
	struct No *dir;
} No;

typedef struct No* ArvBin;

ArvBin* cria_ArvBin() {
	ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if(raiz != NULL) {
		*raiz = NULL;
	}
	return raiz;
}

void preOrdem_ArvBin(ArvBin* raiz) {
	if(raiz == NULL) {
		return;
	}

	if(*raiz != NULL) {
		printf(" %d |", (*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin* raiz) {
	if(raiz == NULL) {
		return;
	}

	if(*raiz != NULL) {
		emOrdem_ArvBin(&((*raiz)->esq));
		printf(" %d |", (*raiz)->info);
		emOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_ArvBin(ArvBin* raiz) {
	if(raiz == NULL) {
		return;
	}

	if(*raiz != NULL) {
		posOrdem_ArvBin(&((*raiz)->esq));
		posOrdem_ArvBin(&((*raiz)->dir));
		printf(" %d |", (*raiz)->info);
	}
}

int totalNos_ArvBin(ArvBin* raiz) {
	if(raiz == NULL || *raiz == NULL)
		return 0;

	int total_esq = totalNos_ArvBin(&((*raiz)->esq));
	int total_dir = totalNos_ArvBin(&((*raiz)->dir));

	return total_esq + total_dir + 1;
}

int altura_ArvBin(ArvBin* raiz) {
	if(raiz == NULL || *raiz == NULL)
		return -1;

	int altura_esq = altura_ArvBin(&((*raiz)->esq));
	int altura_dir = altura_ArvBin(&((*raiz)->dir));

	if(altura_esq > altura_dir) {
		return altura_esq + 1;
	}
	else {
		return altura_dir + 1;
	}
}

int consulta_ArvBin(ArvBin* raiz, int valor) {
	if(raiz == NULL || *raiz == NULL)
		return 0;

	No* atual = *raiz;
	while(atual != NULL) {

		if(valor == atual->info) {
			return 1;
		}
		if(valor > atual->info) {
			atual = atual->dir;
		}
		else {
			atual = atual->esq;
		}
	}
	return 0;
}

void libera_No(No* no) {
	if(no == NULL) {
		return;
	}

	libera_No(no->esq);
	libera_No(no->dir);

	free(no);
	no = NULL;
}

void libera_ArvBin(ArvBin* raiz) {
	if(raiz == NULL) {
		return;
	}
	libera_No(*raiz);
	free(raiz);
}

int insere_ArvBin(ArvBin *raiz, int valor) {
	if(raiz == NULL) {
		return 0;
	}

	No *novo = (No*) malloc(sizeof(No));
	if(novo == NULL) {
		return 0;
	}
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;

	if(*raiz == NULL) { //se a arvore esta vazia
		*raiz = novo;
	}
	else {
		No *atual = *raiz;
		No *anterior = NULL;
		while(atual != NULL) {

			anterior = atual;
			if(valor == atual->info) {
				free(novo);
				return 0;
			}
			if(valor>atual->info) {
				atual = atual->dir;
			} else {
				atual = atual->esq;
			}
		}
		if(valor>anterior->info) {
			anterior->dir = novo;
		} else {
			anterior->esq = novo;
		}
	}
	return 1;
}

No* remove_atual(No* atual) {
	No *no1, *no2;

	if(atual->esq == NULL) {
		no2 = atual->dir;
		free(atual);
		return no2;
	}

	no1 = atual;
	no2 = atual->esq;

	while(no2->dir != NULL) {
		no1 = no2;
		no2 = no2->dir;
	}

	if(no1 != atual) {
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}

	no2->dir = atual->dir;
	free(atual);
	return no2;
}

int remove_ArvBin(ArvBin* raiz, int valor) {
    if (raiz == NULL || *raiz == NULL)
        return 0;

    No *atual = *raiz;
    No *anterior = NULL;

    while (atual != NULL) {
        if (valor == atual->info) {

            // caso seja a raiz
            if (atual == *raiz) {
                *raiz = remove_atual(atual);
            }
            else {
                if (valor > anterior->info)
                    anterior->dir = remove_atual(atual);
                else
                    anterior->esq = remove_atual(atual);
            }
            return 1; // Remoção bem-sucedida
        }

        anterior = atual;

        if (valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    return 0; // valor não encontrado
}


int main() {
    ArvBin* arvore = cria_ArvBin();

    printf("---- TESTE DE INSERÇÃO ----\n");
    insere_ArvBin(arvore, 10);
    insere_ArvBin(arvore, 5);
    insere_ArvBin(arvore, 20);
    insere_ArvBin(arvore, 3);
    insere_ArvBin(arvore, 7);
    insere_ArvBin(arvore, 15);
    insere_ArvBin(arvore, 30);

    printf("\nPré-ordem:   ");
    preOrdem_ArvBin(arvore);

    printf("\nEm ordem:    ");
    emOrdem_ArvBin(arvore);

    printf("\nPós-ordem:   ");
    posOrdem_ArvBin(arvore);

    printf("\n\nTotal de nós: %d", totalNos_ArvBin(arvore));
    printf("\nAltura: %d\n", altura_ArvBin(arvore));

    printf("\n---- TESTE DE CONSULTA ----\n");
    printf("Consulta 7  -> %s\n", consulta_ArvBin(arvore, 7) ? "Encontrado" : "Não encontrado");
    printf("Consulta 99 -> %s\n", consulta_ArvBin(arvore, 99) ? "Encontrado" : "Não encontrado");

    printf("\n---- TESTE DE REMOÇÃO ----\n");

    printf("\nRemovendo 3 (folha)\n");
    remove_ArvBin(arvore, 3);
    emOrdem_ArvBin(arvore);

    printf("\n\nRemovendo 20 (tem 1 filho)\n");
    remove_ArvBin(arvore, 20);
    emOrdem_ArvBin(arvore);

    printf("\n\nRemovendo 10 (raiz)\n");
    remove_ArvBin(arvore, 10);
    emOrdem_ArvBin(arvore);

    printf("\n\nNovo total de nós: %d", totalNos_ArvBin(arvore));
    printf("\nNova altura: %d\n", altura_ArvBin(arvore));

    printf("\n---- LIBERANDO ÁRVORE ----\n");
    libera_ArvBin(arvore);

    return 0;
}
