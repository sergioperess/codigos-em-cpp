#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>

using namespace std;

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const int alphaLength = sizeof(alphanum) - 1;



char geraalph(){
	return alphanum[rand() % alphaLength];
}

struct dado
{
	char campo[5];
	void preenche(int k){
		campo[0] = 4;
		for(int i = 1; i < 5; i++){
		   	campo[i] = geraalph();
		}
	
	}
};



int main(){
	
	ofstream saida;
	saida.open("test.txt", ios :: app);
	
	int quantidade;
	
	cin >> quantidade;
	
	srand(time(NULL));
	dado *dados;
	
	for(int i = 0; i < quantidade; i++){
		dados = new dado;
		dados->preenche(quantidade);
		saida.write((char *) (dados), sizeof(dado));
		delete dados;
	}
	
}