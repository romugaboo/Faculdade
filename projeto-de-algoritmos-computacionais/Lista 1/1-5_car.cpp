#include <iostream>
using namespace std;

int main() {

	char car1, car2, car3;
	
	cout<<"Escreva a letra 1"<<endl;
	cin>>car1;
	
	cout<<"Escreva a letra 2"<<endl;
	cin>>car2;
	
	cout<<"Escreva a letra 3"<<endl;
	cin>>car3;
	
	car1=car2;
	car2=car3;
	car3=car1;
	
	cout<<endl<<car1<<endl<<car2<<endl<<car3<<endl;
	
	return 0;
}
