#include<iostream>

using namespace std;
void notas(){
	double NP1,NP2,NP3,X;
	cin>>NP1>>NP2>>NP3;
	X=(NP1*2+NP2*3+NP3*5)/10;
	cout<<X<<endl;
	
}
int main(){
	
	notas();
}