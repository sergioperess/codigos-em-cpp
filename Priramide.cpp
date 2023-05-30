#include <iostream>
using namespace std;

int main(){
	
	int b,h,soma;
	cin >> b >> h;
	soma = b+h;
	
	if( b%h == 0 ){
		for (int i =0; i<soma; i++){
			cout << "G";
			for (int j =0; j < i; j++){
				cout << "-G" ;
				
			
			}
			cout << endl;
		}
	}
		
	return 0;
}