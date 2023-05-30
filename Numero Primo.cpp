#include<iostream>
#include<stdlib.h> 

using namespace std;

bool exemplo(int X){
	if(X == 1){
		return false;
	}
	for(int i =  ; i < X ; i++){
		if(X % i == 0){
			return true;
		}
	}
}

int main(){
	int X;
	bool P;
	
	cout << "Entre com um numero inteiro" << endl;
	cin >> X;
	
	P = exemplo(P);
	system("pause");
	system("cls");
	
	if(P == true){
		cout << "E primo" << endl;
	}else{
		cout << "Nao e primo" << endl;
	}
	return 0;
}