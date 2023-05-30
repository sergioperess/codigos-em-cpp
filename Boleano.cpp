#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

bool primo(int x){
	
	if(x / 1 == x && x / x == 1 && x != 1 && x % 2 != 0 || x == 2){
		return true;
	}else{
		return false;
	}
}
int main(){
	
	int a;
	
	cin >> a;
	
	if(primo(a) == true){
		cout << "Eh primo!!" << endl;
	}else{
		cout << "Nao Eh primo!!" << endl;
	}
	
}
