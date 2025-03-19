#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 49

void bubbleSort (int a[], int size);

int main (){
    int a[N];
    srand (time(NULL));
    for (int i = 0; i < N; i++){
        a[i] = rand()%1000;
        cout << a[i] << "\t";
    }
    cout << "\n\n";
    bubbleSort (a, N);

        for (int i = 0; i < N; i++){
            cout << a[i] << "\t";
        }
    return 0;
}

void bubbleSort (int a[], int size){
    int aux = 0, i, j;
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
