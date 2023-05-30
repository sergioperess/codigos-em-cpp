#include <iostream>

using namespace std;

void calculo(int NP1,int NP2,int NP3){
	int M;
	M=(NP1+NP2+NP3)/3;
	cout<<M<<endl;
}

int main(){
	int NP1,NP2,NP3;
	cin>>NP1>>NP2>>NP3;
	calculo(NP1,NP2,NP3);
}