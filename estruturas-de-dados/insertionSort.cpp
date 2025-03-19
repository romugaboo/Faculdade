#include <iostream>
using namespace std;

void insertionSort (int a[], int size);

int main (){
    int a[10] = {17, 88, 54, 92, 33, 21, 5, 47, 62, 70};
    cout << "Numeros antes do Insertion Sort: \n";
    
    for (int i = 0; i < 10; i++){
        cout << a[i] << "\t";
    }
    cout << "\n\n";
    
    insertionSort (a, 10);
    cout << "Numeros depois do Insertion Sort: \n";

        for (int i = 0; i < 10; i++){
            cout << a[i] << "\t";
        }       
        cout << "\n\n"; 
    return 0;
}

void insertionSort (int a[], int size){
    int i, chave, j;
    for (i = 1; i < size; i++){
        chave = a[i];
        j = i - 1;
    
        while (j >= 0 && a[j] > chave){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = chave;
    }
}