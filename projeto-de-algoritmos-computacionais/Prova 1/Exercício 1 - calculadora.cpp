#include <iostream>
using namespace std;

void fazer_operacao (double num_1, double num_2, char tipo){
    switch (tipo) {           
        case 'S':
            cout << "A soma de " << num_1 << " e " << num_2 << " é " << num_1 + num_2 << "\n";
        break;
        case 'P':
            cout << "O produto entre " << num_1 << " e " << num_2 << " é " << num_1 * num_2 << "\n";
        break;
        case 'U':
            cout << "A subtração de " << num_1 << " por " << num_2 << " é " << num_1 - num_2 << "\n";
        break;
        case 'D':
            cout << "A divisão entre " << num_1 << " e " << num_2 << " é " << num_1 / num_2 << "\n";
        break;
        default:
            cout << "Essa operação não existe! \n";
        break;
    }
}

int main (){
    double n1, n2;
    char operacao;
    
    cout << "Escolha uma das seguintes opções: \n";
    cout << "S - Soma \n";
    cout << "P - Produto \n";
    cout << "U - Subtração \n";
    cout << "D - Divisão \n";
    cin >> operacao;

    cout << "Digite dois números \n";
    cin >> n1;
    cin >> n2;

    fazer_operacao (n1, n2, operacao);

    return 0;
}
