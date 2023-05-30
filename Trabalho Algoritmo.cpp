#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct pessoas
{
	char nome[100], cpf[50], profissao[100];
	int idade;
	char sexo;
	int ativo;
	int excluido;

} p;

fstream arquivo;

void cadastro()
{
	int controle = 0;
	do
	{
		cout << "Escreva seu nome" << endl;
		cin.ignore();
		cin.getline(p.nome, 100);
		for(int i = 0; i < strlen(p.nome); i++)
		{
			if(isalpha(p.nome[i]) == 0 && strlen(p.nome) == ' ')
			{
				controle = 1;
				break;
			}
			controle = 0;
		}
	}
	while(!(controle == 0));

	system("cls");

	do
	{
		cout << "Escolha o seu sexo (M ou F)" << endl;
		cin >> p.sexo;
	}
	while(!(p.sexo == 'M' || p.sexo == 'F'));

	system("cls");


	do
	{
		cin.ignore();
		do
		{
			cout << "Digite o CPF sem pontos e tracos" << endl;
			cin.getline(p.cpf, 50);
			for(int i = 0; i < strlen(p.cpf); i++)
			{
				if(isdigit(p.cpf[i]) == 0)
				{
					controle = 1;
					break;
				}
				controle = 0;
			}


		}
		while(!(strlen(p.cpf) == 11));
	}
	while(!(controle == 0));

	system("cls");



	do
	{
		cout << "Digite a sua idade" << endl;
		cin >> p.idade;
	}
	while(!(p.idade > 0 && p.idade < 150));

	system("cls");

	do
	{
		cin.ignore();
		cout << "Coloque sua profissao" << endl;
		cin.getline(p.profissao, 100);
		for(int i = 0; i < strlen(p.profissao); i++)
		{
			if(isalpha(p.profissao[i]) == 0 && p.profissao[i] != 32)
			{
				controle = 1;
				break;
			}
			controle = 0;
		}
	}
	while(!(controle == 0));

	system("cls");

	p.ativo = 1;

	arquivo.seekp(0, arquivo.end);
	arquivo.write((char *) &p, sizeof(p));



}

void listar()
{
	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char *) &p, sizeof(p));

	while(!arquivo.eof())
	{
		if(p.ativo == 1)
		{
			cout << "Nome: " << p.nome << endl;
			cout << "Sexo: " << p.sexo << endl;
			cout << "CPF: " << p.cpf << endl;
			cout << "Idade: " << p.idade << endl;
			cout << "Profissao: " << p.profissao << endl;
			cout << "- - - - - - - - - - -" << endl;
		}
		arquivo.read((char *) &p, sizeof(p));
	}
}

void novoexame()
{
	int exame, acucar;
	double eritrocito, hemoglobina, hematocrito;
	double colesteroltotal, colesterolruim, colesterolbom;
	char cpf[50], opcao;

	cout << "Digite um numero de cpf" << endl;
	cin >> cpf;


	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char *) &p, sizeof(p));
	int enc = 0;
	while(!arquivo.eof())
	{
		if(strcmp(cpf, p.cpf) == 0)
		{
			enc = 1;
			cout << "Digite o tipo de exame" << endl;
			cout << "1 - Exame de sangue" << endl;
			cout << "2 - Exame de colesterol" << endl;
			cout << "3 - Exame de glicose" << endl;
			cout << "0 - Voltar" << endl;

			cin >> exame;

			system("cls");

			switch(exame)
			{
			case 1:
				do
				{
					cin.ignore();
					cout << "Coloque o numero de eritrocitos(entre 1 e 100)" << endl;
					cin >> eritrocito;
				}
				while(!(eritrocito > 0 && eritrocito <= 100));

				system("cls");


				do
				{
					cout << "Coloque o numero de hemoglobinas(entre 1 e 100)" << endl;
					cin >> hemoglobina;
				}
				while(!(hemoglobina > 0 && hemoglobina <= 100));

				system("cls");


				do
				{
					cout << "Coloque o numero de hematocritos(entre 1 e 100)" << endl;
					cin >> hematocrito;
				}
				while(!(hematocrito > 0) && hematocrito <= 100);

				system("cls");

				if(eritrocito >= 4 && eritrocito <= 6 && hemoglobina >= 12 && hemoglobina <= 17 && hematocrito >= 35 && hematocrito <= 52)
				{
					cout << "Voce nao possui nenhum anomalia" << endl;
				}
				if(eritrocito < 4 || hemoglobina < 12)
				{
					cout << "Voce tem anemia" << endl;
				}
				if(hematocrito > 52)
				{
					cout << "Voce possivelmente contraiu Policetemia" << endl;
				}
				break;
				if(eritrocito > 6)
				{
					cout << "Voce tem policitemia" << endl;
				}



			case 2:
				do
				{
					cout << "Digite o numero do colesterol total" << endl;
					cin >> colesteroltotal;
				}
				while(!(colesteroltotal > 0));

				system("cls");

				do
				{
					cout << "Digite o numero do colesterol LDL" << endl;
					cin >> colesterolruim;
				}
				while(!(colesterolruim > 0));

				system("cls");

				do
				{
					cout << "Digite o numero do colesterol HDL" << endl;
					cin >> colesterolbom;
				}
				while(!(colesterolbom > 0));

				system("cls");

				if(colesteroltotal > 240)
				{
					cout << "Seu valor de colesterol total eh alto, porem isso nao significa necessariamente alguma anomalia, porem eh recomendado abaixar esse valor" << endl;
				}
				else cout << "Seu valor de colesterol total eh bom" << endl;

				if(colesterolruim > 160)
				{
					cout << "Voce pode ter doencas tais como: Aterosclerose, insuficiencia cardiaca, pressao alta e corre risco de infartos" << endl;
				}
				break;


			case 3:
				do
				{
					cout << "Digite o numero da concentracao de acucar" << endl;
					cin >> acucar;
				}
				while(!(acucar > 0));

				if(acucar < 70)
				{
					cout << "Voce tem hipoglicemia" << endl;
				}

				else if(acucar < 110)
				{
					cout << "Quantidade normal de acucar no sangue. Nenhuma anomalia detectada" << endl;
					system("pause");
				}
				else if (acucar >= 110 && acucar <= 125)
				{
					cout << "Quantidades nao tao elevadas, porem ha indicios de diabetes" << endl;
					system("pause");
				}
				else
				{
					cout << "Voce tem hiperglicemia" << endl;
					system("pause");
				}
				break;
			}

			system("cls");
		}




		arquivo.read((char *) &p, sizeof(p));

	}
	if(enc == 0) ;


}


