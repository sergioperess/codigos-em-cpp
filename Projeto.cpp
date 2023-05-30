#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <stdlib.h>

using namespace std;

void cadastro()
{
	
	int controle = 0;
	char nome[100], cpf[50], idade[4], profissao[100];
	
	do{
		cout << "Escreva seu nome" << endl;
		cin.getline(nome,100);
		for(int i=0; i < strlen(nome); i++){
			if(isalpha(nome[i]) == 0){
				controle = 1;
			   	break;
			}
			controle = 0;
		}
		system("cls");
	}
	while(!(controle == 0));
	
	
	
	
	do{
		do{
			cout << "Digite o CPF sem pontos e tracos" << endl;
			cin.getline(cpf, 50);
			for(int i=0; i < strlen(cpf); i++){
				if(isdigit(cpf[i]) == 0){
					controle = 1;
					break;
				}
				controle = 0;
			}
				
		}while(!(strlen(cpf) == 11));
		system("cls");
	}while(!(controle == 0));
	

	
	do{

		
			cout << "Digite sua idade" << endl;
			cin.getline(idade, 4);
			for(int i=0; i < strlen(idade); i++){
				if(isdigit(idade[i]) == 0){
					controle = 1;
					break;
				}
				controle = 0;
			}
			system("cls");
	
	}while(!(controle == 0));
	
	do{
		cout << "Coloque sua profissao" << endl;
		cin.getline(profissao,100);
		for(int i=0; i < strlen(profissao); i++){
			if(isalpha(profissao[i]) == 0){
				controle = 1;
			   	break;
			}
			controle = 0;
		}
		system("cls");
	}while(!(controle == 0));
	
	
	
}

void listar()
{
	
}

void novoexame()
{
	int exame, controle = 0;
	char hemoglobina[20], leucocitos[20], plaquetas[20];
	
	cout << "Digite o tipo de exame" << endl;
	cout << "1 - Exame de sangue" << endl;
	cout << "2 - bla bla bla" << endl;
	
	switch(exame){
		case 1 :
				do{
					cout << "Coloque o numero de leucocitos" << endl;
					cin.getline(leucocitos, 20);
					for(int i=0; i < strlen(leucocitos); i++){
						if(isdigit(leucocitos[i]) == 0){
							controle = 1;
							break;
						}
						controle = 0;
					}
				}while(!(controle == 0));
				   
					
				do{
					cout << "Coloque o numero de hemoglobinas" << endl;
					cin.getline(hemoglobina, 20);
					for(int i=0; i < strlen(hemoglobina); i++){
						if(isdigit(hemoglobina[i]) == 0){
							controle = 1;
							break;
						}
						controle = 0;
					}
				}while(!(controle == 0));
				
				
				do{
					cout << "Coloque o numero de plaquetas" << endl;
					cin.getline(plaquetas, 20);
					for(int i=0; i < strlen(plaquetas); i++){
						if(isdigit(plaquetas[i]) == 0){
							controle = 1;
							break;
						}
						controle = 0;
					}
				}while(!(controle == 0));
	}
	
	
}


int main()
{
	system("color F0");
	int x;
	
	
		cout << "Bem vindo bla bla bla" << endl;
		
		cout << "Escolha a opcao desejada" << endl;
		
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Listar" << endl;
		cout << "3 - Registrar novo exame" << endl;
		cout << "0 - Sair" << endl;
		
		cin >> x;
		
		switch(x){
			case 1:{
				system("cls");					
   	    		cadastro();
				break;
			}
			
			case 2:{
				system("cls");
				listar();
				break;
			}	
	        case 3:{
	        	system("cls");
				novoexame();
	        	break;
			}	
	        case 0:break;
		}
	
}




















