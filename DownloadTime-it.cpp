#include <iostream>

#define MOLTIPLICATORE 1024
#define BYTE_TO_BIT 8
#define MIN_IN_ORE 60
#define SEC_IN_MIN 60

using namespace std;

int main(){
	
	float dimensione;
	float velocita;
	
	int grandezzaDim;
	int grandezzaVel;
	
	float dimensioneKB;
	float velocitaKB;
	
	int secondi;
	int minuti;
	int ore;
	
	int continua;
	
	do {
		cout<<"Inserisci la dimensione del file da scaricare (solo valore): ";
		cin>>dimensione;
		
		do{
			cout<<"\nSeleziona l'unita' di misura:\n";
			cout<<"1) byte\n";
			cout<<"2) Kbyte\n";
			cout<<"3) Mbyte\n";
			cout<<"4) Gbyte\n";
			
			cin>>grandezzaDim;
		}while(grandezzaDim<1 || grandezzaDim>4);
		
		
		cout<<"\n\nInserisci la velocita' della tua connessione (solo valore): ";
		cin>>velocita;
		
		do{
			cout<<"\nSeleziona l'unita' di misura:\n";
			cout<<"1) Kbyte/s\n";
			cout<<"2) Mbyte/s\n";
			cout<<"3) Kbit/s\n";
			cout<<"4) Mbit/s\n";
			
			cin>>grandezzaVel;
		}while(grandezzaVel<1 || grandezzaVel>4);
		
		
		switch(grandezzaDim){
			case 1: dimensioneKB = dimensione/MOLTIPLICATORE; break;
			case 2: dimensioneKB = dimensione; break;
			case 3: dimensioneKB = dimensione*MOLTIPLICATORE; break;
			case 4: dimensioneKB = dimensione*MOLTIPLICATORE*MOLTIPLICATORE; break;
		}
		
		switch(grandezzaVel){
			case 1: velocitaKB = velocita; break;
			case 2: velocitaKB = velocita*MOLTIPLICATORE; break;
			case 3: velocitaKB = velocita/BYTE_TO_BIT; break;
			case 4: velocitaKB = velocita*MOLTIPLICATORE/BYTE_TO_BIT; break;
		}
		
		secondi = dimensioneKB/velocitaKB;
		
		ore = secondi/(MIN_IN_ORE*SEC_IN_MIN);
		minuti = (secondi%(MIN_IN_ORE*SEC_IN_MIN))/SEC_IN_MIN;
		secondi = (secondi%(MIN_IN_ORE*SEC_IN_MIN))%SEC_IN_MIN;
		
		cout<<"\n\nTempo stimato: "<<ore<<"h "<<minuti<<"m "<<secondi<<"s\n";
		
		do{
			cout<<"\nVuoi inserire un altro file/velocita'?:\n";
			cout<<"1) Si\n";
			cout<<"2) No\n";
			
			cin>>continua;
		}while(continua<1 || continua>2);
		
		cout<<endl<<endl;
		
	} while (continua != 2);
	
	return 0;
}
