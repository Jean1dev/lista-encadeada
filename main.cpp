#include "func_lista_enc.h"
#include <iostream>
#include <string>

using namespace std;


void menu(){
    no *lista;
    int op = -1;
    int info = 0;
    while(op != 0){
      system("cls");
      cout << "--- CADASTRO ---" << endl;
      cout << "0 - Sair" << endl;
      cout << "1 - Criar lista" << endl;
      cout << "2 - Inserir no inicio" << endl;      
      cout << "3 - Inserir no final" << endl;
      cout << "4 - Inserir na ordem crescente" << endl;
      cout << "5 - Remover inicio" << endl;
      cout << "6 - Remover final" << endl;
      cout << "7 - Remover elemento" << endl;
      cout << "8 - Consultar" << endl;
      cout << "9 - Recriar lista" << endl;
      cout << "\nInforme a opcao: ";
      cin >> op;
      if(op == 1){
          lista = criarLista();
      }else if(op == 2){
          cout << "Informe o valor a ser adicionado no inicio: ";
          cin >> info;
          lista = insereInicio(lista,info);
      }else if(op == 3){
          cout << "Informe o valor a ser adicionado no final: ";
          cin >> info;
          lista = insereFinal(lista,info);
      }else if(op == 4){
          cout << "Informe o valor a ser adicionado na ordem: ";
          cin >> info;
          lista = insereOrdemCrescente(lista,info);
      }else if(op == 5){
          lista = removerInicio(lista);
      }else if(op == 6){
          lista = removerFinal(lista);
      }else if(op == 7){
          cout << "Informe o valor a ser removido: ";
          cin >> info;
          lista = removerElemento(lista,info);
      }else if(op == 8){
          consultaValores(lista); 
          system("pause");
      }else if(op == 9){
          lista = recriarLista(lista);
      }
    }
}

void teste(){
  cout << "TESTE" << endl;   
     
   no *lista = criarLista();
   //teste 1
   /*
   lista = insereFinal(lista,10);
   lista = insereFinal(lista,5);
   lista = insereFinal(lista,15);
   lista = insereFinal(lista,3);
   */

   //teste 2
   lista = insereFinal(lista,5);
   lista = insereFinal(lista,10);
   lista = insereFinal(lista,15); 
   lista = insereFinal(lista,2);
   lista = removerElemento(lista,10); 

   lista = ordenaAsc(lista);
   consultaValores(lista); 
          
   cout << "Numeros de elementos da lista "<<consultanlista(lista)<<endl;
   
   system("pause");
}


int main(){
    menu(); 
  //  teste();
    
    return 0;  
}
