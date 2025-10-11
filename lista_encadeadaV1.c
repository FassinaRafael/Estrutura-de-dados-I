#include <stdio.h>
#include <stdlib.h>


//codigo pra liberar lista de tras pra frente.

typedef struct cel{
  int conteudo;
  struct cel *seg;
}cel;

typedef struct cel* Lista;


Lista* cria_lista(){
  Lista* li = malloc(sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

int insere_lista_fim(Lista* lista, int x){
  if(lista == NULL) { return 0; }
  
  cel* aux = (cel*) malloc(sizeof(cel));
  if(aux == NULL){ return 0; }
  
  aux->conteudo = x;
  aux->seg = NULL;
  
  if(*lista == NULL) {
    *lista = aux;
    
  } else {
    cel* temp = *lista;
    
    while(temp->seg != NULL){ 
      temp = temp->seg;
    }
    temp->seg = aux;
  }
  return 1;
}

void imprime_lista(Lista* lista) {
    cel* temp = *lista;
    
    while(temp != NULL){
        printf("%d -> ", temp->conteudo);
        temp = temp->seg;
    }
    
    printf("NULL\n");
}

void buscar(Lista* lista, int chave) {
    cel* temp = *lista;
    int contador = 0;
    int encontrado = 0;
    
    while(temp != NULL) {
        if(temp->conteudo == chave) {
            printf("NUMERO %i ENCONTRADO NA CELULA %i\n", chave, contador);
            encontrado = 1;
            break;
        }
        temp = temp->seg;
        contador++;
    }
    if(!encontrado)
        printf("%d nao encontrado\n", chave);
}

int main(void) {
  Lista *lst;
  lst = cria_lista();
  insere_lista_fim(lst, 1);
  insere_lista_fim(lst, 2);
  insere_lista_fim(lst, 3);
  insere_lista_fim(lst, 4);
  insere_lista_fim(lst, 5);
  imprime_lista(lst);

  imprime_lista(lst);
  
  buscar(lst, 3);
  buscar(lst, 55);

  return 0;
}
