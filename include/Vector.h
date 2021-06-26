#pragma once/**
@file Vector.h
@brief Tutaj znajduje sie Vector wraz z definicja.
*/
#include "Matrix.h"
#include <iostream>
#include <math.h>
#define MIN 0.0000000001

template<int SIZE>
class Vector {

private:

    double tab[SIZE];     ///Tablica wektora

public:

     /**
    @brief konstruktor domyslny 
    @return Vector wypelniony zerami 

    */
    Vector();
    /**
    @brief konstruktor parametryczny 
    @return Vector wypelniony podanymi wartosciami

    */
    Vector(double [SIZE]);

    Vector<SIZE> operator + (const Vector<SIZE>  &v) const; ///< przeciazany operator dodawania dla klasy Vecotr

    Vector<SIZE>  operator - (const Vector<SIZE>  &v) const;///< przeciazany operator odejmowania dla klasy Vecotr

    Vector<SIZE>  operator * (const double &tmp) const;///< przeciazany operator mnozenia dla klasy Vecotr

    Vector<SIZE> operator *(const Vector<SIZE> &vector2); ///<przeciazony operator mnozenia Vector*/VEctor

    Vector<SIZE>  operator / (const double &tmp) const;///< przeciazany operator dzielenia dla klasy Vecotr
    template<int SIZE1>
    friend Vector<SIZE1> operator * (Matrix<SIZE1> m1, Vector<SIZE1> tmp);    ///< przeciazany operator mnożenia przez wektor
   
    template<int SIZE1>
    friend bool operator == (Vector<SIZE1> vec1, Vector<SIZE1> vec2);   ///< przeciazany operator porownania wektorow
    /**
    @brief  indeks wektora
    @return  Wartosc wektora w danym miejscu tablicy.

    */
    const double &operator [] (int index) const;
    /**
    @brief  indeks wektora
    @return  Wartosc wektora w danym miejscu tablicy jako stala. 

    */
    double &operator [] (int index);

    /**
    @brief sprawdzam dlugosc wektora
    @return dlugosc wektora

    */
    double dl_boku () const;

};
template<int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp); ///< przeciazany operator wypisywania
template<int SIZE>
std::istream &operator >> (std::istream &in, Vector<SIZE> &tmp);   ///< przeciazony operator wypisywania


template<int SIZE>
Vector<SIZE>::Vector() {
    for ( int i = 0; i < SIZE; i++) {
        tab[i] = 0;
    }
}

template<int SIZE>
Vector<SIZE>::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        tab[i] = tmp[i];
    }
}


template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator + (const Vector<SIZE> &v) const{
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] + v[i];
    }
    return result;
}


template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator - (const Vector<SIZE> &v) const {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] - v[i];
    }
    return result;
}


template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator * (const double &tmp) const {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        result[i] =  tab[i] * tmp;
    }
    return result;
}


template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator / (const double &tmp)const{
    Vector<SIZE> result;

    for (int i = 0; i < SIZE; i++) {
        result[i] = tab[i] / tmp;
    }

    return result;
}


template<int SIZE>
const double &Vector<SIZE>::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Error: Wektor jest poza zasiegiem!" );
    }
    return tab[index];
}


template<int SIZE>
double &Vector<SIZE>::operator[](int index) {
     if (index < 0 || index >= SIZE) {
        throw std::out_of_range("Error: Wektor jest poza zasiegiem!" );
    }
    return tab[index];
}


template<int SIZE>
std::ostream &operator << (std::ostream &out, Vector<SIZE> const &tmp) {
    for (int i = 0; i < SIZE; i++) {
        out << tmp[i] << " ";
    }
    return out;
}
template<int SIZE>
bool operator == (Vector<SIZE> vec1, Vector<SIZE> vec2)
{
    for(int i = 0; i< SIZE;i++)
    {
        if (abs(vec1[i] - vec2[i]) >MIN)
        {   
            return false;
        }
    }
    return true; 
}


template<int SIZE>
std::istream &operator >> (std::istream &in, Vector <SIZE>&tmp) {
    for (int i = 0; i < SIZE; i++) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

template<int SIZE>
Vector<SIZE> operator * (Matrix<SIZE> m1, Vector<SIZE> tmp) {
    Vector<SIZE> result;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i] += m1(i,j) * tmp[j];
        }
    }
    return result;
}
template<int SIZE>
double Vector<SIZE>::dl_boku() const
{
    double dlugosc = 0;
    for (int i= 0;i<SIZE; i++)
    {
        dlugosc += pow(tab[i], 2);
    }
    return sqrt(dlugosc);
}
template<int SIZE>
Vector <SIZE> Vector<SIZE>::operator*(const Vector <SIZE> &vector2)
{
    Vector wynik;
    for(int i =0;i < SIZE; i++)
    {
        wynik[i] = tab[i] = tab[i]* vector2[i];
    }
    return wynik;
}