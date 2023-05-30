#include<iostream>

using namespace std;

int procurado(int n, int vetor[], int k){
	
	if(n < 0){
		return -1;
	}else if(vetor[n] == k){
		return n;
	}else{
		return procurado(n - 1, vetor, k);
	}	
	
}

int main(){
	int i, proc;
	
	cin >> i;
	
	int vet[i];
	
	for(int j = 0; j < i; j++){
		cin >> vet[j];
	}
	
	cin >> proc;
	
	cout << procurado(i, vet, proc) << endl;
	
	return 0;
	
}