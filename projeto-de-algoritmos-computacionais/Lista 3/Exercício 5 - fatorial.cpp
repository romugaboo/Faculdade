/*Elabore um programa para calcular o fatorial n! = 123...(n − 1)n de um inteiro não negativo, respeitando o fato de
que 0! = 1.*/

#include <iostream>
using namespace std;

int main (){

    int n, valor, fat;

    cout << "Digite um número para calcular o seu fatorial: \n";
    cin >> n;

        if (n > 0){

            for(fat = 1; n >= 2; n--){
                fat = fat * n;
            }
            
            cout << "O fatorial do número é: " << fat << "\n";

        }
        
        else if (n < 0){
            cout << "O fatorial desse número não existe :c \n";
        }
        
        else{
            cout << "O fatorial é 1 \n";
        }

    return 0;
}
