#include <iostream>
using namespace std;

#define PI  3.14159

int main() {

	int r;
	cout<<"Qual é o raio do círculo?"<<endl;
	cin>>r;
	
	double p, s;
	p=2*PI*r;
	s=PI*r*r;
	
	cout<<"O circulo de raio "<<r<<" tem um perímetro de "<<p<<" e área "<<s<<endl;
	
	return 0;
}
