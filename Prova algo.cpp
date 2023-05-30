#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double  NO, I, F, S=0, cidade=0, QTonca=0, SI=0, MediaI=0, SO=0;  // numero de onças, idade, filhotes, soma de onças, 
	double TM, MaiorT=-9999, MenorT=10000, MI=0;  // temperatura média
	char C[100],CC; // nome da cidadee
	do{
		cout<<"Entre com o nome da cidade"<<endl;
		cin.getline(C,100);
		do{
			cout<<"Entre com a temperatura media"<<endl;
			cin>>TM;
		}while(!(TM>=-30 && TM<=45));
		if(TM<MenorT){
			MenorT=TM;
		}
		if(TM>MaiorT){
			MaiorT=TM;
		}
		do{
			cout<<"Entre com o numero de oncas"<<endl;
			cin>>NO;
		}while(!(NO>=0));	
		for(int j=1;j<=NO;j++){
			do{
				cout<<"Entre com a idade da onca"<<endl;
				cin>>I;
			}while(!(I>=0 && I<=50));
			do{
				cout<<"Entre com o numero de filhotes"<<endl;
				cin>>F;
				cin.ignore();
			}while(!(F>=0));
			QTonca=QTonca+F;
			MediaI=MediaI+I;
			SI=SI+I;
			
		}
		cidade++;
		S=QTonca+NO;
		SO=SO+NO;
		NO=0;
		cout<<"Quantidade de oncas em cada cidade : "<<S<<endl;
		do{
			cout<<"Deseja cadastrar mais uma cidade? (S/N)"<<endl;
			cin>>CC;
			cin.ignore();
		}while(!(CC=='S' || CC=='N'));
	}while(!(CC=='N'));
	MI=SI/SO;
	cout<<"Total de cidades : "<<cidade<<endl;
	cout<<"Media das idades : "<<fixed<<setprecision(2)<<MI<<endl;
	cout<<"Maior temperatura : "<<fixed<<setprecision(2)<<MaiorT<<endl;
	cout<<"Menor temperatura : "<<fixed<<setprecision(2)<<MenorT<<endl;
	
}