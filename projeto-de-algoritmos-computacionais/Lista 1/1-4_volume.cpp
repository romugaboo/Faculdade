#include <iostream>
using namespace std;

int main() {

	int r;
	cout<<"Qual é o raio do círculo?"<<endl;
	cin>>r;
	
	double a, v;
	a=3.14*r*r;
	v=4*3.14*r*r*r/3;
	
	cout<<"O circulo de raio "<<r<<" tem uma área de "<<a<<" e volume "<<v<<endl;
	
	return 0;
}
