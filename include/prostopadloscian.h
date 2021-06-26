#pragma once/**
@file prostopadloscian.h
@brief Tutaj znajduje sie prostopadloscin(sluzy on do tworzenia korpusu drona)
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#include "size.h"
#include "Vector.h"
#include "Matrix.h"
#include "bryła_wzorzec.h"

class prostopadloscian: public bryla_wzorzec  ///< klasa prostopadloscianu dziedziczy po bryle wzorcowej
{
    private:
    Vector<SIZE> wierzcholekwzor[SIZE2];
    Vector<SIZE> wierzcholki[SIZE2];
    public:
    prostopadloscian();    ///< Pusty konstruktor
    void ladowanie_wsp ();  ///< Ladowanie wspolrzednych korpusu
    void translacja();      ///< Przesuniecie korpusy
    void obrot();           ///< Obracanie korpusy 
    void zapisz(const char *nazwaplikuzapisu);     ///< Zapisuje wsporzedne zmienione
    void poczatek(Vector <SIZE> poczatek);          ///<  podaje polozenie poczatkowe
    void przesuniecie(Vector <SIZE> miejsce, double kat);  ///<  podaje wspolrzedne i kat obrotu drona
    void tworzenie (Vector <SIZE> skala2);      ///< Konstrukcja drona za pomocą skalowania
};

prostopadloscian::prostopadloscian():bryla_wzorzec()
{
}
void prostopadloscian::ladowanie_wsp()
{
    std::fstream otwarcie;
    otwarcie.open(b_prostopadloscian, std::ios::in);
    if(otwarcie.good() == true)
    {
        for (int i = 0; i <SIZE2; i++)
        {
            otwarcie >> wierzcholekwzor[i];
        }
    }
    else
    {
        throw std::invalid_argument("Nie otworzono pliku !");
        otwarcie.close();
    }
}

void prostopadloscian::translacja()
{
    obiekty++;
    suma_obiektow++;
    for(int i =0; i < SIZE2; i++)
    {
        wierzcholki[i] = (wierzcholekwzor[i] *skala)+polozenie + polozonie_poczatek;
    }
}

void prostopadloscian::obrot()
{
    suma_obiektow++;
    Matrix<SIZE> matrix = Matrix<SIZE>('z', katkat);
    for(int i = 0; i <  SIZE2; i++)
    {
        wierzcholki[i] = matrix * (wierzcholekwzor[i]* skala) + polozenie + polozonie_poczatek;
    }

}

void prostopadloscian::zapisz(const char* nazwaplikuzapisu)
{
    std::ofstream zapis;
    zapis.open(nazwaplikuzapisu, std::ios::out);
    if(zapis.good() == true)
    {
        for(int i= 0; i< SIZE2; i++)
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

void prostopadloscian:: poczatek(Vector<SIZE> poczatek)
{
    polozonie_poczatek = poczatek;
}

void prostopadloscian::przesuniecie(Vector<SIZE> miejsce, double kat)
{
    polozenie = miejsce;
    katkat = kat;
}

void prostopadloscian::tworzenie(Vector <SIZE> skala2)
{
    skala = skala2;
}