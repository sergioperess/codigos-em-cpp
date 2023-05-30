#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <cstring>
#include <windows.h>
#include <fstream>



using namespace std;

struct dados_funcionario{
	
	float salario, exp;  // salario e anos de experiencia do funcionário
	int codigo,idade,horas; // sexo, código e idade do funcionário
	char nome[50],sexo; // nome do funcionário
	int excluido;
	
};

fstream arquivo;

dados_funcionario  funcionario;

int menu(char n[20]);
void menu(){

    	cout<<"  __________________________________________________________________________ "<<endl;
    	cout<<" |                                                                          |"<<endl;
    	cout<<" |           Seja bem vindo ao sistema de cadastro de funcionarios          |"<<endl;
    	cout<<" |                                                                          |"<<endl; 
    	cout<<" |                          da empresa RF Automacao!                        |"<<endl;
		                            
    	cout<<" |__________________________________________________________________________|"<<endl;
		cout<<" "<<endl;
		cout<<"                         APERTE ENTER PARA CONTINUUAR.                        "<<endl;	
		cin.ignore();
	
	return;
	
}

void cadastrar(){
	
	int op;//opção
	

	
		arquivo.seekp(0,arquivo.end);
		do{	
		do{
		cout<<"Digite o codigo do funcionario: "<<endl;
		cin>>funcionario.codigo;
		}while(funcionario.codigo<0);
		cin.ignore();
		cout<<"Digite o nome do funcionario (sem caracteres numericos): "<<endl;
		cin.getline(funcionario.nome,50);
		do{
		cout<<"Digite o sexo ( M - Masculino / F - Feminino ) do funcionario: "<<endl;
		cin>>funcionario.sexo;
		}while(funcionario.sexo!='M' && funcionario.sexo!='F');
		cin.ignore();
		do{
		cout<<"Digite a idade do funcionario: "<<endl;
		cin>>funcionario.idade;
		}while(funcionario.idade<=18);
		cin.ignore();
		do{
		cout<<"entre com o salario em R$ do funcionario com duas casas decimais :"<<endl;
		cout<<fixed<<setprecision(2)<<endl;
		cin>>funcionario.salario;
		}while(funcionario.salario<0);
		do{
		cout<<"entre com as horas trabalhadas por semana do funcionario:"<<endl;
		cin>>funcionario.horas;
		}while(funcionario.horas<0);
		funcionario.excluido = 1; 	
		arquivo.write((char *) &funcionario,sizeof(funcionario));//função para gravar um dado no arquivo
		cout<<"Deseja cadastrar novamente? (1-SIM/2-NAO)"<<endl;
		cin>>op;
		system("pause");
		system("cls");
	
	} while(op == 1);//POR CAUSA DA OPÇÃO DO CADASTRAR
	arquivo.clear();
}

void editar(){
	system("cls");
	
	int pesquisar, x;
	
	system("cls");
	
	x = 0;
	pesquisar = 0; 
	
	cout<<"Digite o codigo para pesquisar"<<endl;
	cin>>pesquisar;
	
		arquivo.seekg(0,arquivo.beg);
		arquivo.read((char *) &funcionario, sizeof(funcionario));


	cin.ignore();

	while(!arquivo.eof())//enquanto não chegar no fim do arquivo,executa os comandos
	{
    
		if((funcionario.excluido ==1) && (funcionario.codigo == pesquisar)){ 
			cout<<"Codigo: "<<funcionario.codigo<<endl;
			cout<<"Nome: "<<funcionario.nome<<endl;
			if(funcionario.sexo == 'M'){
				cout << "Sexo: Masculino " << endl;
			}
			else{
				cout << "Sexo: Feminino " << endl;
			}
			cout<<"Idade: "<<funcionario.idade<<endl;
			cout<<"o salario  R$ do funcionario :"<<funcionario.salario<<endl;
			cout<<"horas trabalhadas :"<<funcionario.salario<<endl;
			cout << "" << endl;
			cout << "" << endl;
			cout  <<"||    Dados novos    ||"<<endl;
			cout<<" "<<endl;
			cout << "Entre com o nome do funcionario: "<<endl;
			cin.getline(funcionario.nome,50);
			cout<<" "<<endl;
			cout<<"Digite o sexo ( 'M- Masculino / 'F'- Feminino ) do funcionario: "<<endl;
			cin>>funcionario.sexo;
			cin.ignore();
			cout<<" "<<endl;						
			cout << "Entre com a idade do funcionario: "<<endl;
			cin>>funcionario.idade;
			cin.ignore();
			cout<<" "<<endl;
			cout<<"entre com o salario em R$ do funcionario com duas casas decimais:"<<endl;
			cout<<fixed<<setprecision(2)<<endl;
			cin>>funcionario.salario;
			cout<<"entre com as horas trabalhadas por semana do funcionario:"<<endl;
			cin>>funcionario.horas;
			cout<<" "<<endl;
			funcionario.excluido = 1;	
			arquivo.seekg(arquivo.tellp()-sizeof(funcionario),arquivo.beg);
			arquivo.write((char *) &funcionario,sizeof(funcionario));
		
		x = 1;
		}
	    
		arquivo.read ((char *) &funcionario, sizeof(funcionario));

    }
	arquivo.clear();
 	if(x != 1)
 		cout << "Nao ha funcionario registrado com esse codigo" << endl;
	 
	cout<<"Enter para voltar ao Menu"<<endl;
	cin.ignore();
}


