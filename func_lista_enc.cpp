//Exemplo de uma lista encadeada
#include "func_lista_enc.h"
#include <iostream>
#include <string>

using namespace std;

//cria um novo nó
no *criar_no(int valor){
   no *novo = new no();
   novo->info = valor;
   novo->prox = NULL;
   return novo;
}

//6-A- cria uma nova lista
no *criarLista(){
  return NULL;
}

// 6 -B- Recria a lista
no *recriarLista(no *lista){
   
   no *n = lista;
   while(n != NULL){
      no *excluir = n;      
      n = n->prox;
      delete(excluir);
   }
   return NULL;
}

// 6-C- Lista Vazia
int listavazia(no *lista){
   if(lista == NULL){
      return 1;
   }    
   return 0;
}

// 6-D- insere no início da lista
no *insereInicio(no *lista, int info){
    no *novo = criar_no(info);
    if(lista == NULL){
        //aponta o objeto primeiro para o novo nó
        lista = novo;    
    }else{
        novo->prox = lista;
        lista = novo; 
    }
    return lista;
}

// 6-E- Remove inicio da lista
no *removerInicio(no *lista){
   if(lista == NULL){
      cout << "Nao existem elementos a serem removidos" << endl; 
      return NULL;
   }
   
   no *primeiro = lista;
   lista = lista->prox;
   delete (primeiro);
   return lista;
}

// 6-F- Consulta lista
void consultaValores(no *lista){
  if(lista == NULL){
    cout << "Nao existem valores a serem consultados" << endl;
  }else{
    while(lista != NULL){
       cout << "Valor: " << lista->info << endl;
       lista = lista->prox;
    }
  }
}

// 6 -G- Consulta primeiro lista
int consultaprimeirolista(no *lista){
    if(listavazia(lista)){
        return -1;
    }
    return lista->info;
}

// 6 -h- Consulta o endereço do primeiro  lista
no *consultaendprimeirolista(no *lista){
    if(listavazia(lista)){
        return NULL;
    }
    
    return lista;
}

// 6 -i- Consulta numero de elementos na lista
int consultanlista(no *lista){
    if(listavazia(lista)){
        return 0;
    }
    int aux = 0;    
    while(lista != NULL){
       lista = lista->prox;
       aux++;
    }
    return aux;
}



no *ordenaAsc(no *lista){
  //será implementado
  if(lista == NULL || lista->prox == NULL){
     return lista;         
  }else{
      
      //conta quantos registros existem na lista
      int reg = 0;
      no *aux = lista;  
      while(aux != NULL){
         aux = aux->prox;
         reg++;     
      }
      
      for(int i = 0; i < reg; i++){
          //faz a troca do registro  
          no *n = lista;
          no *pai = NULL;
          bool first = true;
          while(n != NULL){
               no *a = n;//atual
               no *b = n->prox;
               
               if(b != NULL){
                  if(a->info > b->info){
                     a->prox = b->prox;
                     b->prox = a;
                     
                     if(pai != NULL){
                       pai->prox = b;
                     }
                     
                     n = a;
                     pai = b;
                     if(first){
                       lista = b;
                       first = false;
                     }
                  }else{
                     pai = n;
                     n = n->prox;         
                  }
               }else{
                  pai = n;
                  n = n->prox;
               }
               
             if(first){
               first = false;
             }
          }
      }  
  }
  return lista;
}

no *buscaUltimo(no *lista){
  if(lista == NULL){
     return NULL;
  }
  //busca o último elemento inserido na lista
  no *n = lista;
  while(n->prox != NULL){
    n = n->prox;
  }
  return n;
}

//insere no final da lista e retorna o elemento inserido
no *insereFinal(no *lista, int info){
   no *novo = criar_no(info);
   //a lista ainda não possui valores    
   if(lista == NULL){
        //aponta o objeto primeiro para o novo nó
        lista = novo;
   }else{
        no *ultimo = buscaUltimo(lista);
        ultimo->prox = novo;
   }
   return lista;   
}


no *removerFinal(no *lista){
  if(lista == NULL){
     return NULL;
  }                   
  
  //verifica se existe somente um elemento inserido na lista
  if(lista->prox == NULL){
    delete(lista);
    lista = NULL;
  }else{
    //localiza o último NÓ da lista, guardando os endereços do registro a ser excluido e o seu anterior
    no *atual = lista;
    no *anterior;
    while(atual->prox != NULL){
       anterior = atual;
       atual = atual->prox;                  
    }
    //exclui a última posição
    delete(atual);
    
    //atualiza a referência do ponteiro que aponta para o último para NULL
    anterior->prox = NULL;
  }
  
  return lista;
}


no *insereOrdemCrescente(no *lista, int info){
  
   if(lista == NULL){
      return insereInicio(lista,info);
   }
   
   no *aux = lista;
   no *pai = NULL;
   while(aux != NULL){
      if(aux->info > info){
          no *novo =  criar_no(info);
          novo->prox = aux;
          if(pai != NULL){
            pai->prox = novo;
          }else{
             lista = novo;      
          }
          break;
      }
      pai = aux;
      aux = aux->prox;   
   }
  return lista;
}

no *removerElemento(no *lista, int valor){
  
   if(lista == NULL){
      cout << "Nao existem elementos a serem removidos" << endl; 
      return NULL;
   }
   no *aux = lista;
   no *pai = NULL;
   while(aux != NULL){
      if(aux->info == valor){
          pai->prox = aux->prox;
          delete(aux);
          break;
      }
      pai = aux;
      aux = aux->prox;   
   }
  return lista;
}










