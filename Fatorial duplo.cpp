#include <iostream>

using namespace std;

int fatduplo(int x){

	if(x == 0){
		return 1;
	}else{
		if(x == 1){
			return 1;
		}else{
			return x*fatduplo(x-2);
		}
	}
		
}
int main(){
	
	int n;
	
	cin >> n;
	
	cout << fatduplo(n);
}