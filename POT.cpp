#include <iostream>

using namespace std;

int exp(int B, int E){
	int T=1;
	for(int i=1; i<=E; i++){
		T=T*B;
	}
	return T;
}

int main(){
	
	int B, E;
	cout<<"Entre com a base e o expoente "<<endl;
	cin>>B>>E;
	cout<<"Resultado : "<<exp(B,E)<<endl;
}