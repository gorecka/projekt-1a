#include "pilkarz.hpp"

ostream& operator<<(ostream& stream, const pilkarz& p) {
	stream << p.getImie() << " "<< p.getNazwisko() << endl;
	return stream;
}

pilkarz::pilkarz(string imie, string nazwisko, int kartki, int asysty, int gole, int klub) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->kartki = kartki;
	this->asysty = asysty;
	this->gole = gole;
	this->klub = klub;
}
void pilkarz::setAsysty(int a) {
	asysty = a;
}
void pilkarz::setGole(int a) {
	gole = a;
}
void pilkarz::setImie(string b) {
	imie = b;
}
void pilkarz::setNazwisko(string b) {
	nazwisko = b;
}
void pilkarz::setKartki(int a) {
	kartki = a;
}
void pilkarz::setKlub(int a) {
	klub = a;
}
int pilkarz::getAsysty() {
	return asysty;
}
int pilkarz::getGole() {
	return gole; 
}
string pilkarz::getImie() const {
	return imie;
}
string pilkarz::getNazwisko() const {
	return nazwisko;
}
int pilkarz::getKartki() {
	return kartki;
}
int pilkarz::getKlub() {
	return klub;
}
