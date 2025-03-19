// Eu utilizei o Quick Sort pois é um método de divisão e conquista que apesar de ter uma complexidade 
// de pior caso de O(n²), esse algoritmo não se comporta assim na maior parte dos casos.

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 20

void listarElem (int a[], int n);
void quickSort (int a[], int inicio, int fim);
void troca (int * x, int * y);

int main (){
    int a[N], op = 0;
    srand (time(NULL));
    for (int i = 0; i < N; i++){
        a[i] = rand()%100;
    }

    do {
        cout << "Digite 1 para ordenar os elementos, 2 para listar os elementos ou 0 para sair \n";
        cin >> op;
        cout << "\n";
       
        switch (op){
            case 1: quickSort (a, 0, N - 1); 
                cout << "Os elementos foram ordenados! \n\n";
                break;
            case 2: listarElem (a, N); break;
        }
    }
    
    while (op != 0);
    return 0;
}

void listarElem (int a[], int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << "\n\n";
}

void quickSort (int a[], int inicio, int fim){
    int i = 0, j = 0, chave = 0;
    if (fim - inicio < 2) {
        if ((fim - inicio) == 1) {
            if (a[inicio] > a[fim]){
                troca (&a[inicio], &a[fim]);
            }
        }
    }  
    
    else {
        i = inicio;
        j = fim;
        chave = a[inicio];
        while (j > i) {
            i++;
            while(a[i] < chave) {
                i++;
            }
            while(a[j] > chave) {
                j--;
            }
            if (j > i) {
                troca (&a[i], &a[j]);
            }
        }
        troca (&a[inicio], &a[j]);
        quickSort(a, inicio, j - 1);
        quickSort(a, j + 1, fim);
    }
}

void troca (int * x, int * y){
    int aux;
    aux = * x;
    * x = * y;
    * y = aux;
}