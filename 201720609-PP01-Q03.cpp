#include<iostream>

using namespace std;

void insertion_sort(int vetor[], int tam)
{
	int valor_pivo, j;
	for (int i = 1; i < tam; i++)
	{
		valor_pivo = vetor[i];
		j = i - 1;
		while ((j >= 0) and (valor_pivo < vetor[j]))
		{
			vetor[j + 1] = vetor[j];
			j--;
		}
		vetor[j + 1] = valor_pivo;
		for(int i = 0; i < tam; i++)
		{
			cout << vetor[i] << " ";
		}
		cout << endl;
	}

}


int main()
{
	int tam;
	cin >> tam;
	int vet[tam];
	for(int i = 0; i < tam; i++)
	{
		cin >> vet[i];
	}
	cout << endl;
	insertion_sort(vet, tam);

}
