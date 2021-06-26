#pragma once/**
@file dron.h
@brief Tutaj znajduje sie dron(poloczone poprzez 4 graniastoslupy i jeden prostopadloscian)
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <unistd.h>

#include "size.h"
#include "Vector.h"
#include "Matrix.h"
#include "bryła_wzorzec.h"
#include "graniastoslup.h"
#include "lacze_do_gnuplota.h"
#include "prostopadloscian.h"
class dron
{   
    private:
    prostopadloscian korpus;
    graniastoslup silnik[4];
    double katkat = 0;
    Vector<SIZE> polozenie = V1;
    Vector<SIZE> polozenie_poczatkowe;
    Vector<SIZE> skalasilnik = skala_silnik;
    Vector<SIZE> skalacialo = skala_cialo;
    Vector<SIZE> miejsce_silniki[4] = {v1, v2, v3, v4};
    int nrdrona = 0;
    int promien = 0;

    public:
    void polozenie_drona(Vector<SIZE> parametry_pocz, double kat);   ///< dron dostaje parametry
    void konstrukcja_drona(int numer);    ///< tworzy 2 drony z figur oraz przypisuje mu numer 0 oraz 1
    void przesuniecie_drona();    ///< dron przesuwany jest na nowe wspolrzedne
    void polozenie_poczatek(Vector<SIZE> polozenie_poczatek_d);   ///< dron dostaje parametry poczatkowe
    void przesuniecie ();   ///< dron jest przesuwany lecz bez obrotu
    void obroc();     ///< obrot drona
    void animacja(PzG::LaczeDoGNUPlota Lacze);  ///< ukazuje latajacego drona
    void animacja_okrag(PzG::LaczeDoGNUPlota Lacze, int promien2); ///< ukazuje latajacego  drona po okręgu
    void dodajTrase(PzG::LaczeDoGNUPlota &Lacze, int kat, double dlugosc);   ///< w GNUPlocie ukaza jest trasa drona
    void dodajTrase_okrag(PzG::LaczeDoGNUPlota &Lacze, double dlugosc); ///< w GNUPlocie ukaza jest trasa drona po okręgu
};

void dron::polozenie_drona(Vector<SIZE> parametry_pocz, double kat)
{
    polozenie = parametry_pocz;
    katkat = kat;
}

void dron::konstrukcja_drona(int numer)
{
    nrdrona = numer;
    polozenie_poczatkowe = V2*(numer+1);
    polozenie_drona(V1, 0);
    int i = 0;
    for(unsigned int indeks = 0; PlikiSilniki[nrdrona][indeks] != nullptr; indeks++)
    {
        silnik[indeks].tworzenie(miejsce_silniki[i], skalasilnik);
        silnik[indeks].poczatek(polozenie_poczatkowe);
        silnik[indeks].ladowanie_wsp();
        silnik[indeks].translacja();
        silnik[indeks].zapisz(PlikiSilniki[nrdrona][indeks]);
        i++;
    }
    for(unsigned int indeks = 0; PlikiKorpusy[nrdrona][indeks] != nullptr; indeks++)
    {
        korpus.tworzenie(skalacialo);
        korpus.poczatek(polozenie_poczatkowe+V3);
        korpus.ladowanie_wsp();
        korpus.translacja();
        korpus.zapisz(PlikiKorpusy[nrdrona][indeks]);
        i++;
    }
}

void dron::polozenie_poczatek(Vector <SIZE> polozenie_poczatek_d)
{
    polozenie_poczatkowe = polozenie_poczatek_d;
    for(unsigned int indeks = 0; PlikiSilniki[nrdrona][indeks]!= nullptr; indeks++)
    {
        silnik[indeks].poczatek(polozenie_poczatkowe);
    }
    for(unsigned int indeks = 0; PlikiKorpusy[nrdrona][indeks]!= nullptr; indeks++)
    {
        korpus.poczatek(polozenie_poczatkowe);
    }
}
void dron::przesuniecie()
{
    for(unsigned int indeks = 0; PlikiSilniki[nrdrona][indeks] != nullptr; indeks++)
    {
        silnik[indeks].przesuniecie(polozenie, katkat);
        silnik[indeks].ladowanie_wsp();
        silnik[indeks].translacja();
        silnik[indeks].zapisz(PlikiSilniki[nrdrona][indeks]);
    }
    for(unsigned int indeks = 0; PlikiKorpusy[nrdrona][indeks] != nullptr; indeks++)
    {
        korpus.przesuniecie(polozenie, katkat);
        korpus.ladowanie_wsp();
        korpus.translacja();
        korpus.zapisz(PlikiKorpusy[nrdrona][indeks]);
    }
}

void dron::obroc()
{
    for(unsigned int indeks = 0; PlikiSilniki[nrdrona][indeks] != nullptr; indeks++)
    {
        silnik[indeks].przesuniecie(polozenie, katkat);
        silnik[indeks].ladowanie_wsp();
        silnik[indeks].obrot();
        silnik[indeks].zapisz(PlikiSilniki[nrdrona][indeks]);
    }
    for(unsigned int indeks = 0; PlikiKorpusy[nrdrona][indeks] != nullptr; indeks++)
    {
        korpus.przesuniecie(polozenie, katkat);
        korpus.ladowanie_wsp();
        korpus.obrot();
        korpus.zapisz(PlikiKorpusy[nrdrona][indeks]);
    }
}

