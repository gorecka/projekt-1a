#include <iostream>
#include "pilkarz.hpp"
#include "druzyna.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "funkcje.hpp"




int main() {
	wczytaj();
	najlepszy_gracz(lista_pilkarzy);
	najlepsza_druzyna(lista_druzyn);
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
