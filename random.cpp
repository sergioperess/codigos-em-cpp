#include <iostream>
#include <stdlib.h>

using namespace std;

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int alphaLength = sizeof(alphanum) - 1;



char geraalph(){
	return alphanum[rand() % alphaLength];
}

int main(){
	char camp[5];
	camp[0] = 4;
	for(int i = 1; i < 5; i++){
		camp[i] = geraalph();
	}
	for(int j = 0; j < 5 ; j++){
		
		cout << camp[j] << endl;
	}
	
}

