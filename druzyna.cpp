#include "druzyna.hpp"
using namespace std;

int druzyna::liczba_druzyn = 0;
druzyna::druzyna(string nazwa_druzyny, string trener_imie, string trener_nazwisko, int zwyciestwa, int przegrane, int licznosc)	 {
	liczba_druzyn++;
	indeks = liczba_druzyn; 
	this->nazwa_druzyny = nazwa_druzyny;
	this->trener_imie = trener_imie;
	this->trener_nazwisko = trener_nazwisko;
	this->zwyciestwa = zwyciestwa;
	this->przegrane = przegrane;
	this->licznosc = licznosc;
}
void druzyna::setNazwa_druzyny(string b) {
	nazwa_druzyny = b;
}
void druzyna::setIndeks(int a) {
	indeks = a;
}
void druzyna::setLicznosc(int a) {
	licznosc = a;
}
void druzyna::setPrzegrane(int a) {
	przegrane = a;
}
void druzyna::setTrener_imie(string b) {
	trener_imie = b;
}
void druzyna::setTrener_nazwisko(string b) {
	trener_imie = b;
}
void druzyna::setZwyciestwa(int a) {
	zwyciestwa = a;
}
string druzyna::getNazwa_druzyny() {
	return nazwa_druzyny; 
}
int druzyna::getIndeks() {
	return indeks;
}
int druzyna::getLicznosc() {
	return licznosc;
}
int druzyna::getPrzegrane() {
	return przegrane;
}
int druzyna::getZwyciestwa() {
	return zwyciestwa;
}
int druzyna::getLiczba_druzyn(){
	return liczba_druzyn;
}
string druzyna::getTrener_imie() {
	return trener_imie;
}
string druzyna::getTrener_nazwisko() {
	return trener_nazwisko;
}
