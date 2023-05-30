#include <iostream>
using namespace std;

typedef int Dado;

class noh
{
	friend class fila;
private:
	Dado dado;
	noh* proximo;
public:
	noh(Dado d = 0)
	{
		dado = d;
		proximo = NULL;
	};
};


class fila
{
private:
	noh* inicio;
	noh* fim;
	int tamanho;
public:
	fila();
	~fila();
	void enfileira(Dado valor);
	Dado desenfileira();
};

fila::fila()
{
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}

void fila::enfileira(Dado valor)
{
	noh *novo = new noh(valor);
	if (inicio == NULL)
		inicio = novo;
	else
		fim->proximo = novo;

	fim = novo;
	tamanho++;
}

Dado fila::desenfileira()
{
	Dado retorno = -1;
	noh *auxiliar;

	if (inicio != NULL)
	{
		auxiliar = inicio;
		inicio = auxiliar->proximo;

		retorno = auxiliar->dado;
		delete auxiliar;
	}
	if (inicio == NULL)
		fim = NULL;

	tamanho--;
	return retorno;
}

fila::~fila()
{
	cout << "Destrutor chamado!" << endl;
	while (inicio != NULL)
		cout << desenfileira() << " ";
}

int main(){
	fila *F1 = new fila();
	fila *F2 = new fila();
	fila *Faux = new fila();
	int nf1, nf2;
	cin >> nf1;
	int i = 0;
	int k = 0;
	int x, y;
	int ve[nf1];

	
	while(i < nf1){
		cin >> x;
		F1 -> enfileira(x);
		i++;
	}
	
	cin >> nf2;
	int v[nf2];
	while(k < nf2){
		cin >> y;
		F2 -> enfileira(y);
		k++;
	}
	for(int b = 0; b < nf1; b++)
	{
		ve[b] = F1 ->desenfileira();
   		
	}
	for(int a = 0; a < nf2; a++)
	{
		v[a] = F2 -> desenfileira();
   		
	}
	int cont = 0;
	
	for(int x = 0; x < nf1; x++){
		int aux = 0;
		for(int y = 0; y < nf2; y++){
			if(ve[x] == v[y]){
				aux = ve[x];
			}
		}
		if(ve[x]!= aux){
				Faux -> enfileira(ve[x]);
				cont ++;
			}
	}
	for(int z = 0; z < cont; z++)
	{
		cout << Faux -> desenfileira() << " ";
   		
	}
}
