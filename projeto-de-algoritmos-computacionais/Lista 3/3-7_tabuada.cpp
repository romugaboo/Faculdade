/*Elabore um programa para escrever a tabuada de 0 a 10*/

#include <iostream>
using namespace std;

int main (){
    int valor;

    cout<<"X*Y\tI\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10 \n";
    cout<<"_______________________________________________________________________________________________________\n \n";
    
        for (int i=0; i<=10; i++){            
            cout<<i<<"\tI\t";
            
            for (int j=0; j<=10; j++){
                valor = i*j;
                cout<<valor<<"\t";
            }
        cout<< " \n";
        }
        cout<< " \n";
    return 0;
}