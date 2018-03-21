#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include "druzyna.hpp"
#include "pilkarz.hpp"

vector<pilkarz> lista_pilkarzy;
vector<druzyna> lista_druzyn;
vector<pilkarz> lista_managera;
int licznik_managera = 0;
int licznik_pilkarzy = 0;
int licznik_druzyn = 0;
int budzet = 1000000;

void wczytaj() {
	ifstream infile("pilkarze.txt");
	string imie, nazwisko;
	int asysty, gole, kartki, klub;
	while (infile >> imie >> nazwisko >> kartki >> gole >> asysty >> klub) {
		lista_pilkarzy.push_back(pilkarz(imie, nazwisko, kartki, asysty, gole, klub));
		licznik_pilkarzy++;
	}
	ifstream myfile("druzyny.txt");
	int zwyciestwa, przegrane;
	string trener_imie, trener_nazwisko, nazwa_druzyny;
	int i = 0;
	while (myfile >> nazwa_druzyny >> trener_imie >> trener_nazwisko >> zwyciestwa >> przegrane) {
		lista_druzyn.push_back(druzyna(nazwa_druzyny, trener_imie, trener_nazwisko, zwyciestwa, przegrane));
		licznik_druzyn++;
	}
}
void wczytajcd() {
	ifstream newfile("pilkarze2.txt");
	string imie, nazwisko;
	int asysty, gole, kartki, klub;
	while (newfile >> imie >> nazwisko >> kartki >> gole >> asysty >> klub) {
		lista_pilkarzy.push_back(pilkarz(imie, nazwisko, kartki, asysty, gole, klub));
		licznik_pilkarzy++;
	}
}
void zamiana(pilkarz &a, pilkarz &b){ 
	pilkarz tym = a;
	a = b;
	b = tym;
}
void zamiana(druzyna &a, druzyna &b){
	druzyna tym = a;
	a = b;
	b = tym;
}

void najlepszy_gracz(vector<pilkarz> &a){
	int i, j;
	for(i = 0; i < licznik_pilkarzy; i++) {
		for(j = 0; j < licznik_pilkarzy - 1 - i; j++) {
				if(((a[j].getGole())*2 + a[j].getAsysty()) < ((a[j + 1].getGole())*2 + a[j + 1].getAsysty())) { 
					zamiana(a[j], a[j+1]);
				}
		}
	}
		for(i = 0; i < 10; i++) {
			cout << "--------------------------------------------------------------------" << endl;
			cout << (i + 1) << ". ";
			cout << a[i];
			cout << endl << "Jego liczba goli to: " << a[i].getGole() << endl << "Jego liczba asyst to: " << a[i].getAsysty() << endl;
		}
	cout << "--------------------------------------------------------------------" << endl;
}
void najbardziej_agresywny(vector<pilkarz> &a){
	int i, j;
	for(i = 0; i < licznik_pilkarzy; i++) {
		for(j = 0; j < licznik_pilkarzy - 1 - i; j++) {
			if((a[j].getKartki()) < (a[j + 1].getKartki())) { 
				zamiana(a[j], a[j+1]);
			}
		}
	}
	for(i = 0; i < 10; i++) {
		cout << "--------------------------------------------------------------------" << endl;
		cout << (i + 1) << ". ";
		cout << a[i];
		cout << endl << "Jego liczba kartek to: " << a[i].getKartki() << endl;
	}
		cout << "--------------------------------------------------------------------" << endl;	
}

