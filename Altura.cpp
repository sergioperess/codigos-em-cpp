#include<iostream>

using namespace std;
double altura(double x, char y){
	double PI;
	if(y=='M'){
		PI=(72.7*x)-58;
		return PI;		
	}else if(y=='F'){
		PI=(62.1*x)-44.7;
		return PI;
	}
}

int main(){
	
	double A,R;
	char S;
	cout<<"Entre com sua altura"<<endl;
	cin>>A;
	do{
		cout<<"Entre com seu sexo M - masculino ou F - feminino"<<endl;
		cin>>S;
	}while(!(S=='M' || S=='F'));
	R=altura(A,S);
	cout<<R<<endl;
}