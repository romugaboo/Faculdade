#include <iostream>
using namespace std;

int main (){
    int num_1, num_2, maior_num;
    bool repete=true;
    char simounao;

    cout<<"Digite um número: \n";
    cin>>num_1;
    
    do{
        cout<<"Digite mais um número: \n";
        cin>>num_2;

            if(num_1>num_2){
                maior_num=num_1;
                cout<<"O "<<maior_num<<" é maior que o "<<num_2<<"\n";
            }
            else if (num_2>num_1){
                maior_num=num_2;
                cout<<"O "<<maior_num<<" é maior que o "<<num_1<<"\n";
            }
            else{
                maior_num=num_1;
                cout<<maior_num<<" é igual à "<<maior_num<<"\n";
            }
        
        num_1=maior_num;

        cout<<"Deseja comparar com mais um número? (s/n) \n";
        cin>>simounao;

        if(simounao=='n'){
            repete=false;
        }
    }
    while (repete==true);
    return 0;
}