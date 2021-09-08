//----------------BLACK JACK ------------------- Plik Glowny-------------------------

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
const int L_KART_W_3TALII=156;
struct karta{
	int kolor;
	int figura;
	int wartosc;
	bool as=false;
	
};

void rysowanie(karta talia[],int n);

void gen_talii(karta talia[]);

void losowanie(karta talia[], karta cel[], int ile,int wylosowane[],int &istn,int &a);

void interfejs(karta talia[], karta gr1[], int igr1, karta gr2[], int igr2,karta kr[],int ikr, int& zetony, int stawka);

int punkty(karta talia[],int ile);

void rozdanie(karta talia[],int &zetony,int stawka);

void interfejsstart(karta talia[],int& zetony,int stawka);

void wyszakladu(karta talia[],int& zetony,int stawka);

void menu1(karta talia[], karta gr1[], int& igr1, karta gr2[], int& igr2,karta kr[],int& ikr, int &zetony, int& stawka,int wylosowane[],int& a);

void menu2(karta talia[], karta gr1[], int& igr1, karta gr2[], int& igr2,karta kr[],int& ikr, int &zetony, int& stawka,int wylosowane[],int& a);

void split(karta a[],karta b[],int& ilea,int& ileb);

void zerowanie(karta a[],int roz);

void wynik(karta a[],karta b[],int ilea, int ileb,int& zetony,int stawka);

int main(){
	karta talia[L_KART_W_3TALII];
	int n;
	int igr2=0;
	int igr1=0;
	int ikr=0;
	int zetony = 100;
	int stawka = 0;
	srand(time(0));
	gen_talii(talia);
	int w;
	
	interfejsstart(talia, zetony, stawka);
	

	
	return 0;
}

void gen_talii(karta talia[]){
	int j=0;
	while(j<156){
	for(int k=1;k<5;k++)
		for(int i=2; i<15;i++)
		 	{talia[j].figura=i;
			talia[j].kolor=k;
			if(i==2)talia[j].wartosc=2;
			if(i==3)talia[j].wartosc=3;
			if(i==4)talia[j].wartosc=4;
			if(i==5)talia[j].wartosc=5;
			if(i==6)talia[j].wartosc=6;
			if(i==7)talia[j].wartosc=7;
			if(i==8)talia[j].wartosc=8;
			if(i==9)talia[j].wartosc=9;
			if(i==10||i==11||i==12||i==13)talia[j].wartosc=10;
			if(i==14){ talia[j].wartosc=10; talia[j].as=true;}
			
			j++;
			}
		
	}

	
	
}


