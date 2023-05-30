#include <iostream>

using namespace std;

typedef int Dado;

class noh
{
	friend class pilha;
private:
	Dado dado;
	noh* proximo;
public:
	noh(Dado d = 0)
	{
		dado = d;
	};

};

class pilha
{
private:
	noh* topo;
	int tamanho;
public:
	pilha();
	~pilha();
	void empilha(Dado valor);
	Dado desempilha();
	Dado espia();
};

pilha::pilha()
{
	topo = NULL;
	tamanho = 0;
}

void pilha::empilha(Dado valor)
{
	noh *novo = new noh;
	novo -> proximo = topo;
	novo -> dado = valor;
	topo = novo;
	tamanho++;
}

Dado pilha::desempilha()
{
	Dado retorno = -1;
	noh *auxiliar;
	if(topo != NULL)
	{
		retorno = topo -> dado;
		auxiliar = topo;
		topo = topo -> proximo;
		auxiliar -> proximo = NULL;
		delete auxiliar;
		tamanho --;
	}
	return retorno;

}

pilha::~pilha()
{
	while(topo != NULL)
	{
		desempilha();
	}
}

int main()
{
	pilha *minhaPilha = new pilha();
	pilha *pilhaux = new pilha();
	int i = 0;
	int n;
	int x;

	cin >> n;

	while(i < n)
	{
		cin >> x;
		minhaPilha -> empilha(x);
		i++;
	}
	for(int j = 0; j < n; j++)
	{
		pilhaux -> empilha(minhaPilha -> desempilha());
	}
	for(int k = 0; k < n; k++)
	{
		cout << pilhaux -> desempilha() << " ";
	}

	delete minhaPilha;
	delete pilhaux;
}

