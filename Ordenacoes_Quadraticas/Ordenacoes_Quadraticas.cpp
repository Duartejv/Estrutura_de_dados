#include <iostream>
#include <fstream>
#include <chrono>
#include <windows.h>
#include <locale.h>
using namespace std;
using namespace chrono;
long long ms_Insertion, ms_Selection; 
long long ns_Insertion, ns_Selection;
int escolha;

int Insertion_Sort(int* lista, int tamanho){
    auto inicio = high_resolution_clock::now();
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
    if(escolha<=4){
        Sleep(1);   //colocando um tempo mínimo de execução
    }
    auto fim = high_resolution_clock::now();
    auto duracao = fim - inicio;
    ns_Insertion = duration_cast<nanoseconds>(duracao).count();
    ms_Insertion = duration_cast<milliseconds>(duracao).count();
    for (int i=0; i<tamanho; i++) {
        cout <<lista[i]<<" ";
    }
return 1;
}

int Selection_Sort(int* lista, int tamanho){
    auto inicio = high_resolution_clock::now();
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
    if(escolha<=4){
        Sleep(1);  //colocando um tempo mínimo de execução
    }
    auto fim = high_resolution_clock::now();
    auto duracao = fim - inicio;
    ns_Selection = duration_cast<nanoseconds>(duracao).count();
    ms_Selection = duration_cast<milliseconds>(duracao).count();
    for (int i=0; i<tamanho; i++) {
    cout <<lista[i]<<" ";
    }
return 1;
}

int main(){
    setlocale(LC_ALL, "");
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
    int* lista2 = new int[tam_max];
    int v=0;
    while (arquivo>>valor){
        lista[v] = valor;  //captura dos valores no arquivo
        v++;
    }
    arquivo.close();
    for (int i = 0; i < tam_max; i++) {
        lista2[i] = lista[i];    //clonando para a segunda lista
    }
    Selection_Sort(lista,tam_max);
    cout<<"\n\n\n";
    Insertion_Sort(lista2,tam_max);
    if (escolha<=4){       //removendo o parâmentro do Sleep
        ms_Selection = ms_Selection - 1;
        ms_Insertion = ms_Insertion - 1;
        ns_Selection = ns_Selection - 1000000;   
        ns_Insertion = ns_Insertion - 1000000;
    }
    cout <<"\n\nTempo de execucao do Selection Sort: "<< ms_Selection<<" ms";
    cout <<"\nEm nanosegundos: "<<ns_Selection<<" ns";
    cout <<"\n\nTempo de execucao do Insertion Sort: "<< ms_Insertion<<" ms";
    cout <<"\nEm nanosegundos: "<<ns_Insertion<<" ns";
    delete[] lista;
    delete[] lista2;
    return 1;
}
