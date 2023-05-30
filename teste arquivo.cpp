#include <fstream>
#include <iostream>

using namespace std;

struct aluno{
	int ra;
	char nome[100];
	
};


int main(){
	
	aluno a;
	ofstream arquivoS;
	arquivoS.open("teste.txt", ios::app | ios::binary);
	
	cin >> a.ra;
	
	arquivoS << a.ra << endl;
	
	arquivoS.close();
	
	
	
	
}