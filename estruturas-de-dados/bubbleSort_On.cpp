#include <iostream>
using namespace std;

void bubbleSortOtimizado (int a[], int size);

int main (){
    int a[10] = {17, 88, 54, 92, 33, 21, 5, 47, 62, 70};
    cout << "Numeros antes do Bubble Sort Otimizado: \n";

    for (int i = 0; i < 10; i++){
        cout << a[i] << "\t";
    }
    cout << "\n\n";
    
    bubbleSortOtimizado (a, 10);
    cout << "Numeros depois do Bubble Sort Otimizado: \n";

        for (int i = 0; i < 10; i++){
            cout << a[i] << "\t";
        }       
        cout << "\n\n"; 
    return 0;
}

void bubbleSortOtimizado(int a[], int size) {
    int i, j, aux = 0, troca = 1;
    for (i = 0; i < size - 1 && troca == 1; i++) {
        troca = 0;
       for (j = i + 1; j < size; j++){
            if (a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                troca = 1;
            }
        }
    }
}