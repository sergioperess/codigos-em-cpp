#include <iostream>

using namespace std;
int menor(int A, int B){
	if(A<B){
		return A;
	}else{
		return B;
	}
}
int main(){
	int A,B;
	cin>>A>>B;
	cout<<menor(A,B)<<endl;

}