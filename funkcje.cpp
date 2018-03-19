#include <vector>
#include <fstream>
#include <string>
#include "druzyna.hpp"
#include "pilkarz.hpp"

vector<pilkarz> lista_pilkarzy;
vector<druzyna> lista_druzyn;
int licznik_pilkarzy = 0;
int licznik_druzyn = 0;

void wczytaj() {
	ifstream infile("pilkarze.txt");
	string imie, nazwisko;
	int asysty, gole, kartki, klub;
	while (infile >> imie >> nazwisko >> asysty >> gole >> kartki >> klub) {
	//	cout << imie << nazwisko << gole << endl; 
		lista_pilkarzy.push_back(pilkarz(imie, nazwisko, kartki, asysty, gole, klub));
		licznik_pilkarzy++;
	}
	ifstream myfile("druzyny.txt");
	int licznosc, zwyciestwa, przegrane;
	string trener_imie, trener_nazwisko, nazwa_druzyny;
	int i = 0;
	while (myfile >> nazwa_druzyny >> trener_imie >> trener_nazwisko >> zwyciestwa >> przegrane >> licznosc) {
	//	cout << nazwa_druzyny << trener_imie << trener_nazwisko << zwyciestwa << przegrane << licznosc << endl;
		lista_druzyn.push_back(druzyna(nazwa_druzyny, trener_imie, trener_nazwisko, zwyciestwa, przegrane, licznosc));
		licznik_druzyn++;
	}
}
void zamiana(pilkarz a, pilkarz b){ //z jakiegoœ powodu nie zamienia kolejnosci
	pilkarz tym = a;
	a = b;
	b = tym;
}
void zamiana(druzyna a, druzyna b){
	druzyna tym = a;
	a = b;
	b = tym;
}

void najlepszy_gracz(vector<pilkarz> a){
	int i, j;
	for(i = 0; i < licznik_pilkarzy; i++) {
		for(j = 0; j < licznik_pilkarzy - 1 - i; j++) {
				if(((a[j].getGole())*2 + a[j].getAsysty()) < ((a[j + 1].getGole())*2 + a[j + 1].getAsysty())) { 
					zamiana(a[j], a[j+1]);
				}
		}
	}
		for(i = 0; i < licznik_pilkarzy; i++) {
			cout << i << ". ";
			cout << a[i];
			cout << "Jego liczba goli to: " << a[i].getGole() << endl << "Jego liczba asyst to: " << a[i].getAsysty() << endl;
		}
	
}

void najlepsza_druzyna(vector<druzyna> a){
	int i, j;
	for(i = 0; i < licznik_druzyn; i++) {
		for(j = 0; j < licznik_druzyn - 1 - i; j++) {
				if((a[j].getZwyciestwa() - (a[j].getPrzegrane())*2) < (a[j + 1].getZwyciestwa() - (a[j + 1].getPrzegrane())*2)) { 
					zamiana(a[j], a[j+1]);
				}
		}
	}
		for(i = 0; i < licznik_druzyn; i++) {
			cout << i << ". ";
			cout << a[i].getNazwa_druzyny() << endl;
			cout << "Jej liczba zwyciestw to: " << a[i].getZwyciestwa() << endl << "Jej liczba przegranych to: " << a[i].getPrzegrane() << endl;
		}
}

//zrobic finkcje do wyswietlania skladow druzyny
