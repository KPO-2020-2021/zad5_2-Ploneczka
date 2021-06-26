#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include <cstdlib>

#include "Vector.h"
#include "dron.h"
#include "size.h"
#include "lacze_do_gnuplota.h"
#include "bryła_wzorzec.h"
#include "prostopadloscian.h"
#include "graniastoslup.h"
#include "Matrix.h"

int main() {
       char wybor ='.';
       int numer = 0, promien = 0;

       PzG::LaczeDoGNUPlota Lacze, Lacze2;
       Lacze.DodajNazwePliku("../bryly/plaszczyzna.dat");
       Lacze.DodajNazwePliku(cialo_dron);
       Lacze.DodajNazwePliku(silnik1);
       Lacze.DodajNazwePliku(silnik2);
       Lacze.DodajNazwePliku(silnik3);
       Lacze.DodajNazwePliku(silnik4);
       Lacze.DodajNazwePliku(cialo_dron_2);
       Lacze.DodajNazwePliku(silnik1_d2);
       Lacze.DodajNazwePliku(silnik2_d2);
       Lacze.DodajNazwePliku(silnik3_d2);
       Lacze.DodajNazwePliku(silnik4_d2);

       Lacze.ZmienTrybRys(PzG::TR_3D);
       Lacze.Inicjalizuj();

       Lacze.UstawZakresX(-300,300);
       Lacze.UstawZakresY(-300,300);
       Lacze.UstawZakresZ(0,200);
       dron dron[2];
       dron[0].konstrukcja_drona(0);
       dron[1].konstrukcja_drona(1);
       Lacze.Rysuj();

       while (wybor!='k')
       {
              std::cout << " l - lot dronem" <<std::endl;
              std::cout << " d - zmiana drona" <<std::endl;
              std::cout << " n - Ukazuje numer aktualnego drona" <<std::endl;
              std::cout << " o - lot po okręgu drona" <<std::endl;
              std::cout << " k - koniec programu" <<std::endl;
              std::cout << " Liczba wektorow :" << obiekty <<std::endl;
              std::cout << " Suma wektorów :" << suma_obiektow <<std::endl;

              std::cin >> wybor;

             switch(wybor)
             {
                     case 'l':
                            dron[numer].animacja(Lacze);
                            break;
                     case 'd':
                            if (numer == 0)
                            {
                                   numer = 1;
                            }
                            else
                            {
                                   numer = 0;
                            }
                            std::cout << "Zmieniles drona. Numer aktualnego drona to : " <<numer <<std::endl;
                            break;
                     case 'n':
                            std::cout << "Twoj numer drona to: " << numer <<std::endl;
                            break;
                     case 'o':
                            std::cout << "Podaj promien okregu ruchu: " <<std::endl;
                            std::cin >> promien;
                            dron[numer].animacja_okrag(Lacze2, promien);
                            break;
                     case 'k':
                            std::cout << "Zakonczyles program lotow dronem...." <<std::endl;
                            break;
                     default :
                            if (wybor != 'l' && wybor != 'd' && wybor != 'n')
                            {
                                   std::cout << "Nie ma takiej opcji !, wybierz inna..." <<std::endl;
                            }
                            break;
             }
       }
}