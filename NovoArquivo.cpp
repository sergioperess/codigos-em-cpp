#include<iostream>
#include<cmath>

using namespace std;

void tamanho(){
	
	float m, c, mm;
	
	cin >> m >> c >> mm;
	
	float mc, cc, mmc;
	
	cin >> mc >> cc >> mmc;
	
	m = m +(m * 0.01);
	
	c = c + (c * 0.01);
	
	mm = mm + (mm * 0.01);
	
	if(m >= mc && c >= cc && mm >= mmc){
		cout << "sim" << endl;
	}else{
		cout << "não" << endl;
	}
	
	
}

int main(){
		
	tamanho();	
	
	
}