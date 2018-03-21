#ifndef PILKARZ_HPP
#define PILKARZ_HPP

#include <string>
#include <iostream>

using namespace std;

class pilkarz {
	string imie;
	string nazwisko;
	int kartki;
	int asysty;
	int gole;
	int klub;
	
	public:
	pilkarz(string imie, string nazwisko, int kartki, int asysty, int gole, int klub);
	void setImie(string b);
	void setNazwisko(string b);
	void setKartki(int a);
	void setAsysty(int a);
	void setGole(int a);
	void setKlub(int a);
	string getImie() const;
	string getNazwisko() const;
	int getKartki();
	int getAsysty();
	int getGole();
	int getKlub();
};

ostream& operator<<(ostream& stream, const pilkarz& p);

#endif
