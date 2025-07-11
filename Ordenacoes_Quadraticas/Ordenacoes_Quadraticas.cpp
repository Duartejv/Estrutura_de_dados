#include <iostream>
#include <fstream>
#include <chrono>
#include <locale.h>
using namespace std;
using namespace chrono;

int Insertion_Sort(int* lista, int tamanho){
    long long temp;
    for(int i=1; i<tamanho; i++){
        temp = lista[i];
        int j = i-1; 
        while (j>=0 and lista[j]>temp){
            lista[j+1] = lista[j]; //joga para frente o maior
            lista[j] = temp; // joga para tras o menor
            j=j-1; //olha para o proximo de tras
        }    
    }
    for (int i=0; i<tamanho; i++) {
        cout <<lista[i]<<" ";
    }
return 1;
}

int Seletion_Sort(int* lista, int tamanho){
    int menor;
    int temp;
    for (int i=0; i<=tamanho-2;i++) {
        menor = i;
        for (int j=i+1 ; j<=tamanho-1;j++){
            if (lista[j]<lista[menor]){
                menor = j;  // se tiver menor na frente, ele vira o novo menor
            }
        }
        if (lista[i] != lista[menor]){ //substiuição para o menor ficar atras
            temp = lista[i];      
            lista[i] = lista[menor];
            lista[menor] = temp;
        }
    }
    for (int i=0; i<tamanho; i++) {
    cout <<lista[i]<<" ";
    }
return 1;
}

int main(){
    setlocale(LC_ALL, "");
    int escolha, tipo;
    long long valor;
    int tam_max;
    cout<<"Digite o numero do arquivo para ordena-lo, os aquivos vao do 1 ao 12: \n";
    cin>>escolha;
    ifstream arquivo;
    switch (escolha) {
        case 1:
            tam_max = 1000;
            arquivo.open("num.1000.1.in"); break;
        case 2:
            tam_max = 1000;
            arquivo.open("num.1000.2.in"); break;
        case 3:
            tam_max = 1000;
            arquivo.open("num.1000.3.in"); break;
        case 4:
            tam_max = 1000;
            arquivo.open("num.1000.4.in"); break;
        case 5:
            tam_max = 10000;
            arquivo.open("num.10000.1.in"); break;
        case 6:
            tam_max = 10000;
            arquivo.open("num.10000.2.in"); break;
        case 7:
            tam_max = 10000;
            arquivo.open("num.10000.3.in"); break;
        case 8:
            tam_max = 10000;
            arquivo.open("num.10000.4.in"); break;
        case 9:
            tam_max = 100000;
            arquivo.open("num.100000.1.in"); break;
        case 10:
            tam_max = 100000;
            arquivo.open("num.100000.2.in"); break;
        case 11:
            tam_max = 100000;
            arquivo.open("num.100000.3.in"); break;
        case 12:
            tam_max = 100000;
            arquivo.open("num.100000.4.in"); break;
        default:
            cout<<"Digite um valor entre 1 e 12 para escolher o arquivo";
            break;
    }
    int* lista = new int[tam_max];
    int v=0;
    while (arquivo>>valor){
        lista[v] = valor;
        v++;
    }
    arquivo.close();
    cout<<"Escolha o tipo do algoritmo: ";
    cout<<"\n1- Seletion Sort \n2- Insertion Sort\n";
    cin>>tipo;
    auto inicio = high_resolution_clock::now();
    switch (tipo){
    case 1:
        Seletion_Sort(lista,tam_max);
        break;
    case 2:
        Insertion_Sort(lista,tam_max);  
        break;
    default:
        cout<<"Digite um valor correspondente ao tipo";
        break;
    }
    auto fim = high_resolution_clock::now();
    auto duracao_ms = duration_cast<milliseconds>(fim - inicio);
    duration<double> duracao_s = fim - inicio;
    cout <<"\n\n\nTempo de execucao: "<< duracao_ms.count()<<" ms";
    cout <<"\nEm segundos: "<<duracao_s.count()<<" s";
    return 1;
}