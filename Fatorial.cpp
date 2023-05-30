#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

using namespace std;

 	 long double fatorial( long double A){
	 long double R=1,S=0;
	
	
	for(int j=2; j<=6; j=j+2){
		for(int i=j; i>=1; i--){
			R=R*i;
		}
		if (j%4==0) {         //1936
			S=S+(R*-A);
			cout<<"R(-A)-------->"<<R<<"          S(-A)-------->"<<S<<endl;
		}else{
			S=S+(R*A);	
			cout<<"R(A)-------->"<<R<<"            S(A)-------->"<<S<<endl;
		}
		R=1;
	}
	
	return S;
}
long double calculaY(long double A){
	long double Y;
	Y=A-fatorial(A);
	return Y;
	
}

int main(){
	long double A;
	do{
		cin>>A;
	}while(!(A>=0 && A<=70));
	
	cout<<calculaY(A)<<endl;
}