#include <iostream>
using namespace std;

int main () {

   string sp;
   double r1, r2, r3, Rser, Rpar;
   bool repetir=true;
   char simounao;

   do{
      cout<<"Qual é o valor da sua primeira resistência?\n";
      cin>>r1;
      cout<<"Qual é o valor da sua segunda resistência?\n";
      cin>>r2;
      cout<<"Qual é o valor da sua terceira resistência?\n";
      cin>>r3;
      
      cout<<"Suas resistências foram ligadas em série ou em paralelo?\n";
      cin>>sp;

         if (sp == "paralelo"){
            Rpar = (r1*r2*r3)/(r1*r2+r1*r3+r2*r3);
            cout<<"O valor da resistência equivalente em paralelo é: "<<Rpar<<"\n";
         }
         
         else if (sp == "serie"){
            Rser = r1+r2+r3;
            cout<<"O valor da resistência equivalente em série é: "<<Rser<<"\n";
         }

         else {
            cout<<"Resposta inválida.\n";
          }

      cout<<"Deseja verificar o valor de outra resistência? (s/n) \n";
      cin>>simounao;

      if (simounao=='n'){
         repetir=false;
      }
   }
   while (repetir==true);
   return 0;
}