
#include <iostream>

using namespace std;

int somatorio(int x){
	 int soma, aux;
 	 aux = x;
	 soma = 0;
 	 x = 0;
 	 for(int i=0; i<aux; i++){
 	 	 soma = soma + i;
 	 }
 	 return soma;
}
int main(){
 	 int N, resp;
 	 
	 cout<<"Digite o valor de N:"<<endl;
 	 cin>>N;
	 
	 resp = somatorio( N );
 	 
	 cout<<"Somatorio de "<<N<<" = "<<resp<<endl;
}