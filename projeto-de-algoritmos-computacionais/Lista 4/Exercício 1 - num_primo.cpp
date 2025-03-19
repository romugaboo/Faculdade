/*Escreva um programa que leia um inteiro em tempo de execução e determine se o número entrado
é primo ou não. Se ele não for primo, imprima na tela seu menor divisor (diferente de 1).*/

#include <iostream>
using namespace std;

int main(){
    int num;

    cout<<"Digite um número inteiro \n";
    cin>>num;

    for(int i = 2; num/i; i++){
        if (num%i==0){
            cout<<num<<" não é um número primo e seu menor divisor é "<<i<<".\n";
            break;
        }
        else if (i==num/2) {
            cout<<num<<" é um número primo! \n";
            break;
        }
    }
    return 0;
}