void rysowanie(karta talia[],int n){
			
		char x[3];
	
	
	//1-kier 2-trefl 3-karo 4-pik 5-tyl

	
		for(int i=0;i<n;i++){
			
			if(talia[i].kolor==1)cout<<" ------------------ "; if(talia[i].kolor==2)cout<<" ------------------ "; if(talia[i].kolor==3)cout<<" ------------------ "; if(talia[i].kolor==4)cout<<" ------------------ "; if(talia[i].kolor==5)cout<<" ------------------ ";}cout<<endl;
		for(int i=0;i<n; i++){
			if(talia[i].figura==11)cout<<"| "<<setw(2)<<"J"<<"               |";if(talia[i].figura==12)cout<<"| "<<setw(2)<<"D"<<"               |";if(talia[i].figura==13)cout<<"| "<<setw(2)<<"K"<<"               |";if(talia[i].figura==14)cout<<"| "<<setw(2)<<"A"<<"               |";if(talia[i].figura!=11&&talia[i].figura!=12&&talia[i].figura!=13&&talia[i].figura!=14)cout<<"| "<<setw(2)<<talia[i].figura<<"               |";/*if(talia[i].kolor==5)cout<<"               |";cout<<"|  ##    ##    ##  |";*/}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|                  |";if(talia[i].kolor==2)cout<<"|                  |";if(talia[i].kolor==3)cout<<"|                  |";if(talia[i].kolor==4)cout<<"|                  |";if(talia[i].kolor==5)cout<<"|   ##        ##   |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|      #     #     |";if(talia[i].kolor==2)cout<<"|        #         |";if(talia[i].kolor==3)cout<<"|                  |";if(talia[i].kolor==4)cout<<"|         #        |";if(talia[i].kolor==5)cout<<"|    ##      ##    |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|    #   # #   #   |";if(talia[i].kolor==2)cout<<"|      #   #       |";if(talia[i].kolor==3)cout<<"|         #        |";if(talia[i].kolor==4)cout<<"|       #   #      |";if(talia[i].kolor==5)cout<<"|     ##    ##     |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|    #         #   |";if(talia[i].kolor==2)cout<<"|   #    #    #    |";if(talia[i].kolor==3)cout<<"|        # #       |";if(talia[i].kolor==4)cout<<"|     #       #    |";if(talia[i].kolor==5)cout<<"| #    ##  ##    # |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|     #       #    |";if(talia[i].kolor==2)cout<<"| #   #     #   #  |";if(talia[i].kolor==3)cout<<"|       # # #      |";if(talia[i].kolor==4)cout<<"|    #   # #   #   |";if(talia[i].kolor==5)cout<<"| ##    ####    ## |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|      #     #     |";if(talia[i].kolor==2)cout<<"|   #    #    #    |";if(talia[i].kolor==3)cout<<"|        # #       |";if(talia[i].kolor==4)cout<<"|     #   #   #    |";if(talia[i].kolor==5)cout<<"| #    ##  ##    # |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|       #   #      |";if(talia[i].kolor==2)cout<<"|        #         |";if(talia[i].kolor==3)cout<<"|         #        |";if(talia[i].kolor==4)cout<<"|        # #       |";if(talia[i].kolor==5)cout<<"|     ##    ##     |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|         #        |";if(talia[i].kolor==2)cout<<"|      #   #       |";if(talia[i].kolor==3)cout<<"|                  |";if(talia[i].kolor==4)cout<<"|       #   #      |";if(talia[i].kolor==5)cout<<"|    ##      ##    |";}cout<<endl;
		for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<"|                  |";if(talia[i].kolor==2)cout<<"|                  |";if(talia[i].kolor==3)cout<<"|                  |";if(talia[i].kolor==4)cout<<"|                  |";if(talia[i].kolor==5)cout<<"|   ##        ##   |";}cout<<endl;
		for(int i=0; i<n; i++){
			
			if(talia[i].figura==11)cout<<"|               "<<setw(2)<<"J"<<" |";if(talia[i].figura==12)cout<<"|               "<<setw(2)<<"D"<<" |";if(talia[i].figura==13)cout<<"|               "<<setw(2)<<"K"<<" |";if(talia[i].figura==14)cout<<"|               "<<setw(2)<<"A"<<" |";if(talia[i].figura!=11&&talia[i].figura!=12&&talia[i].figura!=13&&talia[i].figura!=14)cout<<"|               "<<setw(2)<<talia[i].figura<<" |";/*if(talia[i].kolor==5)cout<<"               |";cout<<"|  ##    ##    ##  |";*/}cout<<endl;
		
				for(int i=0; i<n; i++){
			if(talia[i].kolor==1)cout<<" ------------------ ";if(talia[i].kolor==2)cout<<" ------------------ ";if(talia[i].kolor==3)cout<<" ------------------ ";if(talia[i].kolor==4)cout<<" ------------------ ";if(talia[i].kolor==5)cout<<" ------------------ ";}cout<<endl;
	}
	
	
	
	
	
	void losowanie(karta talia[], karta cel[],int ile,int wylosowane[],int &istn,int& a){
		int ind;
		int b=istn;
		
		for(int i=istn;i<(ile+b);i++){
			
			
			los:
			ind=rand()%156;
			for(int j=0;j<a;j++)if(wylosowane[j]==ind)goto los;
			wylosowane[a++]=ind;
			cel[i].kolor=talia[ind].kolor;
			cel[i].figura=talia[ind].figura;
			cel[i].wartosc=talia[ind].wartosc;
			cel[i].as=talia[ind].as;
			istn++;
		}
		
		
	}
	
	int punkty(karta a[], int ile){
		int suma=0;
		for(int i=0;i<ile;i++){
	

			suma=suma+a[i].wartosc;
	
		}
		for(int i =0;i<ile;i++)
		if(a[i].as&&suma>21)suma=suma-9;
		return suma;
	}
	
	void interfejs(karta talia[], karta gr1[], int igr1, karta gr2[], int igr2,karta kr[],int ikr, int &zetony, int stawka){
		cout<<"____________________________________________________________________________________"<<endl;
		cout<<" Karty Krupiera:  "<<endl;
		rysowanie(kr,ikr);
		cout<<"Liczba puntow krupiera: "<<punkty(kr,ikr)<<endl;
		cout<<"Karty gracza: "<<endl;
		rysowanie(gr1,igr1);
		cout<<"Liczba punktow gracza: "<<punkty(gr1,igr1)<<endl;
		cout<<"AKTUALNA STAWKA: "<<stawka<<"   POSIADANE ZETONY: "<<zetony<<endl;
		
		if(igr2>0){cout<<"Karty drugiego pakietu: "<<endl;rysowanie(gr2,igr2);cout<< "Liczba punktow gracza na drugiej rece: "<<punkty(gr2,igr2)<<endl;cout<<"AKTUALNA STAWKA: "<<stawka<<"   POSIADANE ZETONY: "<<zetony<<endl;}
		cout<<"____________________________________________________________________________________"<<endl;
		
		
		
	}
	
	void rozdanie(karta talia[],int &zetony,int stawka){
		karta *rekagr1;
		karta *rekagr2;
		karta *rekakr;
		int *wylosowane;
		int lkgr1,lkgr2,lkkr,a;
		rekagr1= new karta[10];
		rekagr2= new karta[10];
		rekakr=	new karta[20];
		wylosowane= new int[30];
		zerowanie(rekagr1,10);
		zerowanie(rekagr2,10);
		zerowanie(rekakr,20);
		for(int i=0;i<30;i++)
			wylosowane[i]=0;
		a=0;
		lkkr=0;
		lkgr1=0;
		lkgr2=0;
		
			losowanie(talia,rekakr,2,wylosowane,lkkr,a);
			
			losowanie(talia,rekagr1,2,wylosowane,lkgr1,a);
			
			
		
		interfejs(talia,rekagr1,lkgr1,rekagr2,lkgr2,rekakr,1,zetony,stawka);
		
		menu1(talia,rekagr1,lkgr1,rekagr2,lkgr2,rekakr,lkkr,zetony,stawka,wylosowane,a);
	
		
		interfejs(talia,rekagr1,lkgr1,rekagr2,lkgr2,rekakr,lkkr,zetony,stawka);
		
		wynik(rekagr1,rekakr,lkgr1,lkkr,zetony,stawka);
		
		
		if(lkgr2>0){
			menu2(talia,rekagr1,lkgr1,rekagr2,lkgr2,rekakr,lkkr,zetony,stawka,wylosowane,a);
			interfejs(talia,rekagr1,lkgr1,rekagr2,lkgr2,rekakr,lkkr,zetony,stawka);
			wynik(rekagr2,rekakr,lkgr2,lkkr,zetony,stawka);
		}
		
		delete rekagr1;
		rekagr1=0;
		delete rekagr2;
		rekagr2=0;
		delete rekakr;
		rekakr=0;
		delete wylosowane;
		wylosowane=0;
		
	
		
	}
			
	void menu1(karta talia[], karta gr1[], int& igr1, karta gr2[], int& igr2,karta kr[],int& ikr, int &zetony, int& stawka,int wylosowane[],int& a){
		int wyb2;
		
		
		
		cout<< "1 - Hit |"<< " 2 - Stand |"<< " 3 - Double down ";if(gr1[0].figura==gr1[1].figura) cout<< "| 4 - Split "<<endl;
		cin>>wyb2;
		
		
		
		switch(wyb2){
			case 1:{losowanie(talia,gr1,1,wylosowane,igr1,a);interfejs(talia,gr1,igr1,gr2,igr2,kr,1,zetony,stawka);break;	}
			 
			case 2: { break;}
				
					
			case 3: {losowanie(talia,gr1,1,wylosowane,igr1,a); stawka*=2;break;}
				
			case 4:	{split(gr1,gr2,igr1,igr2);interfejs(talia,gr1,igr1,gr2,igr2,kr,ikr,zetony,stawka);break;}
			default: break;
			
		}
		if(wyb2==4){
			if(igr2>0)cout<<"GRASZ PIERWSZYM ZESTAWEM KART"<<endl;	
			cout<< "1 - Hit |"<< " 2 - Stand |"<< " 3 - Double down "<<endl;
			cin>>wyb2;
		
		
			switch(wyb2){
				
				case 1:{losowanie(talia,gr1,1,wylosowane,igr1,a);interfejs(talia,gr1,igr1,gr2,igr2,kr,1,zetony,stawka);break;	}
				 
				case 2: { break;}
					
						
				case 3: {losowanie(talia,gr1,1,wylosowane,igr1,a); stawka*=2;break;}
					
				
				default: break;
				
			}
		}
		while(wyb2!=2&&wyb2!=3&&punkty(gr1,igr1)<21){
			if(igr2>0)cout<<"GRASZ PIERWSZYM ZESTAWEM KART"<<endl;
			
			cout<< "1 - Hit |"<< " 2 - Stand |"<<endl;
			cin>>wyb2;
			
				switch(wyb2){
			case 1:{losowanie(talia,gr1,1,wylosowane,igr1,a);interfejs(talia,gr1,igr1,gr2,igr2,kr,1,zetony,stawka);break;	}
			 
			case 2: { break;}
				
					
			
			
		}
		}
		
		 while((punkty(kr,ikr))<18){losowanie(talia,kr,1,wylosowane,ikr,a);}
		
		
		}
		
	void menu2(karta talia[], karta gr1[], int& igr1, karta gr2[], int& igr2,karta kr[],int& ikr, int &zetony, int& stawka,int wylosowane[],int& a){
		int wyb2;
		
		
		cout<<"GRASZ DRUGIM ZESTAWEM KART"<<endl;
		cout<< "1 - Hit |"<< " 2 - Stand |"<< " 3 - Double down ";
		cin>>wyb2;
		
		
		switch(wyb2){
			case 1:{losowanie(talia,gr2,1,wylosowane,igr2,a);interfejs(talia,gr1,igr1,gr2,igr2,kr,1,zetony,stawka);break;	}
			 
			case 2: { break;}
				
					
			case 3: {losowanie(talia,gr2,1,wylosowane,igr2,a); stawka*=2;break;}
				
			default: break;
			
			
		}
		while(wyb2!=2&&wyb2!=3&&punkty(gr1,igr1)<21){
			cout<<"GRASZ DRUGIM ZESTAWEM KART"<<endl;
			cout<< "1 - Hit |"<< " 2 - Stand |"<<endl;
			cin>>wyb2;
			
				switch(wyb2){
			case 1:{losowanie(talia,gr2,1,wylosowane,igr2,a);interfejs(talia,gr1,igr1,gr2,igr2,kr,1,zetony,stawka);break;	}
			 
			case 2: { break;}
				
			default: break;		
			
		}
		}
		
		 while((punkty(kr,ikr))<18){losowanie(talia,kr,1,wylosowane,ikr,a);}
		
		
		}
	
	void interfejsstart(karta talia[],int& zetony,int stawka){
		cout<< "            -----WITAJ W GRZE BLACK JACK-----                  "<<endl;
		int wyb1;
		cout <<"Aby rozpoczac gre wcisnij 1"<<endl;
		cin>>wyb1;
		if(wyb1==1) wyszakladu(talia,zetony,stawka);
		do{cout<<"Jesli chcesz grac dalej klikij 1"<<endl;
		cin>>wyb1;
		if(wyb1==1) wyszakladu(talia,zetony,stawka);
		}while(wyb1==1);
		
	}
	
	void wyszakladu(karta talia[],int& zetony,int stawka){
		if(zetony>0){cout<< "Posiadasz aktualnie "<<zetony<<" zetonow"<<endl;
		cout<< "Wybierz stawke o jaka chcesz grac: ";cin>>stawka;
		if(stawka<=zetony&&stawka>0)rozdanie(talia,zetony,stawka);
		else cout<<" Nie mozesz ustalic takiej stawki"<<endl;
		}else cout<<"Nie masz zetonow"<<endl;
		
		
	}
	
