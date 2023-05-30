#include <iostream>

using namespace std;

int soma(int a, int b){
	
	if(b == 1){
		return a;
	}else{
		return a + soma(a, b - 1);
	}
	
}

int main(){
	
	int a, b;
	
	cin >> a >> b;
	
	cout << soma(a, b);
	
	
}