void pesquisar(){
	
	system("cls");
	
	int pesquisar, x;
	
	system("cls");
	
	x = 0;
	pesquisar = 0; 
	
	cout<<"Digite o codigo para pesquisar"<<endl;
	cin>>pesquisar;
	
		arquivo.seekg(0,arquivo.beg);
		arquivo.read((char *) &funcionario, sizeof(funcionario));


	cin.ignore();

	while(!arquivo.eof())//enquanto não chegar no fim do arquivo,executa os comandos
	{
    
		if((funcionario.excluido ==1) && (funcionario.codigo == pesquisar)){ 
			
			cout<<"Codigo: "<<funcionario.codigo<<endl;
			cout<<"Nome: "<<funcionario.nome<<endl;
			if(funcionario.sexo == 'M'){
				cout << "Sexo: Masculino " << endl;
			}
			else{
				cout << "Sexo: Feminino " << endl;
			}
			cout<<"Idade: "<<funcionario.idade<<endl;
			cout<<"o salario  R$ do funcionario :"<<funcionario.salario<<endl;
			cout<<"horas trabalhadas :"<<funcionario.horas<<endl;
			cout << "" << endl;
			cout << "" << endl;
		
		x = 1;
		}
	    
		arquivo.read ((char *) &funcionario, sizeof(funcionario));

    }
	arquivo.clear();
 	if(x != 1)
 		cout << "Nao ha funcionario registrado com esse codigo" << endl;
	 
	cout<<"Enter para voltar ao Menu"<<endl;
	cin.ignore();
}

void listar(){
	
	system("cls");
	
	int t=1;
	
	system("cls");
	
	arquivo.seekg(0,arquivo.beg);
	
	
	while(arquivo.read ((char *) &funcionario, sizeof(funcionario)))
	{
		if(funcionario.excluido==1){
			cout<<"Codigo: "<<funcionario.codigo<<endl;
			cout<<"Nome: "<<funcionario.nome<<endl;
			if(funcionario.sexo == 'M'){
				cout << "Sexo: Masculino " << endl;
			}
			else{        
				cout << "Sexo: Feminino " << endl;
			}
			cout<<"Idade: "<<funcionario.idade<<endl;
			cout<<"Salario R$: "<<funcionario.salario<<endl;
			cout<<"horas trabalhadas: "<<funcionario.horas<<endl;
			cout<<endl<<endl;
			t=0;		
		

		}
		
		
		
	}
	arquivo.clear();
	if(t==0) {
	cout<<"Nenhum funcionario encontrado!"<<endl;
	}
	cout<<"Enter para voltar ao Menu"<<endl;
	cin.ignore(); cin.ignore();
	
}

void excluir(){
	
	
	int  opcao,excluir;
	system("cls");
	excluir=1;
	cout<<"Digite o codigo do funcionario que deseja excluir"<<endl;
	cin>>funcionario.codigo;
	excluir = funcionario.codigo;
	arquivo.seekg(0,arquivo.beg);
	arquivo.read ((char *) &funcionario, sizeof(funcionario));
	
	while(!arquivo.eof()){
	

		if(funcionario.excluido ==1)
		{
			if(funcionario.codigo == excluir){ 
			
			
			
			cout<<"Codigo: "<<funcionario.codigo<<endl;
			cout<<"Nome: "<<funcionario.nome<<endl;
			if(funcionario.sexo == 1){
				cout << "Sexo: Masculino " << endl;
			}
			else{
				cout << "Sexo: Feminino " << endl;
			}
			cout<<"Idade: "<<funcionario.idade<<endl;
			cout<<" salario R$  :"<<funcionario.salario<<endl;
			cout<<" horas trabalhadas :"<<funcionario.salario<<endl;
			cout<<"Deseja excluir esse funcionario? (1-SIM/2-NÃO)"<<endl;
			cin>>opcao;
			
			if(opcao==1)
			{
				funcionario.excluido = 0; 	
				cout<<"Funcionario excluido"<<endl;
				arquivo.seekp(0,arquivo.beg);
				arquivo.write((char *) &funcionario, sizeof(funcionario));

					cout<<"Enter para voltar ao Menu"<<endl;
					cin.ignore(); cin.ignore();
					return ;
					
			}
			else 
			{
				cout<<"Funcionario nao excluido"<<endl;
					cout<<"Enter para voltar ao Menu"<<endl;
					cin.ignore(); cin.ignore();
					return ;
			}
			
		}
		}
		arquivo.seekg(arquivo.tellp()-sizeof(funcionario),arquivo.beg);
			arquivo.read((char *) &funcionario, sizeof(funcionario));
	}

		
	arquivo.clear();
	 cout<<"Nenhum funcionario encontrado com esse codigo!"<<endl;
 	
	cout<<"Enter para voltar ao Menu"<<endl;
	
	cin.ignore();cin.ignore();
	arquivo.clear();
		
}

