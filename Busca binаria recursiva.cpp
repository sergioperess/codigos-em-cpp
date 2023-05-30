#include<iostream>

using namespace std;

int procurado(int tam,int v[],int proc){
	
	if(tam < 0){
		return -1;
	}else if(v[tam] == proc){
		return tam;
	}else{
		return procurado(tam - 1, v, proc);
	}

}

int main(){
	
	int proc, tam;
	
	cin >> tam;
	
	int vet[tam];
	
	for(int i = 0; i < tam; i++){
		cin >> vet[i];
	}
	
	cin >> proc;
	
	cout << procurado(tam, vet, proc);
}
