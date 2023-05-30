#include<iostream>

using namespace std;

float numaureo(float n){
	
	if(n == 1){
		return 1;
	}else{
		return (1 + (1 / numaureo(n - 1)));
	}
	
	
}

int main(){
	
	float n;
	
	cin >> n;
	
	cout << numaureo(n);
}