void dron::animacja(PzG::LaczeDoGNUPlota Lacze)
{
    int kat =1, kak2 = katkat;
    double dl_lot = 0;
    Vector <SIZE> V4 = wspolrzedneV10, V6;
    std::cout<< "Podaj kat obrotu drona :" <<std::endl;
    std::cin >> kat;
    std::cout<< "Podaj dlugosc lotu :" <<std::endl;
    std::cin >> dl_lot;
    dodajTrase(Lacze, kat, dl_lot);

    for(int i = 0; i < 100; i = i+2)
    {
        V4 =V4+V3;
        polozenie_drona(V4, kak2);
        obroc();
        usleep(10000);
        Lacze.Rysuj();
    }

    if(kat >= 0)
    {
        for(int i = 0; i <= kat; i+=5)
        {
            polozenie_drona(V4, kak2+i);
            obroc();
            usleep(10000);
            Lacze.Rysuj();
        }
    }
    else{
        for(int i = 0; i >= kat; i-= 5)
        {
            polozenie_drona(V4, kak2+i);
            obroc();
            usleep(10000);
            Lacze.Rysuj();
        }
    }

    Matrix<SIZE> macierz_lot = Matrix<SIZE>('z', katkat);
    V6 = macierz_lot * V5;
    for(int i =0; i <= dl_lot; i+=1)
    {
        V4 = V4+V6;
        polozenie_drona(V4, katkat);
        obroc();
        usleep(10000);
        Lacze.Rysuj();
    }

    for(int i = 100; i > 0; i -= 2)
    {
        V4 = V4-V3;
        polozenie_drona(V4, katkat);
        obroc();
        usleep(10000);
        Lacze.Rysuj();
    }

    polozenie_poczatek((polozenie+polozenie_poczatkowe));
    Lacze.Rysuj();
}

void dron::dodajTrase(PzG::LaczeDoGNUPlota &Lacze, int kat, double dlugosc)
{
    Vector<SIZE> zmienna = polozenie_poczatkowe;
    Vector<SIZE> V6, V7 = V3;
    std::ofstream Wyjscie(trasa);
    if (!Wyjscie.is_open())
    {
        throw std::invalid_argument("Blad otworzenia pliku!");
    }
    Wyjscie << zmienna<<std::endl;
    zmienna = zmienna+(V7*50);
     Wyjscie << zmienna<<std::endl;
     Matrix<SIZE> macierz_trasa = Matrix<SIZE>('z', katkat+kat);
     V6 = macierz_trasa*V5;
     zmienna = zmienna+(V6*dlugosc);
     Wyjscie <<zmienna <<std::endl;
     V7=V3;
     zmienna = zmienna -(V7*50);
     Wyjscie <<zmienna <<std::endl;
     Lacze.DodajNazwePliku(trasa);
     }

void dron::dodajTrase_okrag(PzG::LaczeDoGNUPlota &Lacze, double dlugosc)
{
    Vector<SIZE> zmienna = polozenie_poczatkowe;
    Vector<SIZE> V6, V7 = V3;
    std::ofstream Wyjscie(trasa);
    if (!Wyjscie.is_open())
    {
        throw std::invalid_argument("Blad otworzenia pliku!");
    }
    Wyjscie << zmienna<<std::endl;
    zmienna = zmienna+(V7*50);
    Wyjscie << zmienna<<std::endl;
    for(int i = 0; i < 360; i+=3)
    {
        Matrix<SIZE> macierz_lot = Matrix<SIZE>('z',katkat+i);
        V6 = macierz_lot * V5;

        V6 = V6/V6.dl_boku()*2*M_PI*dlugosc/120;
        zmienna = zmienna +V6;
        Wyjscie << zmienna<<std::endl;

    }
     Wyjscie <<zmienna <<std::endl;
     V7=V3;
     zmienna = zmienna -(V7*50);
     Wyjscie <<zmienna <<std::endl;
     Lacze.DodajNazwePliku(trasa);
     }

void dron::animacja_okrag(PzG::LaczeDoGNUPlota Lacze, int promien2)
{
    int kak2 = katkat;
    double promien = promien2;
    Vector <SIZE> V4 = wspolrzedneV10, V6;
    dodajTrase_okrag(Lacze, promien2);

    for(int i = 0; i < 100; i = i+2)
    {
        V4 =V4+V3;
        polozenie_drona(V4, kak2);
        obroc();
        usleep(10000);
        Lacze.Rysuj();
    }
    
    for(int i = 0; i < 360; i+=3)
    {
    
        polozenie_drona(V4, kak2+i);
        obroc();
        usleep(10000);
        Lacze.Rysuj();

        Matrix<SIZE> macierz_lot = Matrix<SIZE>('z', kak2+i);
        V6 = macierz_lot * V5;

        V6 = V6/V6.dl_boku()*2*M_PI*promien/120;

        V4 = V4+V6;
        polozenie_drona(V4, kak2+i);
        obroc();
        usleep(10000);
        Lacze.Rysuj();

    }

    for(int i = 100; i > 0; i -= 2)
    {
        V4 = V4-V3;
        polozenie_drona(V4, katkat);
        obroc();
        usleep(10000);
        Lacze.Rysuj();
    }

    polozenie_poczatek((polozenie+polozenie_poczatkowe));
    Lacze.Rysuj();
}