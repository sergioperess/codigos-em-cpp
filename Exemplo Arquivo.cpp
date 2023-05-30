#include <iostream>

using namespace std;

struct pessoa{
 	string nome;
 	int idade;
 	string cpf;
 	float altura;
 	string cor_olhos;
 	
	
};

int main(){
	pessoa p;
	cin >> p.nome;
	cin >> p.idade;
	cin >> p.cpf;
	cin >> p.altura;
	cin >> p.cor_olhos;
	
	
	cout << "Seu nome eh = " << p.nome << endl; 
	cout << "Sua idade eh = " << p.idade << endl;
	cout << "Seu cpf eh = " << p.cpf << endl;
	cout << "Sua altura eh = " << p.altura << endl;
	cout << "cor dos olhos = " << p.cor_olhos << endl;
}