/* Escreva um programa que leia n números inteiros em tempo de execução e que imprima a soma, o produto e a
média deles. */
 
#include <iostream>
using namespace std;
 
int main (){
    
    int qntd_num, num, soma = 0, prod, med;
    
    cout<<"Deseja inserir quantos números? \n";
    cin>>qntd_num;
        
        for (int i = 0; i < qntd_num; i++){
            cout << "Digite um número: \n";
            cin >> num;
            
            soma = soma + num;
            prod = prod * num;
        }
    
    cout << soma << "\n";
    cout << prod << "\n";
    cout << soma / qntd_num << "\n";
    
    return 0; 
}