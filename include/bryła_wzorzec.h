#pragma once/**
@file bryla_wzorzec.h
@brief Tutaj znajduje sie bryla_wzorzec wraz z definicja.
*/

#include <iostream>
#include <cmath>
#include <size.h>
#include "Vector.h"

class bryla_wzorzec
{
protected:
    const char* b_prostopadloscian  =  "../bryly/prostopadloscian.dat";  ///< lokalizacja pliku prostopadloscianu  
    const char* b_graniastoslup = "../bryly/graniastoslup.dat";    ///< lokalizacja pliku graniastoslup
    Vector<SIZE> skala;  ///< wektor skalowania
    double katkat;     ///< kat w jakim polozeniu znajduje sie bryla
    Vector<SIZE> polozenie;   ///< aktualne polozenie bryly
    Vector<SIZE> polozonie_poczatek;  ///< polozenie startowe bryly
public:
    // bryla_wzorzec();     ///< Pusty konstruktor bryly
};

// bryla_wzorzec::bryla_wzorzec()
// {
//     // nazwaplikugraniastoslup = "../bryly_wzorcowe/graniastoslup6.dat";
//     // nazwaplikuszescian = "../bryly_wzorcowe/szescian.dat";
//     skala = Vector<SIZE> ();
//     katkat = 0;
//     polozenie = V1;
//     polozonie_poczatek = Vector<SIZE>();
// }
