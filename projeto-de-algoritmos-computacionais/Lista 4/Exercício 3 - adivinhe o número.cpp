#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main (){
    int num_secret, num_guess, num_rod = 0;
    bool repetir;

    srand (time(NULL));
    num_secret = rand()%100;
    
    cout<<"Em qual número o computador está pensando...? \n";
    cin>>num_guess;

        do{
            if (num_guess < 0){
                cout<<"Você perdeu :c \n";
                repetir==false;
            }

            else if (num_guess > num_secret){
                cout<<"Valor alto demais >.< !! Tente novamente: \n";
                num_rod++;
                cin>>num_guess;
            }

            else if(num_guess < num_secret){
                cout<<"Valor pequeno demais >.< !! Tente novamente: \n";
                num_rod++;
                cin>>num_guess;
            }

            else{
                num_rod++;
                cout<<"Parabéns, você descobriu o número em "<< num_rod << "rodadas!! \n";
                repetir = false;
            }
        }
       
        while (repetir == true);

    return 0;
}
