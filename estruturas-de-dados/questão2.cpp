#include <iostream>
using namespace std;

struct buffer {
    int cod;
    struct buffer* prox;
};

typedef struct buffer * buffPtr;
buffPtr topo = NULL;

void enqueue ();
void dequeue ();
bool listaVazia();

int main (){
    int op;
    do {
        cout << "Digite 1 para enviar um pacote, 2 para imprimir um pacote e 0 para sair.\n";
        cin >> op;
        switch(op) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
        }
    } 
    while (op != 0);
    cout << endl;
    return 0;
}

void enqueue () {
    buffPtr aux, p = new buffer;
    cout << "\nDigite o codigo do pacote: ";
    cin >> p -> cod;
    cout << "\nPacote enviado!\n\n";
    p -> prox = NULL;
    
    if (listaVazia())
        topo = p;
    
    else{
        aux = topo;
        aux -> prox = p;
    }
}

void dequeue () {
    buffPtr p = new buffer;

    if (listaVazia())
        cout << "\nO buffer esta vazio!\n\n";
    else {
        p = topo;
        cout << "\nO codigo do pacote e: " << p -> cod << "\n\n";
        topo = p -> prox;
        delete p;
        if (listaVazia())
            cout << "O buffer esta vazio!\n\n";
    }
}

bool listaVazia(){
    if (topo) return false;
    else return true;
}