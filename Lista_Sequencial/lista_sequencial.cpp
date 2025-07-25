
#include <iostream>
#include <windows.h>
using namespace std;
int tam_atual=0;
const int tam_max = 100;
int lista[tam_max];

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
    cout<<"A lista está cheia!\n";
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
      switch (escolha)
      {
      case 1:
        system("cls");
        vazia(); break;
      case 2:
        system("cls");
        cheia(); break;
      case 3:
        system("cls");
        cout<<"Tamanho: "<<tam_atual; break;
      case 4:
        system("cls");
        cout<<"Obter o valor de qual posicao? ";
        cin>>pos;
        obter_modificar(pos); break;
      case 5:
        system("cls");
        if(tam_atual == tam_max){
          cheia();
        }
        cout<<"Valor a ser inserido: ";
        cin>>valor;
        cout<<"Posicao para inserir(Tamanho atual: "<<tam_atual<<"): ";
        cin>>pos;
        inserir(valor, pos);
        cout<<"Valor inserido com sucesso!";
        break;
      case 6:
        system("cls");
        cout<<"Posicao para remover: ";
        cin>>pos;
        remover(pos); 
        cout<<"Remocao feita com sucesso"; break;
      case 7:
        system("cls");
        cout<<"Saindo..."; break;
      default:
        system("cls");
        cout<<"Escolha uma opcao valida"; break;
      }
    cout<<"\n\n\n\n";
    }while (escolha!=7);
}
