#pragma once/**
@file graniastoslup.h
@brief Tutaj znajduje sie graniastoslup(sluzy on do konstrukcji silnikow drona)
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "size.h"
#include "Vector.h"
#include "Matrix.h"
#include "bryła_wzorzec.h"


class graniastoslup: public bryla_wzorzec ///< klasa graniastoslupa dziedziczy po bryle wzorcowej
{
private:
    Vector<SIZE> wierzcholekwzor[SIZE1];
    Vector<SIZE> wierzcholki[SIZE1];
    Vector<SIZE> przesuniecie_korpusu;
public:
    graniastoslup();           ///< Pusty konstruktor
    void ladowanie_wsp ();     ///< Ladowanie wspolrzednych silnika
    void translacja();         ///< Przesuniecie silnika 
    void obrot();              ///< Obracanie korpusy 
    void zapisz(const char *nazwaplikuzapisu); ///< Zapisuje wspolrzedne zmienione
    void poczatek(Vector <SIZE> poczatek);     ///<  podaje polozenie poczatkowe
    void przesuniecie(Vector <SIZE> miejsce, double kat);  ///<  podaje wspolrzedne i kat obrotu drona
    void tworzenie (Vector  <SIZE> korpus, Vector <SIZE> skala);  //< Konstrukcja drona za pomocą skalowania
};

graniastoslup::graniastoslup():bryla_wzorzec()
{
}

void graniastoslup::ladowanie_wsp()
{
    std::fstream otwarcie;
    otwarcie.open(b_graniastoslup, std::ios::in);
    if(otwarcie.good() == true)
    {
        for (int i = 0; i <SIZE1; i++)
        {
            otwarcie >> wierzcholekwzor[i];
        }
    }
    else
    {
        throw std::invalid_argument("Nie otworzono pliku123 !");
        exit(0);
    }
    otwarcie.close();
}

void graniastoslup::translacja()
{
    obiekty++;
    suma_obiektow++;
    for(int i =0; i < SIZE1; i++)
    {
        wierzcholki[i] = (wierzcholekwzor[i] *skala)+przesuniecie_korpusu + polozenie + polozonie_poczatek;
    }
}

void graniastoslup::obrot()
{
    suma_obiektow++;
    Matrix<SIZE> matrix = Matrix<SIZE>('z', katkat);
    for(int i = 0; i <  SIZE1; i++)
    {
        wierzcholki[i] = matrix * (wierzcholekwzor[i]* skala +przesuniecie_korpusu) +polozenie + polozonie_poczatek;
    }

}

void graniastoslup::zapisz(const char* nazwaplikuzapisu)
{
    std::ofstream zapis;
    zapis.open(nazwaplikuzapisu, std::ios::out);
    if(zapis.good() == true)
    {
        for(int i= 0; i< SIZE1; i++)
        {
            zapis<<wierzcholki[i] <<std::endl;
            i++;
            zapis<<wierzcholki[i]<<std::endl;
            i++;
            zapis<<wierzcholki[i] <<std::endl;
            i++;
            zapis<<wierzcholki[i]<<std::endl<<std::endl;
            
        }
    }
    else
    {
        throw std::invalid_argument("Blad zapisu wspolrzednych!");
        zapis.close();
    }
}

void graniastoslup:: poczatek(Vector<SIZE> poczatek)
{
    polozonie_poczatek= poczatek;
}

void graniastoslup::przesuniecie(Vector<SIZE> miejsce, double kat)
{
    polozenie = miejsce;
    katkat = kat;
}

void graniastoslup::tworzenie(Vector <SIZE> korpus, Vector<SIZE> skala_korpus)
{
    przesuniecie_korpusu = korpus;
    skala = skala_korpus;
}