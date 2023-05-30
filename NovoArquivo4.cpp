#include<iostream>

using namespace std;
int fatorial(){
	int x,b=1;
	x=5;
	for(int i = 1; i<=5;i++){
		b=b*i;
	}
	return b;
}

int main(){
	cout<<fatorial()<<endl;
}