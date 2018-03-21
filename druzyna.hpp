#ifndef DRUZYNA_HPP
#define DRUZYNA_HPP

#include <iostream>
#include <string>

using namespace std;

class druzyna {
	string nazwa_druzyny;
	int zwyciestwa;
	int przegrane;
	string trener_imie, trener_nazwisko;
	int indeks; //numer druzyny
	static int liczba_druzyn;
	
	
	public:
	druzyna(string nazwa_druzyny, string trener_imie, string trener_nazwisko, int zwyciestwa, int przegrane);	
	void setNazwa_druzyny(string b);
	void setZwyciestwa(int a);
	void setPrzegrane(int a);
	void setTrener_imie(string b);
	void setTrener_nazwisko(string b);
	void setIndeks(int a);
	string getNazwa_druzyny();
	int getZwyciestwa();
	int getPrzegrane();
	string getTrener_imie();
	string getTrener_nazwisko();
	int getIndeks();
};

#endif
