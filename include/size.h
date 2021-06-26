#pragma once/**
@file size.h
@brief Tutaj znajduje sie zdefiniowane parametry przekazywane dla calego programu
*/
#include "Vector.h"

constexpr int SIZE = 3; ///< Zmienna wektorowa
constexpr int SIZE1 = 28; ///< Zmienna do graniastoslupa
constexpr int SIZE2 = 20; ///< Zmienna do prostopadloscianu

#define cialo_dron "../dat/cialo_dron.dat" ///< sciezka do ciala drona numer  = 0
#define silnik1 "../dat/silnik1.dat"       ///< sciezka do silnika numer = 1 drona = 0
#define silnik2 "../dat/silnik2.dat"       ///< sciezka do silnika numer = 2 drona = 0
#define silnik3 "../dat/silnik3.dat"       ///< sciezka do silnika numer = 3 drona = 0
#define silnik4 "../dat/silnik4.dat"       ///< sciezka do silnika numer = 4 drona = 0
#define trasa "../dat/trasa.dat"           ///< sciezka do zapisanej trasy ktora pokona dron
#define cialo_dron_2 "../dat/cialo_dron_2.dat"  ///< sciezka do ciala drona numer = 1
#define silnik1_d2 "../dat/silnik1_d2.dat"      ///< sciezka do silnika numer = 1 drona = 1
#define silnik2_d2 "../dat/silnik2_d2.dat"      ///< sciezka do silnika numer = 2 drona = 1
#define silnik3_d2 "../dat/silnik3_d2.dat"      ///< sciezka do silnika numer = 3 drona = 1
#define silnik4_d2 "../dat/silnik4_d2.dat"      ///< sciezka do silnika numer = 4 drona = 1
int obiekty = 0;                                ///< licznik obiektow
int suma_obiektow = 0;                          ///< suma wszystkich obiektow

double wspolrzedneV1[] = {5,4,5};
double wspolrzedneV2[] = {5,-4,5};
double wspolrzedneV3[] = {-5,4,5};
double wspolrzedneV4[] = {-5,-4,5};
double wspolrzedneV5[] = {10,8,4};
double wspolrzedneV6[] = {8,8,2};
double wspolrzedneV7[] = {20,20,0};
double wspolrzedneV8[] = {0,0,0};
double wspolrzedneV9[] = {0,0,2};
double wspolrzedneV10[] = {0,0,0};
double wspolrzedneV11[] = {1,0,0};
/**
    @brief zespol Vectorow sluzacy do obslugiwania drona w fazie latania
    @return Vectory wypelione wspolrzednymi

*/
Vector<SIZE> v1 = wspolrzedneV1;
Vector<SIZE> v2 = wspolrzedneV2;
Vector<SIZE> v3 = wspolrzedneV3;
Vector<SIZE> v4 = wspolrzedneV4;

Vector<SIZE> skala_cialo = wspolrzedneV5;
Vector<SIZE> skala_silnik = wspolrzedneV6;

Vector<SIZE> V1 = wspolrzedneV8;
Vector<SIZE> V2 = wspolrzedneV7;
Vector<SIZE> V3 = wspolrzedneV9;
Vector<SIZE> V5 = wspolrzedneV11;
const char *PlikiSilniki[][5] = {{silnik1, silnik2, silnik3, silnik4, nullptr},{silnik1_d2, silnik2_d2, silnik3_d2, silnik4_d2, nullptr }};  ///< Pliki zapisane wraz z silnikami do obu dronow
const char *PlikiKorpusy[][2] = {{cialo_dron, nullptr},{cialo_dron_2, nullptr}};   ///< Pliki zapisane wraz z korpusami do obu dronow
