#include <iostream>

using namespace std;

/* Sérgio Luiz Camargo Peres */

class noh
{
	friend class pilha;
private:
	int dado;
	noh* proximo;
public:
	noh(int d)
	{
		dado = d;
		proximo = NULL;
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
	int tam();
	void limpapilha();
	void empilha(int valor);
	int desempilha();
	bool vazia();
	int acessaElemento(pilha& p1, int elemento);
};

pilha::pilha()
{
	topo = NULL;
	tamanho = 0;
}

pilha::~pilha()
{
	while (topo != NULL)
	{
		desempilha();
	}
}

int pilha::tam()
{


	return tamanho;
}
void pilha::limpapilha()
{
	while (tamanho > 0)
	{
		desempilha();
	}
}

void pilha::empilha(int valor)
{
	noh *novo = new noh(valor);
	novo->proximo = topo;
	topo = novo;
	tamanho++;
}

int pilha::desempilha()
{
	int retorno = topo->dado;
	noh *aux = topo;
	topo = topo->proximo;
	aux->proximo = NULL;
	delete aux;
	tamanho--;

	return retorno;
}


bool pilha::vazia()
{
	if (topo == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int acessaElemento(pilha& p1, int elemento)
{
	pilha *pilha1 = new pilha();
	int aux = p1.desempilha();
	int j = 1;
	while(aux != elemento && (not p1.vazia()))
	{
		pilha1 -> empilha(aux);
		aux = p1.desempilha();
		j++;
	}


	while(not pilha1 -> vazia())
	{
		p1.empilha(pilha1->desempilha());
	}

	delete pilha1;
	return j;
}

int main()
{
	pilha p1;
	int n, numero, elemento;
	cin >> n;

	while (n > 0)
	{
		cin >> numero;
		p1.empilha(numero);
		n--;
	}

	cin >> elemento;
	cout << acessaElemento(p1, elemento) << endl;

	while (not p1.vazia())
	{
		cout << p1.desempilha() << " ";
	}

	cout << endl;

	return 0;
}
