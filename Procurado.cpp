#include<iostream>

using namespace std;

int posicao(int tam, int procurado, int v[]){
	
	if(tam < 0){
		return -1;
	}else if(v[tam] == procurado){
		return tam;
	}
	else{
		return posicao(tam - 1, procurado, v);
	}
	
	
}

int main(){
	
	int tam, x;
	cin >> tam;
	int v[tam];
	
	for(int i = 0; i < tam; i++){
		
		cin >> v[i];
				
	}
	
	cin >> x;
	
	cout << posicao(tam, x, v);
	
	
}