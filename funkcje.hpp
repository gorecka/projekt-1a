#ifndef FUNKCJE_HPP
#define FUNKCJE_HPP

void wczytaj();
void wczytajcd();
void zamiana(pilkarz &a, pilkarz &b);
void zamiana(druzyna &a, druzyna &b);
void najlepszy_gracz(vector<pilkarz> &a);
void najbardziej_agresywny(vector<pilkarz> &a);
void najlepsza_druzyna(vector<druzyna> &a, vector<pilkarz> &b);
void wyswietl_pilkarzy(vector<pilkarz> &a, vector<druzyna> &b);
void wyswietl_druzyny(vector<druzyna> &b, vector<pilkarz> &a);
void wyswietl_manager(vector<pilkarz> &a);
void skup_pilkarza(int indeks);
void sprzedaj_pilkarza(int indeks, int indeks_druzyny);
void kup();
extern vector<pilkarz> lista_pilkarzy;
extern vector<druzyna> lista_druzyn;
extern vector<pilkarz> lista_managera;
extern int licznik_pilkarzy;
extern int licznik_druzyn;
extern int licznik_managera;
extern int budzet;

#endif
