int main (){
    int valor, quantidade;
    int nota [6] {100,50,20,10,5,2};

    cout<<"Digite uma quantia em reais: \n";
    cin>>valor;
    
        for (int i=0; valor>=nota[i];i++){
            if (valor<nota[i]){
                i++;
            }
            quantidade = valor / nota[i];
            valor = valor % nota[i];
            cout<<quantidade<<" nota(s) de "<<nota[i]<<" reais\n";
        }
        
        if (valor=1){
             cout<<"1 moeda de 1 real \n";
        }

    return 0;
}
