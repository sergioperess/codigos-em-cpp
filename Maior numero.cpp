#include<iostream>

using namespace std;

int maior(int x, int y, int c){
	if(x>y){
		return x;
	}else{
		return y;
	}
	return c+1;
}

int main(){
	
	int a,b,c;
	do{
		cin>>a>>b>>c;
	}while(!(a>0 && b>0));
	
	cout<<"O maior eh "<<maior(a,b,c)<<endl;
	
	
}