void split(karta a[],karta b[],int& ilea,int& ileb){
	b[0].kolor=a[1].kolor;
	b[0].figura=a[1].figura;
	b[0].wartosc=a[1].wartosc;
	b[0].as=a[1].as;
	ilea-=1;
	ileb+=1;
	a[1].kolor=0;
	a[1].figura=0;
	a[1].wartosc=0;
	a[1].as=0;

}
void zerowanie(karta a[],int roz){
	for(int i=0; i<roz;i++){
	a[i].wartosc=0;
	a[i].kolor=0;
	a[i].figura=0;
	a[i].as=0;
	}
	
}
void wynik(karta a[],karta b[],int ilea, int ileb,int& zetony,int stawka){
	if(punkty(a,ilea)<=21&&punkty(b,ileb)<=21&&punkty(a,ilea)==punkty(b,ileb)){cout<<"Remis. Twoje zetony: "<<zetony<<endl;}
		if(punkty(a,ilea)<=21&&punkty(b,ileb)<=21&&punkty(a,ilea)>punkty(b,ileb)){zetony+=stawka; cout<<"Wygrales. Twoje zetony: "<<zetony<<endl; }
		if(punkty(a,ilea)<=21&&punkty(b,ileb)<=21&&punkty(a,ilea)<punkty(b,ileb)){zetony-=stawka; cout<<"Przegrales. Twoje zetony: "<<zetony<<endl;}
		if(punkty(a,ilea)<=21&&punkty(b,ileb)>21){zetony+=stawka; cout<<"Wygrales. Twoje zetony: "<<zetony<<endl; }
		if(punkty(a,ilea)>21){ zetony-=stawka;cout<<"Przegrales. Twoje zetony: "<<zetony<<endl;}
}
