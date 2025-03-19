#include <iostream>
using namespace std;

void bubbleSort (int a[], int size);

int main (){
    int a[10] = {17, 88, 54, 92, 33, 21, 5, 47, 62, 70};
    cout << "Numeros antes do Bubble Sort: \n";

    for (int i = 0; i < 10; i++){
        cout << a[i] << "\t";
    }
    cout << "\n\n";
    
    bubbleSort (a, 10);
    cout << "Numeros depois do Bubble Sort: \n";

        for (int i = 0; i < 10; i++){
            cout << a[i] << "\t";
        }       
        cout << "\n\n"; 
    return 0;
}

void bubbleSort (int a[], int size){
    int i, j, aux = 0;
    for (i = 0; i < size - 1; i++){
        for (j = i + 1; j < size; j++){
            if (a[i] > a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}