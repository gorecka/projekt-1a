#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pilkarz.hpp"
#include "druzyna.hpp"
#include "funkcje.hpp"





int main() {
	wczytaj();
	wczytajcd();
	cout << "Witaj!" << endl << "Oto Football Manager" << endl;
	int indeks;
	while(1) {
		cout << endl <<"Co chcialbys zrobic?" << endl;
		cout << "1 - przeprowadz testy" << endl;
		cout << "2 - zobacz dostepnych pilkarzy" << endl;
		cout << "3 - wyswietl sklady druzyn" << endl;
		cout << "4 - zobacz nalepszych pilkarzy" << endl;
		cout << "5 - zobacz najczesciej karanych pilkarzy" << endl;
		cout << "6 - sprawdz, ktora druzyna jest najlepsza" << endl;
		cout << "7 - skup pilkarza" << endl;
		cout << "8 - sprzedaj pilkarza" << endl;
		cout << "9 - wyswietl swoich pilkarzy i pozostale srodki" << endl;
		cout << "10 - wyjscie" << endl;
		cin >> indeks;
		if(cin.fail()) {
			cout << "Powinienes wprowadzic liczbe" << endl << endl;
			cin.clear();
			cin.sync();	
			continue;
		}
				
		
		switch(indeks){
			case 1:
				kup();
				break;
			case 2:
				wyswietl_pilkarzy(lista_pilkarzy, lista_druzyn);
				break;
			case 3:
				wyswietl_druzyny(lista_druzyn, lista_pilkarzy);			
				break;
			case 4:
				najlepszy_gracz(lista_pilkarzy);
				break;
			case 5:
				najbardziej_agresywny(lista_pilkarzy);	
				break;
			case 6:			
				najlepsza_druzyna(lista_druzyn);
				break;
			case 7:
				int wybor, i;
				while(1) {
				cout << "Podaj numer pilkarza, ktorego chcesz kupic" << endl;
				cout << "Zeby wrocic do menu wpisz -1" << endl;
				cin >> wybor;
				if(cin.fail() || (wybor > licznik_pilkarzy)) {
					cout << "powinienes wprowadzic liczbe nie wieksza niz numer ostatniego pilkarza" << endl;
					cin.clear();
					cin.sync();
					continue;
				}
				if(wybor == -1) {
					break;
				}
				if(budzet < 100000) {
					cout << "Nie masz dosc pieniedzy, musisz sprzedac jakiegos pilkarza" << endl;
					break;
				}
				for(i = 0; i < licznik_managera; i++){
					if(lista_managera[i].getNazwisko() == lista_pilkarzy[wybor - 1].getNazwisko()){
						cout << "Juz kupiles tego pilkarza" << endl;
						break;
					}		
				}
				if((licznik_managera > 0) && (lista_managera[i].getNazwisko() == lista_pilkarzy[wybor - 1].getNazwisko())) {
						continue;
					}
				break;
				}
				if((wybor == -1) || (budzet < 100000)) {
					break;
				}
				skup_pilkarza(wybor);
				break;
			case 8:
				cout << "Podaj numer pilkarza, ktorego chcesz sprzedac z listy managera" << endl;
				cout << "Zeby wrocic do menu wpisz -1" << endl;
				cin >> wybor;
				if(cin.fail() || (wybor > licznik_managera)) {
					cout << "powinienes wprowadzic liczbe nie wieksza niz numer ostatniego pilkarza" << endl;
					cin.clear();
					cin.sync();
				}
				if(wybor == -1) {
					break;
				}
				int numer;
				cout << "Podaj numer druzyny, ktorej chcesz go sprzedac" << endl;
				cin >> numer;
				if(cin.fail() || (wybor > licznik_druzyn)) {
					cout << "Powinienes wprowadzic liczbe nie wieksza niz numer ostatniej druzyny" << endl;
					cin.clear();
					cin.sync();
				}
				sprzedaj_pilkarza(wybor, numer);
				break;	
			case 9:
				wyswietl_manager(lista_managera);
				break;	
			case 10:
				cout << "Do zobaczenia!" << endl;
				return 0;
			default:
				cout << "Nie istnieje taka opcja w menu. Wybierz jeszcze raz." << endl;
				break;	
		}
	}
	
	
/*	wczytaj();
	najlepszy_gracz(lista_pilkarzy);
	najlepsza_druzyna(lista_druzyn);
	wyswietl_pilkarzy(lista_pilkarzy, lista_druzyn);
	wyswietl_druzyny(lista_druzyn, lista_pilkarzy); */

/*	vector<pilkarz> lista_pilkarzy;
	vector<druzyna> lista_druzyn;
	
	ifstream infile("pilkarze.txt");
	string imie, nazwisko;
	int asysty, gole, kartki, klub;
	while (infile >> imie >> nazwisko >> asysty >> gole >> kartki >> klub) {
		cout << imie << nazwisko << gole << endl; 
		lista_pilkarzy.push_back(pilkarz(imie, nazwisko, kartki, asysty, gole, klub));
	}
	ifstream myfile("druzyny.txt");
	int licznosc, zwyciestwa, przegrane;
	string trener_imie, trener_nazwisko, nazwa_druzyny;
	int i = 0;
	while (myfile >> nazwa_druzyny >> trener_imie >> trener_nazwisko >> zwyciestwa >> przegrane >> licznosc) {
		cout << nazwa_druzyny << trener_imie << trener_nazwisko << zwyciestwa << przegrane << licznosc << endl;
		lista_druzyn.push_back(druzyna(nazwa_druzyny, trener_imie, trener_nazwisko, zwyciestwa, przegrane, licznosc));
	}
	
	//cout << lista_pilkarzy[0] << endl;
	//cout << lista_pilkarzy[1] << endl;
	//cout << lista_pilkarzy[2] << endl;
*/	
	return 0;
} 