int menu (char n[20]){
	
	system("cls");
	
	int tam,cont;
	cont=0;
	tam=strlen(n);
	for (int i=0; i<tam; i++)
	{
		if(!isalpha(n[i]))
		{
			cont=cont+1;
		}
	}
	return cont;
}

void Bonus_Salarial(){
	
		
	int   cod,horas;
	
		cout<<"entre com o codigo do funcionario"<<endl;
		cin>>cod;
		cout<<"entre com as horas trabalhadas "<<endl;
		cin>>horas;
		if(cod==funcionario.codigo && horas==funcionario.horas){
			
		arquivo.seekg(0,arquivo.beg);
		arquivo.read((char *) &funcionario, sizeof(funcionario));
		
			
			if(horas>30 && horas < 40){
				cout<<"o funcionario"<<funcionario.nome<<"recebe R$:"<<funcionario.salario*0.1+funcionario.salario;
			}
			else if(horas>40 && horas<50){
				cout<<"o funcionario"<<funcionario.nome<<"recebe R$:"<<funcionario.salario*0.2+funcionario.salario;
			}
			else if(horas>50 && horas < 60){
				cout<<"o funcionario"<<funcionario.nome<<"recebe R$:"<<funcionario.salario*0.3+funcionario.salario;
			}
		}
 	

       else{ 
        
        	cout<<"Nenhum funcionário cadasatrado."<<endl;
	   }
        
  
		
		system("pause");
   	
}

int main() {
	
	int op;
	
	arquivo.open("teste.txt",ios::in|ios::out|ios::binary);//abre o arquivo p leitura,para saída e em modo binário
	system("color f8");	 
	if(arquivo.is_open() == false){//verifica se o arquivo é falso,se for,ele cria um novo arquivo e se ja existe apaga o que há nele
		arquivo.open("teste.txt",ios::in|ios::out|ios::binary|ios::trunc);
		system("pause");
		system("cls");	//limpa a tela
	}
		menu();
	
		do{
			
		system("CLS");
			
	      cout<<"            ______________________________________________ "<<endl;
          cout<<"           |                                              |"<<endl;
          cout<<"           |                  RF Automacao                |"<<endl;
          cout<<"           |______________________________________________|"<<endl;
          cout<<"           |          1 - Cadastrar                       |"<<endl;
          cout<<"           |          2 - Editar                          |"<<endl;
          cout<<"           |          3 - Pesquisar                       |"<<endl; 
          cout<<"           |          4 - Listar                          |"<<endl;       
          cout<<"           |          5 - Excluir                         |"<<endl;
		  cout<<"           |          6 - bonus salarial                  |"<<endl;            
          cout<<"           |          7 - Sair                            |"<<endl;
          cout<<"           |______________________________________________|"<<endl;
          cout<<endl;
          cout<<"                      Opcao Escolhida: "; cin>>op;
					
			switch(op){
				
				case 1:cadastrar(); break;
				case 2:editar(); break;
				case 3:pesquisar(); break;
				case 4:listar(); break;
				case 5:excluir(); break;
				case 6:Bonus_Salarial(); break;
				
			}
		} while(op < 7);
		
		system("CLS");
		
          cout<<"                ______________________________________________ "<<endl;
          cout<<"               |                                              |"<<endl;
          cout<<"               |                 RF Automacao                 |"<<endl;
          cout<<"               |                                              |"<<endl;
          cout<<"               |               TENHA UM BOM DIA!              |"<<endl;
          cout<<"               |______________________________________________|"<<endl;
	
	
	return 0;
}




