#include<iostream>

using namespace std;

int buscas(int n, int v[], int proc){
	
	int j = 0;
	
	while(proc > v[j] && proc < n){
		j++;
	}
	if(j < n && v[j] == proc){
		return j + 1;
	}else{
		return -1;
	}
	
	

	
}

int busca(int tam, int v[], int proc){
	int inicio = 0;
	int fim = tam - 1;
	int meio;
	int x = 0;
	
	while(inicio <= fim){
		x++;
		meio = (inicio + fim)/ 2;
		if(v[meio] == proc){
			cout << meio << endl;
			cout << buscas(tam,v,proc) << endl;
			return x;
		}else{
			if(v[meio] > proc){
				fim = meio - 1;	
						
			}else{
				inicio = meio + 1;
				
			}
		}	
		
	}
	cout << -1 << endl;
	cout << buscas(tam,v,proc) << endl;
	return x;

}

int main(){
	
	int n, proc;
	
	cin >> n;
	
	int vet[n];
	
	for(int i = 0; i < n; i++){
		cin >> vet[i];
	}
	
	cin >> proc;
	
	
	cout << busca(n, vet, proc) << endl;
	
	
}