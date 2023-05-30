#include<iostream>

using namespace std;
double area(){
	double r,a;
	cout<<"O Raio = ";
	cin>>r;
	a=3.14*r;
	return a;
}

void perimetro(){
	double r,p;
	cout<<"O Raio = ";
	cin>>r;
	p=3.14*r*2;
	cout<< p <<endl;
}

int main(){
	int x;
	cout<<"1 - Calculo da area "<<endl;
	cout<<"2 - Calculo do perimetro "<<endl;
	do{
		cin>>x;
	}while(!(x==1 || x==2));	
	switch(x){
		case 1: cout<<"Calculo da area "<<area()<<endl;
				break;
		case 2: cout<<"Calculo do perimetro "<<perimetro()<<endl;
				break;
	}
}