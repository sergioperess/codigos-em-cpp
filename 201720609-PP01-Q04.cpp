#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>


using namespace std;

struct funcionarios
{
	int ident;
	float horas;
	float ht;
	float salario;
} p;

fstream arquivo;

int particiona(int v[], int c, int f)   // c = começo, f = fim
{
	int pivo = v[c], i = c + 1, j = f;
	while (i <= j)
	{
		if (v[i] <= pivo) i++;
		else if (pivo <= v[j]) j--;
		else   // (v[i] > pivo) e (v[j] < pivo)
		{
			swap (v[i], v[j]);
			i++;
			j--;
		}
	} // agora i == j+1
	v[c] = v[j];
	v[j] = pivo;
	return j; // retorna posição do pivô
}


void quicksort(int a[], int pos_pivo, int fim)
{
	int pos_novo_pivo;
	if (pos_pivo < fim)
	{
		pos_novo_pivo = particiona(a, pos_pivo, fim);
		quicksort(a, pos_pivo, pos_novo_pivo - 1);
		quicksort(a, pos_novo_pivo + 1, fim);
	}
	for(int i = 0; i < fim; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{


	arquivo.open("bancoDeDados.txt", ios::in | ios::out | ios::binary);
	if(arquivo.is_open() == false)
	{
		arquivo.open("bancoDeDados.txt", ios::in | ios::out | ios::trunc | ios::binary);
	}

	cin >> p.ident >> p.horas >> p.ht;

	int vet[100];
	p.salario = p.horas * p.ht;
	int pivo = 0;


	for(int i = 0; i < 100; i++)
	{
		if(p.ident != -1)
		{
			vet[i] = p.salario;
		}
		else
		{
			break;
		}
	}



	quicksort(vet, pivo, 100);




}
