#include <iostream>
using namespace std;

int main() {

    double x;
    double y;
    cout<<"Digite um valor para x!\n";
    cin>>x;

        if (x>0){
        y=10/x+x*x;
        }
        else{
        y=x*x;
        }

    cout<<"y vale: "<<y<<"\n";
    return 0;
}
