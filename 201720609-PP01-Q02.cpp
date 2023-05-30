#include<iostream>
#include<stdlib.h>
#include<time.h>


using namespace std;

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

int binariap(int tam, int vetor[], int procurado)
{
	int inicio = 0;
	int fim = tam - 1;
	int meio;
	int posicao = 0;
	while(inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		if(vetor[meio] == procurado)
		{
			return meio;
		}
		else if(vetor[meio] > procurado)
		{
			fim = meio - 1;
		}
		else
		{
			inicio = meio + 1;
		}
		posicao++;
	}
	return -1;
}

int binaria(int tam, int vetor[], int procurado)
{
	int inicio = 0;
	int fim = tam - 1;
	int meio;
	int posicao = 0;
	while(inicio <= fim)
	{
		meio = (inicio + fim) / 2;
		if(vetor[meio] == procurado)
		{
			return posicao + 1;
		}
		else if(vetor[meio] > procurado)
		{
			fim = meio - 1;
		}
		else
		{
			inicio = meio + 1;
		}
		posicao++;
	}
	return posicao + 1;
}

int linear(int n, int vetor[], int k)
{
	int c = 1;
	for(int i = 0; (i < n); i++)   //chave de busca(procurado) fica menor que o elemento(valor no vetor)para de procurar
	{
		if(vetor[i] == k)
		{
			return c;
		}
		c++;
	}
	return c;

}


int main()
{
	int n, k;
	int pivo = 0;

	cin >> n;

	int vet[n];
	
	srand(10);

	int maior = 100;
	int menor = 1;
	for(int i = 0; i < n; i++)
	{
		vet[i] = rand() % 100;
	}

	cin >> k;

	quicksort(vet, pivo, n);
	cout << binariap(n, vet, k) << endl;
	cout << linear(n, vet, k) << endl;
	cout << binaria(n, vet, k) << endl;
}
