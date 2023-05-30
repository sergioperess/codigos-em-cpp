#include <iostream>
#include <string>

typedef int TValor; 

class InfoHash {
    friend class Hash; 
    InfoHash();
    InfoHash(const std::string& chave, const TValor& valor);
    std::string mChave;
    TValor mValor;
};

class Hash {
    public:
        Hash(unsigned capacidade = 50);
        ~Hash();
        void EscreverEstrutura(std::ostream& saida) const;
        
        void Inserir(const std::string& chave, const TValor& valor);
       
        void Remover(const std::string& chave);
        
        TValor Valor(const std::string& chave) const;
    protected:
        
        unsigned Buscar(const std::string& chave) const;
       
        void Inserir(InfoHash* ptPar);
        
        unsigned Posicao(const std::string& chave) const;
       
        void Redimensionar(unsigned novaCapacidade);
        InfoHash** mVetPtDados;
        InfoHash* REMOVIDO; 
        unsigned mCapacidade;
        unsigned mTamanho;
};

using namespace std;

InfoHash::InfoHash()
    : mChave(), mValor() {
}

InfoHash::InfoHash(const std::string& chave, const TValor& valor)
    : mChave(chave), mValor(valor) {
}

Hash::Hash(unsigned capacidade) 
    : mVetPtDados(new InfoHash*[capacidade]), REMOVIDO(new InfoHash()), mCapacidade(capacidade), mTamanho(0) {
    
    for (unsigned i = 0; i < capacidade; i++)
    {
        mVetPtDados[i] = NULL;
    }
}

Hash::~Hash() {
    
    for (unsigned i = 0; i < mTamanho; i++)
    {
        mVetPtDados[i] = NULL;
    }
    delete REMOVIDO;
    delete[] mVetPtDados;
}

unsigned Hash::Buscar(const std::string& chave) const {
    
    unsigned posicaoAuxiliar = Posicao(chave);
    unsigned contador = 0;
    bool confirmacao = false;
    while (contador < mCapacidade and confirmacao == false)
    {
        if ((mVetPtDados[posicaoAuxiliar] != NULL) and (mVetPtDados[posicaoAuxiliar] != REMOVIDO))
        {
            if (mVetPtDados[posicaoAuxiliar]->mChave == chave)
            {
                confirmacao = true;
            }
            else
            {
                if (posicaoAuxiliar+1 == mCapacidade)
                {
                    posicaoAuxiliar = 0;
                }
                else
                {
                    posicaoAuxiliar++;
                }
                contador++;
            }
        }
        else
        {
            if (posicaoAuxiliar+1 == mCapacidade)
            {
                posicaoAuxiliar = 0;
            }
            else
            {
                posicaoAuxiliar++;
            }
            contador++;
        }
    }
    if ((mVetPtDados[posicaoAuxiliar] != NULL) and (mVetPtDados[posicaoAuxiliar]->mChave == chave))
    {
        return posicaoAuxiliar;
    }
}

void Hash::EscreverEstrutura(std::ostream& saida) const {
    
    for (unsigned i = 0; i < mCapacidade; ++i) {
        saida << '[' << i;
        if (mVetPtDados[i] != NULL) {
            if (mVetPtDados[i] == REMOVIDO)
                saida << "/removido";
            else
                saida << '/' << mVetPtDados[i]->mChave << '/' << mVetPtDados[i]->mValor;
        }
        saida << "] ";
    }
}

void Hash::Inserir(const string& chave, const TValor& valor) {
   
    if (mTamanho < mCapacidade)
    {
        InfoHash* novoHash = new InfoHash(chave, valor);
        int posicaoAuxiliar = Posicao(chave);
        while (mVetPtDados[posicaoAuxiliar] != NULL and mVetPtDados[posicaoAuxiliar]->mChave != chave and mVetPtDados[posicaoAuxiliar] != REMOVIDO)
        {
            posicaoAuxiliar ++;
            posicaoAuxiliar %= mCapacidade;
        }
        if (mVetPtDados[posicaoAuxiliar] == NULL or mVetPtDados[posicaoAuxiliar] == REMOVIDO)
        {
            mTamanho++;
            mVetPtDados[posicaoAuxiliar] = novoHash;
        }
        else
        {
            cout << "chave repetida" << endl;
        }
    }
    else
    {
        Redimensionar(mCapacidade+5);
        Inserir(chave, valor);
    }
}

void Hash::Inserir(InfoHash* ptPar) {
   
    unsigned posicaoAux = Posicao(ptPar->mChave);
    unsigned i = 0;
    while (mVetPtDados[(posicaoAux+i)%mCapacidade] != NULL)
    {
        i++;
    }
    mVetPtDados[(posicaoAux+i)%mCapacidade] = ptPar;
}

unsigned Hash::Posicao(const string& chave) const {
    
    unsigned pos = 1;
    unsigned tamanho = unsigned(chave.length());
    for (unsigned i = 0; i < tamanho; ++i)
        pos = 7 * pos + chave[i];
    return pos % mCapacidade;
}

void Hash::Redimensionar(unsigned novaCapacidade) {
    

    if (novaCapacidade < mTamanho)
    {
        cout << "nova capacidade invalida" << endl;
    }
    else
    {
        InfoHash** mVetAux = mVetPtDados;
        unsigned capacidadeAntiga = mCapacidade;
        mCapacidade = novaCapacidade;
        mVetPtDados = new InfoHash*[novaCapacidade];
        for (unsigned i = 0; i < novaCapacidade; i++)
        {
            mVetPtDados[i] = NULL;
        }
        InfoHash* vetAux;
        for (unsigned i = 0; i < capacidadeAntiga; i++)
        {
            vetAux = mVetAux[i];
            if (vetAux != NULL)
            {
                Inserir(vetAux);
            }
            mVetAux[i] = NULL;
        }
        delete[] mVetAux;
    }
}

void Hash::Remover(const std::string& chave) {
   
    unsigned posicaoAuxiliar = Buscar(chave);
    delete mVetPtDados[posicaoAuxiliar];
    mVetPtDados[posicaoAuxiliar] = REMOVIDO;
    mTamanho--;
}

TValor Hash::Valor(const std::string& chave) const {
    
    unsigned  posicaoAuxiliar = Buscar(chave);
    return mVetPtDados[posicaoAuxiliar]->mValor;
}

int main() {
    unsigned capacidade;
    cin >> capacidade;
    Hash tabela(capacidade);
    char operacao;
    string chave;
    TValor valor;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // inserir
                    cin >> chave >> valor;
                    tabela.Inserir(chave, valor);
                    break;
                case 'r': // remover
                    cin >> chave;
                    tabela.Remover(chave);
                    break;
                case 'c': // consultar
                    cin >> chave;
                    valor = tabela.Valor(chave);
                    cout << valor << endl;
                    break;
                case 'd': // debug (mostrar estrutura)
                    tabela.EscreverEstrutura(cout);
                    cout << endl;
                    break;
                case 'f': // finalizar
                    // vai testar depois
                    break;
                default:
                    cerr << "operação inválida\n";
            }
        }
        catch (exception& e) {
            // ignorar a mensagem que explica o erro e só escrever ERRO.
            cout << "ERRO" << endl;
        }
    } while (operacao != 'f');
    return 0;
}