void najlepsza_druzyna(vector<druzyna> &a){
	int i, j;
	for(i = 0; i < licznik_druzyn; i++) {
		for(j = 0; j < licznik_druzyn - 1 - i; j++) {
			if(((double)a[j].getZwyciestwa() / ((double)a[j].getPrzegrane() + (double)a[j].getZwyciestwa())) < ((double)a[j + 1].getZwyciestwa() / ((double)a[j + 1].getPrzegrane() + (double)a[j + 1].getZwyciestwa()))) { 
				zamiana(a[j], a[j+1]);
			}
		}
	}
	for(i = 0; i < licznik_druzyn; i++) {
		cout << "--------------------------------------------------------------------" << endl;
		cout << (i + 1) << ". ";
		cout << a[i].getNazwa_druzyny() << endl;
		cout << endl << "Jej liczba zwyciestw to: " << a[i].getZwyciestwa() << endl << "Jej liczba przegranych to: " << a[i].getPrzegrane() << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
}

void wyswietl_pilkarzy(vector<pilkarz> &a, vector<druzyna> &b) {
	for(int i = 0; i < licznik_pilkarzy; i++) {
		cout << "--------------------------------------------------------------------" << endl;
		cout << (i + 1) << ".  ";
		cout << a[i];
		cout << endl << "Gole: " << a[i].getGole() << " | Asysty: " << a[i].getAsysty() << " | Kartki: " << a[i].getKartki();
		if(a[i].getKlub() == -8) {
			cout << " | Pilkarz zostal kupiony przez managera, nie ma obecnie przydzielonej druzyny" << endl;
		}
		else {
			cout << " | Druzyna: " << b[a[i].getKlub() - 1].getNazwa_druzyny() << endl; 
		}
	}
	cout << "--------------------------------------------------------------------" << endl;
}

void wyswietl_druzyny(vector<druzyna> &b, vector<pilkarz> &a){
	for(int i = 0; i < licznik_druzyn; i++){
		cout << "--------------------------------------------------------------------" << endl;
		cout << (i + 1) << ". ";
		cout << b[i].getNazwa_druzyny() << endl << "Trener: " << b[i].getTrener_imie() << " " << b[i].getTrener_nazwisko()
			 << " | Zwyciestwa: " << b[i].getZwyciestwa() << " | Porazki: " << b[i].getPrzegrane() << endl << endl;
		cout << "Zwodnicy: " << endl;
		int k = 1;
		for(int j = 0; j < licznik_pilkarzy; j++) {
			if(a[j].getKlub() == b[i].getIndeks()) {
				cout << k << ". " ;
				cout << a[j];
				k++; 
			}
		}
	}
}

void skup_pilkarza(int indeks) {
	lista_managera.push_back(pilkarz(lista_pilkarzy[indeks - 1].getImie(), 
	lista_pilkarzy[indeks - 1].getNazwisko(), lista_pilkarzy[indeks - 1].getKartki(), lista_pilkarzy[indeks - 1].getAsysty(), 
	lista_pilkarzy[indeks - 1].getGole(), lista_pilkarzy[indeks - 1].getKlub()));
	lista_pilkarzy[indeks - 1].setKlub(-8);
	budzet = budzet - 100000;	
	licznik_managera ++;
} 

void sprzedaj_pilkarza(int indeks_managera, int indeks_druzyny) {
	lista_managera[indeks_managera - 1].setKlub(indeks_druzyny);
	lista_managera[indeks_managera - 1].getKlub();
	int i;
	for(i = 0; i < licznik_pilkarzy; i ++) {
		if(lista_pilkarzy[i].getNazwisko() == lista_managera[indeks_managera - 1].getNazwisko()) {
			lista_pilkarzy[i].setKlub(lista_managera[indeks_managera - 1].getKlub());
			break;
		}
	}
	zamiana(lista_managera[indeks_managera - 1], lista_managera[licznik_managera - 1]);
	lista_managera.pop_back();
	licznik_managera -= 1;
	budzet += 100000;
}

void wyswietl_manager(vector<pilkarz> &a) {
	for(int i = 0; i < licznik_managera; i++) {
		cout << "--------------------------------------------------------------------" << endl;
		cout << (i + 1) << ".  ";
		cout << a[i];
		cout << endl << "Gole: " << a[i].getGole() << " | Asysty: " << a[i].getAsysty() << " | Kartki: " << a[i].getKartki() << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Twoj pozostaly budzet to: " << budzet << endl;
}

void kup() {
	srand(time (NULL));
	
	int n = (rand() % 60);
	skup_pilkarza(n);
	int k = (rand() % 50);
	skup_pilkarza(k);
	int m = (rand() % 30);
	skup_pilkarza(m);
	wyswietl_manager(lista_managera);
	k = (k % 3) + 1;
	m = (m % 6) + 1;
	cout << "Numer sprzedawanego: "<< k << " Numer druzyny: " << m << endl;
	cout << "Sprzedajemy: " << lista_managera[k - 1] << " Do klubu:  " << lista_druzyn[m - 1].getNazwa_druzyny() << endl;
	sprzedaj_pilkarza(k, m);
	wyswietl_manager(lista_managera);
	wyswietl_druzyny(lista_druzyn, lista_pilkarzy);
}