void receitas()
{
	cin.ignore();

	int doenca = -1;

	cout << "Selecione a doenca que voce foi diagnosticado" << endl;

	cout << "1 - Anemia" << endl;
	cout << "2 - Policitemia" << endl;
	cout << "3 - Hiperglicemia" << endl;
	cout << "4 - Hipoglicemia" << endl;
	cout << "0 - Voltar" << endl;

	cin >> doenca;
	system("cls");

	switch(doenca)
	{
	case 1:
		cout << "Para curar a anemia, recomenda-se aumentar a quantidade de ferro consumido durante as refeicoes, preferindo alimentos tais como o feijao e carnes vermelhas. Eh recomendado que diminua a quantidade de alimentos que prejudiquem a absorcao de ferro pelo corpo, tal como o cafe e o chocolate. Caso seja necessario medicamentos, o Combiron e o Ferronil sao as melhores opcoes" << endl;
		break;
	case 2:
		cout << "Infelizmente, a policitemia nao tem uma cura, porem existem tratamentos, o mais comum eh a transfusao sanguinea para reduzir a quantidade de celulas vermelhas no sangue, lembrando que a transfusao deve ser feita periodicamente e nao uma vez apenas. A aspirina tambem eh uma boa indicacao de medicamento pois ajuda a reduzir a viscosidade do sangue" << endl;
		break;
	case 3:
		cout << "Para tratar a hiperglicemia, nao eh necessario medicamentos, apenas a realizacao de atividades fisicas e uma dieta adequada podem resolver o seu problema" << endl;
		break;
	case 4:
		cout << "Para elevar os niveis de glicose no sangue, basta ingerir uma pequena quantidade de carboidratos, de preferencia acucares, tais como uma colher de mel ou um copo de refrigerante, em seguida meça novamente o nivel da glicose e se continuar baixa repita o processo até que normalize o valor" << endl;
		break;
	case 0:
		break;
	}

	system("pause");

	system("cls");

}


void excluir()
{
	char cpf[50];

	cout << "Digite o numero do cpf para excluir" << endl;

	cin >> cpf;

	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char *) &p, sizeof(p));
	int enc = 0;
	while(!arquivo.eof())
	{
		//cout << p.cpf;
		if(strcmp(cpf, p.cpf) == 0)
		{
			p.ativo = 0;
			//	cout <<"teste";
			arquivo.seekp(arquivo.tellp() - sizeof(p));
			arquivo.write((char *) &p, sizeof(p));
		}



		arquivo.read((char *) &p, sizeof(p));
	}

	system("cls");

}


