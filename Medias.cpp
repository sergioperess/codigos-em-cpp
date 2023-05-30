#include<iostream>
#include<iomanip>

using namespace std;

double media(int x, int y, int z, char b){
	double M;
	if(b=='P'){
		M=(x*5+y*3+z*2)/10;
		return M;
	}else if(b=='A'){
		M=(x+y+z)/3;
		return M;
	}
		 
}

int main(){
	int a,b,c;
	double r;
	char X;
	cout<<"Entre com suas notas"<<endl;
	cin>>a>>b>>c;
	do{
		cout<<"Entre com P - Media ponderada ou A - Media aritmetica"<<endl;
		cin>>X;
	}while(!(X=='P' || X=='A'));
	
	r=media(a,b,c,X);
	
	cout<<"A media eh : "<<fixed<<setprecision(2)<<r<<endl;	
	
	
}