
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
int tam_atual=0;
const int tam_max = 100;
int* lista;
int lista1[23] = {
    -152, 483, 709, -397, 128, 90, -624, 311,
    -97, 253, 102, 401, -555, 639, 187, 210,
    -891, 478, 93, 26, -308, 770, -99
};
int lista2[100] = {
    39, 273, 803, 509, 472, 139, 654, 277, 700, 541,
    19, 921, 84, 17, 602, 886, 754, 10, 305, 470,
    699, 524, 820, 444, 932, 105, 628, 303, 902, 327,
    82, 259, 93, 584, 207, 91, 388, 742, 659, 640,
    205, 579, 662, 193, 38, 129, 674, 845, 215, 789,
    316, 512, 731, 624, 487, 50, 185, 77, 421, 844,
    381, 211, 367, 31, 998, 195, 146, 601, 203, 498,
    412, 907, 173, 213, 669, 325, 334, 410, 271, 802,
    397, 140, 117, 460, 697, 830, 9, 39, 245, 510,
    58, 725, 768, 187, 154, 760, 146, 671, 313, 521
};
int lista3[5] = {
    17, -300, 84, 455, -192
};

void vazia(){
  if (tam_atual == 0){
      cout<<"lista vazia!\n";
  }
  else{
    cout<<"Nao!\n";
  }
}
void cheia(){
  if (tam_atual == tam_max){
    cout<<"A lista esta cheia!\n";
  }
  else{
    cout<<"Nao!\n";
  }
}

int obter_modificar(int pos){
  int res;
  int novo_valor;
  if(pos>0 && pos<=tam_atual){
    cout<<"Valor presente na posicao "<<pos<<": ";
    cout<<lista[pos-1];
  }
  else{
    cout<<"posicao invalida, tente novamente";
    return(0);
  }
  cout<<"\nDeseja modificar?\nSim (1)\nNao(2)\n";
  cin>>res;
  if(res==1){
    cout<<"insira um novo valor: ";
    cin>>novo_valor;
    lista[pos-1] = novo_valor;
    cout<<"Valor inserido com sucesso!";
  }
  else if(res==2){
    return(0);
  }
  else{
    cout<<"Erro! insira o numero de acordo com a opcao";
  }
return(1);
}

void inserir(int valor, int pos){
  if(pos>0 && pos<=tam_atual+1){
  for(int i=tam_atual; i>=pos; i--){
      lista[i] = lista[i-1];  //criando um espaço
    }
  lista[pos-1] = valor; //inserindo no espaço criado
  tam_atual++;
  }
}

void remover(int pos){
  if(pos>0 && pos<=tam_atual){
    for(int i=pos-1; i<=tam_atual-1;i++){
      lista[i] = lista[i+1];
    }
    tam_atual--;
  }
}
int main(){
  int valor;
  int pos;
  int escolha;
  cout<<"Escolha uma lista (1) (2) (3): \n";
  cin>>escolha;
  switch (escolha) {
      case 1:
          lista = lista1; 
          tam_atual=23 ;break;
      case 2:
          lista = lista2;
          tam_atual=100; break;
      case 3:
          lista = lista3;
          tam_atual=5; break;
      default:
        cout<<"Escolha uma opcao valida"; break;
  }
  do{
    cout<<"LISTA SEQUENCIAL\n";
    cout<<"1-Verificar se a lista esta vazia\n";
    cout<<"2-Verificar se a lista esta cheia\n";
    cout<<"3-Obter o tamanho da lista\n";
    cout<<"4-Obter/Modificar um elemento da lista\n";
    cout<<"5-Inserir um valor na lista\n";
    cout<<"6-Remover um valor da lista\n";
    cout<<"7-Sair\n";
    cin>>escolha;
    system("cls");
      switch (escolha)
      {
      case 1:
        vazia(); break;
      case 2:
        cheia(); break;
      case 3:
        cout<<"Tamanho: "<<tam_atual; break;
      case 4:
        cout<<"Obter o valor de qual posicao? ";
        cin>>pos;
        obter_modificar(pos); break;
      case 5:
        if(tam_atual == tam_max){
          cheia();
          break;
        }
        cout<<"Valor a ser inserido: ";
        cin>>valor;
        cout<<"Posicao para inserir(Tamanho atual: "<<tam_atual<<"): ";
        cin>>pos;
        inserir(valor, pos);
        cout<<"Valor inserido com sucesso!";
        break;
      case 6:
        cout<<"Posicao para remover: ";
        cin>>pos;
        remover(pos); 
        cout<<"Remocao feita com sucesso"; break;
      case 7:
        cout<<"Saindo..."; break;
      default:
        cout<<"Escolha uma opcao valida";
      }
    cout<<"\n\n\n\n";
    }while (escolha!=7);
}