void pesquisar()
{
	char cpf[50];

	cout << "Digite um numero de cpf" << endl;
	cin >> cpf;

	arquivo.seekg(0, arquivo.beg);
	int enc = 0;
	while(arquivo.read((char *) &p, sizeof(p)))
	{
		if(strcmp(cpf, p.cpf) == 0)
		{
			cout << "CPF encontrado!" << endl;
			cout << "Nome: " << p.nome << endl;
			cout << "Idade: " << p.idade << endl;
			cout << "Sexo: " << p.sexo << endl;
			cout << "Profissao: " << p.profissao << endl;
			enc = 1;
			break;
		}
	}

	if(enc == 0)
		cout << "CPF n encontrado" << endl;
}
void editar()
{
	char cpf[50];
	int x, n;

	x = 0;

	cout << "Digite um numero de cpf" << endl;
	cin >> cpf;

	arquivo.seekg(0, arquivo.beg);
	arquivo.read((char *) &p , sizeof(p));

	cin.ignore();

	while(!arquivo.eof())
	{
		if(strcmp(cpf,p.cpf) == 0)
		{
			cout << "Cpf: " << p.cpf << endl;
			if(p.sexo == 'M')
			{
				cout << "Sexo: Masculino " << endl;
			}
			else
			{
				cout << "Sexo: Feminino " << endl;
			}
			cout << "Nome :" << p.nome << endl;
			cout << "Idade: " << p.idade << endl;
			cout << "Profissao :" << p.profissao << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout  << "||    Dados novos    ||" << endl;
			cout << " " << endl;
			do
			{
				cout << "Deseja alterar o nome? (1-Sim e 2-Nao)" << endl;
				cin >> n;
			}
			while(!(n == 1 || n == 2));
			if(n == 1)
			{
				cin.ignore();
				cout << "Entre com o nome da pessoa: " << endl;
				cin.getline(p.nome, 50);
				cout << " " << endl;
			}
			do
			{
				cout << "Deseja alterar o sexo? (1-Sim e 2-Nao)" << endl;
				cin >> n;
			}
			while(!(n == 1 || n == 2));
			if(n == 1)
			{
				cin.ignore();
				do{
					cout << "Digite o sexo (M ou F): " << endl;
				   	cin >> p.sexo;
				}while(!(p.sexo == 'M' || p.sexo == 'F'));
				cout << " " << endl;
			}
			do
			{
				cout << "Deseja alterar a idade? (1-Sim e 2-Nao)" << endl;
				cin >> n;
			}
			while(!(n == 1 || n == 2));
			if(n == 1)
			{
				cin.ignore();
				cout << "Entre com a idade da pssoa: " << endl;
				cin >> p.idade;
				cout << " " << endl;
			}
			do
			{
				cout << "Deseja alterar a profissao? (1-Sim e 2-Nao)" << endl;
				cin >> n;
			}
			while(!(n == 1 || n == 2));
			if(n == 1)
			{
				cin.ignore();
				cout << "Profissao:" << endl;
				cin >> p.profissao;
			}
			arquivo.seekg(arquivo.tellp() - sizeof(p), arquivo.beg);
			arquivo.write((char *) &p, sizeof(p));

			x = 1;
		}

		arquivo.read ((char *) &p, sizeof(p));

	}
	arquivo.clear();
	if(x != 1)
	{
		cout << "Nao ha funcionario registrado com esse codigo" << endl;
	}
	cout << "Enter para voltar ao Menu" << endl;
	cin.ignore();



}

int main()
{
	int opcao = -1;

	arquivo.open("bancoDeDados.txt", ios::in | ios::out | ios::binary);
	if(arquivo.is_open() == false)
	{
		arquivo.open("bancoDeDados.txt", ios::in | ios::out | ios::trunc | ios::binary);
	}


	do
	{
		cout << "Bem vindo ao Laboratorio de Exames. Como podemos ajuda-lo?" << endl;
		arquivo.clear();
		cout << "Escolha a opcao desejada" << endl;

		cout << "1 - Cadastrar" << endl;
		cout << "2 - Listar" << endl;
		cout << "3 - Excluir cadastro" << endl;
		cout << "4 - Registrar novo exame" << endl;
		cout << "5 - Receitas" << endl;
		cout << "6 - Pesquisar" << endl;
		cout << "7 - Editar" << endl;
		cout << "0 - Sair" << endl;

		cin >> opcao;

		system("cls");

		switch(opcao)
		{
		case 1:
			cadastro();
			break;

		case 2:
			listar();
			break;
		case 3:
			excluir();
			break;
		case 4:
			novoexame();
			break;
		case 5:
			receitas();
			break;
		case 6:
			pesquisar();
			break;
		case 7:
			editar();
			break;
		case 0:
			break;

		}
	}
	while(!(opcao == 0));

}




















