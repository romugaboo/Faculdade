#include <iostream>
using namespace std;

int mdc(int x, int y){
    if(x > y){
        return mdc(x - y, y);
    }
    else if(x < y){
        return mdc(x, y - x);
    }
    else{
        return x;
    }
    return 0;
}

int main(){
    int x, y;

    cout << "Digite o primeiro numero: \n";
    cin >> x;
    
    cout << "Digite o segundo numero: \n";
    cin >> y;

    cout << "O MDC entre " << x << " e " << y << " eh " << mdc(x, y) << " \n";
    return 0;
}
